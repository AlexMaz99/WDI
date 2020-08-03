#include <iostream>

using namespace std;

struct node {
    int val;
    int pot;
    node *next;
};

/* 1 + 2x - 7x^2 -3x^3
6x  -2x^2 + 8x^4 */

node *difference(node *f, node *s) {
    if (f == NULL) return s;
    if (s == NULL) return f;
    node *third = new node;
    if (f->pot < s->pot) {
        third->pot = f->pot;
        third->val = f->val;
        f = f->next;
    } else if (f->pot > s->pot) {
        third->pot = s->pot;
        third->val = -s->val;
        s = s->next;
    } else {
        third->pot = f->pot;
        third->val = f->val - s->val;
        f = f->next;
        s = s->next;
    }
    node *last = third;
    last->next = NULL;
    while (f != NULL && s != NULL) {
        node *p = new node;
        p->next = NULL;
        last->next = p;
        last = p;
        if (f->pot < s->pot) {
            p->pot = f->pot;
            p->val = f->val;
            f = f->next;
        } else if (f->pot > s->pot) {
            p->pot = s->pot;
            p->val = -s->val;
            s = s->next;
        } else {
            p->pot = f->pot;
            p->val = f->val - s->val;
            f = f->next;
            s = s->next;
        }
    }
    while (f != NULL) {
        node *p = new node;
        p->next = NULL;
        last->next = p;
        last = p;
        p->val = f->val;
        p->pot = f->pot;
        f = f->next;
    }
    while (s != NULL) {
        node *p = new node;
        p->next = NULL;
        last->next = p;
        last = p;
        p->val = -s->val;
        p->pot = s->pot;
        s = s->next;
    }
    last = third;
    while (last->next != NULL) {
        if (last->next->val == 0) {
            node *r = last->next;
            last->next = r->next;
            delete r;
        } else last = last->next;
    }
    if (third->val == 0) {
        last = third;
        third = third->next;
        delete last;
    }
    return third;


}

void insert_last(node *&first, int n, int m) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->val = n;
    p->pot = m;
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

    insert_last(first, 1, 0);
    insert_last(first, 2, 1);
    insert_last(first, -7, 2);
    insert_last(first, -3, 3);

    insert_last(second, 1, 0);
    insert_last(second, 2, 1);
    insert_last(second, -2, 2);
    insert_last(second, 8, 4);

    node *third = difference(first, second);
    while (third != NULL) {
        cout << third->val << " ";
        third = third->next;
    }
    cout << endl;
    while (first != NULL) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
    while (second != NULL) {
        cout << second->val << " ";
        second = second->next;
    }

    return 0;
}