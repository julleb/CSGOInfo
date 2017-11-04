#ifndef PLAYEREXTRACTOR_H
#define PLAYEREXTRACTOR_H

#include <vector>
#include "LocalPlayer.h"
#include "EntityPlayer.h"

class PlayerExtractor {
public:
	virtual std::string getPlayers() = 0;

};


#endif