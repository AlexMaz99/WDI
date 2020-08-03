#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

void remove(node *&first) {
    if (first == NULL) return;

    while (first->next != NULL && first->next->w % first->w == 0) //dopoki bedziemy usuwac pierwszy
    {
        node *p = first;
        first = first->next;
        delete p;
    }
    node *q = first;

    if (q->next != NULL) {
        while (q->next->next != NULL) {
            if (q->next->next->w % q->next->w == 0) {
                node *s = q->next;
                q->next = s->next;
                delete s;
            } else q = q->next;
        }

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
    insert_last(first, 4);
    insert_last(first, 8);
    insert_last(first, 3);
    insert_last(first, 9);
    insert_last(first, 12);

    remove(first);
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    return 0;
}