#pragma once

#include <algorithm>
#include <cassert>
#include <utility>

template <typename K, typename V>
class AvlMap {
	public:
		// define Iterator to be used by find_()
		class Iterator;

	private:
		class Node {
			public:
				std::pair<K, V> data;
				Node *p_left, *p_right, *p_parent;
				int height;

				Node(const K &k, const V &v)
				    : data(k, v), p_left(nullptr),
				      p_right(nullptr), p_parent(nullptr),
				      height(0) {}
		};

		Node *root_;

		// finds smallest node that is greater than p_node
		Node *successor_(const Node *p_node) const;
		void destroy_(Node *p_node);

		int unwrap_height_(const Node *p_node) const {
			return p_node ? p_node->height : 0;
		}

		void insert_(Node *&p_node, Node *p_prev, const K &key,
			     const V &value);
		void erase_(Node *&p_node, const K &key);
		Iterator find_(Node *p_node, const K &key) const;

	public:
		AvlMap() : root_(nullptr) {}

		~AvlMap() {
			destroy_(root_);
		}

		void insert(const K &key, const V &value) {
			insert_(root_, nullptr, key, value);
		}

		void erase(const K &key) {
			erase_(root_, key);
		}

		Iterator find(const K &key) const {
			return find_(root_, key);
		}

		Iterator begin() const;

		Iterator end() const {
			return Iterator(nullptr);
		}

		class Iterator {
			private:
				Node *p_curr_;

			public:
				Iterator(Node *p_node) : p_curr_(p_node) {}

				std::pair<K, V> &operator*() {
					assert(p_curr_);
					return p_curr_->data;
				}

				bool operator==(const Iterator &other) const {
					return p_curr_ == other.p_curr_;
				}

				bool operator!=(const Iterator &other) const {
					return p_curr_ != other.p_curr_;
				}

				Iterator &operator++();
				Iterator &operator--();
		};
};

template <typename K, typename V>
typename AvlMap<K, V>::Node *
AvlMap<K, V>::successor_(const Node *p_node) const {
	assert(p_node);

	// find smallest node that is greater than p_node (leftmost of right
	// subtree)
	Node *p_curr;
	for (p_curr = p_node->p_right; p_curr && p_curr->p_left;
	     p_curr = p_curr->p_left)
		;

	return p_curr;
}

template <typename K, typename V>
void AvlMap<K, V>::destroy_(Node *p_node) {
	if (!p_node) {
		return;
	}

	destroy_(p_node->p_left);
	destroy_(p_node->p_right);
	delete p_node;
}

template <typename K, typename V>
void AvlMap<K, V>::insert_(Node *&p_node, Node *p_prev, const K &key,
			   const V &value) {
	if (!p_node) {
		p_node = new Node(key, value);
		p_node->p_parent = p_prev;
		return;
	}

	if (key == p_node->data.first) {
		p_node->data.second = value;
		return;
	}

	Node *&p_next =
	    key < p_node->data.first ? p_node->p_left : p_node->p_right;
	insert_(p_next, p_node, key, value);

	// update height
	p_node->height = std::max(unwrap_height_(p_node->p_left),
				  unwrap_height_(p_node->p_right)) +
			 1;
}

template <typename K, typename V>
void AvlMap<K, V>::erase_(Node *&p_node, const K &key) {
	if (!p_node) {
		throw "key not found";
	}

	// if key not found, continue searching
	if (key != p_node->data.first) {
		Node *&p_next =
		    key < p_node->data.first ? p_node->p_left : p_node->p_right;
		erase_(p_next, key);

		p_node->height = std::max(unwrap_height_(p_node->p_left),
					  unwrap_height_(p_node->p_right)) +
				 1;
		return;
	}

	Node *p_tmp = nullptr;
	bool incomplete = false;
	// case 1: 0 children or only right child
	if (!p_node->p_left) {
		p_tmp = p_node->p_right;
		incomplete = true;
	}
	// case 2: only left child
	else if (!p_node->p_right) {
		p_tmp = p_node->p_left;
		incomplete = true;
	}

	if (incomplete) {
		if (p_tmp) {
			p_tmp->p_parent = p_node->p_parent;
		}
		delete p_node;
		p_node = p_tmp;
		return;
	}

	// case 3: both children
	Node *p_succ = successor_(p_node);
	p_node->data.first = p_succ->data.first;
	p_node->data.second = p_succ->data.second;
	erase_(p_node->p_right, p_succ->data.first);
}

template <typename K, typename V>
typename AvlMap<K, V>::Iterator AvlMap<K, V>::find_(Node *p_node,
						    const K &key) const {
	if (!p_node) {
		return Iterator(nullptr);
	}

	if (key == p_node->data.first) {
		return Iterator(p_node);
	}

	if (key < p_node->data.first) {
		return find_(p_node->p_left, key);
	}

	return find_(p_node->p_right, key);
}

template <typename K, typename V>
typename AvlMap<K, V>::Iterator AvlMap<K, V>::begin() const {
	if (!root_) {
		return Iterator(nullptr);
	}

	Node *p_curr;
	for (p_curr = root_; p_curr->p_left; p_curr = p_curr->p_left)
		;

	return Iterator(p_curr);
}

template <typename K, typename V>
typename AvlMap<K, V>::Iterator &AvlMap<K, V>::Iterator::operator++() {
	assert(p_curr_);

	// if right child exists, find smallest node in right subtree
	if (p_curr_->p_right) {
		for (p_curr_ = p_curr_->p_right; p_curr_->p_left;
		     p_curr_ = p_curr_->p_left)
			;

		return *this;
	}

	// else find first parent that is to the right
	Node *p_parent = p_curr_->p_parent;
	while (p_parent && p_curr_ == p_parent->p_right) {
		p_curr_ = p_parent;
		p_parent = p_parent->p_parent;
	}
	p_curr_ = p_parent;

	return *this;
}

template <typename K, typename V>
typename AvlMap<K, V>::Iterator &AvlMap<K, V>::Iterator::operator--() {
	assert(p_curr_);

	if (p_curr_->p_left) {
		for (p_curr_ = p_curr_->p_left; p_curr_->p_right;
		     p_curr_ = p_curr_->p_right)
			;

		return *this;
	}

	Node *p_parent = p_curr_->p_parent;
	while (p_parent && p_curr_ == p_parent->p_left) {
		p_curr_ = p_parent;
		p_parent = p_parent->p_parent;
	}
	p_curr_ = p_parent;

	return *this;
}
