#pragma once

#include "linked_list.hpp"
#include <functional>

namespace sorting {
	// merge sort
	template <typename T>
	LinkedList<T>
	msort(LinkedList<T> const &list,
	      std::function<bool(const T &x, const T &y)> const &f);
} // namespace sorting

template <typename T>
LinkedList<T> merge(LinkedList<T> const &xs, LinkedList<T> const &ys,
		    std::function<bool(const T &x, const T &y)> const &f) {
	if (ys.length() == 0) {
		return xs;
	}
	if (xs.length() == 0) {
		return ys;
	}

	T x = xs.nth(0);
	T y = ys.nth(0);
	if (f(x, y)) {
		LinkedList<T> res = merge(xs.drop(1), ys, f);
		res.push_front(x);
		return res;
	}
	LinkedList<T> res = merge(xs, ys.drop(1), f);
	res.push_front(y);
	return res;
}

template <typename T>
LinkedList<T>
sorting::msort(LinkedList<T> const &list,
	       std::function<bool(const T &x, const T &y)> const &f) {
	if (list.length() <= 1) {
		return list;
	}

	LinkedList<T> left = list.take(list.length() / 2);
	LinkedList<T> right = list.drop(list.length() / 2);
	return merge(msort(left, f), msort(right, f), f);
}
