#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

// without guard

int remove(node *&first, node *&second) {
    if (first == NULL || second == NULL) return 0;
    node *s = second;
    node *f = first;
    int result = 0;

    while (f->next != NULL && s->next != NULL) {
        while (first != NULL && s != NULL && s->next != NULL) {
            if (first->val == second->val) {
                node *p = first;
                first = first->next;
                delete p;
                node *q = second;
                second = second->next;
                delete q;
                result += 2;
            } else if (first->val == s->next->val) {
                node *p = first;
                first = first->next;
                delete p;
                node *q = s->next;
                s->next = q->next;
                delete q;
                s = second;
                result += 2;
            } else s = s->next;
        }
        s = second;
        f = first;
        while (f != NULL && f->next != NULL && s != NULL && s->next != NULL) {
            if (f->next->val == second->val) {
                node *p = f->next;
                f->next = p->next;
                delete p;
                node *q = second;
                second = second->next;
                delete q;
                result += 2;
            } else if (f->next->val == s->next->val) {
                node *p = f;
                f->next = p->next;
                delete p;
                node *q = s->next;
                s->next = q->next;
                delete q;
                s = second;
                result += 2;
            } else s = s->next;
            if (s->next == NULL && f->next != NULL) {
                s = second;
                f = f->next;
            }
        }
    }
    return result;
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
    insert_last(first, 8);
    insert_last(first, 9);

    insert_last(second, 9);
    insert_last(second, 2);
    insert_last(second, 12);
    insert_last(second, 7);
    insert_last(second, 1);
    cout << remove(first, second) << endl;
    while (first != NULL) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
    while (second != NULL) {
        cout << second->val << " ";
        second = second->next;
    }
    return 0;
}