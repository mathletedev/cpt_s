#include "bst.hpp"

bst::bst() {
	p_root_ = nullptr;
}

bst::~bst() {
	destroy(p_root_);
}

void bst::insert(const std::string &data) {
	if (p_root_ == nullptr) {
		p_root_ = new bst_node(data);
		return;
	}
	insert(p_root_, data);
}

void bst::inorder_traversal() const {
	inorder_traversal(p_root_);
}

void bst::preorder_traversal() const {
	preorder_traversal(p_root_);
}

void bst::postorder_traversal() const {
	postorder_traversal(p_root_);
}

void bst::sort_into(std::vector<std::string> &names) {
	sort_into(names, p_root_);
}

std::ostream &operator<<(std::ostream &lhs, bst const &rhs) {
	rhs.print(lhs, rhs.p_root_);

	return lhs;
}

void bst::insert(bst_node *const &curr, const std::string &data) {
	if (data == curr->get_data()) return;

	if (data < curr->get_data()) {
		if (curr->get_left() != nullptr) {
			insert(curr->get_left(), data);
			return;
		}

		bst_node *p_node = new bst_node(data);
		curr->set_left(p_node);
	} else {
		if (curr->get_right() != nullptr) {
			insert(curr->get_right(), data);
			return;
		}

		bst_node *p_node = new bst_node(data);
		curr->set_right(p_node);
	}
}

void bst::inorder_traversal(const bst_node *const &curr) const {
	if (curr == nullptr) return;

	inorder_traversal(curr->get_left());
	std::cout << curr->get_data() << std::endl;
	inorder_traversal(curr->get_right());
}

void bst::preorder_traversal(const bst_node *const &curr) const {
	if (curr == nullptr) return;

	std::cout << curr->get_data() << std::endl;
	preorder_traversal(curr->get_left());
	preorder_traversal(curr->get_right());
}

void bst::postorder_traversal(const bst_node *const &curr) const {
	if (curr == nullptr) return;

	std::cout << curr->get_data() << std::endl;
	postorder_traversal(curr->get_left());
	postorder_traversal(curr->get_right());
}

void bst::destroy(bst_node *const &curr) {
	if (curr == nullptr) return;

	destroy(curr->get_left());
	destroy(curr->get_right());
	delete curr;
}

void bst::sort_into(std::vector<std::string> &names,
		    const bst_node *const &curr) const {
	if (curr == nullptr) return;

	sort_into(names, curr->get_left());
	names.push_back(curr->get_data());
	sort_into(names, curr->get_right());
}

void bst::print(std::ostream &stream, const bst_node *const &curr) const {
	if (curr == nullptr) return;

	print(stream, curr->get_left());
	stream << *curr << " -> ";
	print(stream, curr->get_right());
}
