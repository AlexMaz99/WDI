#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};


void remove(node *&first, int val) {
    node *p = first;
    do {
        if (p->next->w == val) {
            node *w = p->next;
            p->next = w->next;
            delete w;
        } else p = p->next;
    } while (first != p->next);
    if (p->next->w == val) {
        first = first->next;
        node *w = p->next;
        p->next = w->next;
        delete w;
    }
}

bool was_deleted(node *&first, int k) {
    node *tmp = first;
    node *p = first->next;;
    int n = 0;
    bool done = false;

    while (first != p) {
        tmp = tmp->next;
        int val = tmp->w;
        n = 1;
        p = tmp->next;
        while (p != tmp) {
            if (p->w == val) n++;
            p = p->next;
        }
        if (n == k) {
            done = true;
            remove(first, val);
            tmp = first;
            p = first->next;
        }

    }

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
    first->w = 1;
    a->w = 3;
    b->w = 1;
    c->w = 5;
    d->w = 5;
    e->w = 5;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = first;
    was_deleted(first, 3);
    node *p = first;
    do {
        cout << first->w << " ";
        first = first->next;
    } while (first != p);
}