#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

// // for sorted cycle with guard

bool remove(node *&first, int k) {
    node *f = new node;
    f->next = first->next;
    first->next = f;
    first = f;

    node *p;
    int n;
    bool done = false;

    while (f->next != first) {
        p = f->next;
        n = 1;
        while (p->next != first && p->next->w == f->next->w) {
            n++;
            p = p->next;
        }
        if (n == k) {
            done = true;
            p = f->next;
            while (f->next->w == p->next->w) {
                node *d = p->next;
                p->next = d->next;
                delete d;
            }
            node *d = f->next;
            f->next = d->next;
            delete d;
            p = f;
        } else f = p;

    }
    p = first;
    first = first->next;
    f->next = first;
    delete p;
    return done;
}

int main() {
    node *first = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;

    first->next = a;
    first->w = 5;
    a->w = 1;
    b->w = 2;
    c->w = 3;
    d->w = 5;
    e->w = 5;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = first;
    cout << remove(first, 3);
    node *p = first;
    do {
        cout << first->w << " ";
        first = first->next;
    } while (first != p);
}