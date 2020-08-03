#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

// without deleting second list

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
    node *s = second;
    bool was_deleted = true;

    while (was_deleted) {
        was_deleted = false;
        while (s != NULL && first->val > s->val) s = s->next;
        if (s != NULL && first->val != s->val) {
            node *p = first;
            first = first->next;
            delete p;
            was_deleted = true;
            result++;
        }
    }
    node *f = first;
    was_deleted = true;
    while (was_deleted) {
        was_deleted = false;
        while (f != NULL && f->val < second->val) f = f->next;
        if (f != NULL && f->val != second->val) {
            node *p = second;
            second = second->next;
            delete p;
            was_deleted = true;
            result++;
        }
    }
    if (first == NULL) return remove_list(second, result);
    if (second == NULL) return remove_list(first, result);
    s = second->next;
    f = first;
    while (f->next != NULL) {
        while (s != NULL && f->next->val > s->val) s = s->next;
        if (s != NULL && f->next->val != s->val) {
            node *p = f->next;
            f->next = p->next;
            delete p;
            result++;
        }
        if (s == NULL) break;
        else f = f->next;
    }
    if (s == NULL) {
        while (f->next != NULL) {
            node *p = f->next;
            f->next = p->next;
            delete p;
            result++;
        }
    }
    f = first->next;
    s = second;
    while (s->next != NULL) {
        while (f != NULL && f->val < s->next->val) f = f->next;

        if (f != NULL && f->val != s->next->val) {
            node *p = s->next;
            s->next = p->next;
            delete p;
            result++;
        } else if (f == NULL) break;
        else s = s->next;
    }
    if (f == NULL && s != NULL) {
        while (s->next != NULL) {
            node *p = s->next;
            s->next = p->next;
            delete p;
            result++;
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

    insert_last(first, 0);
    insert_last(first, 2);
    insert_last(first, 5);
    insert_last(first, 7);
    insert_last(first, 9);

    insert_last(second, 1);
    insert_last(second, 2);
    insert_last(second, 5);
    insert_last(second, 9);
    insert_last(second, 10);
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