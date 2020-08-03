#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

// with guard

//1 2 5 8 9
//9 2 12 7 1

int remove(node *&first, node *&second) {
    if (first == NULL || second == NULL) return 0;
    node *f = new node;
    f->next = first;
    first = f;
    node *s = new node;
    s->next = second;
    second = s;
    int result = 0;

    while (f->next != NULL && s->next != NULL) {
        if (f->next->w < s->next->w)
            f = f->next;
        else if (f->next->w > s->next->w) {
            s = s->next;
            f = first;
        } else if (f->next->w == s->next->w) {
            node *d = f->next;
            f->next = d->next;
            delete d;
            node *r = s->next;
            s->next = r->next;
            delete r;
            result += 2;
            f = first;
        }
    }
    f = first;
    s = second;
    first = first->next;
    second = second->next;
    delete s;
    delete f;
    return result;
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
    insert_last(first, 9);
    insert_last(first, 13);

    insert_last(second, 9);
    insert_last(second, 2);
    insert_last(second, 12);
    insert_last(second, 7);
    insert_last(second, 1);

    cout << remove(first, second) << endl;
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    cout << endl;
    while (second != NULL) {
        cout << second->w << " ";
        second = second->next;
    }
    return 0;
}