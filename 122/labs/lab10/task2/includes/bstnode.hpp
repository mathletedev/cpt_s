#pragma once

template <class T>
class bstnode {
	public:
		bstnode(T const &data);

		T get_data() const;
		bstnode<T> *get_left() const;
		bstnode<T> *get_right() const;

		void set_data(T const data);
		void set_left(bstnode<T> *const &p_node);
		void set_right(bstnode<T> *const &p_node);

	private:
		T data_;
		bstnode<T> *p_left_;
		bstnode<T> *p_right_;
};

template <class T>
bstnode<T>::bstnode(T const &data) {
	data_ = data;
}

template <class T>
T bstnode<T>::get_data() const {
	return data_;
}

template <class T>
bstnode<T> *bstnode<T>::get_left() const {
	return p_left_;
}

template <class T>
bstnode<T> *bstnode<T>::get_right() const {
	return p_right_;
}

template <class T>
void bstnode<T>::set_left(bstnode<T> *const &p_node) {
	p_left_ = p_node;
}

template <class T>
void bstnode<T>::set_right(bstnode<T> *const &p_node) {
	p_right_ = p_node;
}
