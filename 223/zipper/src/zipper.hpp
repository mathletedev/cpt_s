#pragma once

#include "list.hpp"

template <typename T>
struct ListZipper {
		ListPtr(T) left;
		ListPtr(T) right;

		ListZipper(ListPtr(T) left, ListPtr(T) right)
		    : left(left), right(right) {};
		ListZipper(ListPtr(T) xs) : left(Nil), right(xs) {};
};

template <typename T>
T extract(const ListZipper<T> &z) {
	return z.right->head;
}

template <typename T>
ListZipper<T> left(const ListZipper<T> &z) {
	return ListZipper<T>(z.left->tail, cons(z.left->head, z.right));
}

template <typename T>
ListZipper<T> right(const ListZipper<T> &z) {
	return ListZipper<T>(cons(z.right->head, z.left), z.right->tail);
}

template <typename T>
ListZipper<T> insert(const ListZipper<T> &z, T x) {
	return ListZipper<T>(z.left, cons(x, z.right));
}

template <typename T>
ListZipper<T> drop(const ListZipper<T> &z) {
	return ListZipper<T>(z.left, z.right->tail);
}

template <typename T>
ListZipper<T> modify(const ListZipper<T> &z, T x) {
	return ListZipper<T>(z.left, cons(x, z.right->tail));
}

template <typename T>
ListPtr(T) to_list_(ListPtr(T) & left, ListPtr(T) & right) {
	if (!left) {
		return right;
	}

	return to_list_(left->tail, cons(left->head, right));
}

template <typename T>
ListPtr(T) to_list(const ListZipper<T> &z) {
	return to_list_(z.left, z.right);
}
