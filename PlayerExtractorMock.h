#ifndef PLAYEREXTRACTORMOCK_H
#define PLAYEREXTRACTORMOCK_H

#include "PlayerExtractor.h"

class PlayerExtractorMock : public PlayerExtractor {
private:
	std::vector<Player*> players;
	void resetPlayers();

public:
	PlayerExtractorMock();
	virtual std::string getPlayers();
};



#endif