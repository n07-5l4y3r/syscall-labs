#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_WINNT 0x600
#include <iostream>
#include <map>
#include <chrono>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <atomic>
#include <ostream>
#include <fstream>
#include <mutex>
#include <xmmintrin.h>
#include <chrono>

#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h>
#include <dinputd.h>

#include <d3d11.h>
#include <D3DX11.h>
#include <DxErr.h>

#include <d3dx9math.h>

#include <d3dcompiler.h>
#include <D3D11Shader.h>
#include "rendering/fx/d3dx11effect.h"

template <typename T>
class s
{
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
protected:
	s() {}
	~s() {}
public:
	s(s const&) = delete;
	s& operator=(s const&) = delete;
};

#pragma comment(lib, "d3d11.lib")
#pragma comment( lib, "DXErr" )
#pragma comment (lib, "D3D11.lib")
#pragma comment (lib, "D3DX11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "Effects11.lib")


#include "rendering/font_wrapper/FW1FontWrapper.h"
#include "rendering/shader.h"
#include <dcommon.h> 
#include "games/vec3.h"

#include "rendering/rn.h"

//ipc
#include "ipc/ipc_master.h"

//imgui
//#include "imgui/imgui_impl_win32.h"
//#include "imgui/imgui_impl_dx11.h"
//#include "imgui/imgui.h"

#pragma comment(lib, "ddraw.lib")
#pragma comment(lib, "dxguid.lib")
#include <ddraw.h>

#include <d2d1.h>
#pragma comment(lib, "d2d1.lib")

#include <dwrite.h>
#pragma comment(lib, "dwrite.lib")

//#pragma comment(lib, "gdiplus.lib")
//#include <gdiplus.h>
//using namespace Gdiplus;

//ddraw
#include "DD_Overlay/DD_Overlay.hpp"

//d3d
#include "DX11_BackgroundRenderer/DX11_BackgroundRenderer.hpp"

#include "ID2D1_Renderer/render.h"
#include "input/input.h"
#include "ID2D1_Renderer/ui.h"

//d2d
#include "ID2D1_Renderer/ID2D1_Renderer.hpp"

#include "games/pys_util.h"

#include "games/eft/unity_transform.h"
#include "games/eft/camera.h"
#include "games/eft/player.h"
#include "games/eft/game_world.h"
#include "games/eft/updaters.h"
#include "games/eft/object_utils.h"

#include "games/arma3/util_entity.h"

#include "games/thread_util.h"