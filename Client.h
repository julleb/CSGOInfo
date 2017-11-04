#ifndef CLIENT_H
#define CLIENT_H
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

class Client {
private:
	tcp::socket *socketPointer;
public:
	Client(tcp::socket *sp);
	tcp::socket* getSocketAsPointer();
	~Client();
};



#endif