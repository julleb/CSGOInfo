#include "EntityPlayer.h"



EntityPlayer::EntityPlayer(int health, int team, int dormant, float * position)
{
	this->health = health;
	this->team = team;
	this->dormant = dormant;
	this->position = position;
}

bool EntityPlayer::isValid()
{
	if (dormant == 1 || (health > 100 || health < 1)) return false;
	return true;
}

std::string EntityPlayer::toString()
{
	std::string positionAsJson = getPositionAsJson();

	oss.str(""); //flushes the oss-stream

	oss << "{\"Health\":" << getHealth() << ", " << positionAsJson
		<< ", \"Team\":" << team << ", \"Dormant\":" << dormant << "}";
	return oss.str();
}
