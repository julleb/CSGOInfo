#ifndef ENTITYPLAYER_H
#define ENTITYPLAYER_H

#include "Player.h"

class EntityPlayer : public Player {

private:
	int dormant;
	


public:
	virtual std::string toString();
	EntityPlayer(int health, int team, int dormant, float *position);
	bool isValid();


};




#endif