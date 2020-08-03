#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};

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

void add_one(node *&first) {
    node *p = first;
    while (p->next != NULL) p = p->next;
    p->val += 1;
    if (p->val == 10) {
        bool rest = true;
        while (rest) {
            rest = false;
            p = first;
            while (p->next != NULL && p->next->val < 10) p = p->next;
            if (p->next != NULL && p->next->val == 10) {
                p->next->val = 0;
                p->val += 1;
                rest = true;
            }
        }
    }

    if (first->val == 10) {
        node *q = new node;
        q->val = 1;
        q->next = first;
        first->val = 0;
        first = q;
    }

}

int main() {
    node *first = new node;
    first = NULL;
    insert_last(first, 9);
    insert_last(first, 9);
    insert_last(first, 9);


    add_one(first);
    while (first != NULL) {
        cout << first->val << endl;
        first = first->next;
    }
    return 0;
}