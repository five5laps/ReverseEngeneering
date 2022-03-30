#pragma once
#include "Windows.h"

#define PRESS(x) press_key(x)
#define RELEASE(x) release_key(x)

bool forever = true;

void sighandler(int sig) { forever = false; }

BYTE scan_code(DWORD pKey)
{
	const DWORD result = MapVirtualKey(pKey, MAPVK_VK_TO_VSC);

	return static_cast<BYTE>(result);
}

void press_key(DWORD pKey)
{
	keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), 0, 0);
}

void release_key(DWORD pKey)
{
	keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), KEYEVENTF_KEYUP, 0);
}