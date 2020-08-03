#include <iostream>

using namespace std;

struct node {
    int x;
    int y;
    node *next;
};

void wsp(node *&f, node *&a, node *&b, node *&c, node *&d) {
    if (f == NULL) return;
    while (f != NULL) {
        node *tmp = f;
        f = f->next;
        if (tmp->x > 0 && tmp->y > 0) {
            tmp->next = a;
            a = tmp;
        } else if (tmp->x > 0 && tmp->y < 0) {
            tmp->next = b;
            b = tmp;
        } else if (tmp->x < 0 && tmp->y > 0) {
            tmp->next = c;
            c = tmp;
        } else if (tmp->x < 0 && tmp->x < 0) {
            tmp->next = d;
            d = tmp;
        } else {
            delete tmp;
        }

    }
}

void insert_last(node *&first, int a, int b) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->x = a;
    p->y = b;
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

    node *f = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    f = a = b = c = d = NULL;
    insert_last(f, 0, 1);
    insert_last(f, 5, 5);
    insert_last(f, -1, 1);
    insert_last(f, 3, -1);
    insert_last(f, -4, -5);
    insert_last(f, 4, 4);
    insert_last(f, 0, -1);
    insert_last(f, -7, 6);
    insert_last(f, 4, -7);
    insert_last(f, -9, -5);

    wsp(f, a, b, c, d);

    while (a != NULL) {
        cout << a->x << "," << a->y << " ";
        a = a->next;
    }
    cout << endl;
    while (b != NULL) {
        cout << b->x << "," << b->y << " ";
        b = b->next;
    }
    cout << endl;
    while (c != NULL) {
        cout << c->x << "," << c->y << " ";
        c = c->next;
    }
    cout << endl;
    while (d != NULL) {
        cout << d->x << "," << d->y << " ";
        d = d->next;
    }
}