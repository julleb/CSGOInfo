#ifndef SERVER_H
#define SERVER_H

#include "ConnectionHandler.h"
#include "MessageHandler.h"
#include "PlayerExtractorMock.h"
#include "PlayerExtractorImpl.h"
#include "GameHandler.h"

class Server {
private:
	int port;
	ConnectionHandler *connectionHandlerPointer;
	MessageHandler *messageHandlerPointer;
	PlayerExtractor *playerExtractorPointer;
	GameHandler *gameHandlerPointer;
	void cleanUp(Client &client);

public:
	Server(int port);
	void run();
	void init();

};



#endif