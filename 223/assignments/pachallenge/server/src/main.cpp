#include "server.hpp"
#include "tcp.hpp"
#include <boost/asio.hpp>
#include <boost/uuid.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

#define DEFAULT_PORT 8080

int main() {
	char *port_cstr = std::getenv("PORT");
	uint16_t port = port_cstr ? std::stoi(port_cstr) : DEFAULT_PORT;

	Server server;
	// run sender on a separate thread
	std::thread sender(&Server::run_sender, &server);

	boost::asio::io_context io_context;
	TCPServer tcp_server(io_context, port, server);

	// graceful shutdown
	boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
	signals.async_wait([&](auto, auto) {
		std::cout << "Server shutting down..." << std::endl;
		server.stop();
		io_context.stop();
	});

	std::cout << "Server starting on port " << port << "!" << std::endl;

	io_context.run();
	sender.join();

	return 0;
}
