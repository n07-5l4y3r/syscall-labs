// DirectDrawFun.cpp

#include <inc.hpp>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

HWND CreateRenderWindow(unsigned uWidth, unsigned uHeight)
{
	printf("\n > Creating Render Preview Window...\n");

	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"rendererWC";

	RegisterClassEx(&wc);

	RECT wr = { 0, 0, (LONG)uWidth, (LONG)uHeight };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(NULL,
		L"rendererWC",
		L"DirectX11 Renderer Preview",
		WS_OVERLAPPEDWINDOW,
		300,
		300,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		wc.hInstance,
		NULL);

	ShowWindow(hWnd, SW_HIDE);

	return hWnd;
}

HRESULT Blt_DXGISurface_To_DIRECTDRAWSURFACE7(IDirectDraw7* pDevice, IDXGISurface* pSrc, LPDIRECTDRAWSURFACE7 pDest)
{
	// Check Source Format
	bool SrcFormatIsRGBA = false;
	DXGI_SURFACE_DESC ds = { 0 };
	{
		ZeroMemory(&ds, sizeof(DXGI_SURFACE_DESC));
		{
			auto hResult = pSrc->GetDesc(&ds);
			if (hResult != S_OK)
			{
				printf(" !      pSrc->GetDesc\n");
				printf("    [-] hResult = %#x\r\n", hResult);
				return hResult;
			}
		}
		for (auto o :
			{
				DXGI_FORMAT_R8G8B8A8_TYPELESS,
				DXGI_FORMAT_R8G8B8A8_UNORM,
				DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
				DXGI_FORMAT_R8G8B8A8_UINT,
				DXGI_FORMAT_R8G8B8A8_SNORM,
				DXGI_FORMAT_R8G8B8A8_SINT
			})
			if (ds.Format == o)
			{
				SrcFormatIsRGBA = true;
				continue;
			}
		if (!SrcFormatIsRGBA)
		{
			printf(" !      SrcFormatIs<NOT>RGBA\n");
			return DD_FALSE;
		}
	}
	// Lock Destination
	DDSURFACEDESC2 dd;
	{
		ZeroMemory(&dd, sizeof(dd));
		dd.dwSize = sizeof(dd);
		{
			auto hResult = pDest->Lock(NULL, &dd, DDLOCK_NOSYSLOCK | DDLOCK_WAIT | DDLOCK_WRITEONLY, NULL);
			if (hResult != DD_OK)
			{
				printf(" !      pDest->Lock\n");
				printf("    [-] hResult = %#x\r\n", hResult);
				return hResult;
			}
		}
	}
	// Check Destination Format
	bool DestFormatIsBGRA = false;
	{
		DestFormatIsBGRA = (
			(dd.ddpfPixelFormat.dwRBitMask & 0x00FF0000) &&
			(dd.ddpfPixelFormat.dwGBitMask & 0x0000FF00) &&
			(dd.ddpfPixelFormat.dwBBitMask & 0x000000FF) &&
			(dd.ddpfPixelFormat.dwRGBAlphaBitMask & 0xFF000000));
		if (!DestFormatIsBGRA)
		{
			printf(" !      DestFormatIs<NOT>BGRA\n");
			printf("    > B: %#x\n", dd.ddpfPixelFormat.dwBBitMask);
			printf("    > G: %#x\n", dd.ddpfPixelFormat.dwGBitMask);
			printf("    > R: %#x\n", dd.ddpfPixelFormat.dwRBitMask);
			printf("    > A: %#x\n", dd.ddpfPixelFormat.dwRGBAlphaBitMask);
			pDest->Unlock(NULL);
			return DD_FALSE;
		}
	}
	// Map Source
	DXGI_MAPPED_RECT ms = { 0 };
	{
		ZeroMemory(&ms, sizeof(DXGI_MAPPED_RECT));
		{
			auto hResult = pSrc->Map(&ms, D3D11_MAP_READ);
			if (hResult != DD_OK)
			{
				printf(" !      pSrc->Map\n");
				printf("    [-] hResult = %#x\r\n", hResult);
				pDest->Unlock(NULL);
				return hResult;
			}
		}
	}
	// Blit
	{
		const auto cpixelbytes = 4u;
		auto src_ptr = ms.pBits;
		auto dest_ptr = (BYTE*)dd.lpSurface;
		for (auto h = 0u; h < min(dd.dwHeight, ds.Height); h++)
		{
			auto w = 0u;
			for (; w < min(dd.dwWidth, ds.Width); w++)
			{
				dest_ptr[0] = src_ptr[2];
				dest_ptr[1] = src_ptr[1];
				dest_ptr[2] = src_ptr[0];
				dest_ptr[3] = src_ptr[3];
				//
				src_ptr += cpixelbytes;
				dest_ptr += cpixelbytes;
			}
			dest_ptr = dest_ptr - (w * cpixelbytes) + dd.lPitch;
			src_ptr = src_ptr - (w * cpixelbytes) + ms.Pitch;
		}
	}
	// Unmap Source
	{
		auto hResult = pSrc->Unmap();
		if (hResult != DD_OK)
		{
			printf(" !      pSrc->Unmap\n");
			printf("    [-] hResult = %#x\r\n", hResult);
			pDest->Unlock(NULL);
			return hResult;
		}
	}
	// Unlock Destination
	{
		auto hResult = pDest->Unlock(NULL);
		if (hResult != DD_OK)
		{
			printf(" !      pDest->Unlock\n");
			printf("    [-] hResult = %#x\r\n", hResult);

			return hResult;
		}
	}
	return S_OK;
}

auto duration = 0ull;

namespace GLOBALS
{
	DD_Overlay* pDD_Overlay = nullptr;
	DX11_BackgroundRenderer* pDX11_BackgroundRenderer = nullptr;
	ID2D1_Renderer* pID2D1_Renderer = nullptr;
}


