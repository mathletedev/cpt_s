#include "listnode.hpp"

ListNode::ListNode(int data) {
	this->data = data;
	this->next = nullptr;
}

ListNode::ListNode(const ListNode &other) {
	data = other.data;
	next = other.next;
}

ListNode::~ListNode() {}

int ListNode::getData() const {
	return data;
}

ListNode *ListNode::getNext() const {
	return next;
}

void ListNode::setData(const int data) {
	this->data = data;
}

void ListNode::setNext(ListNode *const next) {
	this->next = next;
}
