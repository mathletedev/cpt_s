#pragma once

#include "server.hpp"
#include <boost/asio.hpp>
#include <boost/uuid.hpp>
#include <ctime>
#include <memory>
#include <string>

using boost::asio::ip::tcp;

const unsigned int MAX_LENGTH = 1024;

class TCPConnection : public std::enable_shared_from_this<TCPConnection> {
	private:
		tcp::socket socket_;
		char data_[MAX_LENGTH];

		TCPConnection(boost::asio::io_context &io_context)
		    : socket_(io_context) {}

		void handle_read_();

	public:
		typedef std::shared_ptr<TCPConnection> Pointer;
		static Pointer create(boost::asio::io_context &io_context) {
			return Pointer(new TCPConnection(io_context));
		}

		tcp::socket &socket() {
			return socket_;
		}
		void send(const std::string &message);
		void start() {
			handle_read_();
		}
};

class Server;

class TCPServer {
	private:
		boost::asio::io_context &io_context_;
		tcp::acceptor acceptor_;

		void start_accept_();
		void handle_accept_(TCPConnection::Pointer new_connection,
				    const boost::system::error_code &error);

	public:
		TCPServer(boost::asio::io_context &io_context, uint16_t port,
			  Server &server)
		    : io_context_(io_context),
		      acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
			start_accept_();
		}
};
