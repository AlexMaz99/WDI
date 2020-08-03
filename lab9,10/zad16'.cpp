#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

// with guard

int remove(node *&first, node *&second) {
    if (first == NULL) return 0;
    if (second == NULL) return 0;

    node *f = new node;
    f->val = -100; //wartowniki
    f->next = first;
    first = f;
    node *s = new node;
    s->val = -100;
    s->next = second;
    second = s;
    int counter = 0;

    while (s->next != NULL && f->next != NULL) {
        while (s->next != NULL && f->next != NULL && s->next->val < f->next->val) s = s->next;
        while (s->next != NULL && f->next != NULL && s->next->val > f->next->val)f = f->next;
        if (s->next != NULL && f->next != NULL && f->next->val == s->next->val) {
            node *p = s->next;
            s->next = p->next;
            delete p;
            node *r = f->next;
            f->next = r->next;
            delete r;
            counter += 2;
        }
    }
    f = first;
    s = second;
    first = first->next;
    delete f;
    second = second->next;
    delete s;
    return counter;
}

void insert_last(node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->val = n;
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
    insert_last(first, 2);
    insert_last(first, 4);
    insert_last(first, 6);
    insert_last(first, 8);
    insert_last(first, 10);
    insert_last(second, 1);
    insert_last(second, 2);
    insert_last(second, 3);
    insert_last(second, 5);
    insert_last(second, 6);
    insert_last(second, 9);
    insert_last(second, 10);


    cout << remove(first, second) << endl;
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