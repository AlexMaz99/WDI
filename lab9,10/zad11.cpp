#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};


bool more_ones(int n) //sprawdza czy liczba ma wiecej jedynek niz dwojek w systemie trojkowym
{
    int ones = 0;
    int twos = 0;
    while (n != 0) {
        if (n % 3 == 1) ones++;
        if (n % 3 == 2) twos++;
        n /= 3;
    }
    return ones > twos;
}

void remove(node *&first) {
    if (first == NULL) return;

    node *q = first;
    while (q != NULL &&
           more_ones(q->val)) //dopoki pierwszy wyraz ma wiecej jedynek to go usuwamy i zmieniamy first
    {
        node *y = first;
        first = first->next;
        q = first;
        delete y;
    }
    while (q->next !=
           NULL) //jezeli znalezlismy wyraz w petli wczesniej ktory nie mial wiecej jedynek to zostawiamy first i sprawdzamy nastepne
    {
        if (more_ones(q->next->val)) //jeseli ma wiecej jedynek to go usuwamu i nie zmianiamy q
        {
            node *p = q->next;
            q->next = q->next->next;
            delete p;
        } else q = q->next; //jezeli nie ma wiecej jedynek to zmieniamy q
    }

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
    insert_last(first, 1); //usun
    insert_last(first, 2);
    insert_last(first, 4); //usun
    insert_last(first, 8);
    insert_last(first, 11);
    insert_last(first, 14); //usun
    remove(first);

    while (first != NULL) {
        cout << first->val << endl;
        first = first->next;
    }
    return 0;
}