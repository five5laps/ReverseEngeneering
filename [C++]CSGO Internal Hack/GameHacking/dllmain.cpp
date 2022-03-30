// dllmain.cpp : Определяет точку входа для приложения DLL.
//nullptr = указатель на 0
//uintptr_t тот же инт он же DWORD
#include "pch.h"
#include "include.h"

BOOL APIENTRY DllMain( 
                       HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            //Возможность закрыть поток, чтобы заного инжектить
            DisableThreadLibraryCalls(hModule);
            //Закрываем поток триггера
            CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)triggerThread, 0, 0, 0));
            //Закрываем поток ESP
            CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)glowThread, 0, 0, 0));
            //Закрываем поток BHOP
            CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)bhopThread, 0, 0, 0));

        case DLL_PROCESS_DETACH: 
        {
            break;
        }
    }
    return TRUE;
}
