#ifndef PLAYEREXTRACTORIMPL_H
#define PLAYEREXTRACTORIMPL_H

#include "PlayerExtractor.h"

#include "PlayerHandler.h"
#include "PlayersJson.h"

class PlayerExtractorImpl : public PlayerExtractor {
private:
	std::vector<std::string> entityPlayers;
	void resetPlayers();

	GameHandler *gameHandler;
	PlayerHandler *playerHandler;


public:
	PlayerExtractorImpl();
	virtual std::string getPlayers();
};



#endif