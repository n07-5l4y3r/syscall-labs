#include <inc.hpp>

bool games::eft::c_camera::update_matrix()
{
	if (!base) return {};
	
	uint64_t FPSCamera = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x30);
	if (!FPSCamera) return false;

	uint64_t CameraObject = games::c_phys_util::Instance().phys_read<uint64_t>(FPSCamera + 0x18);
	if (!CameraObject) return false;

	struct s_mat { float m[4][4]; };

	auto v = games::c_phys_util::Instance().phys_read<s_mat>(CameraObject + 0xD8);

	ViewMatrix[0][0] = v.m[0][0];
	ViewMatrix[1][0] = v.m[0][1];
	ViewMatrix[2][0] = v.m[0][2];
	ViewMatrix[3][0] = v.m[0][3];
	ViewMatrix[0][1] = v.m[1][0];
	ViewMatrix[1][1] = v.m[1][1];
	ViewMatrix[2][1] = v.m[1][2];
	ViewMatrix[3][1] = v.m[1][3];
	ViewMatrix[0][2] = v.m[2][0];
	ViewMatrix[1][2] = v.m[2][1];
	ViewMatrix[2][2] = v.m[2][2];
	ViewMatrix[3][2] = v.m[2][3];
	ViewMatrix[0][3] = v.m[3][0];
	ViewMatrix[1][3] = v.m[3][1];
	ViewMatrix[2][3] = v.m[3][2];
	ViewMatrix[3][3] = v.m[3][3];

	//printf("	%f		%f		%f		%f\n", v.m[0][0], v.m[0][1], v.m[0][2], v.m[0][3]);
	//printf("	%f		%f		%f		%f\n", v.m[3][0], v.m[3][1], v.m[3][2], v.m[3][3]);

	return true;
}

games::c_vector3 games::eft::c_camera::get_pos()
{
	uint64_t Buffer = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x30);
	if (!Buffer)
		return games::c_vector3(0, 0, 0);
	Buffer = games::c_phys_util::Instance().phys_read<uint64_t>(Buffer + 0x8);
	if (!Buffer)
		return games::c_vector3(0, 0, 0);
	Buffer = games::c_phys_util::Instance().phys_read<uint64_t>(Buffer + 0x38);
	if (!Buffer)
		return games::c_vector3(0, 0, 0);
	return games::c_phys_util::Instance().phys_read<games::c_vector3>(Buffer + 0x90);
}

bool games::eft::c_camera::w2s(games::c_vector3 wpos, games::c_vector3& spos, games::eft::s_mat v)
{
	//D3DXVECTOR3 _point3D = D3DXVECTOR3(wpos.x, wpos.z, wpos.y);

	//struct s_mat { float m[4][4]; };

	//uint64_t FPSCamera = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x30);
	//if (!FPSCamera) return false;

	//uint64_t CameraObject = games::c_phys_util::Instance().phys_read<uint64_t>(FPSCamera + 0x18);
	//if (!CameraObject) return false;

	//auto matrix = games::c_phys_util::Instance().phys_read<D3DMATRIX>(CameraObject + 0xD8);

	////auto& matrix = ViewMatrix;

	//D3DXVECTOR3 translationVector = D3DXVECTOR3(matrix._41, matrix._42, matrix._43);
	//D3DXVECTOR3 up = D3DXVECTOR3(matrix._21, matrix._22, matrix._23);
	//D3DXVECTOR3 right = D3DXVECTOR3(matrix._11, matrix._12, matrix._13);

	//float w = D3DXVec3Dot(&translationVector, &_point3D) + matrix._44;

	//if (w < 0.098f)
	//	return false;

	//float y = D3DXVec3Dot(&up, &_point3D) + matrix._24;
	//float x = D3DXVec3Dot(&right, &_point3D) + matrix._14;

	//spos.x = (1920 / 2) * (1.f + x / w);
	//spos.y = (1080 / 2) * (1.f - y / w);

	//return true;

	if (wpos.x == 99.0 && wpos.y == 99.0 && wpos.z == 99.0)
	{
		//printf("W2S Error\n");
		return false;
	}

	if (wpos.x == 0.0 && wpos.y == 0.0 || (wpos.z == 0.0 && wpos.y == 0.0))
	{
		//printf("Invalid W2S Error\n");
		return false;
	}

	games::c_vector3 up = games::c_vector3(v.m[1][0], v.m[1][1], v.m[1][2]);

	games::c_vector3 right = games::c_vector3(v.m[0][0], v.m[0][1], v.m[0][2]);
	games::c_vector3 translationVector = games::c_vector3(v.m[3][0], v.m[3][1], v.m[3][2]);

	float w = translationVector.Dot(wpos) + v.m[3][3];

	if (w < 0.001f) // 0.099f 0.001f   return false if entity behind local player camera   This also stops the esp from rendering on your xhair
		return false;

	float y = up.Dot(wpos) + v.m[1][3];
	float x = right.Dot(wpos) + v.m[0][3];

	spos.x = (ScreenSize.x / 2.f) * (1.f + x / w);
	spos.y = (ScreenSize.y / 2.f) * (1.f - y / w);

	if (spos.x == 0.0f || spos.y == 0.0f)
		return false;

	if ((spos.x > 0 && spos.x < ScreenSize.x) && (spos.y > 0 && spos.y < ScreenSize.y))
		return true;

	return true;
}
