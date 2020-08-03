#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};


void divide(node *first, node *tab_first[10], node *tab_end[10]) {
    while (first != NULL) {
        int i = (first->val) % 10;
        if (tab_first[i] == NULL) {
            tab_first[i] = first;
            tab_end[i] = tab_first[i];
        } else {
            tab_end[i]->next = first;
            tab_end[i] = tab_end[i]->next;
        }

        first = first->next;
        tab_end[i]->next = NULL;
    }
}

node *merge(node *tab_first[10], node *tab_end[10]) {
    node *first = NULL;
    int i = 0;
    while (tab_first[i] == NULL) i++;
    first = tab_first[i];
    for (int j = i + 1; j < 10; j++) {
        if (tab_first[j] != NULL) {
            tab_end[i]->next = tab_first[j];
            i = j;
        }
    }

    return first;
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
    insert_last(first, 12);
    insert_last(first, 32);
    insert_last(first, 6);
    insert_last(first, 56);
    insert_last(first, 26);
    insert_last(first, 92);
    insert_last(first, 102);

    node *tab_first[10];
    node *tab_end[10];
    for (int i = 0; i < 10; i++) {
        tab_first[i] = NULL;
        tab_end[i] = NULL;
    }
    divide(first, tab_first, tab_end);

    /*for (int i=0; i<10; i++)
    {
        while(tab_first[i] != NULL)
        {
            cout << tab_first[i]->val << ", ";
            tab_first[i] = tab_first[i]->next;
        }
        cout<<endl;
    }*/
    node *first1 = merge(tab_first, tab_end);
    while (first1 != NULL) {
        cout << first1->val << " ";
        first1 = first1->next;
    }

    return 0;
}