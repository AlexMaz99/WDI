#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int w;
    node *next;
};

node *merge_list_iterative(node *first1, node *first2) {
    if (first1 == NULL) return first2; //jezeli ktoras jest pusta to zwracamy druga
    if (first2 == NULL) return first1;
    node *first3;
    if (first1->w < first2->w) //wybieramy ta ktora ma mniejszy pierwszy element
    {
        first3 = first1;
        first1 = first1->next;
    } else {
        first3 = first2;
        first2 = first2->next;
    }
    node *last = first3;
    while (first1 != NULL && first2 != NULL) //dopasowujemy reszte
    {
        if (first1->w < first2->w) {
            last->next = first1;
            last = last->next;
            first1 = first1->next;
        } else {
            last->next = first2;
            last = last->next;
            first2 = first2->next;
        }
    }
    if (first1 != NULL) last->next = first1; //jezeli ktoras sie skonczyla to dopinamy na koniec druga
    else last->next = first2;
    return first3;
}


node *merge_list_recursive(node *first1, node *first2) {
    if (first1 == NULL) return first2;
    if (first2 == NULL) return first1;
    if (first1->w < first2->w) {
        first1->next = merge_list_recursive(first1->next, first2);
        return first1;
    } else {
        first2->next = merge_list_recursive(first1, first2->next);
        return first2;
    }
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
    node *first1 = new node;
    first1 = NULL;
    node *first2 = new node;
    first2 = NULL;
    insert_last(first1, 2);
    insert_last(first2, 1);
    insert_last(first1, 5);
    insert_last(first2, 6);
    insert_last(first1, 7);
    insert_last(first2, 9);

    node *first3 = merge_list_iterative(first1, first2);
    while (first3 != NULL) {
        cout << first3->w << endl;
        first3 = first3->next;
    }
    return 0;
}