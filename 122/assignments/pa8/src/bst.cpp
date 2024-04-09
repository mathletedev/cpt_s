#include "bst.hpp"

bst::bst() {
	p_root_ = nullptr;
}

bst::~bst() {
	destroy_tree(p_root_);
}

void bst::insert(std::string const &data, int const &units) {
	insert(p_root_, data, units);
}

void bst::in_order_traversal() const {
	in_order_traversal(p_root_);
}

// pre-condition: tree is not empty
transaction_node &bst::find_smallest() const {
	// must cast to transaction_node first
	transaction_node *p_curr = dynamic_cast<transaction_node *>(p_root_);

	// left is always smaller
	while (p_curr->get_left() != nullptr)
		p_curr = dynamic_cast<transaction_node *>(p_curr->get_left());

	return *p_curr;
}

// pre-condition: tree is not empty
transaction_node &bst::find_largest() const {
	transaction_node *p_curr = dynamic_cast<transaction_node *>(p_root_);

	// right is always larger
	while (p_curr->get_right() != nullptr)
		p_curr = dynamic_cast<transaction_node *>(p_curr->get_right());

	return *p_curr;
}

void bst::destroy_tree(node *const &p_curr) {
	if (p_curr == nullptr) return;

	// post-order traversal
	destroy_tree(p_curr->get_left());
	destroy_tree(p_curr->get_right());

	delete p_curr;
}

void bst::insert(node *&p_curr, std::string const &data, int const &units) {
	// base case - re-assign p_curr directly through reference
	if (p_curr == nullptr) {
		p_curr = new transaction_node(data, units);
		return;
	}

	// left/right based on units comparison
	insert(units < dynamic_cast<transaction_node *>(p_curr)->get_units()
		   ? p_curr->get_left()
		   : p_curr->get_right(),
	       data, units);
}

void bst::in_order_traversal(node *const &p_curr) const {
	if (p_curr == nullptr) return;

	in_order_traversal(p_curr->get_left());
	p_curr->print_data();
	in_order_traversal(p_curr->get_right());
}
