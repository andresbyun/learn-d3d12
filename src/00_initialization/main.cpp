// Function definitions
#include "main.h"
#include "HelloWindow.h"

#include <stdio.h>

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR nCmdLine, int nCmdShow) {
	return InitializeWindowClass(hInstance, nCmdShow, L"Hello Window");
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		// All painting occurs here, between BeginPaint and EndPaint.

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW));

		EndPaint(hwnd, &ps);
		}
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int InitializeWindowClass(HINSTANCE hInst, int nCmdShow, LPCWSTR name) {
	WNDCLASSEX wndClass = { 0 };

	wndClass.cbSize = sizeof(WNDCLASSEX);	// Size of the structure
	wndClass.style = CS_HREDRAW | CS_VREDRAW;	// Style of the class (CS_HREDRAW redraws if width changes and CS_VREDRAW redraws if height changes)
	wndClass.lpfnWndProc = &WndProc;	// Pointer to the window procedure handler
	wndClass.cbClsExtra = 0;	// Extra bytes to allocate to the window-class
	wndClass.cbWndExtra = 0;	// Extra bytes to allocate for the window instance
	wndClass.hInstance = hInst; // Handle instance
	wndClass.hCursor = ::LoadCursor(NULL, IDC_ARROW); // Cursor class
	wndClass.lpszClassName = L"Hello Window Class"; // Null-terminated string to identify this window class

	RegisterClassEx(&wndClass);

	HelloWindow hello(600, 600, L"Hello Window");

	RECT windowRect = { 0, 0, static_cast<LONG>(hello.w_width), static_cast<LONG>(hello.w_height) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// Create the window
	HWND m_hwnd = CreateWindow(
		wndClass.lpszClassName,	// Class name
		hello.w_title,	// Window name
		WS_OVERLAPPEDWINDOW,	// Style of window being created
		
		// Initial position of the window (x, y)
		CW_USEDEFAULT,	CW_USEDEFAULT,
		hello.w_width, // Width of the window
		hello.w_height,	// Height of the window
		nullptr,	// Handle to parent window
		nullptr,	// Handle to menu
		hInst,	// Handle to the instance
		nullptr	// Pointer to the value to be passed through CREATESTRUCT
	);

#ifdef DEBUG
	MessageBox(NULL, L"This is a debug window", L"I AM ERROR", NULL);
#endif // DEBUG

	ShowWindow(m_hwnd, nCmdShow);

	// Run the message loop.
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

