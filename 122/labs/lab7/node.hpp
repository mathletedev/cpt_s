#pragma once

template <class T>
class Node {
	public:
		Node(const T &data);

		T getData() const;
		Node<T> *getNext() const;

		void setNext(Node<T> *&next);

	private:
		T data;
		Node<T> *next;
};

template <class T>
Node<T>::Node(const T &data) {
	this->data = data;
	next = nullptr;
}

template <class T>
T Node<T>::getData() const {
	return data;
}

template <class T>
Node<T> *Node<T>::getNext() const {
	return next;
}

template <class T>
void Node<T>::setNext(Node<T> *&next) {
	this->next = next;
}
