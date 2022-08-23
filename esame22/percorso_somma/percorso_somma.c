#include "tree.h"

static void PercorsoSommaRec(Node* t, const ElemType* target, ElemType somma, bool *ret) {
	if (*ret)
		return;
	if (TreeIsEmpty(t)) {
		if (ElemCompare(&somma, target) == 0) {
			*ret = true;
		}
		return;
	}
	somma += *TreeGetRootValue(t);
	PercorsoSommaRec(TreeLeft(t), target, somma, ret);
	PercorsoSommaRec(TreeRight(t), target, somma, ret);
}
bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t))
		return false;
	bool ret = false;
	PercorsoSommaRec(t, target, 0, &ret);
	return ret;
}