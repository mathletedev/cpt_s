#include "client.hpp"
#include <boost/json/src.hpp>
#include <iostream>

void Client::run_receiver() {
	while (true) {
		size_t len = socket_.read_some(asio::buffer(buf_, BUF_SIZE));
		std::string message(buf_, len);

		std::cout << message << std::endl;
	}
}

void Client::send(json::object req) {
	// tie client id to request
	req["clientID"] = uuids::to_string(id_);
	asio::write(socket_, asio::buffer(json::serialize(req) + "\n"));
}
