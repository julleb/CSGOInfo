#include "PlayersJson.h"

std::string PlayersJson::toString()
{
	return std::string();
}

std::string PlayersJson::buildJsonString(std::string &localPlayer, std::vector<std::string> &entityPlayers)
{
	std::string json = "{\"Entities\": [";
	for (int i = 0; i < entityPlayers.size(); ++i) {
		json.append(entityPlayers[i]);
		json.append(",");
	}
	json[json.size() - 1] = ']';
	json.append(", \"LocalPlayer\": ");
	json.append(localPlayer);
	json.append("}\n");
	return json;
}

