#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    int index;
    node *next;
};

const int N = 5;

void init(node *&tab) //inicjalizacja tablicy
{
    tab->val = 0;
    tab->next = NULL;
    tab->index = -1;
}

int value(node *tab, int n) //sprawdzenie wartosci pod indeksem n w tablicy
{
    if (tab == NULL) return 0;
    if (tab->index == n) return tab->val;
    while (tab->next != NULL && tab->next->index < n) tab = tab->next;
    if (tab->next != NULL && tab->next->index == n) return tab->next->val;
    return 0;
}

void set(node *&tab, int n, int value) //podstawienie wartosci value pod indeks n
{
    if (value != 0) //jezeli wartosc jest rozna od zera to sprawdzamy czy istnieje juz indeks n czy nie i dodajemy
    {
        node *p = new node;
        p->next = NULL;
        p->val = value;
        p->index = n;
        if (tab == NULL) {
            tab = p;
            return;
        }
        if (tab->index == n) {
            tab->val = value;
            return;
        }
        if (tab->index > n) {
            p->next = tab;
            tab = p;
            return;
        }
        node *q = tab;
        while (q->next != NULL && q->next->index < n) q = q->next;
        if (q->next != NULL && q->next->index == n) q->next->val = value;
        else {
            p->next = q->next;
            q->next = p;
        }
    } else //jezeli wartosc jest rowna 0 to sprawdzamy czy istnieje ten indeks, jesli tak to go usuwamy, jesli nie to nie robimy nic
    {
        if (tab == NULL) return;
        node *q = tab;
        if (tab->index == n) {
            tab = tab->next;
            delete q;
            return;
        }
        if (tab->index > n) return;
        if (tab->next != NULL) {
            while (q->next->next != NULL && q->next->index < n) q = q->next;
            if (q->next->index == n) {
                node *p = q->next;
                q->next = q->next->next;
                delete p;
            }
        }
    }
}

int main() {
    node *tab = new node;
    init(tab);
    set(tab, 0, 3);
    set(tab, 2, 6);
    set(tab, 3, 5);
    set(tab, 4, 8);
    set(tab, 5, 0);

    node *current = tab;
    if (current != NULL) {
        cout << current->index << ": " << current->val << " ";
        current = current->next;


        while (current != NULL && current->next != NULL) {
            cout << current->index << ": " << current->val << " ";
            current = current->next;
        }
        cout << current->index << ": " << current->val << endl;
    } else
        cout << "Tablica jest pusta" << endl;


    cout << "1: " << value(tab, 1) << endl;
    cout << "3: " << value(tab, 3) << endl;
    return 0;
}