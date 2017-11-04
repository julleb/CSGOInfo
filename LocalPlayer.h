#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "Player.h"

class LocalPlayer : public Player {
private:
	float *eyePosition;
	
public:
	LocalPlayer(int health, float *position, int team, float *eyePosition);
	float * getEyePosition();
	virtual std::string toString();

};

#endif
