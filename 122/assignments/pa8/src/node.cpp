#include "node.hpp"

node::node(std::string const &data) {
	data_ = data;

	p_left_ = nullptr;
	p_right_ = nullptr;
}

node::~node() {
	// nothing to do
}
