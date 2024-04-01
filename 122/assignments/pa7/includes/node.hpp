#pragma once

template <class T>
class node {
	public:
		node(T const &data);

		T const &get_data() const;
		node<T> *const &get_next() const;

		void set_data(T const &data);
		void set_next(node<T> *const &p_next);

	private:
		T data_;
		node<T> *p_next_;
};

template <class T>
node<T>::node(T const &data) {
	data_ = data;
	p_next_ = nullptr;
}

template <class T>
T const &node<T>::get_data() const {
	return data_;
}

template <class T>
node<T> *const &node<T>::get_next() const {
	return p_next_;
}

template <class T>
void node<T>::set_data(T const &data) {
	data_ = data;
}

template <class T>
void node<T>::set_next(node<T> *const &p_next) {
	p_next_ = p_next;
}
