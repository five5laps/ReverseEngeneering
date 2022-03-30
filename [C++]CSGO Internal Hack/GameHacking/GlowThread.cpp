#include "include.h"
#include "GlowThread.h"

//Функция триггера

BOOL WINAPI glowThread(HMODULE hModule) {
    //Получаем в gameModule наш главный client.dll 
    uintptr_t gameModule = (uintptr_t)GetModuleHandle("client.dll");
    //Выключаем прогу если нажата END
    while (!GetAsyncKeyState(VK_END)) {
        //Получаем локального игрока из оффсета dwLocalPlayer в переменную localPlayer
        uintptr_t localPlayer = *(uintptr_t*)(gameModule + dwLocalPlayer);
        //Если нет локального игрока, не вылетаем из проги
        if (localPlayer == NULL) continue;
        //Получаем localPlayer команду
        uint32_t localTeam = *(uint32_t*)(localPlayer + m_iTeamNum);
        
    }
    //Выход из потока
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
