#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

bool has_cycle(node *first) {
    if (first == NULL || first->next == NULL) return false;
    node *fast = first;
    node *slow = first;
    do {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL) return false;
        fast = fast->next;
        if (fast == slow) return true;
    } while (fast != NULL);
    return false;
}

bool has_cycle2(node *first) {
    if (first == NULL) return false;
    node *slow = first;
    node *fast = first->next;
    while (fast != NULL) {
        if (fast == slow) return true;
        fast = fast->next;
        if (fast == NULL) return false;
        slow = slow->next;
        fast = fast->next;
    }
    return false;
}

void insert_last(node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->val = n;
    p->next = NULL;
    if (n == 0) {
        p->next = first;
    }
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
    insert_last(first, 3);
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 6);
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 0);
    return has_cycle2(first);
}