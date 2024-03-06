#pragma once

#include <iostream>
#include <string>

class bst_node {
	public:
		bst_node(const std::string &data);

		~bst_node();

		std::string get_data() const;
		bst_node *get_left() const;
		bst_node *get_right() const;

		void set_left(bst_node *const &p_left);
		void set_right(bst_node *const &p_right);

		friend std::ostream &operator<<(std::ostream &lhs,
						const bst_node &rhs);

	private:
		std::string data_;
		bst_node *p_left_;
		bst_node *p_right_;
};
