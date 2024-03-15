#include "queuenode.hpp"

queue_node::queue_node(const data &data) {
	p_data_ = new class data(data);
	p_next_ = nullptr;
}

queue_node::~queue_node() {
	// recurse into next node
	// base case: p_next_ is nullptr
	delete p_next_;
	delete p_data_;
}

data *queue_node::get_data() const {
	return p_data_;
}

queue_node *queue_node::get_next() const {
	return p_next_;
}

void queue_node::set_next(queue_node *const &p_next) {
	p_next_ = p_next;
}
