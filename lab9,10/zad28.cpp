#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

/* 1 + 2x - 7x^2 -3x^3
6  -2x + 8x^2 */

node *difference(node *first, node *second) {
    if (first == NULL) return second;
    if (second == NULL) return first;
    node *third = new node;
    third->val = first->val - second->val;
    first = first->next;
    second = second->next;
    third->next = NULL;
    node *prev = third;
    while (first != NULL && second != NULL) {
        node *p = new node;
        p->val = first->val - second->val;
        p->next = NULL;
        prev->next = p;
        prev = p;
        first = first->next;
        second = second->next;
    }
    if (first != NULL) {
        node *p = new node;
        p->val = first->val;
        p->next = NULL;
        first = first->next;
        prev->next = p;
        prev = p;
    }
    if (second != NULL) {
        node *p = new node;
        p->val = -second->val;
        p->next = NULL;
        second = second->next;
        prev->next = p;
        prev = p;
    }
    return third;
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

    insert_last(first, 1);
    insert_last(first, 2);
    insert_last(first, -7);
    insert_last(first, -3);

    insert_last(second, 6);
    insert_last(second, -2);
    insert_last(second, 8);

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