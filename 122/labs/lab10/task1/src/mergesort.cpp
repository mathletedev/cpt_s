#include <vector>

template <class T>
void merge_sort(std::vector<T> &list) {
	// base case
	if (list.size() == 1) return;

	// split list
	std::vector<T> left, right;
	for (int i = 0; i < list.size(); ++i)
		(i < list.size() / 2 ? left : right).push_back(list[i]);

	// sort individual parts
	merge_sort(left);
	merge_sort(right);

	int a = 0, b = 0;
	list.clear();
	while (a < left.size() || b < right.size()) {
		// feed through remaining elements
		if (a == left.size()) {
			list.push_back(right[b++]);
			continue;
		}
		if (b == right.size()) {
			list.push_back(left[a++]);
			continue;
		}

		// merge step
		list.push_back(left[a] < right[b] ? left[a++] : right[b++]);
	}
}
