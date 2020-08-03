#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};

void key(node *&first, int x) //dla nieposortowanych
{
    if (first->val == x) {
        node *q = first;
        first = first->next;
        delete q;
        return;
    }
    node *q = first;
    while (q->next != NULL) {
        if (q->next->val == x) {
            node *p = q->next;
            q->next = q->next->next;
            delete p;
            return;
        }
        q = q->next;
    }
    node *p = new node;
    p->next = NULL;
    p->val = x;
    q->next = p;
}

void key_sorted(node *&first, int x) //dla posortowanych
{
    if (first->val == x) {
        node *q = first;
        first = first->next;
        delete q;
        return;
    }
    if (first->val > x) {
        node *q = new node;
        q->val = x;
        q->next = first;
        first = q;
        return;
    }
    node *q = first;
    while (q->next != NULL && q->next->val < x) q = q->next;
    if (q->next != NULL && q->next->val == x) {
        node *p = q->next;
        q->next = q->next->next;
        delete p;
        return;
    }

    node *p = new node;
    p->next = q->next;
    p->val = x;
    q->next = p;
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
    insert_last(first, 2);
    insert_last(first, 4);
    insert_last(first, 6);


    key_sorted(first, 9);
    while (first != NULL) {
        cout << first->val << endl;
        first = first->next;
    }
    return 0;
}
