#pragma once

#include <iostream>
#include <string>

class Node {
	public:
		Node(std::string printJob);

		std::string getPrintJob() const;

		Node *getNext() const;
		void setNext(Node *const next);

	private:
		std::string printJob;
		Node *next;
};
