#pragma once

#include "tcp.hpp"
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

struct Message {
		boost::uuids::uuid to_id;
		std::string content;
		int priority;

		bool operator<(const Message &other) const {
			return priority < other.priority;
		}
};

struct Topic {
		boost::uuids::uuid owner;
		std::vector<boost::uuids::uuid> subscribers;
};

class TCPConnection;

class Server {
	private:
		std::mutex mutex_;
		std::condition_variable cv_;
		std::atomic<bool> running_;
		std::map<boost::uuids::uuid, std::shared_ptr<TCPConnection>>
		    clients_;
		std::map<std::string, std::shared_ptr<Topic>> topics_;
		std::priority_queue<Message> messages_;

	public:
		void publish(const std::string &topic,
			     const boost::uuids::uuid &client_id,
			     const std::string &message);
		void run_sender();
		void stop();
};
