#include "tree.h"

static void InvertRec(Node* left, Node*right) {
	if (TreeIsEmpty(left) || TreeIsEmpty(right))
		return;
	ElemType app = left->value;
	left->value = *TreeGetRootValue(right);
	right->value = app;
	InvertRec(TreeLeft(left), TreeRight(right));
	InvertRec(TreeRight(left), TreeLeft(right));
}
Node* Invert(Node* t) {
	if (TreeIsEmpty(t))
		return NULL;
	InvertRec(TreeLeft(t), TreeRight(t));
	return t;
}