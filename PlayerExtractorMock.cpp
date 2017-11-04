#include "PlayerExtractorMock.h"

PlayerExtractorMock::PlayerExtractorMock()
{

}

std::string PlayerExtractorMock::getPlayers()
{
	resetPlayers();

	
	
	for (int i = 0; i < 10; i++) {
		EntityPlayer entityPlayer();
	}

	return "wow";
}

void PlayerExtractorMock::resetPlayers() {
	
}
