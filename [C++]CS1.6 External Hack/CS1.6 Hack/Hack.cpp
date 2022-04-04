#include "include.h"

void main()
{
    FindProcess();

    DWORD IsOnGround;
    DWORD zCordAddr;

    while (true)
    {
        //Find out on ground player or not
        IsOnGround = memory.readMemory<DWORD>(pv.engineModule + Offsets::Fl_Onground);

        //Find out local player current Z coordinate
        zCordAddr = memory.readMemory<DWORD>(pv.engineModule + Offsets::Zcord) + 0x90;
        //std::cout << zCordAddr << std::endl;

        if(GetAsyncKeyState(KEYS::DDrunKey) && IsOnGround == 1)
        {
            DDRun();
        }
        if (GetAsyncKeyState(KEYS::BhopKey) && IsOnGround == 1)
        {
            BunnyHop();
        }
        if (GetAsyncKeyState(KEYS::HangKey))
        {
            Glide(zCordAddr);
        }
        Sleep(1);
    }
}