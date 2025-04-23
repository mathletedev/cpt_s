#pragma once

#include "tcp.hpp"
#include "types.hpp"
#include <atomic>
#include <boost/asio.hpp>
#include <boost/uuid.hpp>
#include <condition_variable>
#include <ctime>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <string>

namespace uuids = boost::uuids;

class TCPConnection;

class Server {
	private:
		std::mutex mutex_;
		std::condition_variable cv_;
		std::atomic<bool> running_;
		std::map<uuids::uuid, std::shared_ptr<TCPConnection>> clients_;
		std::map<std::string, std::shared_ptr<Topic>> topics_;
		std::priority_queue<Message> messages_;

	public:
		void create_topic(const uuids::uuid &client_id,
				  const std::string &topic);
		void publish(const uuids::uuid &client_id,
			     const std::string &topic,
			     const std::string &message);
		void subscribe(const uuids::uuid &client_id,
			       const std::string &topic);

		void handle_request(std::string &req,
				    std::shared_ptr<TCPConnection> connection);

		void run_sender();
		void stop();
};
