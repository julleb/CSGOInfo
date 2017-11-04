#include "Client.h"

Client::Client(tcp::socket *sp) {
	socketPointer = sp;
}

tcp::socket* Client::getSocketAsPointer()
{
	return socketPointer;
}

Client::~Client()
{
	delete socketPointer;
}