class c_phys_helper
{
public:
	template<typename T>
	static T phys_read(UINT64 address, UINT64 target)
	{
		auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
		req_readmem.data.obj.target = target;
		req_readmem.data.obj.address = address;
		req_readmem.data.obj.size = sizeof T;

		if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
		{
			//printf("[%s		%llu	ms] rcv size: %lu\n", __FUNCTION__, std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::microseconds(took_time)).count(), ret_readmem.data.obj.read);
			return *(T*)(ret_readmem.data.obj.buf);
		}
	}
	template<typename T>
	static bool phys_write(UINT64 address, UINT64 target, T buf)
	{
		auto [req_writemem, ret_writemem] = ipc::master::alloc_packet<ipc::shared::internal::writemem>();
		req_writemem.data.obj.target = target;
		req_writemem.data.obj.address = address;
		req_writemem.data.obj.size = sizeof T;

		memcpy(req_writemem.data.obj.buf, (void*)&buf, sizeof(buf));

		if (&ret_writemem == ipc::master::cmd<ipc::shared::internal::writemem>(&req_writemem))
		{
			return true;
		}
		return false;
	}
};

struct matrixdata
{
	D3DXVECTOR3 Translation;
	D3DXVECTOR3 ViewUp;
	D3DXVECTOR3 ViewRight;
	D3DXVECTOR3 ViewForward;
	D3DXVECTOR3 ViewMatrix;
	D3DXVECTOR3 Projection_1;
	D3DXVECTOR3 Projection_2;
};

UINT64 address = 0, target = 0, max_address = 0;

bool esp_toggle, esp_eft_toggle = 0;
void esp()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	auto world = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x26535F0);
	if (!world)
	{
		return;
	}
	auto Camera = games::c_phys_util::Instance().phys_read<uintptr_t>(world + 0x918);
	if (!Camera)
	{
		return;
	}

	//
	if (games::arma3::c_a3::Instance().entities_write.load() == true) return;
	auto e = games::arma3::c_a3::Instance().entities;
	//

	auto vm = games::arma3::s_matrix();

	struct s_block { char mem[0x100]; };
	auto read_block_matrix = games::c_phys_util::Instance().phys_read<s_block>(Camera);

	vm.mtranslation = *(D3DXVECTOR3*)(read_block_matrix.mem + 0x2C);
	vm.up = *(D3DXVECTOR3*)(read_block_matrix.mem + 0x14);
	vm.right = *(D3DXVECTOR3*)(read_block_matrix.mem + 0x8);
	vm.forward = *(D3DXVECTOR3*)(read_block_matrix.mem + 0x20);
	vm.matrice = *(D3DXVECTOR3*)(read_block_matrix.mem + 0x58);
	vm.projection1 = *(D3DXVECTOR3*)(read_block_matrix.mem + 0xD0);
	vm.projection2 = *(D3DXVECTOR3*)(read_block_matrix.mem + 0xDC);

	for (auto ent : e)
	{
		auto feet_w2s = games::arma3::c_a3::Instance().world_to_screen(ent.feet_pos, vm);
		if (feet_w2s.x == 0) continue;

		auto head_w2s = games::arma3::c_a3::Instance().world_to_screen(ent.head_pos, vm);
		if (head_w2s.x == 0) continue;

		float rapport = feet_w2s.y - head_w2s.y;
		sdk::render::render->DrawBorder(head_w2s.x - 25 - (rapport / 4), head_w2s.y, rapport / 2, rapport, 2, 0xff00ff00);
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

	sdk::render::render->RenderText(5, 20, 0xff00ff00, (char*)"graphic driver    execution time: %i", ms_int.count());
	sdk::render::render->RenderText(5, 35, 0xff00ff00, (char*)"entity processing execution time: %i", games::arma3::c_a3::Instance().execution_time_ms.load());
	sdk::render::render->RenderText(5, 50, 0xff00ff00, (char*)"packet queue current            : %i", ipc::master::queue.size());
}
class SystemString
{
public:
	uint64_t Address = 0;

	SystemString(uint64_t Addr = 0)
	{
		Address = Addr;
	}

	std::string GetContents()
	{
		std::string Return;

		uint32_t Length = games::c_phys_util::Instance().phys_read<uint32_t>(Address + 0x10);

		if (Length > 150)
		{
			//printf("Fake item\n");
			return Return;
		}

		struct s_block { char m[0x100]; };

		if (!Address)
			return Return;

		auto a = games::c_phys_util::Instance().phys_read<s_block>(Address + 0x14).m;

		for (int i = 0; i < 0x100; i++)
		{
			if (a[i * 2] != '\0')
				Return.push_back(a[i * 2]);
			else
				return Return;
		}

		return Return;
	}
};

static bool eft_bonknation = 0;

