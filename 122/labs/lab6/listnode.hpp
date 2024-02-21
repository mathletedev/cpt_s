#pragma once

#include <iostream>

class ListNode {
	public:
		ListNode(int data = 0);
		ListNode(const ListNode &other);

		~ListNode();

		int getData() const;
		ListNode *getNext() const;

		void setData(const int data);
		void setNext(ListNode *const next);

	private:
		int data;
		ListNode *next;
};
