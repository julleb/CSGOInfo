#ifndef MESSAGEHANDLER_H
#define MESSAGE_HANDLER

#include "Client.h"
#include <string>
using boost::asio::ip::tcp;
class MessageHandler {
	
private:
	boost::system::error_code ignored_error;
public:
	int sendMessageToClient(Client &client, std::string message);
	std::string getMessageFromClient(Client &client);


};




#endif