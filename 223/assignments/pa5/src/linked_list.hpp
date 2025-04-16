// NOTE: copied from PA1
#pragma once

#include <cassert>
#include <functional>
#include <iostream>

// generic linked list class
template <typename T>
class LinkedList {
	private:
		// private node class
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

		// removes all elements from the list
		void clear();
		// returns the length of the list
		int length() const {
			return length_;
		}
		// returns the nth element of the list
		T const &nth(int n) const;

		// appends an element to the head of the list
		void push_front(const T &data);
		// appends an element to the tail of the list
		void push_back(const T &data);
		// removes the head of the list and returns its value
		T pop_front();
		// removes the first element that satisfies the predicate
		void remove(std::function<bool(const T &data)> const &f);

		// returns a new list with the first n elements
		LinkedList<T> take(int n) const;
		// returns a new list with the last n elements
		LinkedList<T> drop(int n) const;

		// returns a new list with all elements that satisfy the
		// predicate
		LinkedList<T>
		filter(std::function<bool(const T &data)> const &f) const;
		// maps f onto each element of the list, returns the new list
		template <typename U>
		LinkedList<U>
		map(std::function<U(const T &data)> const &f) const;
		// folds the list from right to left
		template <typename U>
		U foldr(std::function<U(U, const T &data)> const &f,
			U init) const;
		// calls f on each element of the list
		void
		for_each(std::function<void(const T &data)> const &f) const;
		// returns true if any element satisfies the predicate
		bool any(std::function<bool(const T &data)> const &f) const;
		// returns true if element is in the list
		bool elem(const T &data) const;
		// prints each element of the list to stdout
		void display() const;

		// https://stackoverflow.com/a/3279550/14946864
		LinkedList<T> &operator=(LinkedList<T> other);
		template <typename U>
		friend void swap(LinkedList<U> &a, LinkedList<U> &b);

		template <typename U>
		friend bool operator==(const LinkedList<U> &xs,
				       const LinkedList<U> &ys);
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

	if (p_head_ == nullptr) {
		p_head_ = p_tail_ = p_node;
		length_ = 1;
		return;
	}

	p_node->p_next = p_head_;
	p_head_ = p_node;
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
T LinkedList<T>::pop_front() {
	assert(p_head_ != nullptr);

	T data = p_head_->data;

	Node *p_next = p_head_->p_next;
	delete p_head_;
	p_head_ = p_next;
	--length_;

	return data;
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
	     // look ahead "twice"
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
LinkedList<T> LinkedList<T>::take(int n) const {
	assert(n <= length_);
	LinkedList<T> res;

	Node *p_curr = p_head_;
	for (int i = 0; i < n; ++i, p_curr = p_curr->p_next) {
		res.push_back(p_curr->data);
	}

	return res;
}

template <typename T>
LinkedList<T> LinkedList<T>::drop(int n) const {
	assert(n <= length_);
	LinkedList<T> res;

	Node *p_curr = p_head_;
	// skip first n elements
	for (int i = 0; i < n; ++i, p_curr = p_curr->p_next) {
	}
	for (; p_curr != nullptr; p_curr = p_curr->p_next) {
		res.push_back(p_curr->data);
	}

	return res;
}

template <typename T>
LinkedList<T>
LinkedList<T>::filter(std::function<bool(const T &data)> const &f) const {
	LinkedList<T> res;
	for_each([&res, &f](const T &data) {
		if (f(data)) {
			res.push_back(data);
		}
	});

	return res;
}

template <typename T>
template <typename U>
LinkedList<U>
LinkedList<T>::map(const std::function<U(const T &data)> &f) const {
	LinkedList<U> res;
	for_each([&res, &f](const T &data) { res.push_back(f(data)); });

	return res;
}

template <typename T>
template <typename U>
U LinkedList<T>::foldr(const std::function<U(U, const T &data)> &f,
		       U init) const {
	U res = init;

	for_each([&res, &f](const T &data) { res = f(res, data); });

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
bool LinkedList<T>::any(std::function<bool(const T &data)> const &f) const {
	bool res = false;
	for_each([&res, &f](const T &data) {
		if (f(data)) {
			res = true;
		}
	});

	return res;
}

template <typename T>
bool LinkedList<T>::elem(const T &data) const {
	return any([&data](const T &x) { return x == data; });
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
	std::swap(a.p_tail_, b.p_tail_);
	std::swap(a.length_, b.length_);
}

template <typename T>
bool operator==(const LinkedList<T> &xs, const LinkedList<T> &ys) {
	if (xs.length() != ys.length()) {
		return false;
	}

	auto p_x = xs.p_head_;
	auto p_y = ys.p_head_;
	for (int i = 0; i < xs.length();
	     ++i, p_x = p_x->p_next, p_y = p_y->p_next) {
		if (p_x->data != p_y->data) {
			return false;
		}
	}

	return true;
}
