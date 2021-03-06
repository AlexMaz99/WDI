#include <iostream>

using namespace std;

struct node {
    node *next;
};

int length_before_cycle(node *first) {
    if (first == NULL) return 0;
    node *slow = first;
    node *fast = first->next;
    while (fast != slow) {
        fast = fast->next;
        if (fast == NULL) return 0;
        slow = slow->next;
        fast = fast->next;
    }
    int length = 0;
    do {
        slow = slow->next;
        length++;
    } while (slow != fast);

    int n = 0;
    int x = 0;
    while (first != slow) {
        if (x == length) {
            x = 0;
            first = first->next;
            n++;
        }
        x++;
        slow = slow->next;
    }
    return n;
}

int main() {
    node *first = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;

    first->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = a;
    return length_before_cycle(first);
}