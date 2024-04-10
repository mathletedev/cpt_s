#pragma once

#include "list.hpp"

template <class T>
class queue : private list<T> {
	public:
		queue();

		void enqueue(T const &data);
		bool dequeue(T &data);
		bool is_empty() const;
};

template <class T>
queue<T>::queue() : list<T>() {}

template <class T>
void queue<T>::enqueue(T const &data) {
	list<T>::insert_at_back(data);
}

template <class T>
bool queue<T>::dequeue(T &data) {
	return list<T>::remove_from_front(data);
}

template <class T>
bool queue<T>::is_empty() const {
	return list<T>::is_empty();
}
