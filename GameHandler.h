#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H


#include <Windows.h>
#include <tlhelp32.h>
#include <cstdint>
#include <iostream>

class GameHandler {

private:
	DWORD clientDll;
	HANDLE ProcessHandler;
	DWORD pid;
	DWORD getDllAdress(TCHAR *DLLName);

public:
	GameHandler(char *gameName);
	DWORD& getClientDll();
	HANDLE& getProcessHandler();

};



#endif