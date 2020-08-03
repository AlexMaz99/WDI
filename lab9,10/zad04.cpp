struct node {
    int val;
    node *next;
};

void reverse(node *&first) {
    if (first != NULL) {
        node *pc = first;
        node *p = first;
        while (pc->next != NULL) {
            p = pc->next;
            pc->next = p->next;
            p->next = first;
            first = p;
        }
    }
}