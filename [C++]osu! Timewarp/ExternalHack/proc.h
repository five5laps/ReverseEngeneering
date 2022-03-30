#pragma once

#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
//Found our proc
DWORD GetProcId(const wchar_t* procName);
//Found modulebase in proc
uintptr_t GetModuleBaseAddress(DWORD procID, const wchar_t* modName);

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);


