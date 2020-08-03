#include <iostream>
#include <string>

using namespace std;

struct node {
    string txt;
    node *next;
};

int last(string a) {
    return a[a.size() - 1];
}

int first(string a) {
    return a[0];
}

bool can_insert(node *&first, string txt) {
    node *p = first;
    if (first == NULL && first(txt) > last(txt)) {
        first = new node;
        first->txt = txt;
        first->next = first;
        return true;
    }
    if (first == NULL) return false;

    do {
        if (last(first->txt) < first(txt) && last(txt) < first(first->next->txt)) {
            node *q = new node;
            q->txt = txt;
            q->next = first->next;
            first->next = q;
            first = q;
            return true;
        }
        first = first->next;
    } while (first != p);
    return false;
}


int main() {
    node *first = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;

    first->next = a;
    first->txt = "bartek";
    a->txt = "leszek";
    a->next = b;
    b->txt = "marcjan";
    b->next = c;
    c->txt = "ola";
    c->next = d;
    d->txt = "zosia";
    d->next = first;
    string n;
    cin >> n;
    return can_insert(first, n);
}