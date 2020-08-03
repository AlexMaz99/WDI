#include <iostream>

using namespace std;

struct node {
    int w;
    node *prev;
    node *next;
};

bool odd_ones(int n) {
    int ones = 0;
    while (n != 0) {
        if (n % 2 == 1) ones++;
        n /= 2;
    }
    return ones % 2 == 1;
}

// 1 2 5 6 8
// 5 6
void remove(node *&first) {
    if (first == NULL) return;

    while (first != NULL && odd_ones(first->w)) {
        node *q = first;
        first = first->next;
        first->prev = NULL;
        delete q;
    }
    node *p = first->next;
    while (p != NULL) {
        if (odd_ones(p->w)) {
            node *s = p;
            p = p->next;
            s->prev->next = p;
            if (p != NULL) p->prev = s->prev;
            delete s;
        } else p = p->next;
    }


}

void insert_last(node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->w = n;
    p->next = NULL;
    p->prev = NULL;
    if (first == NULL) first = p;
    else {
        node *r = first;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = p;
        p->prev = r;
    }
}

int main() {
    node *first = new node;
    first = NULL;
    insert_last(first, 1);
    insert_last(first, 2);
    insert_last(first, 5);
    insert_last(first, 6);
    insert_last(first, 8);

    remove(first);

    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    return 0;
}