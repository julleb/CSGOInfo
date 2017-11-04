#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler(int port){
	
	//we need to clear this
	ap = new tcp::acceptor (io_service, tcp::endpoint(tcp::v4(), port));
}

ConnectionHandler::ConnectionHandler(tcp::acceptor acceptor)
{
	
}

Client ConnectionHandler::acceptConnection()
{
	std::cout << "Waiting for connection" << std::endl;
	tcp::socket *sp = new tcp::socket(io_service); //we need to clear this.
	ap->accept(*sp);
	std::cout << "Got a connection" << std::endl;
	Client client(sp);
	return client;
}


