#pragma once

#include <functional>
#include <iostream>

/// generic linked list class
template <typename T>
class LinkedList {
	private:
		/// private node class
		class Node {
			public:
				T data;
				Node *p_next;

				Node(const T &data)
				    : data(data), p_next(nullptr) {}
		};

		Node *p_head_;
		Node *p_tail_;
		int length_;

	public:
		LinkedList() : p_head_(nullptr), p_tail_(nullptr), length_(0) {}
		LinkedList(const LinkedList<T> &other);
		LinkedList(const std::initializer_list<T> &data);
		~LinkedList();

		void clear();
		int length() const {
			return length_;
		}
		T const &nth(int n) const;

		void push_front(const T &data);
		void push_back(const T &data);
		void remove(std::function<bool(const T &data)> const &f);

		template <typename U>
		LinkedList<U> map(std::function<U(const T &data)> const &f);
		void
		for_each(std::function<void(const T &data)> const &f) const;
		void display() const;

		// https://stackoverflow.com/a/3279550/14946864
		LinkedList<T> &operator=(LinkedList<T> other);
		template <typename U>
		friend void swap(LinkedList<U> &a, LinkedList<U> &b);
};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
	p_head_ = p_tail_ = nullptr;
	length_ = 0;

	for (Node *p_curr = other.p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next) {
		push_back(p_curr->data);
	}
}

template <typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T> &data) {
	p_head_ = p_tail_ = nullptr;
	length_ = 0;

	for (const T &d : data) {
		push_back(d);
	}
}

template <typename T>
LinkedList<T>::~LinkedList() {
	clear();
}

template <typename T>
void LinkedList<T>::clear() {
	for (Node *p_curr = p_head_, *p_next; p_curr != nullptr;
	     p_curr = p_next) {
		p_next = p_curr->p_next;
		delete p_curr;
	}

	p_head_ = p_tail_ = nullptr;
	length_ = 0;
}

template <typename T>
const T &LinkedList<T>::nth(int n) const {
	int i = 0;
	for (Node *p_curr = p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next, ++i) {
		if (i == n) {
			return p_curr->data;
		}
	}

	throw "index out of bounds";
}

template <typename T>
void LinkedList<T>::push_front(const T &data) {
	Node *p_node = new Node(data);

	p_node->p_next = p_head_;
	p_head_ = p_node;

	if (p_tail_ == nullptr) {
		p_tail_ = p_head_;
	}

	++length_;
}

template <typename T>
void LinkedList<T>::push_back(const T &data) {
	Node *p_node = new Node(data);

	if (p_head_ == nullptr) {
		p_head_ = p_tail_ = p_node;
		length_ = 1;
		return;
	}

	p_tail_->p_next = p_node;
	p_tail_ = p_node;
	++length_;
}

template <typename T>
void LinkedList<T>::remove(const std::function<bool(const T &data)> &f) {
	if (p_head_ == nullptr) {
		throw "list is empty";
	}

	if (f(p_head_->data)) {
		Node *p_next = p_head_->p_next;
		delete p_head_;
		p_head_ = p_next;

		--length_;

		return;
	}

	for (Node *p_curr = p_head_;
	     // look awhohead "twice"
	     p_curr != nullptr && p_curr->p_next != nullptr;
	     p_curr = p_curr->p_next) {
		// use a predicate f to find node to remove
		if (!f(p_curr->p_next->data)) {
			continue;
		}

		Node *p_next = p_curr->p_next->p_next;
		delete p_curr->p_next;
		p_curr->p_next = p_next;

		--length_;

		return;
	}

	throw "item not found";
}

template <typename T>
template <typename U>
LinkedList<U> LinkedList<T>::map(const std::function<U(const T &data)> &f) {
	LinkedList<U> res;

	for (Node *p_curr = p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next) {
		res.push_back(f(p_curr->data));
	}

	return res;
}

template <typename T>
void LinkedList<T>::for_each(
    const std::function<void(const T &data)> &f) const {
	for (Node *p_curr = p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next) {
		f(p_curr->data);
	}
}

template <typename T>
void LinkedList<T>::display() const {
	for_each([](const T &data) { std::cout << data << std::endl; });
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> other) {
	swap(*this, other);

	return *this;
}

template <typename T>
void swap(LinkedList<T> &a, LinkedList<T> &b) {
	std::swap(a.p_head_, b.p_head_);
	std::swap(a.length_, b.length_);
}
