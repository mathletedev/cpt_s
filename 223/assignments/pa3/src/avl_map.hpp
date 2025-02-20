#pragma once

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
				Node *p_left, *p_right;
				int bf;

				Node(const K &k, const V &v)
				    : data(k, v), p_left(nullptr),
				      p_right(nullptr), bf(0) {}
		};

		Node *root_;

		Node *successor_(const Node *p_node);
		void destroy_(Node *p_node);

		void insert_(Node *&p_node, const K &key, const V &value);
		void erase_(Node *&p_node, const K &key);
		Iterator find_(Node *p_node, const K &key);

	public:
		AvlMap() : root_(nullptr) {}
		~AvlMap() {
			destroy_(root_);
		}

		void insert(const K &key, const V &value) {
			insert_(root_, key, value);
		}
		void erase(const K &key) {
			erase_(root_, key);
		}
		Iterator find(const K &key) {
			return find_(root_, key);
		}

		class Iterator {
			private:
				Node *p_curr_;

			public:
				Iterator(Node *p_node) : p_curr_(p_node) {}

				std::pair<K, V> &operator*() {
					assert(p_curr_ != nullptr);
					return p_curr_->data;
				}
		};
};

template <typename K, typename V>
typename AvlMap<K, V>::Node *AvlMap<K, V>::successor_(const Node *p_node) {
	assert(p_node != nullptr);

	// find smallest node that is greater than p_node (leftmost of right
	// subtree)
	Node *p_curr;
	for (p_curr = p_curr->p_right;
	     p_curr != nullptr && p_curr->p_left != nullptr;
	     p_curr = p_curr->p_left)
		;

	return p_curr;
}

template <typename K, typename V>
void AvlMap<K, V>::destroy_(Node *p_node) {
	if (p_node == nullptr) {
		return;
	}

	destroy_(p_node->p_left);
	destroy_(p_node->p_right);
	delete p_node;
}

template <typename K, typename V>
void AvlMap<K, V>::insert_(Node *&p_node, const K &key, const V &value) {
	if (p_node == nullptr) {
		p_node = new Node(key, value);
		return;
	}

	if (key == p_node->data.first) {
		p_node->data.second = value;
		return;
	}

	if (key < p_node->data.first) {
		insert_(p_node->p_left, key, value);
		--p_node->bf;
		return;
	}

	insert_(p_node->p_right, key, value);
	++p_node->bf;
}

template <typename K, typename V>
void AvlMap<K, V>::erase_(Node *&p_node, const K &key) {
	if (p_node == nullptr) {
		throw "key not found";
	}

	// if key not found, continue searching
	if (key < p_node->data.first) {
		erase_(p_node->p_left, key);
		++p_node->bf;
		return;
	}
	if (key > p_node->data.first) {
		erase_(p_node->p_right, key);
		--p_node->bf;
		return;
	}

	// case 1: 0 children or only right child
	if (p_node->p_left == nullptr) {
		Node *p_tmp = p_node->p_right;
		delete p_node;
		p_node = p_tmp;
	}
	// case 2: only left child
	if (p_node->p_right == nullptr) {
		Node *p_tmp = p_node->p_left;
		delete p_node;
		p_node = p_tmp;
	}
	// case 3: both children
	Node *p_succ = successor_(p_node);
	p_node->data.first = p_succ->data.first;
	p_node->data.second = p_succ->data.second;
	erase_(p_node->p_right, p_succ->data.first);
}

template <typename K, typename V>
typename AvlMap<K, V>::Iterator AvlMap<K, V>::find_(Node *p_node,
						    const K &key) {
	if (p_node == nullptr) {
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
