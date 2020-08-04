#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

int jedynki(int a) {
    int j = 0;
    while (a != 0) {
        if (a % 2 == 1) j++;
        a /= 2;
    }
    if (j < 8) return 0;
    if (j > 24) return 2;
    return 1;
}

void divide_and_connect(node *&first) {
    if (first == NULL) return;
    node *f[3];
    node *l[3];
    for (int i = 0; i < 3; i++) f[i] = l[i] = NULL;
    int j;
    while (first != NULL) {
        j = jedynki(first->w);
        if (f[j] == NULL) {
            f[j] = first;
            l[j] = first;
            first = first->next;
        } else {
            l[j]->next = first;
            first = first->next;
            l[j] = l[j]->next;
        }
        l[j]->next = NULL;
    }
    j = 0;
    while (f[j] == NULL) j++;
    first = f[j];
    for (int i = j + 1; i < 3; i++) {
        if (f[i] != NULL) {
            l[j]->next = f[i];
            j = i;
        }
    }


}

void insert_last(node *&first, int n) {
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
    node *first = new node;
    first = NULL;


    insert_last(first, 6);
    insert_last(first, 5);
    insert_last(first, 7);
    insert_last(first, 3);
    insert_last(first, 1);
    insert_last(first, 2);

    divide_and_connect(first);
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
}