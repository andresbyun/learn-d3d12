// Function definitions
#include "main.h"
#include "HelloWindow.h"

#include <stdio.h>

int main() {
	printf("IT BUILDS!!!");

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

}

void InitializeWindowClass(HINSTANCE hInst, LPCSTR name) {
	// Initialize the window class
	WNDCLASSEX wndClass = { 0 };

	wndClass.cbSize = sizeof(WNDCLASSEX);	// Size of the structure
	wndClass.style = CS_HREDRAW | CS_VREDRAW;	// Style of the class (CS_HREDRAW redraws if width changes and CS_VREDRAW redraws if height changes)
	wndClass.lpfnWndProc = &WndProc;	// Pointer to the window procedure handler
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInst;
	wndClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wndClass.lpszClassName = name;

	RegisterClassEx(&wndClass);
}

