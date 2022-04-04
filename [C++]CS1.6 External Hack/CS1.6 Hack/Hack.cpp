#include "include.h"

DWORD IsOnGround;

void main()
{
    FindProcess();
    while (true)
    {
        IsOnGround = memory.readMem<DWORD>(pv.engineModule + Offsets::OnGround);
        if(GetAsyncKeyState(KEYS::DDrunKey) && IsOnGround == 1)
        {
            DDRun();
        }
        if (GetAsyncKeyState(KEYS::BhopKey) && IsOnGround == 1)
        {
            BunnyHop();
        }
        Sleep(1);
    }
}