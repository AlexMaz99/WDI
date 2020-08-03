#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

// 3 3 2 6 1 1 9 2
//  6 9
void remove(node *&first) {
    if (first == NULL) return;
    node *p;
    int counter = 1;
    while (counter > 0) {
        counter = 0;
        p = first;
        while (p->next != NULL) {
            if (first->w == p->next->w) {
                counter++;
                node *q = p->next;
                p->next = q->next;
                delete q;
            } else p = p->next;
        }
        if (counter > 0) {
            node *s = first;
            first = first->next;
            delete s;
        }
    }
    if (first == NULL || first->next == NULL) return; //first jest na 6
    p = first; // p jest na 6
    while (p->next->next != NULL) // 6 1 1 9 2
    {
        node *s = p->next;
        while (s->next != NULL) {
            if (p->next->w == s->next->w) {
                counter++;
                node *r = s->next;
                s->next = r->next;
                delete r;
            } else s = s->next;
        }
        if (counter > 0) {
            node *r = p->next;
            p->next = r->next;
            delete r;
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
    insert_last(first, 6);
    insert_last(first, 1);
    insert_last(first, 1);
    insert_last(first, 9);
    insert_last(first, 2);

    remove(first);

    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    return 0;
}