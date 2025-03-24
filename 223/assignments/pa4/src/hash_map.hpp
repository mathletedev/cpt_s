#pragma once

#include <algorithm>
#include <cassert>
#include <functional>

#define LF_CUTOFF 0.75
#define MAX_CAPACITY 100000

template <typename Key, typename Value>
class HashMap {
	private:
		int capacity_;
		int size_ = 0;
		std::pair<Key, Value> **table_;
		// calculates load factor
		double lf_() const;
		// sieve of eratosthenes for finding next prime
		bool sieve_[MAX_CAPACITY];

		std::pair<Key, Value> *&get_(const Key &key) const;
		void rehash_();

	public:
		HashMap(int capacity = 1);
		~HashMap();

		Value &operator[](const Key &key);
		bool contains(const Key &key) const;
		void erase(const Key &key);
};

template <typename Key, typename Value>
double HashMap<Key, Value>::lf_() const {
	return double(size_) / capacity_;
}

template <typename Key, typename Value>
std::pair<Key, Value> *&HashMap<Key, Value>::get_(const Key &key) const {
	std::hash<Key> hash;
	int index = hash(key) % capacity_;

	// quadratic probing
	int i = 1;
	while (table_[index] != nullptr && table_[index]->first != key) {
		index = (index + i * i) % capacity_;
		++i;
	}

	return table_[index];
}

template <typename Key, typename Value>
void HashMap<Key, Value>::rehash_() {
	// find smallest prime larger than 2 * capacity_
	int new_capacity = capacity_ * 2;
	while (!sieve_[new_capacity]) {
		++new_capacity;
	}

	HashMap<Key, Value> new_map(new_capacity);
	for (int i = 0; i < capacity_; ++i) {
		if (table_[i] == nullptr) {
			continue;
		}

		new_map[table_[i]->first] = table_[i]->second;
	}

	std::swap(capacity_, new_map.capacity_);
	std::swap(size_, new_map.size_);
	std::swap(table_, new_map.table_);

	// new_map is automatically deleted
}

template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(int capacity) {
	assert(capacity > 0);

	capacity_ = capacity;
	table_ = new std::pair<Key, Value> *[capacity]();

	// initialise sieve of eratosthenes
	std::fill(sieve_, sieve_ + MAX_CAPACITY, true);
	for (long long i = 2; i < MAX_CAPACITY; ++i) {
		if (sieve_[i]) {
			for (long long j = i * i; j < MAX_CAPACITY; j += i) {
				sieve_[j] = false;
			}
		}
	}
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
		++size_;
		if (lf_() > LF_CUTOFF) {
			// first rehash, then rerun
			rehash_();
			return (*this)[key];
		}

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
	--size_;
}
