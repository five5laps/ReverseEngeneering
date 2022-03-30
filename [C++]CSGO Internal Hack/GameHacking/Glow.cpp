#include "pch.h"
#include "include.h"

bool glow = false;

//Функция глоу
BOOL WINAPI glowThread(HMODULE hModule) {
    
    DWORD gameModule = (DWORD)GetModuleHandle("client.dll");
    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
            glow = !glow;
        }
        if(glow){
        DWORD localPlayer = *(DWORD*)(gameModule + dwLocalPlayer);
        
        DWORD GlowObjectManager = *(DWORD*)(gameModule + dwGlowObjectManager);
        DWORD EntityList = *(DWORD*)(gameModule + dwEntityList);
        if (localPlayer == NULL) continue;
        uint32_t localTeam = *(uint32_t*)(localPlayer + m_iTeamNum);
        //Проверка на 64 игрока
        for (int Players = 0; Players <= 64; Players++) {
            DWORD EnemyPlayer = *(DWORD*)(gameModule + dwEntityList + Players * 0x10);
            if (EnemyPlayer == NULL) continue;

            uint32_t glowIndex = *(uint32_t*)(EnemyPlayer + m_iGlowIndex);
            uint32_t EnemyTeam = *(uint32_t*)(EnemyPlayer + m_iTeamNum);
            //Отрисовываем энеми
            if (EnemyTeam != localTeam) {
                *(float*)(GlowObjectManager + glowIndex * 0x38 + 0x4) = 1.f; //R
                *(float*)(GlowObjectManager + glowIndex * 0x38 + 0x8) = 0.f; //G
                *(float*)(GlowObjectManager + glowIndex * 0x38 + 0xc) = 1.f; //B
                *(float*)(GlowObjectManager + glowIndex * 0x38 + 0x10) = 1.7f; //A
            }
            
            *(bool*)(GlowObjectManager + glowIndex * 0x38 + 0x24) = true;
            *(bool*)(GlowObjectManager + glowIndex * 0x38 + 0x25) = false;
        }
        }
        Sleep(1);
    }
    //Выход из потока
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
