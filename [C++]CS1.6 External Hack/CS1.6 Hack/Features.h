#pragma once
#include "Windows.h"

//ќбъ€вление библиотеки дл€ работы с пам€тью
MemMan memory;

void FindProcess()
{
    pv.process = memory.getProcess("hl.exe");
    pv.clientModule = memory.getModule(pv.process, "client.dll");
    pv.engineModule = memory.getModule(pv.process, "hw.dll");
    if (pv.clientModule != NULL && pv.engineModule != NULL)
    {
        std::cout << "Process found!" << std::endl << "hl.exe -> " << "0x" << std::hex << pv.process << std::endl;
    }
}

//BHOP
void BunnyHop()
{
    if (MISC::bunnyhop)
    {
        memory.writeMemory<int>(pv.clientModule + Offsets::dwForceJump, 5);
        Sleep(1);
        memory.writeMemory<int>(pv.clientModule + Offsets::dwForceJump, 4);
    }
}
//DDrun
void DDRun()
{
    if (MISC::DDrun)
    {
        memory.writeMemory<int>(pv.clientModule + Offsets::dwForceDuck, 5);
        Sleep(1);
        memory.writeMemory<int>(pv.clientModule + Offsets::dwForceDuck, 4);
    }
}

//Hang
void Glide(DWORD zCordAddr)
{
    if (MISC::Hang)
    {
        memory.writeMemory<DWORD>(zCordAddr, zCordAddr);
    }
}