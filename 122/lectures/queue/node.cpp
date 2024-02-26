#include "node.hpp"

Node::Node(std::string printJob) {
	this->printJob = printJob;
	this->next = nullptr;
}

std::string Node::getPrintJob() const {
	return printJob;
}

Node *Node::getNext() const {
	return next;
}

void Node::setNext(Node *const next) {
	this->next = next;
}
