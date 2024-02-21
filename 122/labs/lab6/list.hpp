#pragma once

#include <iostream>

#include "listnode.hpp"

class List {
	public:
		List();
		List(const List &copyList);

		~List();

		List &operator=(const List &other);

		ListNode *getHead() const;

		void setHead(ListNode *const head);

		bool insertAtFront(const int data);
		bool insertInOrder(const int data);
		bool insertAtEnd(const int data);

		bool isEmpty() const;

		int deleteAtFront();
		bool deleteNode(const int target);
		int deleteAtEnd();

		void printList();

	private:
		ListNode *head;

		void destroyList();
		void destroyListHelper(ListNode *const node);
};
