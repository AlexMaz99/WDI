#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int common_part(node *&first, node *&second) {
    if (first == NULL) return 0;
    if (second == NULL) return 0;

    node *f = new node;
    f->next = first;
    first = f;
    node *s = new node;
    s->next = second;
    second = s;

    int counter = 0;

    while (f->next != NULL) {
        s = second;
        while (s->next != NULL && s->next->w != f->next->w) s = s->next;
        if (s->next == NULL)f = f->next;
        else break;
    }

    while (f->next != NULL) {
        node *p = new node;
        p->w = f->next->w;
        s->next = p;
        p->next = f->next->next;
        f = f->next;
        s = s->next;
        counter++;
    }

    f = first;
    s = second;
    first = first->next;
    second = second->next;

    delete f;
    delete s;
    return counter;
}

int main() {
    node *first = new node;
    node *second = new node;
    node *a = new node;
    node *b = new node;
    node *q = new node;
    node *w = new node;
    node *e = new node;
    node *m = new node;
    node *s = new node;

    first->w = 5;
    second->w = 13;
    a->w = 11;
    b->w = 12;
    q->w = 7;
    w->w = 17;
    e->w = 21;
    m->w = 3;
    s->w = 2;
    first->next = a;
    a->next = b;
    b->next = m;
    m->next = s;
    s->next = NULL;
    second->next = q;
    q->next = w;
    w->next = e;
    e->next = m;

    return common_part(first, second);
}