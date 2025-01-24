#pragma once

template <typename T>
class ListNode {
	public:
		T data;
		ListNode<T> *p_next;

		ListNode(T const &data) {
			this->data = data;
			this->p_next = nullptr;
		}
};
