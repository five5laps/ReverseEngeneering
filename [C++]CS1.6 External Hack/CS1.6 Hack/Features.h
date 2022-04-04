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
        std::cout << "Process found!" << std::endl << "hl.exe -> " << pv.process << std::endl;
    }
}

///BHOP
void BunnyHop()
{
    if (MISC::bunnyhop)
    {
        memory.writeMem<int>(pv.clientModule + Offsets::dwForceJump, 5);
        Sleep(1);
        memory.writeMem<int>(pv.clientModule + Offsets::dwForceJump, 4);
    }
}
//DDrun
void DDRun()
{
    if (MISC::DDrun)
    {
        memory.writeMem<int>(pv.clientModule + Offsets::dwForceDuck, 5);
        Sleep(1);
        memory.writeMem<int>(pv.clientModule + Offsets::dwForceDuck, 4);
    }
}
//Close program
void QuitCheat()
{
    return;
}