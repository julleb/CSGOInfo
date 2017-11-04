#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <boost/asio.hpp>
#include <iostream>
#include "Client.h"

using boost::asio::ip::tcp;

class ConnectionHandler {
	
private: 
	int port;
	tcp::acceptor *ap;
	boost::asio::io_service io_service;

public:
	ConnectionHandler(int port);

	ConnectionHandler(tcp::acceptor acceptor);
	Client acceptConnection();

};


#endif
