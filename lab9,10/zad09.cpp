#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

void remove(node *&first) {
    if (first == NULL) return;
    node *p = first;
    while (p->next != NULL) {
        if (p->next->w < p->w) {
            node *q = p->next;
            p->next = q->next;
            delete q;
        } else p = p->next;
    }

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
    insert_last(first, 2);
    insert_last(first, 1);
    insert_last(first, 4);
    insert_last(first, 10);
    insert_last(first, 8);
    insert_last(first, 7);
    insert_last(first, 11);
    remove(first);
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    return 0;
}