void esp_eft()
{
	auto t1 = std::chrono::high_resolution_clock::now();
	//
	int rendered = 0;

	if (!games::eft::c_updater::Instance().fps_object || !games::eft::c_updater::Instance().world_object)
	{
		sdk::render::render->RenderText(5, 55, 0xff00ff00, (char*)"FPS or WORLD not ready %04x", GetTickCount());
		return;
	}

	auto p = games::eft::c_updater::Instance().players;
	auto c = (games::eft::c_camera)games::eft::c_updater::Instance().fps_object;

	uint64_t FPSCamera = games::c_phys_util::Instance().phys_read<uint64_t>(c.base + 0x30);
	if (!FPSCamera)
	{
		sdk::render::render->RenderText(5, 55, 0xff00ff00, (char*)"Camera not ready");
		return;
	}

	uint64_t CameraObject = games::c_phys_util::Instance().phys_read<uint64_t>(FPSCamera + 0x18);
	if (!CameraObject)
	{
		sdk::render::render->RenderText(5, 55, 0xff00ff00, (char*)"Camera Object not ready");
		return;
	}

	auto v = games::c_phys_util::Instance().phys_read<games::eft::s_mat>(CameraObject + 0xD8);

	games::eft::s_mat ViewMatrix;
	ViewMatrix.m[0][0] = v.m[0][0];
	ViewMatrix.m[1][0] = v.m[0][1];
	ViewMatrix.m[2][0] = v.m[0][2];
	ViewMatrix.m[3][0] = v.m[0][3];
	ViewMatrix.m[0][1] = v.m[1][0];
	ViewMatrix.m[1][1] = v.m[1][1];
	ViewMatrix.m[2][1] = v.m[1][2];
	ViewMatrix.m[3][1] = v.m[1][3];
	ViewMatrix.m[0][2] = v.m[2][0];
	ViewMatrix.m[1][2] = v.m[2][1];
	ViewMatrix.m[2][2] = v.m[2][2];
	ViewMatrix.m[3][2] = v.m[2][3];
	ViewMatrix.m[0][3] = v.m[3][0];
	ViewMatrix.m[1][3] = v.m[3][1];
	ViewMatrix.m[2][3] = v.m[3][2];
	ViewMatrix.m[3][3] = v.m[3][3];

	/*printf("%f		%f		%f		%f\n",		v.m[0][0], v.m[0][1], v.m[0][2], v.m[0][3]);
	printf("%f		%f		%f		%f\n",		v.m[1][0], v.m[1][1], v.m[1][2], v.m[1][3]);
	printf("%f		%f		%f		%f\n",		v.m[2][0], v.m[2][1], v.m[2][2], v.m[2][3]);
	printf("%f		%f		%f		%f\n\n\n",	v.m[3][0], v.m[3][1], v.m[3][2], v.m[3][3]);*/

	auto gw = (games::eft::c_game_world)(games::eft::c_updater::Instance().world_object);
	auto local = (games::eft::c_player)games::eft::c_updater::Instance().localplayer;
	//auto local_fireport = local.get_fireport();

	//games::c_vector3 fireport_w2s;
	//if (c.w2s(local_fireport, fireport_w2s, ViewMatrix))
	//{
	//	sdk::render::render->RenderText(fireport_w2s.x, fireport_w2s.y, 0xff00ff00, (char*)"fireport");
	//}

	//recoil bonk
	if (local.base)
	{
		auto ProceduralWeaponAnimation = games::c_phys_util::Instance().phys_read<UINT64>(local.base + 0x190);
		if (ProceduralWeaponAnimation)
		{
			auto Breath = games::c_phys_util::Instance().phys_read<UINT64>(ProceduralWeaponAnimation + 0x28);
			if (Breath)
			{
				games::c_phys_util::Instance().phys_write<float>(Breath + 0xA4, 0.f);
				games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x22C, 0.f);
				games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x228, 0.f);
				games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x100, 1.f);
				games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x2f4, 0.f);
			}
		}
	}

	for (auto&& a : p)
	{
		auto w2s_bones = games::eft::t_bones();

		if (a.base == local.base) continue;

		if (!a.bones[games::eft::Bones::HumanHead].valid() /*|| !a.root_pos.valid()*/) continue;

		/*printf("%p	head	%f		%f		%f	\n", a.base, a.head_pos.x, a.head_pos.y, a.head_pos.z);
		printf("%p	root	%f		%f		%f	\n", a.base, a.root_pos.x, a.root_pos.y, a.root_pos.z);*/

		if (!c.w2s(a.bones[games::eft::Bones::HumanHead], w2s_bones[games::eft::Bones::HumanHead], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanRFoot], w2s_bones[games::eft::Bones::HumanRFoot], ViewMatrix)
			)
			continue;

		/*if (!c.w2s(a.bones[games::eft::Bones::HumanHead], w2s_bones[games::eft::Bones::HumanHead], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanNeck], w2s_bones[games::eft::Bones::HumanNeck], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanSpine3], w2s_bones[games::eft::Bones::HumanSpine3], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanSpine2], w2s_bones[games::eft::Bones::HumanSpine2], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanSpine1], w2s_bones[games::eft::Bones::HumanSpine1], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanPelvis], w2s_bones[games::eft::Bones::HumanPelvis], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanLCalf], w2s_bones[games::eft::Bones::HumanLCalf], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanLFoot], w2s_bones[games::eft::Bones::HumanLFoot], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanRCalf], w2s_bones[games::eft::Bones::HumanRCalf], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanRFoot], w2s_bones[games::eft::Bones::HumanRFoot], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanLForearm2], w2s_bones[games::eft::Bones::HumanLForearm2], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanLElbow], w2s_bones[games::eft::Bones::HumanLElbow], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanLUpperarm], w2s_bones[games::eft::Bones::HumanLUpperarm], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanRForearm2], w2s_bones[games::eft::Bones::HumanRForearm2], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanRElbow], w2s_bones[games::eft::Bones::HumanRElbow], ViewMatrix)
			|| !c.w2s(a.bones[games::eft::Bones::HumanRUpperarm], w2s_bones[games::eft::Bones::HumanRUpperarm], ViewMatrix)
		) continue;*/

		//printf("%p	w2shead		%f		%f		%f	\n", a.base, head_w2s.x, head_w2s.y);

		//sdk::render::render->DrawBox(head_w2s.x, head_w2s.y, 35, 35, 0x0000ff00, 0xff00ff00);

		/*sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanHead], w2s_bones[games::eft::Bones::HumanNeck], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanNeck], w2s_bones[games::eft::Bones::HumanSpine3], 0xff00ff00);

		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanSpine3], w2s_bones[games::eft::Bones::HumanSpine2], 0xff00ff00);

		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanSpine2], w2s_bones[games::eft::Bones::HumanSpine1], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanSpine1], w2s_bones[games::eft::Bones::HumanPelvis], 0xff00ff00);

		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanPelvis], w2s_bones[games::eft::Bones::HumanLCalf], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanLCalf], w2s_bones[games::eft::Bones::HumanLFoot], 0xff00ff00);

		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanPelvis], w2s_bones[games::eft::Bones::HumanRCalf], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanRCalf], w2s_bones[games::eft::Bones::HumanRFoot], 0xff00ff00);

		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanSpine3], w2s_bones[games::eft::Bones::HumanLUpperarm], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanLUpperarm], w2s_bones[games::eft::Bones::HumanLForearm2], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanLForearm2], w2s_bones[games::eft::Bones::HumanLElbow], 0xff00ff00);

		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanSpine3], w2s_bones[games::eft::Bones::HumanRUpperarm], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanRUpperarm], w2s_bones[games::eft::Bones::HumanRForearm2], 0xff00ff00);
		sdk::render::render->DrawLine(w2s_bones[games::eft::Bones::HumanRForearm2], w2s_bones[games::eft::Bones::HumanRElbow], 0xff00ff00);*/

		float rapport = w2s_bones[games::eft::Bones::HumanRFoot].y - w2s_bones[games::eft::Bones::HumanHead].y;
		sdk::render::render->DrawBorder(w2s_bones[games::eft::Bones::HumanHead].x - 25 - (rapport / 4), w2s_bones[games::eft::Bones::HumanHead].y, rapport / 2, rapport, 2, 0xff00ff00);

		if (a.is_ai()) sdk::render::render->RenderText(w2s_bones[games::eft::Bones::HumanHead].x, w2s_bones[games::eft::Bones::HumanHead].y - 25, 0xff00ff00, (char*)"AI");
		else sdk::render::render->RenderText(w2s_bones[games::eft::Bones::HumanHead].x, w2s_bones[games::eft::Bones::HumanHead].y - 25, 0xff00ff00, (char*)"PLAYER");

		//if ((GetAsyncKeyState(VK_LBUTTON) & 1))
		//{
		//	printf("bonknatioN!\n");
		//	auto _hitColliders = games::c_phys_util::Instance().phys_read<UINT64>(a.base + 0x490);
		//	if (_hitColliders)
		//	{
		//		auto first_entry = games::c_phys_util::Instance().phys_read<UINT64>(_hitColliders);

		//		games::c_phys_util::Instance().phys_write<games::c_vector3>(first_entry + 0x6C, local_fireport);

		//		/*
		//		1a41dfdef30 : BodyPartCollider
		//		static fields
		//		fields
		//			60 : \uE007 (type: System.Single)
		//			64 : \uE008 (type: System.Single)
		//			68 : \uE009 (type: System.Single)
		//			6c : \uE00A (type: UnityEngine.Vector3)
		//			78 : BodyPartType (type: EBodyPart)
		//			7c : BodyPartColliderType (type: EBodyPartColliderType)
		//			50 : Collider (type: UnityEngine.Collider)
		//			58 : Player (type: EFT.Player)
		//		*/

		//	}
		//	/*for (auto col : _hitColliders)
		//	{
		//		if (!col) continue;
		//		auto part_type = games::c_phys_util::Instance().phys_read<UINT>(col + 0x78);
		//		if (part_type == games::eft::Bones::HumanHead)
		//		{
		//			printf("head collider found :))))))))\n");
		//			
		//		}
		//	}*/
		//}

		rendered++;
	}

	//

	auto t2 = std::chrono::high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

	sdk::render::render->RenderText(5, 25, 0xff00ff00, (char*)"graphic driver    execution time: %i", ms_int.count());
	sdk::render::render->RenderText(5, 55, 0xff00ff00, (char*)"rendered                        : %i", rendered);
	sdk::render::render->RenderText(5, 85, 0xff00ff00, (char*)"entities                        : %i", p.size());
}

