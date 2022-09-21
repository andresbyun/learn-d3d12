#pragma once
#include "common.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int InitializeWindowClass(HINSTANCE hInst, int nCmdShow, LPCWSTR name);
