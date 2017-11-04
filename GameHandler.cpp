#include "GameHandler.h"

DWORD GameHandler::getDllAdress(TCHAR * DLLName)
{
	DWORD moduleBase = 0;
	HANDLE Snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
	if (Snap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 moduleEntry;
		moduleEntry.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(Snap, &moduleEntry)) {
			do {
				if (strcmp(moduleEntry.szModule, DLLName) == 0) {
					moduleBase = (DWORD)moduleEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(Snap, &moduleEntry));
		}
		CloseHandle(Snap);
	}
	return moduleBase;
}

GameHandler::GameHandler(char * windowGameName)
{
	HWND hwnd = FindWindow(0, windowGameName);
	GetWindowThreadProcessId(hwnd, &pid);
	ProcessHandler = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (!ProcessHandler) {
		std::cout << "cannot find the process for the game: " << windowGameName << std::endl;
		//throw exception
	}
	else {
		std::cout << "Found the process for the game: " << windowGameName << std::endl;
		clientDll = getDllAdress("client.dll");
	}

	

}

DWORD& GameHandler::getClientDll()
{
	return clientDll;
}

HANDLE& GameHandler::getProcessHandler()
{
	return ProcessHandler;
}
