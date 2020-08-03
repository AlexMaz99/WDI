#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};

node *reverse(node *first) {
    if (first != NULL) {
        node *pc = first;
        node *p = new node;
        while (pc->next != NULL) {
            p = pc->next;
            pc->next = p->next;
            p->next = first;
            first = p;
        }
    }
    return first;
}

node *sum(node *first1, node *first2) {
    if (first1 == NULL) return first2;
    if (first2 == NULL) return first1;
    node *f1 = reverse(first1);
    node *f2 = reverse(first2);
    node *first3 = f1;

    first3->val += f2->val;
    f1 = f1->next;
    f2 = f2->next;
    node *last = first3;

    while (f1 != NULL && f2 != NULL) {
        last->next->val += f2->val;
        f1 = f1->next;
        f2 = f2->next;
    }
    if (f2 != NULL) last = f2;

    node *p = first3;
    while (p != NULL) {
        if (p->next != NULL && p->val > 9) {
            p->next->val += (p->val / 10);
            p->val = p->val % 10;
        }
        p = p->next;
    }
    first3 = reverse(first3);

    if (first3->val > 9) {
        node *q = new node;
        q->val = first3->val / 10;
        q->next = first3;
        first3->val = first3->val % 10;
        first3 = q;
    }

    return first3;
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
    node *first1, *first2, *first3;
    first1 = first2 = first3 = NULL;
    insert_last(first1, 9);
    insert_last(first1, 6);
    insert_last(first1, 9);
    insert_last(first2, 3);
    insert_last(first2, 8);

    first3 = sum(first1, first2);

    while (first3 != NULL) {
        cout << first3->val << endl;
        first3 = first3->next;
    }
    return 0;
}