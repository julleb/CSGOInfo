#include "PlayerHandler.h"



PlayerHandler::PlayerHandler(GameHandler * gameHandler)
{
	PlayerHandler::gameHandler = gameHandler;
}

void PlayerHandler::localPlayerDebug()
{
	std::cout << "health: " << health << std::endl;
	std::cout << "position: " << position[0] << std::endl;
	std::cout << "Team: " << team << std::endl;
	std::cout << "EyePosition[0] " << eyePosition[0] << std::endl;
	std::cout << "EyePosition[1] " << eyePosition[1] << std::endl;
}

void PlayerHandler::entityPlayerDebug()
{
	std::cout << "health: " << entityHealth << std::endl;
	std::cout << "position: " << entityPosition[0] << std::endl;
	std::cout << "Team: " << entityTeam << std::endl; 
	
}

EntityPlayer PlayerHandler::readEntity(int entityIndex)
{
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(gameHandler->getClientDll() + entityBase + (entityIndex * 0x10)), &entityPlayerAdress, sizeof(DWORD), 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(entityPlayerAdress + dwHealth), &entityHealth, 4, 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(entityPlayerAdress + dwPosition), &entityPosition, sizeof(entityPosition), 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(entityPlayerAdress + dwTeam), &entityTeam, 4, 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(entityPlayerAdress + dwDormant), &dormant, 4, 0);

	//entityPlayerDebug();
	return EntityPlayer(entityHealth, entityTeam, dormant, entityPosition);
}

LocalPlayer PlayerHandler::readPlayer()
{
	
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(gameHandler->getClientDll() + localBase), &localPlayerAdress, sizeof(DWORD), 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(localPlayerAdress + dwHealth), &health, 4, 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(localPlayerAdress + dwPosition), &position, sizeof(position), 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(localPlayerAdress + dwTeam), &team, 4, 0);
	ReadProcessMemory(gameHandler->getProcessHandler(), (PBYTE*)(gameHandler->getClientDll() + dwEyePosition), &eyePosition, sizeof(eyePosition), 0);

	

	//localPlayerDebug();

	return LocalPlayer(health, position, team, eyePosition);
}


