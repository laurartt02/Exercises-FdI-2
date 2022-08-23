#include "cc.h"

int main(void) {
	ElemType v[] = { 7, 8, 0, 4, 6 };
	ElemType v1[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	size_t v1_size = sizeof(v1) / sizeof(ElemType);
	Item* i = NULL;
	for (size_t j = 0; j < v1_size; ++j) {
		i = ListInsertBack(i, v1 + j);
	}
	int ret = ComponentiConnesse(i, v, v_size);

	return 0;
}