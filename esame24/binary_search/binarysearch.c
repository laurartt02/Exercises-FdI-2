#include <stdlib.h>
int BinarySearch(const int* v, size_t v_size, int value) {
	int mid = v_size / 2;
	int first = 0;
	int last = v_size - 1;
	if (v == NULL)
		return -1;
	while (1) {
		if (v[mid] == value)
			return mid;
		if (first >= last)
			return -1;
		if (v[mid] > value) {
			last = mid - 1;
			mid = (first + last) / 2;
		}
		else {
			first = mid + 1;
			mid = (first + last) / 2;
		}
	}
}