#include "tree.h"

static void PopulatingNextRec(Node* n, Node **prev) {
    if (TreeIsEmpty(n)) {
        return;
    }

    PopulatingNextRec(TreeLeft(n), prev);
    if (!TreeIsEmpty(*prev))
        (*prev)->next = n;
    *prev = n;
    PopulatingNextRec(TreeRight(n), prev);

}
void PopulatingNext(Node* t) {
    Node* prev = TreeCreateEmpty();
    PopulatingNextRec(t, &prev);
    return;
}