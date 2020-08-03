#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

bool repeated(node *first, node *p) {
    while (first != NULL) {
        if (first != p && first->w == p->w) return true;
        first = first->next;
    }
    return false;
}

// 3 3 2 1 6  1 9
// 3 2 1 6 9
void remove(node *first) {
    if (first == NULL) return;

    node *p = first;
    while (p->next != NULL) {
        if (repeated(first, p->next)) {
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
    insert_last(first, 3);
    insert_last(first, 3);
    insert_last(first, 2);
    insert_last(first, 1);
    insert_last(first, 6);
    insert_last(first, 1);
    insert_last(first, 9);

    remove(first);

    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    return 0;
}