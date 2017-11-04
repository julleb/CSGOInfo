#include "MessageHandler.h"

#include <iostream>

int MessageHandler::sendMessageToClient(Client &client, std::string message) {
	
	boost::asio::write(*(client.getSocketAsPointer()), boost::asio::buffer(message), ignored_error);
	return ignored_error.value();
}
std::string MessageHandler::getMessageFromClient(Client &client) {
	
	std::stringstream message_stream;
	boost::asio::streambuf buffer;
	boost::system::error_code error;
	size_t len = boost::asio::read_until(*client.getSocketAsPointer(), buffer, '\n', error);
	if (len)
	{
		message_stream.write(boost::asio::buffer_cast<const char *>(buffer.data()), len);
		std::string message = message_stream.str();
		return message;
	}
	return "XD";
	
	
	/*boost::asio::streambuf sb;
	boost::system::error_code ec;

	boost::asio::read(*client.getSocketAsPointer(), sb, ec);

	std::ostringstream sline;
	sline << &sb;
	std::string message = sline.str();
	return message;
	*/
}