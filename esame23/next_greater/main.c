#include "next_greater.h"


int main(void) {
	ElemType v[] = { 30, 1, 1, 1, 1, 1, 1, 1, 7, 6, 4, 8, 21, 12, 5, 6 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Item* list = NULL;
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, v + i);
	}
	size_t answer_size;
	ElemType* answer = NextGreater(list, &answer_size);

	return 0;
}