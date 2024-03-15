#include "queue.hpp"

queue::queue() {
	p_head_ = p_tail_ = nullptr;
}

bool queue::is_empty() const {
	return p_head_ == nullptr;
}

queue::~queue() {
	delete p_head_;
}

// inserts a new element at the back of the queue
bool queue::enqueue(const data &data) {
	queue_node *p_node = new queue_node(data);
	if (p_node == nullptr) return false;

	if (is_empty()) {
		p_head_ = p_tail_ = p_node;
		return true;
	}

	p_tail_->set_next(p_node);
	p_tail_ = p_node;

	return true;
}

// deletes and returns the first element
data queue::dequeue() {
	data data = *p_head_->get_data();
	queue_node *p_tmp = p_head_->get_next();

	// https://stackoverflow.com/a/14882140
	operator delete(p_head_);
	p_head_ = p_tmp;
	if (is_empty()) p_tail_ = nullptr;

	return data;
}

// returns the data in the first element
data *queue::peek() const {
	return p_head_->get_data();
}

void queue::print() {
	// cannot use loop because queues can't see into elements
	// therefore, make a tmp queue and re-enqueue all elements
	queue tmp_queue;

	while (!is_empty()) {
		data tmp_data = dequeue();
		std::cout << "#" << tmp_data.get_customer_number() << " "
			  << tmp_data.get_service_time() << "m "
			  << tmp_data.get_total_time() << "m";

		if (!is_empty()) std::cout << " | ";

		tmp_queue.enqueue(tmp_data);
	}

	while (!tmp_queue.is_empty())
		enqueue(tmp_queue.dequeue());
}
