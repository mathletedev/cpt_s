int binary_search(int arr[], int n, int target) {
	int low = 0;
	int high = n;

	while (low < high) {
		int mid = (low + high) / 2;
		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] < target) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

	return -1;
}
