#pragma once
#include "common.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void InitializeWindowClass(HINSTANCE hInst, LPCSTR name);