bool no_recoil = false;
void write_cheats()
{
	while (0xF00D != 0xDEAD)
	{
		auto world = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x26535F0);
		if (!world) continue;

		auto cameraOn = games::c_phys_util::Instance().phys_read<UINT64>(world + 0x27E8);
		if (!cameraOn) continue;

		auto selfCamera = games::c_phys_util::Instance().phys_read<UINT64>(cameraOn + 0x8);
		if (!selfCamera) continue;

		if (no_recoil)
		{
			games::c_phys_util::Instance().phys_write<float>(selfCamera + 0x1068, 0.f);
			games::c_phys_util::Instance().phys_write<float>(selfCamera + 0x10B8, 0.f);
		}
		else games::c_phys_util::Instance().phys_write<float>(selfCamera + 0x1068, 1.f);
	}
}

int thread(std::promise<void>* shutdown_promise, std::future<void> shutdown)
{

	while (1)
	{
		system("cls");

		printf("\n\
				0	-	exit\n\
				1	-	attatch test\n\
				2	-	IPC 500x read test\n\
				3	-	IPC 500x ping test\n\
				4	-	ping krnl\n\
				5	-	get explorer\n\
				6	-	bdo menu\n\
				7	-	arma3 menu\n\
				8	-	eft menu\n\
				\n");

		printf("selection: ");
		int in;
		std::cin >> in;

		switch (in)
		{
		case 0:
		{
			auto [req_shutdown, ret_shutdown] = ipc::master::alloc_packet<ipc::shared::internal::shutdown>();
			req_shutdown.data.obj.done = false;
			if (&ret_shutdown == ipc::master::cmd<ipc::shared::internal::shutdown>(&req_shutdown))
			{
				std::cout << "req_shutdown: " << req_shutdown.data.obj.done << " == " << ret_shutdown.brother->data.obj.done << std::endl;
				std::cout << "ret_shutdown: " << ret_shutdown.data.obj.done << " == " << req_shutdown.brother->data.obj.done << std::endl;
			}
			shutdown_promise->set_value();
			system("pause");
			break;
		}
		break;
		case 1:
		{
			auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
			strcpy_s(req_getmodule.data.obj.target, "explorer.exe");
			wcscpy_s(req_getmodule.data.obj.mem_target, 0xFF, L"advapi32.dll");
			if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
			{
				printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
				printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);

				address = ret_getmodule.data.obj.address;
				target = ret_getmodule.data.obj.target;
			}
			system("pause");
		}
		break;
		case 2:
		{
			auto test_run = []()
			{
				auto errors = 0;
				for (auto a = 0; a < 50000; a++)
				{
					auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
					req_readmem.data.obj.target = target;
					req_readmem.data.obj.address = address;
					req_readmem.data.obj.size = 2;
					if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
					{
						//printf("\"%c%c %i\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1], a);
						if (req_readmem.data.obj.size != ret_readmem.data.obj.read || ret_readmem.data.obj.buf[0] != 'M' || ret_readmem.data.obj.buf[1] != 'Z')
						{
							printf("\"THRD MISMATCHED DATA RCV: 0->%c , 1->%c , s-> %i, packet: %i\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1], ret_readmem.data.obj.read, a);
							errors++;
						}
					}
				}
				printf("thread done 50k - failed %i\n", errors);
			};

			auto b = std::thread(test_run);
			b.detach();

			auto c = std::thread(test_run);
			c.detach();

			auto errors = 0;
			for (auto a = 0; a < 50000; a++)
			{
				auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
				req_readmem.data.obj.target = target;
				req_readmem.data.obj.address = address;
				req_readmem.data.obj.size = 2;
				if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
				{
					//printf("\"%c%c %i\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1], a);
					if (req_readmem.data.obj.size != ret_readmem.data.obj.read || ret_readmem.data.obj.buf[0] != 'M' || ret_readmem.data.obj.buf[1] != 'Z')
					{
						printf("\" MISMATCHED DATA RCV: 0->%c , 1->%c , s-> %i, packet: %i\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1], ret_readmem.data.obj.read, a);
						errors++;
					}
				}
			}
			printf("nonthread done 50k - failed %i\n", errors);

			system("pause");
		}
		break;
		case 3:
		{
			for (auto a = 0; a < 2000; a++)
			{
				auto [ping, pong] = ipc::master::alloc_packet<ipc::shared::internal::ping>();
				strcpy_s(ping.data.obj.data, "PING");
				if (&pong == ipc::master::cmd<ipc::shared::internal::ping>(&ping))
				{
					continue;
				}
			}
			/*auto [req_writemem, ret_writemem] = ipc::master::alloc_packet<ipc::shared::internal::writemem>();
			req_writemem.data.obj.target = target;
			req_writemem.data.obj.address = address;
			req_writemem.data.obj.size = 2;
			req_writemem.data.obj.buf[0] = 'Z';
			req_writemem.data.obj.buf[1] = 'M';
			if (&ret_writemem == ipc::master::cmd<ipc::shared::internal::writemem>(&req_writemem))
			{
				printf("[rcv writemem] written: %lu\n", ret_writemem.data.obj.written);
			}
			system("pause");*/
		}
		break;
		case 4:
		{
			auto [ping, pong] = ipc::master::alloc_packet<ipc::shared::internal::ping>();
			strcpy_s(ping.data.obj.data, "PING");
			if (&pong == ipc::master::cmd<ipc::shared::internal::ping>(&ping))
			{
				std::cout << "ping.first: " << ping.data.obj.data << " == " << pong.brother->data.obj.data << std::endl;
				std::cout << "ping.second: " << pong.data.obj.data << " == " << ping.brother->data.obj.data << std::endl;
			}
			system("pause");
		}
		break;
		case 5:
		{
			auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
			strcpy_s(req_getmodule.data.obj.target, "explorer.exe");
			wcscpy_s(req_getmodule.data.obj.mem_target, 0xFF, L"mlang.dll");
			if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
			{
				printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
				printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);
			}
			auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
			req_readmem.data.obj.target = ret_getmodule.data.obj.target;
			req_readmem.data.obj.address = ret_getmodule.data.obj.address;
			req_readmem.data.obj.size = 2;
			if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
			{
				printf("[rcv readmem] buffer length is: %lu\n", ret_readmem.data.obj.read);
				printf("              \"%c%c\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1]);
			}
			system("pause");
		}
		break;
		default: break;
		}

		if (in == 6)
		{
			system("cls");

			printf("\n\
				0	-	attatch to bdo\n\
				1	-	get local player\n\
				2	-	set animation to 5\n\
				3	-	set animation to 1\n\
				\n");

			printf("selection: ");

			std::cin >> in;

			switch (in)
			{
			case 0:
			{
				auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
				strcpy_s(req_getmodule.data.obj.target, "BlackDesert64.exe");
				wcscpy_s(reinterpret_cast<wchar_t*>(req_getmodule.data.obj.mem_target), 0xFF, L"BlackDesert64.exe");
				if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
				{
					printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
					printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);

					address = ret_getmodule.data.obj.address;
					target = ret_getmodule.data.obj.target;
				}
				system("pause");
			}
			break;
			case 1:
			{
				auto local_player = c_phys_helper::phys_read<UINT64>(0x145D96AA0, target);
				printf("local player: %llx\n", local_player);
				system("pause");
			}
			break;
			case 2:
			{
				uint64_t local_player = 0x0;

				local_player = c_phys_helper::phys_read<UINT64>(0x145D96AA0, target);

				if (!local_player) continue;

				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x430, target);

				if (!local_player) continue;

				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x10, target);

				if (!local_player) continue;

				c_phys_helper::phys_write<float>(local_player + 0x4C0, target, 5.f);

				system("pause");
			}
			break;
			case 3:
			{
				uint64_t local_player = 0x0;

				local_player = c_phys_helper::phys_read<UINT64>(0x145D96AA0, target);

				if (!local_player) continue;

				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x430, target);

				if (!local_player) continue;

				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x10, target);

				if (!local_player) continue;

				c_phys_helper::phys_write<float>(local_player + 0x4C0, target, 1.f);

				system("pause");
			}
			break;
			default: break;
			}
		}
		if (in == 7)
		{
			system("cls");

			printf("\n\
				0	-	attatch to arma3\n\
				1	-	get local player\n\
				2	-	get position\n\
				3	-	set position + x 50\n\
				4	-	esp\n\
				5	-	no recoil\n\
				\n");

			printf("selection: ");

			std::cin >> in;

			switch (in)
			{
			case 0:
			{
				auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
				strcpy_s(req_getmodule.data.obj.target, "arma3_x64.exe");
				wcscpy_s(req_getmodule.data.obj.mem_target, 0xFF, L"arma3_x64.exe");
				if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
				{
					printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
					printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);

					address = ret_getmodule.data.obj.address;
					max_address = ret_getmodule.data.obj.max_address;
					target = ret_getmodule.data.obj.target;

					games::c_phys_util::Instance().target = target;
					games::c_phys_util::Instance().max_address = max_address;
					games::c_phys_util::Instance().base = address;

				}

				std::thread m([]() {games::arma3::c_a3::Instance().update(); });
				m.detach();

				std::thread m2([]() { write_cheats(); });
				m2.detach();

				system("pause");
			}
			break;
			case 1:
			{
				auto local_player = c_phys_helper::phys_read<UINT64>(address + 0x26535F0, target);
				if (!local_player)
				{
					printf("[rcv local_player] is null\n");
					system("pause");
					continue;
				}
				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x2818, target);
				printf("[rcv local_player] %llx\n", local_player);
				system("pause");
			}
			break;
			case 2:
			{
				auto local_player = c_phys_helper::phys_read<UINT64>(address + 0x26535F0, target);
				if (!local_player)
				{
					printf("[rcv local_player] is null\n");
					system("pause");
					continue;
				}
				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x2818, target);
				if (!local_player)
				{
					printf("[rcv local_player] is null\n");
					system("pause");
					continue;
				}
				auto local_player_obj = c_phys_helper::phys_read<UINT64>(local_player + 0x8, target);
				if (!local_player_obj)
				{
					printf("[rcv local_player_obj] is null\n");
					system("pause");
					continue;
				}
				auto man_visual_state = c_phys_helper::phys_read<UINT64>(local_player_obj + 0xD0, target);
				if (!man_visual_state)
				{
					printf("[rcv man_visual_state] is null\n");
					system("pause");
					continue;
				}
				//man_visual_state + 0x28  = isVisible
				// 
				//local_player_obj + 0xA98 = AIUnitInfo
				//local_player_obj + 0xA98 + 0x10 = Name string & gear below...
				//local_player_obj + 0x14B (uint8) = Entity type
				//local_player_obj + 0xC8 = LODShapeWithShadow (bones etc)
				//local_player_obj + 0x340 = side (enemy/friendly)
				//local_player_obj + 0x366 = has parent object
				//local_player_obj + 0x368 = parent object
				//local_player_obj + 0xB88 = objid

				auto pos_x = c_phys_helper::phys_read<float>(man_visual_state + 0x2C, target);
				auto pos_y = c_phys_helper::phys_read<float>(man_visual_state + 0x30, target);
				auto pos_z = c_phys_helper::phys_read<float>(man_visual_state + 0x34, target);

				printf("[rcv pos] x:%f y:%f z:%f\n", pos_x, pos_y, pos_z);
				system("pause");
			}
			break;
			case 3:
			{
				auto local_player = c_phys_helper::phys_read<UINT64>(address + 0x26535F0, target);
				if (!local_player)
				{
					printf("[rcv local_player] is null\n");
					system("pause");
					continue;
				}
				local_player = c_phys_helper::phys_read<UINT64>(local_player + 0x2818, target);
				if (!local_player)
				{
					printf("[rcv local_player] is null\n");
					system("pause");
					continue;
				}
				auto local_player_obj = c_phys_helper::phys_read<UINT64>(local_player + 0x8, target);
				if (!local_player_obj)
				{
					printf("[rcv local_player_obj] is null\n");
					system("pause");
					continue;
				}
				auto man_visual_state = c_phys_helper::phys_read<UINT64>(local_player_obj + 0xD0, target);
				if (!man_visual_state)
				{
					printf("[rcv man_visual_state] is null\n");
					system("pause");
					continue;
				}
				auto pos_x = c_phys_helper::phys_read<float>(man_visual_state + 0x2C, target);
				c_phys_helper::phys_write<float>(man_visual_state + 0x2C, target, pos_x + 50.f);
			}
			break;
			case 4:
			{
				esp_toggle = !esp_toggle;
				printf("[esp toggled] %i\n", esp_toggle);
			}
			break;
			case 5:
			{
				no_recoil = !no_recoil;
				printf("[no recoil toggled] %i\n", no_recoil);
			}
			break;
			default: break;
			}
		}
		if (in == 8)
		{
			system("cls");

			printf("\n\
				0	-	attatch to eft\n\
				1	-	dump objects\n\
				2	-	get gameworld\n\
				3	-	esp\n\
				\n");

			printf("selection: ");

			std::cin >> in;

			switch (in)
			{
			case 0:
			{
				auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
				strcpy_s(req_getmodule.data.obj.target, "EscapeFromTarkov.exe");
				wcscpy_s(req_getmodule.data.obj.mem_target, 0xFF, L"UnityPlayer.dll");
				if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
				{
					printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
					printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);

					address = ret_getmodule.data.obj.address;
					target = ret_getmodule.data.obj.target;

					games::c_phys_util::Instance().target = target;
					games::c_phys_util::Instance().max_address = max_address;
					games::c_phys_util::Instance().base = address;

					/*games::eft::c_updater::Instance().setup();*/
				}
				system("pause");
			}
			break;
			case 1:
			{
				games::eft::c_game_objects::Instance().dump_objects();
				system("pause");
			}
			break;
			case 2:
			{
				games::eft::c_updater::Instance().update_fps_object();
				printf("fpscamera: %p\n", games::eft::c_updater::Instance().fps_object);
				games::eft::c_updater::Instance().update_world_object();
				printf("world: %p\n", games::eft::c_updater::Instance().world_object);

				system("pause");
			}
			break;
			case 3:
			{
				static bool first_timer = 0;

				if (!first_timer)
				{
					games::eft::c_updater::Instance().setup();
					first_timer = 1;
				}

				esp_eft_toggle = !esp_eft_toggle;
				printf("[esp toggled] %i\n", esp_eft_toggle);
				system("pause");
			}
			break;
			default: break;
			}
		}
	}
	//example ping
	//auto [ping, pong] = ipc::master::alloc_packet<ipc::shared::internal::ping>();
	//strcpy_s(ping.data.obj.data, "PING");
	//if (&pong == ipc::master::cmd<ipc::shared::internal::ping>(&ping))
	//{
	//	std::cout << "ping.first: " << ping.data.obj.data << " == " << pong.brother->data.obj.data << std::endl;
	//	std::cout << "ping.second: " << pong.data.obj.data << " == " << ping.brother->data.obj.data << std::endl;
	//}
	////get module of explorer.exe
	//auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
	//strcpy_s(req_getmodule.data.obj.target, "explorer.exe");
	//wcscpy_s(reinterpret_cast<wchar_t*>(req_getmodule.data.obj.mem_target), 0xF, L"mlang.dll");
	//if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
	//{
	//	printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
	//	printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);
	//}
	////
	//{
	//	auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
	//	req_readmem.data.obj.target = ret_getmodule.data.obj.target;
	//	req_readmem.data.obj.address = ret_getmodule.data.obj.address;
	//	req_readmem.data.obj.size = 2;
	//	if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
	//	{
	//		printf("[rcv readmem] buffer length is: %lu\n", ret_readmem.data.obj.read);
	//		printf("              \"%c%c\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1]);
	//	}
	//}
	////
	//{
	//	auto [req_writemem, ret_writemem] = ipc::master::alloc_packet<ipc::shared::internal::writemem>();
	//	req_writemem.data.obj.target = ret_getmodule.data.obj.target;
	//	req_writemem.data.obj.address = ret_getmodule.data.obj.address;
	//	req_writemem.data.obj.size = 2;
	//	req_writemem.data.obj.buf[0] = 'Z';
	//	req_writemem.data.obj.buf[1] = 'M';
	//	if (&ret_writemem == ipc::master::cmd<ipc::shared::internal::writemem>(&req_writemem))
	//	{
	//		printf("[rcv writemem] written: %lu\n", ret_writemem.data.obj.written);
	//	}
	//}
	////
	//{
	//	auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
	//	req_readmem.data.obj.target = ret_getmodule.data.obj.target;
	//	req_readmem.data.obj.address = ret_getmodule.data.obj.address;
	//	req_readmem.data.obj.size = 2;
	//	if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
	//	{
	//		printf("[rcv readmem] buffer length is: %lu\n", ret_readmem.data.obj.read);
	//		printf("              \"%c%c\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1]);
	//	}
	//}
	////
	//auto [req_shutdown, ret_shutdown] = ipc::master::alloc_packet<ipc::shared::internal::shutdown>();
	//req_shutdown.data.obj.done = false;
	//if (&ret_shutdown == ipc::master::cmd<ipc::shared::internal::shutdown>(&req_shutdown))
	//{
	//	std::cout << "req_shutdown: " << req_shutdown.data.obj.done << " == " << ret_shutdown.brother->data.obj.done << std::endl;
	//	std::cout << "ret_shutdown: " << ret_shutdown.data.obj.done << " == " << req_shutdown.brother->data.obj.done << std::endl;
	//}
	//shutdown_promise->set_value();

	return 0;
}

