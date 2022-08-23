#include "next_greater.h"
#include <stdlib.h>
#include <limits.h>
ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}
	size_t n = 0;
	for (const Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		++n;
	}
	ElemType* answer = malloc(n * sizeof(ElemType));
	size_t i = 0;
	for (const Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ElemType g_min = INT_MAX;
		for (const Item* tmp1 = tmp->next; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp1)) < 0) {
					g_min = *ListGetHeadValue(tmp1);
					break;
			}
		}
		if (g_min == INT_MAX)
			g_min = INT_MIN;
		answer[i] = g_min;
		++i;
	}
	*answer_size = n;
	return answer;
}