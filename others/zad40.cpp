#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int remove_repeated(node *&first, node *&second) {
    if (first == NULL) return 0;
    if (second == NULL) return 0;
    while (first->w < first->next->w) first = first->next;
    while (second->w < second->next->w) second = second->next;
    node *f = first;
    node *s = second;

    int counter = 0;

    while (s->next != second && f->next != first) {
        if (f->next->w == s->next->w) {
            node *p = f->next;
            f->next = p->next;
            delete p;

            node *r = s->next;
            s->next = r->next;
            delete r;
            counter += 2;
        } else if (f->next->w < s->next->w) f = f->next;
        else s = s->next;
    }
    if (f->next != first && f->next->w < s->next->w) {
        while (f->next != first && f->next->w < s->next->w) f = f->next;
        if (f->next->w == s->next->w) {
            node *p = f->next;
            first = first->next;
            f->next = p->next;
            delete p;

            node *r = s->next;
            second = second->next;
            s->next = r->next;
            delete r;
            counter += 2;
        }
    } else if (s->next != second && s->next->w < f->next->w) {
        while (s->next != second && s->next->w < f->next->w) s = s->next;
        if (s->next->w == f->next->w) {
            node *p = f->next;
            first = first->next;
            f->next = p->next;
            delete p;

            node *r = s->next;
            second = second->next;
            s->next = r->next;
            delete r;
            counter += 2;
        }
    }
    return counter;
}

//with guards

int remove_repeated_with_guards(node *&first, node *&second) {
    if (first == NULL) return 0;
    if (second == NULL) return 0;
    while (first->w < first->next->w) first = first->next;
    while (second->w < second->next->w) second = second->next;

    node *f = new node;
    f->next = first->next;
    first->next = f;
    first = f;
    node *s = new node;
    s->next = second->next;
    second->next = s;
    second = s;

    int counter = 0;

    while (s->next != second && f->next != first) {
        if (f->next->w == s->next->w) {
            node *p = f->next;
            f->next = p->next;
            delete p;
            node *r = s->next;
            s->next = r->next;
            delete r;
            counter += 2;
        } else if (f->next->w < s->next->w) f = f->next;
        else s = s->next;
    }
    while (f->next != first) f = f->next;
    while (s->next != second) s = second->next;

    node *p = first;
    first = first->next;
    f->next = p->next;
    delete p;

    node *r = second;
    second = second->next;
    s->next = r->next;
    delete r;

    return counter;
}

int main() {
    node *first = new node;
    node *second = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *q = new node;
    node *w = new node;
    node *e = new node;
    node *r = new node;
    node *t = new node;

    first->w = 4;
    a->w = 5;
    b->w = 6;
    c->w = 7;
    d->w = 9;
    first->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = first;

    second->w = 3;
    q->w = 4;
    w->w = 5;
    e->w = 8;
    r->w = 9;
    t->w = 2;
    second->next = q;
    q->next = w;
    w->next = e;
    e->next = r;
    r->next = t;
    t->next = second;
    cout << remove_repeated(first, second) << endl;
    node *f = first;
    node *s = second;
    do {
        cout << f->w << " ";
        f = f->next;
    } while (f != first);
    cout << endl;
    do {
        cout << s->w << " ";
        s = s->next;
    } while (s != second);
    return 0;
}