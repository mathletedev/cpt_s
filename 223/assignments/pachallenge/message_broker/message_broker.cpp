#include <boost/asio.hpp>
#include <ctime>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

const unsigned int MAX_LENGTH = 1024;

using boost::asio::ip::tcp;

class TCPConnection : public std::enable_shared_from_this<TCPConnection> {
	private:
		tcp::socket socket_;
		char data_[MAX_LENGTH];

		TCPConnection(boost::asio::io_context &io_context)
		    : socket_(io_context) {}

		void handle_read_() {
			// capture self to keep alive during async operations
			auto self(shared_from_this());
			socket_.async_read_some(
			    boost::asio::buffer(data_, MAX_LENGTH),
			    [this, self](const boost::system::error_code &ec,
					 size_t length) {
				    if (ec) {
					    std::cerr << ec.message()
						      << std::endl;
					    return;
				    }

				    std::string received(data_, length);
				    std::cout << received << std::endl;

				    // loop back unto itself
				    handle_write_(length);
			    });
		}

		void handle_write_(size_t length) {
			auto self(shared_from_this());
			boost::asio::async_write(
			    socket_, boost::asio::buffer(data_, length),
			    [this, self](const boost::system::error_code &ec,
					 size_t) {
				    if (ec) {
					    std::cerr << ec.message()
						      << std::endl;
					    return;
				    }

				    handle_read_();
			    });
		}

	public:
		typedef std::shared_ptr<TCPConnection> Pointer;

		static Pointer create(boost::asio::io_context &io_context) {
			return Pointer(new TCPConnection(io_context));
		}

		tcp::socket &socket() {
			return socket_;
		}

		void start() {
			handle_read_();
		}
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
		      acceptor_(io_context, tcp::endpoint(tcp::v4(), 8080)) {
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
