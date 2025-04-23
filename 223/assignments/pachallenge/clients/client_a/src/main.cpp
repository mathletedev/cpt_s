#include "client.hpp"
#include <boost/asio.hpp>
#include <boost/uuid.hpp>
#include <iostream>
#include <thread>

namespace json = boost::json;

int main() {
	boost::asio::io_context io_context;

	Client client(io_context, "127.0.0.1", "8080");

	// run receiver in separate thread to avoid blocking sending
	std::thread receiver(std::bind(&Client::run_receiver, &client));

	json::object req1;
	req1["method"] = "CREATE_TOPIC";
	req1["topic"] = "Emergency";
	client.send(req1);

	std::cout << "Press Enter to publish message..." << std::endl;
	std::cin.get();

	json::object req2;
	req2["method"] = "PUBLISH";
	req2["topic"] = "Emergency";
	req2["message"] = "Snoqualmie Pass closed";
	client.send(req2);

	receiver.join();

	return 0;
}
