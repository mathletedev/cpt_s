#pragma once

#include "bstnode.hpp"
#include <iostream>
#include <vector>

class bst {
	public:
		bst();

		~bst();

		void insert(const std::string &data);
		void inorder_traversal() const;
		void preorder_traversal() const;
		void postorder_traversal() const;
		void sort_into(std::vector<std::string> &names);

		friend std::ostream &operator<<(std::ostream &lhs,
						const bst &rhs);

	private:
		bst_node *p_root_;

		void insert(bst_node *const &curr, const std::string &data);
		void inorder_traversal(const bst_node *const &curr) const;
		void preorder_traversal(const bst_node *const &curr) const;
		void postorder_traversal(const bst_node *const &curr) const;
		void destroy(bst_node *const &curr);
		void sort_into(std::vector<std::string> &names,
			       const bst_node *const &curr) const;
		void print(std::ostream &stream,
			   const bst_node *const &curr) const;
};
