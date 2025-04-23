#pragma once

#include <boost/uuid.hpp>

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

// for documentation; actual implementation uses boost::json::value
struct Request {
		boost::uuids::uuid clientID;
		std::string method;
		std::string params;
};
