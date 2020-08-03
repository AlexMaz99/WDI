#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

bool is_repeated(node *first, int a) {
    int counter = 0;
    node *p = first;
    do {
        if (p->w == a) counter++;
        p = p->next;
    } while (p != first);
    return (counter > 1);
}

void remove_repeated(node *&first, int a) {
    node *p = first;
    while (p->next != first) {
        if (p->next->w == a) {
            node *s = p->next;
            p->next = s->next;
            delete s;
        } else p = p->next;
    }
    if (p->next->w == a) {
        first = first->next;
        node *s = p->next;
        p->next = s->next;
        delete s;
    }
}

void cycle(node *&first) {
    if (first == NULL) return;
    node *p = first;
    while (p->next != first) {
        if (is_repeated(first, p->next->w)) remove_repeated(first, p->next->w);
        else p = p->next;
    }
}

int main() {
    node *first = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    first->w = 5;
    a->w = 3;
    b->w = 1;
    c->w = 2;
    d->w = 1;
    e->w = 2;
    first->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = first;

    cycle(first);
    node *p = first;
    do {
        cout << p->w
        " ";
        p = p->next;
    } while (p != first);
}