#pragma once

#include "server.hpp"
#include <boost/asio.hpp>
#include <boost/uuid.hpp>
#include <ctime>
#include <memory>
#include <string>

namespace asio = boost::asio;
using boost::asio::ip::tcp;

constexpr size_t BUF_SIZE = 1024;

class Server;

class TCPConnection : public std::enable_shared_from_this<TCPConnection> {
	private:
		tcp::socket socket_;
		Server &server_;
		char buf_[BUF_SIZE];

		TCPConnection(asio::io_context &io_context, Server &server)
		    : socket_(io_context), server_(server) {}

		void handle_read_();

	public:
		typedef std::shared_ptr<TCPConnection> Pointer;
		static Pointer create(asio::io_context &io_context,
				      Server &server) {
			return Pointer(new TCPConnection(io_context, server));
		}

		tcp::socket &socket() {
			return socket_;
		}
		void send(const std::string &message);
		void start() {
			handle_read_();
		}
};

class TCPServer {
	private:
		asio::io_context &io_context_;
		Server &server_;
		tcp::acceptor acceptor_;

		void start_accept_();
		void handle_accept_(TCPConnection::Pointer new_connection,
				    const boost::system::error_code &error);

	public:
		TCPServer(asio::io_context &io_context, uint16_t port,
			  Server &server)
		    : io_context_(io_context), server_(server),
		      acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
			start_accept_();
		}
};
