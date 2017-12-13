// MyDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
HHOOK hook;
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
INT InitHook()
{
	hook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, 0, 0);
	if (hook != NULL)
		return 1;
	return 0;
}
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (wParam == WM_LBUTTONDOWN)
	{
		return TRUE;
	}
	return CallNextHookEx(hook, nCode, wParam, lParam);
}
INT UninstallHook()
{
	if (hook != NULL)
	{
		UnhookWindowsHookEx(hook);
		return 1;
	}
	return 0;
}

