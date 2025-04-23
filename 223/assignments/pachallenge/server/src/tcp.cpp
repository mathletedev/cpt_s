#include "tcp.hpp"
#include <functional>
#include <iostream>

void TCPConnection::handle_read_() {
	// capture self to keep alive during async operations
	auto self(shared_from_this());
	socket_.async_read_some(
	    boost::asio::buffer(data_, MAX_LENGTH),
	    [this, self](const boost::system::error_code &ec, size_t length) {
		    if (ec) {
			    std::cerr << ec.message() << std::endl;
			    return;
		    }

		    std::string received(data_, length);

		    try {
			    server_.handle_request(received);
		    } catch (std::runtime_error &status_code) {
			    send(status_code.what());
		    }

		    // loop back unto itself
		    handle_read_();
	    });
}

void TCPConnection::send(const std::string &message) {
	auto self(shared_from_this());
	boost::asio::async_write(
	    socket_, boost::asio::buffer(message + "\n"),
	    [this, self](const boost::system::error_code &ec, std::size_t) {
		    if (ec) {
			    std::cerr << ec.message() << std::endl;
		    }
	    });
}

void TCPServer::start_accept_() {
	TCPConnection::Pointer new_connection =
	    TCPConnection::create(io_context_, server_);

	acceptor_.async_accept(new_connection->socket(),
			       std::bind(&TCPServer::handle_accept_, this,
					 new_connection,
					 boost::asio::placeholders::error));
}

void TCPServer::handle_accept_(TCPConnection::Pointer new_connection,
			       const boost::system::error_code &error) {
	if (!error) {
		new_connection->start();
	}

	start_accept_();
}
