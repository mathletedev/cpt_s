#pragma once

#include <boost/asio.hpp>
#include <boost/json.hpp>
#include <boost/uuid.hpp>

namespace asio = boost::asio;
namespace uuids = boost::uuids;
namespace json = boost::json;
using boost::asio::ip::tcp;

constexpr size_t BUF_SIZE = 1024;

class Client {
	private:
		uuids::uuid id_;
		tcp::socket socket_;
		tcp::resolver resolver_;
		char buf_[BUF_SIZE];

	public:
		Client(asio::io_context &io_context, const std::string &host,
		       const std::string &port)
		    : socket_(io_context), resolver_(io_context) {
			id_ = uuids::random_generator()();
			asio::connect(socket_, resolver_.resolve(host, port));
		};

		void run_receiver();
		void send(json::object req);
};
