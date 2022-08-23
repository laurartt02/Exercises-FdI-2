#include "cc.h"
#include <stdbool.h>
int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v_size == 0 || v == NULL)
		return 0;
	int componenti = 0;
	bool connesse = false;
	bool connesse_prev = false;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		connesse = false;
		for (size_t j = 0; j < v_size; ++j) {
			if (ElemCompare(v + j, ListGetHeadValue(tmp)) == 0) {
				connesse = true;
			}
		}
		if (!connesse&&connesse_prev)
			++componenti;
		if (tmp->next == NULL && connesse)
			++componenti;
		connesse_prev = connesse;
	}

	return componenti;

}