#pragma once

#include "list_node.hpp"
#include <functional>

template <typename T>
class LinkedList {
	public:
		LinkedList() {
			this->p_head_ = nullptr;
		}

		~LinkedList() {
			ListNode<T> *p_curr, *p_next;
			for (p_curr = this->p_head_; p_curr != nullptr;
			     p_curr = p_next) {
				p_next = p_curr->p_next;
				delete p_curr;
			}
		}

		T const &nth(int n) const {
			int i = 0;
			for (ListNode<T> *p_curr = this->p_head_;
			     p_curr != nullptr; p_curr = p_curr->p_next, ++i) {
				if (i == n) {
					return p_curr->data;
				}
			}

			throw "index out of bounds";
		}

		void push(T const &data) {
			ListNode<T> *p_node = new ListNode<T>(data);

			p_node->p_next = this->p_head_;
			this->p_head_ = p_node;
		}

		// use a predicate to find node to remove
		void remove(std::function<bool(T const &data)> const &f) {
			if (this->p_head_ == nullptr) {
				throw "list is empty";
			}

			if (f(this->p_head_->data)) {
				ListNode<T> *p_next = this->p_head_->p_next;
				delete this->p_head_;
				this->p_head_ = p_next;

				return;
			}

			ListNode<T> *p_curr;
			for (p_curr = this->p_head_;
			     // look ahead "twice"
			     p_curr != nullptr && p_curr->p_next != nullptr;
			     p_curr = p_curr->p_next) {
				if (!f(p_curr->p_next->data)) {
					continue;
				}

				ListNode<T> *p_next = p_curr->p_next->p_next;
				delete p_curr->p_next;
				p_curr->p_next = p_next;

				return;
			}

			throw "item not found";
		}

	private:
		ListNode<T> *p_head_;
};
