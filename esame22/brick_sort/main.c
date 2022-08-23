#include <stdlib.h>

extern void BrickSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 1, 3, 4, 2, 5, 7, 0, 9, 8 };
	size_t v_size = sizeof(v) / sizeof(int);
	BrickSort(v, v_size);

	return 0;
}