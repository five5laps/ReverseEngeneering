#include "include.h"

void RemorWarePrint() {
    //huge print
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wcout << L"██████████████████████████████████████████████" << std::endl;
    std::wcout << L"█────█───█─███─█────█────█─███─█────█────█───█" << std::endl;
    std::wcout << L"█─██─█─███──█──█─██─█─██─█─███─█─██─█─██─█─███" << std::endl;
    std::wcout << L"█────█───█─█─█─█─██─█────█─█─█─█────█────█───█" << std::endl;
    std::wcout << L"█─█─██─███─███─█─██─█─█─██─────█─██─█─█─██─███" << std::endl;
    std::wcout << L"█─█─██───█─███─█────█─█─███─█─██─██─█─█─██───█" << std::endl;
    std::wcout << L"██████████████████████████████████████████████" << std::endl;
    std::wcout << "" << std::endl;
    std::wcout << L"████████████████████████████████████" << std::endl;
    std::wcout << L"█────█───█─█─█─█─██─█────█────█─██─█" << std::endl;
    std::wcout << L"█─██─█─███─█─█─█─██─█─██─█─██─█─█─██" << std::endl;
    std::wcout << L"█─██─█───█─█─█─█────█────█─████──███" << std::endl;
    std::wcout << L"█─██─███─█─█─███─██─█─██─█─██─█─█─██" << std::endl;
    std::wcout << L"█────█───█───█─█─██─█─██─█────█─██─█" << std::endl;
    std::wcout << L"████████████████████████████████████" << std::endl;
}


int main()
{
    //Get procID of the target process
    // L CONVERT string to unicode

    DWORD procId = GetProcId(L"osu!.exe");

    //GetModulebaseaddr

    uintptr_t moduleBase = GetModuleBaseAddress(procId, L"bass.dll");

    //Get Handle to process

    HANDLE hProcess = 0;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

    //Resolve base address of the pointer chain

    uintptr_t ratePtrAddr = moduleBase + 0x00034268;
    uintptr_t AudioCheckTimePtrAddr = moduleBase + 0x154;


    //std::cout << "dynamicPtrBaseAddr = " << "0x" << std::hex << dynamicPtrBaseAddr << std::endl;

    //Resolve our rate pointer 

    std::vector<unsigned int> rateOffests = { 0x8, 0x10, 0xC, 0x48 };
    uintptr_t rateAddr = FindDMAAddy(hProcess, ratePtrAddr, rateOffests);

    std::vector<unsigned int> AudioCheckTimeOffests = { 0x154, 0x158 };
    uintptr_t AudioCheckTimeAddr = FindDMAAddy(hProcess, AudioCheckTimePtrAddr, AudioCheckTimeOffests);
    std::cout << "rateAddr = " << "0x" << std::hex << rateAddr << std::endl;

    double rateMultiplier = 1;
    double initRate;
    double currentRate;
    double AudioCheckTime;

    while (true) {
        system("cls");
        RemorWarePrint();
        ReadProcessMemory(hProcess, (BYTE*)rateAddr, &currentRate, sizeof(currentRate), nullptr);
        ReadProcessMemory(hProcess, (BYTE*)AudioCheckTimeAddr, &AudioCheckTime, sizeof(AudioCheckTime), nullptr);
        std::wcout << "Current rate = " << std::dec << currentRate << std::endl;
        //std::wcout << "Current speed = " << std::dec << rateMultiplier << std::endl;
        std::wcout << "Change speed to ";
        std::wcout << "->";
        std::cin >> initRate;
        /*
        std::cin >> rateMultiplier;
        
        if (rateMultiplier > 1) {
            initRate = currentRate / rateMultiplier;
        }
        else if(rateMultiplier < 1){
            initRate = currentRate * rateMultiplier;
        }
        else if (rateMultiplier == 1) {
            initRate = 1147;
        }
        else if (rateMultiplier == 1.5) {
            initRate = 1720;
        }
        */
        WriteProcessMemory(hProcess, (BYTE*)rateAddr, &initRate, sizeof(initRate), nullptr);
        WriteProcessMemory(hProcess, (BYTE*)AudioCheckTimeAddr, &initRate, sizeof(initRate), nullptr);
        Sleep(5);
    }
    return 0;
}