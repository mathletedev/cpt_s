#include "list_my_josephus.hpp"

void ListMyJosephus::clear() {
	destinations_.clear();
}

size_t ListMyJosephus::current_size() const {
	return destinations_.size();
}

bool ListMyJosephus::is_empty() const {
	return destinations_.empty();
}
