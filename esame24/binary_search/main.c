#include <stdlib.h>
#include <string.h>

extern int BinarySearch(const int* v, size_t v_size, int value);
int main(void)
{
	int v[] = { 2, 3, 4, 6 };

	int pos = BinarySearch(v, 4, 6);
	return 0;
}