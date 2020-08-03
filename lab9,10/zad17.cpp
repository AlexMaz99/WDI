#include <iostream>

using namespace std;

struct node {
    int a;
    int b;
    node *next;
};

void reduction(node *&first) {
    if (first == NULL) return;
    node *p = first;
    node *q = p;
    while (p->next != NULL) {
        q = p;
        while (q->next != NULL) {
            if (p->a <= q->next->b && p->b >= q->next->a || p->a >= q->next->b && p->b <= q->next->a) {
                if (p->a >= q->next->a && p->b >= q->next->b) p->a = q->next->a;
                else if (p->a <= q->next->a && p->b <= q->next->b) p->b = q->next->b;
                else if (p->a >= q->next->a && p->b <= q->next->b) {
                    p->a = q->next->a;
                    p->b = q->next->b;
                }
                node *s = q->next;
                q->next = s->next;
                delete s;
                q = p;
            } else q = q->next;
        }
        p = p->next;
        if (p == NULL) return;
    }
}

void insert_last(node *&first, int n, int m) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->a = n;
    p->b = m;
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

    insert_last(first, 13, 17);
    insert_last(first, 2, 5);
    insert_last(first, 7, 11);
    insert_last(first, 11, 20);
    insert_last(first, 5, 6);
    insert_last(first, 15, 19);

    reduction(first);

    while (first != NULL) {
        cout << first->a << " " << first->b << endl;
        first = first->next;
    }

    return 0;
}