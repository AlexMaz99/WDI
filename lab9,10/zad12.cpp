#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

bool even_fives(int n) {
    int fives = 0;
    while (n != 0) {
        if (n % 8 == 5) fives++;
        n /= 8;
    }
    return fives % 2 == 0;
}

//2 4 5 6 9
//1 3 4 8 7
void move(node *&first) {
    if (first == NULL || first->next == NULL) return;
    node *q = first;

    while (q->next != NULL) {
        if (!even_fives(q->next->w)) {
            node *p = q->next;
            q->next = p->next;
            p->next = first;
            first = p;
        } else q = q->next;
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
    node *first = new node;
    first = NULL;
    insert_last(first, 100); // parzysta
    insert_last(first, 40);// nieparzysta
    insert_last(first, 45); // parzysta
    insert_last(first, 5); // nieparzysta
    insert_last(first, 15); // parzysta
    insert_last(first, 92); // parzysta

    move(first);

    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    return 0;
}