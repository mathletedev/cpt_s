#include <boost/asio.hpp>
#include <ctime>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

using boost::asio::ip::tcp;

class TCPConnection : public std::enable_shared_from_this<TCPConnection> {
	public:
		typedef std::shared_ptr<TCPConnection> Pointer;

		static Pointer create(boost::asio::io_context &io_context) {
			return Pointer(new TCPConnection(io_context));
		}

		tcp::socket &socket() {
			return socket_;
		}

		void start() {
			message_ = "Hello world!\n";

			boost::asio::async_write(
			    socket_, boost::asio::buffer(message_),
			    std::bind(
				&TCPConnection::handle_write_,
				shared_from_this(),
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
		}

	private:
		tcp::socket socket_;
		std::string message_;

		TCPConnection(boost::asio::io_context &io_context)
		    : socket_(io_context) {}

		void handle_write_(const boost::system::error_code &, size_t) {}
};

class TCPServer {
	private:
		boost::asio::io_context &io_context_;
		tcp::acceptor acceptor_;

		void start_accept_() {
			TCPConnection::Pointer new_connection =
			    TCPConnection::create(io_context_);

			acceptor_.async_accept(
			    new_connection->socket(),
			    std::bind(&TCPServer::handle_accept_, this,
				      new_connection,
				      boost::asio::placeholders::error));
		}

		void handle_accept_(TCPConnection::Pointer new_connection,
				    const boost::system::error_code &error) {
			if (!error) {
				new_connection->start();
			}

			start_accept_();
		}

	public:
		TCPServer(boost::asio::io_context &io_context)
		    : io_context_(io_context),
		      acceptor_(io_context, tcp::endpoint(tcp::v4(), 13)) {
			start_accept_();
		}
};

int main() {
	try {
		boost::asio::io_context io_context;
		TCPServer server(io_context);
		io_context.run();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
