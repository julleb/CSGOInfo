
#include "Server.h"

int main() {
	Server server(8080);
	server.run();

	getchar();
}