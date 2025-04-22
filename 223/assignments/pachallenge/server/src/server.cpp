#include "server.hpp"

void Server::publish(const std::string &topic,
		     const boost::uuids::uuid &client_id,
		     const std::string &message) {
	// lock mutex for thread safety
	std::lock_guard<std::mutex> lock(mutex_);

	if (topics_.find(topic) == topics_.end()) {
		topics_[topic] = std::make_shared<Topic>();
		topics_[topic]->owner = client_id;
		return;
	}

	for (auto &subscriber : topics_[topic]->subscribers) {
		messages_.push(Message{subscriber, message, 0});
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
