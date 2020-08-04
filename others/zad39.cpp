#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int remove_not_repeated(node *&first, node *&second) {
    int counter = 0;
    if (first == NULL) {
        while (second != NULL) {
            node *p = second;
            second = second->next;
            delete p;
            counter++;
        }
        return counter;
    }
    if (second == NULL) {
        while (first != NULL) {
            node *p = first;
            first = first->next;
            delete p;
            counter++;
        }
        return counter;
    }

    node *f = new node;
    node *s = new node;
    f->next = first;
    first = f;
    s->next = second;
    second = s;

    while (s->next != NULL && f->next != NULL) {
        if (f->next->w == s->next->w) {
            f = f->next;
            s = s->next;
        } else if (f->next->w < s->next->w) {
            node *p = f->next;
            f->next = p->next;
            delete p;
            counter++;
        } else {
            node *q = s->next;
            s->next = q->next;
            delete q;
            counter++;
        }
    }
    while (f->next != NULL) {
        node *p = f->next;
        f->next = p->next;
        delete p;
        counter++;
    }
    while (s->next != NULL) {
        node *p = s->next;
        s->next = p->next;
        delete p;
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
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 8);
    insert_last(first, 10);
    insert_last(first, 11);
    insert_last(second, 0);
    insert_last(second, 1);
    insert_last(second, 2);
    insert_last(second, 3);
    insert_last(second, 5);
    insert_last(second, 10);
    cout << remove_not_repeated(first, second) << endl;
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