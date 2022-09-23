#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include <directx/d3d12.h>
#include <directx/d3dx12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include <string>
#include <wrl.h>
#include <shellapi.h>

using Microsoft::WRL::ComPtr;

// Generic class to create a window
class GenericWindow {
public:
	GenericWindow(LPCWSTR classname, LPCWSTR p_title, UINT width, UINT height);

	virtual int initialize() = 0;
	virtual LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;

private:
	LPCWSTR p_name;
	LPCWSTR p_title;
	UINT p_width;
	UINT p_height;
};
