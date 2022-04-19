
#include "include.h"

void main() 
{
	startPrint();

	FindProcess();

	while (true) 
	{
		if (GetAsyncKeyState(KEYS::BhopKey)  && checkGroundState() == 1) 
		{
			BunnyHop();
		}
		if (GetAsyncKeyState(KEYS::DuckTapKey) && checkGroundState() == 1)
		{
			DuckTap();
		}
		Sleep(1);
	}
}

