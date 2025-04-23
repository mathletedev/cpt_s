#include "client.hpp"
#include <boost/asio.hpp>
#include <boost/uuid.hpp>
#include <thread>

namespace json = boost::json;

int main() {
	boost::asio::io_context io_context;

	Client client(io_context, "127.0.0.1", "8080");

	// run receiver in separate thread to avoid blocking sending
	std::thread receiver(std::bind(&Client::run_receiver, &client));

	json::object req;
	req["method"] = "SUBSCRIBE";
	req["topic"] = "Emergency";
	client.send(req);

	receiver.join();

	return 0;
}
