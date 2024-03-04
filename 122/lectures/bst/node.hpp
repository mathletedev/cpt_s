#pragma once

template <class T>
class node {
	public:
		node(const T &data);

		T get_data() const;
		node<T> *get_left() const;
		node<T> *get_right() const;

		void set_left(node<T> *const &p_node);
		void set_right(node<T> *const &p_node);

	private:
		T data_;
		node<T> *p_left_;
		node<T> *p_right_;
};

template <class T>
node<T>::node(const T &data) {
	data_ = data;
}

template <class T>
T node<T>::get_data() const {
	return data_;
}

template <class T>
node<T> *node<T>::get_left() const {
	return p_left_;
}

template <class T>
node<T> *node<T>::get_right() const {
	return p_right_;
}

template <class T>
void node<T>::set_left(node<T> *const &p_node) {
	p_left_ = p_node;
}

template <class T>
void node<T>::set_right(node<T> *const &p_node) {
	p_right_ = p_node;
}
