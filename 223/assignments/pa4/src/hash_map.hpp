#pragma once

#include <functional>

template <typename Key, typename Value>
class HashMap {
	private:
		int size_;
		std::pair<Key, Value> **table_;

		std::pair<Key, Value> *&get_(const Key &key) const;

	public:
		HashMap(int size);
		~HashMap();

		Value &operator[](const Key &key);
		bool contains(const Key &key) const;
		void erase(const Key &key);
};

template <typename Key, typename Value>
std::pair<Key, Value> *&HashMap<Key, Value>::get_(const Key &key) const {
	std::hash<Key> hash;
	int index = hash(key) % size_;

	// quadratic probing
	int i = 1;
	while (table_[index] != nullptr && table_[index]->first != key) {
		index = (index + i * i) % size_;
		++i;
	}

	return table_[index];
}

template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(int size) {
	size_ = size;
	table_ = new std::pair<Key, Value> *[size_];
}

template <typename Key, typename Value>
HashMap<Key, Value>::~HashMap() {
	delete[] table_;
}

template <typename Key, typename Value>
bool HashMap<Key, Value>::contains(const Key &key) const {
	return get_(key) != nullptr;
}

template <typename Key, typename Value>
Value &HashMap<Key, Value>::operator[](const Key &key) {
	std::pair<Key, Value> *&element = get_(key);

	if (element == nullptr) {
		element = new std::pair(key, Value());
	}

	return element->second;
}

template <typename Key, typename Value>
void HashMap<Key, Value>::erase(const Key &key) {
	std::pair<Key, Value> *&element = get_(key);
	assert(element != nullptr);

	delete element;
	element = nullptr;
}
