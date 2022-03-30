#include "include.h"

double rNum = 0.011 + rand() % 2;
static Vector prevViewAngle;

void RemorniaPrint() {
cout << "  _   _   _   _   _   _   _   _  " << endl;
cout << " / \ / \ / \ / \ / \ / \ / \ / \ " << endl;
cout << "( R | E | M | O | R | N | I | A )" << endl;
cout << " \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ " << endl;
}

void FindProc() {
	val.process = mem.getProcess("csgo.exe");
	val.clientModule = mem.getModule(val.process, "client.dll");
	val.engineModule = mem.getModule(val.process, "engine.dll");
	if (val.clientModule != NULL && val.engineModule != NULL) {
		cout << "Process found!" << endl;
	}
}

void FindLocal() {
	val.localPlayer = mem.readMem<DWORD>(val.clientModule + dwLocalPlayer);
	if (val.localPlayer == NULL) {
		while (val.localPlayer == NULL) {
			val.localPlayer = mem.readMem<DWORD>(val.clientModule + dwLocalPlayer);
		}
	}
}


void Autostrafe() {
	DWORD EngineState = mem.readMem<DWORD>(val.engineModule + dwClientState);
	Vector currentViewAngles = mem.readMem<Vector>(EngineState + dwClientState_ViewAngles);

	if (GetAsyncKeyState(VK_RBUTTON))
	{
		if (val.flag != (1 << 0)) {
			if (currentViewAngles.y > prevViewAngle.y) {
				RELEASE(0x44);
				Sleep(rNum);
				PRESS(0x41);
			}
			else if (currentViewAngles.y < prevViewAngle.y) {
				RELEASE(0x41);
				Sleep(rNum);
				PRESS(0x44);
			}
		}
	}
	prevViewAngle = currentViewAngles;
}



void BHOP() {
	val.flag = mem.readMem<BYTE>(val.localPlayer + m_fFlags);
	if (GetAsyncKeyState(VK_RBUTTON) && val.flag & (1 << 0)) {
		mem.writeMem<DWORD>(val.clientModule + dwForceJump, 6);
	}
	Sleep(1);
}



void main() {
	//Для цветного вывода
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"Remornia");
	//Для работы RELEASE PRESS
	signal(SIGABRT, &sighandler);
	signal(SIGTERM, &sighandler);
	signal(SIGINT, &sighandler);
	SetConsoleTextAttribute(hConsole, LIGHTRED);
	RemorniaPrint();
	SetConsoleTextAttribute(hConsole, GREEN);
	wcout << "========================================" << endl;
	SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
	wcout << "|   CS:GO Autostrafe - By Remor(Lund)  |" << endl;
	SetConsoleTextAttribute(hConsole, GREEN);
	wcout << "========================================" << endl;
	SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
	FindProc();
	FindLocal();

	while (true) {
		//BHOP();
		Autostrafe();
	}

}
