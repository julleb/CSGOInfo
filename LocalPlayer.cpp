#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(int health, float *position, int team, float *eyePosition)
{
	this->health = health;
	this->team = team;
	this->position = position;
	this->eyePosition = eyePosition;
}

float * LocalPlayer::getEyePosition()
{
	return eyePosition;
}

std::string LocalPlayer::toString()
{
	std::string positionAsJson = getPositionAsJson();

	oss.str("");

	oss << "{\"Health\":" << getHealth() << ", \"EyePosition\":{" << " \"x\": \""<<getEyePosition()[0] << "\", \"y\": \""
		<< getEyePosition()[1] << "\", \"z\": \"" << getEyePosition()[2] << "\"}, " << positionAsJson
		<< ", \"Team\":" << team <<  "}";
	return oss.str();
}
