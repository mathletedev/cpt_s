#pragma once

#include <iostream>
#include <memory>

#define Nil nullptr
#define ListPtr(T) const std::shared_ptr<const List<T>>

template <typename T>
struct List {
		const T head;
		ListPtr(T) tail;

		List(T head, ListPtr(T) tail) : head(head), tail(tail) {}
};

template <typename T>
ListPtr(T) cons(T head, std::nullptr_t) {
	return std::make_shared<const List<T>>(head, Nil);
}

template <typename T>
ListPtr(T) cons(T head, ListPtr(T) tail) {
	return std::make_shared<const List<T>>(head, tail);
}

template <typename T>
void print_(ListPtr(T) & xs) {
	if (!xs) {
		return;
	}

	std::cout << xs->head;
	if (!xs->tail) {
		return;
	}

	std::cout << ",";
	print_(xs->tail);
}

template <typename T>
void print(ListPtr(T) & xs) {
	std::cout << "[";
	print_(xs);
	std::cout << "]" << std::endl;
}
