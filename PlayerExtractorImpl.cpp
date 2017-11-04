#include "PlayerExtractorImpl.h"


void PlayerExtractorImpl::resetPlayers()
{

}

PlayerExtractorImpl::PlayerExtractorImpl()
{
	gameHandler = new GameHandler("Counter-Strike: Global Offensive");
	playerHandler = new PlayerHandler(gameHandler);
	entityPlayers = std::vector<std::string>();
}

std::string PlayerExtractorImpl::getPlayers()
{
		entityPlayers = std::vector<std::string>();
		for (int i = 0; i < 10; i++) {	
			EntityPlayer entityPlayer = playerHandler->readEntity(i);
			if (!entityPlayer.isValid()) continue;
			entityPlayers.push_back(entityPlayer.toString());
			
		}
		LocalPlayer localPlayer = playerHandler->readPlayer();


		PlayersJson playersJson;
		std::string json = playersJson.buildJsonString(localPlayer.toString(), entityPlayers);
		//std::cout << json << std::endl;
		return json;
}

