#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int remove_list(node *&first, int &result) {
    while (first != NULL) {
        node *p = first;
        first = first->next;
        delete p;
        result++;
    }
    return result;
}

int remove(node *&first, node *&second) {
    int result = 0;
    if (first == NULL) return remove_list(second, result);
    if (second == NULL) return remove_list(first, result);

    node *f = new node;
    f->next = first;
    first = f;
    node *s = new node;
    s->next = second;
    second = s;

    while (f->next != NULL && s->next != NULL) {
        if (f->next->w < s->next->w) {
            node *d = f->next;
            f->next = d->next;
            delete d;
            result++;
        } else if (f->next->w > s->next->w) {
            node *d = s->next;
            s->next = d->next;
            delete d;
            result++;
        } else {
            f = f->next;
            s = s->next;
        }
    }
    while (s->next != NULL) {
        node *d = s->next;
        s->next = d->next;
        delete d;
        result++;
    }
    while (f->next != NULL) {
        node *d = f->next;
        f->next = d->next;
        delete d;
        result++;
    }
    f = first;
    s = second;
    first = first->next;
    second = second->next;
    delete f;
    delete s;
    return result;
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

    insert_last(first, 2);
    insert_last(first, 3);
    insert_last(first, 5);
    insert_last(first, 7);
    insert_last(first, 11);

    insert_last(second, 1);
    insert_last(second, 4);
    insert_last(second, 5);
    insert_last(second, 7);
    insert_last(second, 9);
    insert_last(second, 12);
    cout << remove(first, second) << endl;
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    cout << endl;
    while (second != NULL) {
        cout << second->w << " ";
        second = second->next;
    }
    return 0;
}