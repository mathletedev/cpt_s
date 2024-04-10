#pragma once

template <class T>
class list;

template <class T>
class list_node {
		friend class list<T>;

	public:
		list_node(T const &data);

		T const &get_data() const;

	private:
		T data_;
		list_node<T> *p_next_;
};

template <class T>
list_node<T>::list_node(T const &data) {
	data_ = data;
	p_next_ = nullptr;
}
