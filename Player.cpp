#include "Player.h"

std::string Player::getPositionAsJson()
{	
	oss << "\"Position\": { \"x\":\"" << position[0] << "\", \"y\": \"" << position[1] << "\", \"z\":\""<< position[2] << "\"}";
	return oss.str();
}

int Player::getHealth()
{
	return health;
}

int Player::getTeam()
{
	return team;
}

float * Player::getPosition()
{
	return position;
}
