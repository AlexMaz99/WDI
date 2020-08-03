#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};

void insert_first(node *&first, int n) //dodawanie elementu na poczatek listy
{
    node *p = new node;
    p->val = n;
    p->next = first;
    first = p;
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

int length(node *first) //obliczanie dlugosci listy
{
    int result = 0;
    while (first != NULL) {
        result++;
        first = first->next;
    }
    return result;
}

bool is_empty(node *first) //sprawdzenie czy lista jest pusta
{
    return length(first) == 0;
}

void delete_first(node *&first) //usuwanie pierwszego elementu
{
    if (first != NULL) {
        node *p = first;
        first = first->next;
        delete p;
    }
}

void delete_last(node *first) //usuwanie ostatniego elementu
{
    if (first != NULL && first->next != NULL) {
        while (first->next->next != NULL) {
            first = first->next;
        }
        delete first->next;
        first->next = NULL;
    }
}

void delete_x(node *&first, int x) //usuwanie elementu o podanej wartosci
{
    if (first == NULL) return;
    node *q, *p;
    p = first;
    q = NULL;
    while (p != NULL && p->val < x) {
        q = p;
        p = p->next;
    }
    if (p == NULL) return;
    if (q = NULL && p->val == x) {
        first = p->next;
        delete p;
        return;
    }
    if (x == p->val) {
        q->next = p->next;
        delete p;
    }
}

void delete_second(node *first) //usuwanie co drugiego elementu
{
    int i = 1;
    while (first != NULL && first->next != NULL) {
        i++;
        if (i % 2 == 0) {
            if (first->next->next != NULL) {
                node *p = first->next;
                first->next = first->next->next;
                delete p;
                i++;
            } else {
                delete first->next;
                first->next = NULL;
            }
        }
        first = first->next;
    }
}

int main() {
    node *first = new node;
    first = NULL;
    insert_last(first, 2);
    insert_first(first, 1);
    insert_last(first, 3);
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 6);
    insert_last(first, 7);
    delete_second(first);
    while (first != NULL) {
        cout << first->val << endl;
        first = first->next;
    }
    return 0;
}