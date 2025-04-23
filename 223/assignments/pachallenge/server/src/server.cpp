#include "server.hpp"
// WARN: ld unable to find boost/json.hpp
#include <boost/json/src.hpp>
#include <iostream>

namespace json = boost::json;

void Server::create_topic(const uuids::uuid &client_id,
			  const std::string &topic) {
	// lock mutex for thread safety
	std::lock_guard<std::mutex> lock(mutex_);

	if (topics_.find(topic) != topics_.end()) {
		throw std::runtime_error("409 Conflict");
	}

	topics_[topic] = std::make_shared<Topic>();
	topics_[topic]->owner = client_id;
}

void Server::publish(const uuids::uuid &client_id, const std::string &topic,
		     const std::string &message) {
	std::cout << "Message published by Client A, forwarding to subscribers"
		  << std::endl;

	std::lock_guard<std::mutex> lock(mutex_);

	if (topics_.find(topic) == topics_.end()) {
		throw std::runtime_error("404 Not Found");
	}

	for (auto &subscriber : topics_[topic]->subscribers) {
		messages_.push(Message{subscriber, message, 0});
		// actually notify thread to send message
		cv_.notify_one();
	}
}

void Server::subscribe(const uuids::uuid &client_id, const std::string &topic) {
	topics_[topic]->subscribers.push_back(client_id);
}

void Server::handle_request(std::string &req,
			    TCPConnection::Pointer connection) {
	json::object _req = json::parse(req).as_object();

	std::string client_id_str = _req["clientID"].as_string().c_str();
	uuids::string_generator gen;
	uuids::uuid client_id = gen(client_id_str);

	if (clients_.find(client_id) == clients_.end()) {
		// need to remember client shared ptr
		clients_[client_id] = connection;
	}

	json::string method = _req["method"].as_string();

	if (method == "CREATE_TOPIC") {
		std::string topic = _req["topic"].as_string().c_str();

		create_topic(client_id, topic);
	} else if (method == "PUBLISH") {
		std::string topic = _req["topic"].as_string().c_str();
		std::string message = _req["message"].as_string().c_str();

		publish(client_id, topic, message);
	} else if (method == "SUBSCRIBE") {
		std::string topic = _req["topic"].as_string().c_str();

		subscribe(client_id, topic);
	} else {
		throw std::runtime_error("501 Not Implemented");
	}
}

void Server::run_sender() {
	running_ = true;
	while (running_) {
		std::unique_lock<std::mutex> lock(mutex_);
		cv_.wait(lock,
			 [this] { return !messages_.empty() || !running_; });

		if (!running_) {
			break;
		}

		while (!messages_.empty()) {
			Message message = messages_.top();
			messages_.pop();
			lock.unlock();

			auto client = clients_.find(message.to_id);
			client->second->send(message.content);

			lock.lock();
		}
	}
}

void Server::stop() {
	running_ = false;
	cv_.notify_all();
}
