#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include <Windows.h>
#include "GameHandler.h"
#include "LocalPlayer.h"
#include "EntityPlayer.h"
class PlayerHandler {
private: 
	//LOCALPLAYER address
	const DWORD localBase = 0xAACBAC;
	const DWORD dwHealth = 0xFC;
	const DWORD dwPosition = 0x134;
	const DWORD dwVecView = 0x104;
	const DWORD dwTeam = 0xF0;
	const DWORD dwEyePosition = 0xAC270C;

	int health;
	float position[3];
	int team;
	float eyePosition[3];


	//ENTITY address
	const DWORD entityBase = 0x4A89C7C;
	const DWORD dwDormant = 0xE9;
	const DWORD dwEPosition = 0x134;

	int entityHealth;
	float entityPosition[3];
	int entityTeam;
	int dormant;

	GameHandler *gameHandler;
	DWORD localPlayerAdress;
	DWORD entityPlayerAdress;

	void localPlayerDebug();
	void entityPlayerDebug();

public:
	EntityPlayer readEntity(int entityIndex);
	LocalPlayer readPlayer();
	PlayerHandler(GameHandler *gameHandler);
};



#endif