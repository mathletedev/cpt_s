#include "bstnode.hpp"

bst_node::bst_node(const std::string &data) {
	data_ = data;
	p_left_ = nullptr;
	p_right_ = nullptr;
}

bst_node::~bst_node() {}

std::string bst_node::get_data() const {
	return data_;
}

bst_node *bst_node::get_left() const {
	return p_left_;
}

bst_node *bst_node::get_right() const {
	return p_right_;
}

void bst_node::set_left(bst_node *const &p_node) {
	p_left_ = p_node;
}

void bst_node::set_right(bst_node *const &p_node) {
	p_right_ = p_node;
}

std::ostream &operator<<(std::ostream &lhs, const bst_node &rhs) {
	lhs << rhs.data_;

	return lhs;
}
