#include "include.h"
#include "TriggerThread.h"

//Функция триггера
BOOL WINAPI triggerThread(HMODULE hModule) {
    //Получаем в gameModule наш главный client.dll 
    uintptr_t gameModule = (uintptr_t)GetModuleHandle("client.dll");
    //Выключаем прогу если нажата END
    while (!GetAsyncKeyState(VK_END)) {

        //Получаем локального игрока из оффсета dwLocalPlayer в переменную localPlayer
        uintptr_t localPlayer = *(uintptr_t*)(gameModule + dwLocalPlayer);
        //Если нет локального игрока, не вылетаем из проги
        if (localPlayer == NULL) continue;
        //Получаем прицел localPlayer и его команду
        uint32_t localTeam = *(uint32_t*)(localPlayer + m_iTeamNum);
        uint32_t CrosshairID = *(uint32_t*)(localPlayer + m_iCrosshairId);
        if (CrosshairID != 0 && CrosshairID < 32) {
            //Находим нашего врага
            uintptr_t EnemyPlayer = *(uintptr_t*)(gameModule + dwEntityList + (CrosshairID - 1) * 0x10);
            //Если врага нет, не вылетаем
            if (EnemyPlayer == NULL) continue;
            //Получаем вражескую команду и хп
            uint32_t EnemyHealth = *(uint32_t*)(EnemyPlayer + m_iHealth);
            uint32_t EnemyTeam = *(uintptr_t*)(EnemyPlayer + m_iTeamNum);

            if (EnemyTeam != localTeam && EnemyHealth > 0 && EnemyHealth <= 100) {
                //Стреляем в игрока
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                // задержка после выстрела
                Sleep(100);
            }
            //Оптимизация потока
            Sleep(1);
        }

    }

    //Выход из потока
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
