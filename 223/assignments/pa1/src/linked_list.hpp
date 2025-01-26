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

				Node(T const &data)
				    : data(data), p_next(nullptr) {}
		};

		Node *p_head_;
		int length_;

	public:
		LinkedList() : p_head_(nullptr), length_(0) {}
		~LinkedList();

		void clear();
		int length() const {
			return this->length_;
		}
		T const &nth(int n) const;

		void push(T const &data);
		void remove(std::function<bool(T const &data)> const &f);

		template <typename U>
		LinkedList<U> map(std::function<U(T const &data)> const &f);
		void
		for_each(std::function<void(T const &data)> const &f) const;
		void display() const;

		LinkedList<T> &operator=(LinkedList<T> const &other);
};

template <typename T>
LinkedList<T>::~LinkedList() {
	this->clear();
}

template <typename T>
void LinkedList<T>::clear() {
	for (Node *p_curr = this->p_head_, *p_next; p_curr != nullptr;
	     p_curr = p_next) {
		p_next = p_curr->p_next;
		delete p_curr;
	}

	this->p_head_ = nullptr;
	this->length_ = 0;
}

template <typename T>
T const &LinkedList<T>::nth(int n) const {
	int i = 0;
	for (Node *p_curr = this->p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next, ++i) {
		if (i == n) {
			return p_curr->data;
		}
	}

	throw "index out of bounds";
}

template <typename T>
void LinkedList<T>::push(T const &data) {
	Node *p_node = new Node(data);

	p_node->p_next = this->p_head_;
	this->p_head_ = p_node;

	++this->length_;
}

template <typename T>
void LinkedList<T>::remove(std::function<bool(T const &data)> const &f) {
	if (this->p_head_ == nullptr) {
		throw "list is empty";
	}

	if (f(this->p_head_->data)) {
		Node *p_next = this->p_head_->p_next;
		delete this->p_head_;
		this->p_head_ = p_next;

		--this->length_;

		return;
	}

	for (Node *p_curr = this->p_head_;
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

		--this->length_;

		return;
	}

	throw "item not found";
}

template <typename T>
template <typename U>
LinkedList<U> LinkedList<T>::map(std::function<U(T const &data)> const &f) {
	LinkedList<U> res;

	for (Node *p_curr = this->p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next) {
		res.push(f(p_curr->data));
	}

	return res;
}

template <typename T>
void LinkedList<T>::for_each(
    std::function<void(T const &data)> const &f) const {
	for (Node *p_curr = this->p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next) {
		f(p_curr->data);
	}
}

template <typename T>
void LinkedList<T>::display() const {
	for_each([](T const &data) { std::cout << data << std::endl; });
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> const &other) {
	if (this == &other) {
		return *this;
	}

	this->clear();
	for (Node *p_curr = other.p_head_; p_curr != nullptr;
	     p_curr = p_curr->p_next) {
		this->push(p_curr->data);
	}

	return *this;
}
