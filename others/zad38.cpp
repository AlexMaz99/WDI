#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int remove_repeated_elements(node *&first, node *&second) {
    if (first == NULL || second == NULL) return 0;
    node *f = new node;
    f->next = first;
    first = f;
    node *s = new node;
    s->next = second;
    second = s;

    int counter = 0;
    while (s->next != NULL) {
        f = first;
        if (s->next->w > f->next->w)
            while (f->next != NULL && s->next->w > f->next->w) f = f->next;

        if (f->next != NULL && s->next != NULL && f->next->w == s->next->w) {
            node *p = f->next;
            f->next = p->next;
            delete p;
            node *q = s->next;
            s->next = q->next;
            delete q;
            counter += 2;
        } else s = s->next;
    }
    f = first;
    s = second;
    first = first->next;
    second = second->next;
    delete f;
    delete s;
    return counter;
}

void insert_last(node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->w = n;
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

    insert_last(first, 1);
    insert_last(first, 2);
    insert_last(first, 5);
    insert_last(first, 8);
    insert_last(first, 10);
    insert_last(second, 8);
    insert_last(second, 7);
    insert_last(second, 2);
    insert_last(second, 1);
    insert_last(second, 14);
    insert_last(second, 15);
    cout << remove_repeated_elements(first, second) << endl;
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    cout << endl;
    while (second != NULL) {
        cout << second->w << " ";
        second = second->next;
    }

}