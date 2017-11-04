#ifndef PLAYERSJSON_H
#define PLAYERSJSON_H

#include <string>
#include "LocalPlayer.h"
#include "EntityPlayer.h"
#include <vector>
class PlayersJson {


	
public:
	std::string toString();
	std::string buildJsonString(std::string &localPlayer, std::vector<std::string> &entityPlayers);

};

#endif