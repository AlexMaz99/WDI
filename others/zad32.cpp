#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int remove_repeated_elements(node *&first, node *&second, node *&third) {
    if (first == NULL || second == NULL || third == NULL) return 0;
    int counter = 0;
    node *f = new node;
    f->next = first;
    first = f;
    node *s = new node;
    s->next = second;
    second = s;
    node *t = new node;
    t->next = third;
    third = t;

    while (f->next != NULL && s->next != NULL && t->next != NULL) {
        if (f->next->w < s->next->w) f = f->next;
        else if (f->next->w > s->next->w) s = s->next;
        else {
            while (t->next != NULL && t->next->w < f->next->w) t = t->next;
            if (t->next == NULL) return counter;
            else if (t->next->w == f->next->w) {
                node *p = f->next;
                f->next = p->next;
                delete p;
                node *q = s->next;
                s->next = q->next;
                delete q;
                node *r = t->next;
                t->next = r->next;
                delete r;
                counter += 3;
            } else {
                f = f->next;
                s = s->next;
            }
        }
    }
    f = first;
    first = first->next;
    delete f;
    s = second;
    second = second->next;
    delete s;
    t = third;
    third = third->next;
    delete t;

    return counter;
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
    node *second = new node;
    second = NULL;
    node *third = new node;
    third = NULL;

    insert_last(first, 2);
    insert_last(first, 5);
    insert_last(first, 8);
    insert_last(first, 9);
    insert_last(first, 11);

    insert_last(second, 3);
    insert_last(second, 4);
    insert_last(second, 5);
    insert_last(second, 8);
    insert_last(second, 11);
    insert_last(second, 12);
    insert_last(second, 13);

    insert_last(third, 1);
    insert_last(third, 2);
    insert_last(third, 5);
    insert_last(third, 6);
    insert_last(third, 8);
    insert_last(third, 10);
    insert_last(third, 13);
    insert_last(third, 15);
    cout << remove_repeated_elements(first, second, third) << endl;
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    cout << endl;
    while (second != NULL) {
        cout << second->w << " ";
        second = second->next;
    }
    cout << endl;
    while (third != NULL) {
        cout << third->w << " ";
        third = third->next;
    }

    return 0;
}
