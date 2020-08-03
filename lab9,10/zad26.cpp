#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};


/*f -> 2 -> 3 -> 5 ->7-> 11
s -> 8 -> 2 -> 7 -> 4

2 -> 3 -> 4 -> 5 ->7-> 8 -> 11*/

node *multiplication(node *&first, node *&second) {
    node *f = new node;
    f->next = first;
    first = f;
    node *s = new node;
    s->next = second;
    second = s;

    while (f->next != NULL && s->next != NULL) {

        if (f->next->val < s->next->val) f = f->next;
        else if (f->next->val == s->next->val) {
            node *d = s->next;
            s->next = d->next;
            delete d;
            f = first;
        } else {
            node *w = s->next;
            s->next = w->next;
            w->next = f->next;
            f->next = w;
            f = first;
        }
    }
    f = first;
    s = second;
    second = second->next;
    first = first->next;
    delete s;
    delete f;
    return first;

}


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

int main() {
    node *first = new node;
    first = NULL;
    node *second = new node;
    second = NULL;

    insert_last(first, 2);
    insert_last(first, 3);
    insert_last(first, 5);
    insert_last(first, 7);
    insert_last(first, 11);

    insert_last(second, 8);
    insert_last(second, 2);
    insert_last(second, 7);
    insert_last(second, 4);

    first = multiplication(first, second);
    while (first != NULL) {
        cout << first->val << " ";
        first = first->next;
    }

    return 0;
}