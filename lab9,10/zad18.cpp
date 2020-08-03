#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};


void sub_list(node *&first) {
    if (first == NULL || first->next == NULL) return;
    node *p = first;
    node *q = first;
    node *start = first;
    node *end = first;
    int current_length = 0;
    int max_length = 0;
    bool only_one = true;
    bool exist = false;
    while (p->next != NULL) {
        while (q->next != NULL && q->val < q->next->val) {
            current_length++;
            q = q->next;
        }
        if (max_length < current_length) {
            max_length = current_length;
            start = p;
            end = q;
            only_one = true;
            exist = true;
        } else if (max_length == current_length) only_one = false;
        current_length = 0;
        p = q;
        q = q->next;
    }
    if (!exist) return;
    if (!only_one) return;
    if (start == first) {
        end = end->next;
        while (first != end) {
            node *s = first;
            first = first->next;
            delete s;
        }
        return;
    }
    while (start->next != end) {
        node *s = start->next;
        start->next = s->next;
        delete s;
    }
    node *s = start->next;
    start->next = s->next;
    delete s;


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

    insert_last(first, 2);
    insert_last(first, 3);
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 6);
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 0);
    insert_last(first, 0);

    sub_list(first);

    while (first != NULL) {
        cout << first->val << " ";
        first = first->next;
    }

    return 0;
}