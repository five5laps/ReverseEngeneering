#pragma once

#include "include.h"

MemMan memory;

void FindProcess() 
{
	pv.process      = memory.getProcess("svencoop.exe");
	pv.clientModule = memory.getModule(pv.process, "client.dll");
	pv.engineModule = memory.getModule(pv.process, "hw.dll");
	if(pv.clientModule != NULL && pv.engineModule != NULL)
	{
		std::wcout << L"Process found!" << std::endl;
		std::wcout << L"svencoop.exe ";
		std::wcout << L"adress is ->";
		std::wcout << L"0x" << std::hex << pv.process << std::endl;
	}
}

void BunnyHop() 
{
	if(MISC::BunnyHop)
	{
		memory.writeMemory<int>(pv.clientModule + offsets::dwForceJump, 5);
		Sleep(1);
		memory.writeMemory<int>(pv.clientModule + offsets::dwForceJump, 4);
	}
}

void DuckTap() 
{
	if(MISC::DuckTap)
	{
		memory.writeMemory<int>(pv.clientModule + offsets::dwForceDuck, 5);
		Sleep(1);
		memory.writeMemory<int>(pv.clientModule + offsets::dwForceDuck, 4);
	}
}

int checkGroundState() 
{
	return memory.readMemory<DWORD>(pv.engineModule + offsets::Fl_OnGround);
}