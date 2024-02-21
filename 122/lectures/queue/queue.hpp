#pragma once

#include "node.hpp"
#include <iostream>
#include <string>

class Queue {
	public:
		Queue(Node *head = nullptr, Node *tail = nullptr);
		bool enqueue(std::string printJob);

	private:
		Node *head;
		Node *tail;
};
