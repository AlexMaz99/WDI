#include <iostream>
#include <string>

using namespace std;

struct node {
    int val;
    node *next;
};


bool first_shorter(node *f, node *s) {
    while (f != NULL && s != NULL) {
        f = f->next;
        s = s->next;
    }
    return f == NULL;
}

bool contains_list(node *first, node *second) {
    if (first == NULL || second == NULL) return true;
    node *f = first;
    node *s = second;

    while (s != NULL && f != NULL) {
        while (f != NULL && s != NULL && f->val == s->val) {
            s = s->next;
            f = f->next;
        }
        if (f == NULL || s == NULL) return true;
        first = first->next;
        f = first;
        s = second;
    }
    return false;
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
    insert_last(first, 5);

    insert_last(second, 1);
    insert_last(second, 2);
    insert_last(second, 5);
    insert_last(second, 8);

    if (first_shorter(first, second)) return contains_list(second, first);
    return contains_list(first, second);
}
