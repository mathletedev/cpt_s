#pragma once

#include "linked_list.hpp"
#include <functional>

// WARN: msort() works; however, due to functional design, it runs in O(n^2)
// time since drop() and take() are unoptimised
// WARN: use LinkedList::msort() instead for O(n log n) time
namespace sorting {
	// merge sort
	template <typename T>
	LinkedList<T>
	msort(LinkedList<T> const &xs,
	      std::function<bool(const T &x, const T &y)> const &f);
	// insert sort
	template <typename T>
	LinkedList<T>
	isort(LinkedList<T> const &xs,
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
sorting::msort(LinkedList<T> const &xs,
	       std::function<bool(const T &x, const T &y)> const &f) {
	if (xs.length() <= 1) {
		return xs;
	}

	LinkedList<T> left = xs.take(xs.length() / 2);
	LinkedList<T> right = xs.drop(xs.length() / 2);
	return merge(msort(left, f), msort(right, f), f);
}

template <typename T>
LinkedList<T>
sorting::isort(LinkedList<T> const &xs,
	       std::function<bool(const T &x, const T &y)> const &f) {
	LinkedList<T> res = xs;
	res.isort(f);
	return res;
}
