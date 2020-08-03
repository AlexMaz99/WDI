void insert_last(node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->val = n;
    p->next = NULL;
    if (first == NULL) first = p;
    else {
        node *r = first;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = p;
    }
}