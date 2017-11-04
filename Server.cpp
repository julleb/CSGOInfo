#include "Server.h"

#include "LocalPlayer.h"



void Server::cleanUp(Client &client)
{
	
}

Server::Server(int port) {
	this->port = port;
	init();
}

void Server::init() {
	//we need to remove these!
	messageHandlerPointer = new MessageHandler();
	connectionHandlerPointer = new ConnectionHandler(port);
	playerExtractorPointer = new PlayerExtractorImpl();
}


void Server::run() {

	
	while (1) {
		Client newClient = connectionHandlerPointer->acceptConnection();

		while (1) {

			std::string message = playerExtractorPointer->getPlayers();


			//std::cout << message << std::endl;
			int status = messageHandlerPointer->sendMessageToClient(newClient, message);

			if (status != 0) {
				//The client has dc, lets break and wait for new connection!
				std::cout << "Client disconnected!" <<std::endl;
				break;
			}

			//std::cout << "Waiting for message" << std::endl;
			message = messageHandlerPointer->getMessageFromClient(newClient);

			//std::cout << message << std::endl;
			//std::cout << "Done reading message" << std::endl;

			//Sleep(100);
			//Sleep(100);

		}
	}
	

	

	
}