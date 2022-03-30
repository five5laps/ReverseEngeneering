#include "pch.h"
#include "include.h"


bool bhop = false;
//Функция бхопа

BOOL WINAPI bhopThread(HMODULE hModule) {
    
DWORD gameModule = (DWORD)GetModuleHandle("client.dll");
while (true) {
    if (GetAsyncKeyState(VK_NUMPAD3) & 1) {
        bhop = !bhop;
    }
    if(bhop){
    DWORD localPlayer = *(DWORD*)(gameModule + dwLocalPlayer);
    if (localPlayer == NULL) continue;

    BYTE flag = *(BYTE*)(localPlayer + m_fFlags);
    //Если нажат space и мы на земле (1 << 0) мы прыгаем
    //С помощью флага проверяем на земле ли мы.
    //На земле 1, нет 0.
    if (GetAsyncKeyState(VK_SPACE) && flag && (1 << 0)) {
        *(DWORD*)(gameModule + dwForceJump) = 6;
    }
    }
    Sleep(1);
}

//Выход из потока
FreeLibraryAndExitThread(hModule, 0);
return 0;
}