int main()
{
	unsigned uZoom = 120;

	/*while (true)
	{
		printf("------------------------------------------------------" "\n");
		{
			auto pParam = queueCmd(eCmdID::ECHO, (unsigned char*)"test", 5);
			auto oParam = getFuture(pParam).get();
			std::cout << " > " << "RPLpBuf: " << (char*)oParam.ui64RPLpBuf << std::endl;
			std::cout << " > " << "RPLsize:  " << oParam.ui64RPLsize << std::endl;
			freeCmd(pParam);
		}
		printf("------------------------------------------------------" "\n");
		{
			auto pParam = queueCmd(eCmdID::PING, (unsigned char*)"ping", 5);
			auto oParam = getFuture(pParam).get();
			std::cout << " > " << "RPLpBuf: " << (char*)oParam.ui64RPLpBuf << std::endl;
			std::cout << " > " << "RPLsize:  " << oParam.ui64RPLsize << std::endl;
			freeCmd(pParam);
		}
		system("pause");
	}*/

	unsigned uWidth = 16 * uZoom;
	unsigned uHeight = 9 * uZoom;

	printf(" > Init...\n");

	//HWND hWnd = GetConsoleWindow();

	// Setup Dear ImGui context
	//IMGUI_CHECKVERSION();
	//ImGui::CreateContext();
	//ImGuiIO&io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	//io.ConfigViewportsNoAutoMerge = true;
	//io.ConfigViewportsNoTaskBarIcon = true;
	//io.ConfigViewportsNoDefaultParent = true;
	//io.ConfigDockingAlwaysTabBar = true;
	//io.ConfigDockingTransparentPayload = true;
	//io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleFonts;     // FIXME-DPI: Experimental. THIS CURRENTLY DOESN'T WORK AS EXPECTED. DON'T USE IN USER APP!
	//io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleViewports; // FIXME-DPI: Experimental.
	//io.DisplaySize.x = uWidth;
	//io.DisplaySize.y = uHeight;

	//ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	//ImGui_ImplDX11_Init(GLOBALS::pDX11_BackgroundRenderer->GpDevice(), GLOBALS::pDX11_BackgroundRenderer->GpDeviceContext());
	//	
	auto shutdown = std::promise<void>();

	printf("\n > Render Loop...\n");

	// enter the main loop:

	auto future = std::async(std::launch::async, thread, &shutdown, shutdown.get_future());

	HWND hWnd = CreateRenderWindow(uWidth, uHeight);

	GLOBALS::pDD_Overlay = new DD_Overlay(uWidth, uHeight);
	GLOBALS::pDX11_BackgroundRenderer = new DX11_BackgroundRenderer(uWidth, uHeight, hWnd);
	GLOBALS::pID2D1_Renderer = new ID2D1_Renderer(uWidth, uHeight, GLOBALS::pDX11_BackgroundRenderer->GpDXGISurface());
	render_utils::render = new render_utils::c_render();
	input::input = new input::c_input();
	ui::ui = new ui::c_ui();

	sdk::render::render = new sdk::render::c_render();

	auto t1 = std::chrono::high_resolution_clock::now();

	MSG msg;
	while (TRUE)
	{
		auto t2 = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		// check for pending window close
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			printf("msg: 0x%x\n", msg.message);

			if (msg.hwnd == GetConsoleWindow() && msg.message == WM_QUIT)
			{
				printf("\n > wmquit\n");
				break;
			}
		}
		{
			auto hResult = GLOBALS::pID2D1_Renderer->Draw([](ID2D1_Renderer* pInst, ID2D1RenderTarget* pRenderTarget) -> HRESULT
				{

					pRenderTarget->BeginDraw();
					pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

					pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black, 0.F)); //Transparent
					//auto fps = duration ? 1000000ull / duration : 9999999ull;

					//if (render_utils::render->was_setup == false) render_utils::render->setup(pInst->m_pDirect2dFactory, pRenderTarget, pInst->dwrite_factory);
					//else
					//{
					//	//render_utils::render->text("global-draw-overlay~", 0.6f, 0.6f, RGBA({ 0, 255, 0, 255 }), "Consolas0.8");
					//	//render_utils::render->text(std::string("overlay fps:").append(std::to_string((int)fps)), 0.6f, 2.4f, RGBA({ 255, 0, 0, 255 }), "Consolas0.8");

					//	//render_utils::render->text(std::string("middle"), 96.f/2.f, 96.f/2.f, RGBA({ 255, 0, 0, 255 }), "Consolas0.8");
					//	//
					//	//render_utils::render->line(0.6f, 4.f, 8.f, 4.f, 0.15f, RGBA({0, 255, 0, 255}));
					//	////
					//	//render_utils::render->orect(0.6f, 5.f, 5.f, 5.f, 0.15f, RGBA({ 255,0,0,255 }));
					//	////
					//	//pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black, 1.F));
					//	////
					//	//render_utils::render->orrect(0.6f, 11.f, 5.f, 5.f, 5.f, 0.15f, RGBA({ 255,0,0,255 }));
					//	////
					//	//render_utils::render->frect(0, 0, 1920, 1080, RGBA({0,255,0,255}));
					//	//render_utils::render->frect(0, 0, 1920, 1080, RGBA({0,255,0,255}));						
					//}
					return pRenderTarget->EndDraw();

				}
			);
			if (hResult != DD_OK)
			{
				printf(" !      pID2D1_Renderer->Draw\n");
				printf("    [-] hResult = %#x \n", hResult);
				return hResult;
			}
		}
		static bool cum = false;
		static clock_t deltaTime = 0;
		static unsigned int frames = 0;
		static double  frameRate = 60;
		static double  averageFrameTimeMilliseconds = 33.333;
		// Render DirectX11 (Direct3D)
		{
			auto hResult = GLOBALS::pDX11_BackgroundRenderer->Draw([](ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView) -> HRESULT
				{
					if (!cum) sdk::render::render->InitializeRenderClass(pDevice, pContext, 16, (char*)"Consolas", 0);
					else
					{
						if (esp_toggle)
						{
							try {
								esp();
							}
							catch (...) {}
						}
						if (esp_eft_toggle)
						{
							try {
								esp_eft();
							}
							catch (...) {}
						}

						auto fps = duration ? 1000000ull / duration : 9999999ull;
						sdk::render::render->RenderText(5, 5, 0xff00ff00, (char*)"graphics driver fps: %i", fps);
					}

					cum = true;
					pContext->OMSetRenderTargets(1, &pRenderTargetView, NULL);

					return S_OK;
				}
			);
			if (hResult != S_OK)
			{
				printf(" !      pDX11_BackgroundRenderer->Draw\n");
				printf("    [-] hResult = %#x \n", hResult);
				//return hResult;
			}
		}
		// Render DirectDraw
		{
			auto hResult = GLOBALS::pDD_Overlay->Draw([](IDirectDraw7* pDevice, LPDIRECTDRAWSURFACE7 pSurface) -> HRESULT
				{
					// Render 2D Texture of 3D Space
					D3D11_TEXTURE2D_DESC desc;
					ID3D11Texture2D* pTexture = nullptr;
					{
						auto hResult = GLOBALS::pDX11_BackgroundRenderer->CaptureTexture(desc, pTexture);
						if (hResult != S_OK)
						{
							printf(" !      pDX11_BackgroundRenderer->CaptureTexture\n");
							printf("    [-] hResult = %#x \n", hResult);
							return hResult;
						}
					}
					// Query Surface
					IDXGISurface* pTextureSurface = nullptr;
					{
						auto hResult = pTexture->QueryInterface<IDXGISurface>(&pTextureSurface);
						if (hResult != S_OK)
						{
							printf(" !      pTexture->QueryInterface<IDXGISurface>(&pTextureSurface)\n");
							printf("    [-] hResult = %#x\r\n", hResult);
							return hResult;
						}
					}
					// BitBlit
					{
						auto hResult = Blt_DXGISurface_To_DIRECTDRAWSURFACE7(pDevice, pTextureSurface, pSurface);
						if (hResult != S_OK)
						{
							printf(" !      Blt_DXGISurface_To_DIRECTDRAWSURFACE7\n");
							printf("    [-] hResult = %#x\r\n", hResult);
							return hResult;
						}
					}
					// Release Surface
					{
						pTextureSurface->Release();
					}
					// Release Texture
					{
						pTexture->Release();
					}
					return S_OK;
				}
			);
			if (hResult != S_OK)
			{
				printf(" !      pDD_Overlay->Draw\n");
				printf("    [-] hResult = %#x \n", hResult);
				//return hResult;
			}
		}
		// Present DirectX11 (Direct3D) [+Direct2D rendered on top of it]
		{
			//auto hResult = GLOBALS::pDX11_BackgroundRenderer->Present();
			//if (hResult != DD_OK)
			//{
			//	printf(" !      pDX11_BackgroundRenderer->Present\n");
			//	printf("    [-] hResult = %#x \n", hResult);
			//	//return hResult;
			//}
		}
		// Flip DirectDraw
		{
			auto hResult = GLOBALS::pDD_Overlay->Flip();
			if (hResult != DD_OK)
			{
				printf(" !      pDD_Overlay->Flip\n");
				printf("    [-] hResult = %#x \n", hResult);
				printf("\n");
			}
			if (hResult == DDERR_SURFACELOST)
			{
				hResult = GLOBALS::pDD_Overlay->Restore();
				if (hResult != DD_OK)
				{
					printf(" !      pOverlay->Restore\n");
					printf("    [-] hResult = %#x \n", hResult);
					printf("\n");
				}
				if (hResult == DDERR_WRONGMODE)
				{
					printf(" !      DDERR_WRONGMODE\n");
					break;
				}

			}
		}
		// Update DirectDraw Overlay
		{
			auto hResult = GLOBALS::pDD_Overlay->UpdateOverlay();
			if (hResult != DD_OK)
			{
				printf(" !      pDD_Overlay->UpdateOverlay\n");
				printf("    [-] hResult = %#x \n", hResult);
				printf("\n");
			}
			if (hResult == DDERR_SURFACELOST)
			{
				hResult = GLOBALS::pDD_Overlay->Restore();
				if (hResult != DD_OK)
				{
					printf(" !      pOverlay->Restore\n");
					printf("    [-] hResult = %#x \n", hResult);
					printf("\n");
				}
				if (hResult == DDERR_WRONGMODE)
				{
					printf(" !      DDERR_WRONGMODE\n");
					break;
				}
			}
		}
		t1 = t2;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	delete GLOBALS::pID2D1_Renderer;
	delete GLOBALS::pDX11_BackgroundRenderer;
	delete GLOBALS::pDD_Overlay;

	future.get();

	printf("\n");
	printf(" > Quitting...\n");

	shutdown.set_value();

	system("pause");

	return 0;
}