#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int val;
    node *next;
};

bool belongs_to(node *first, int n) {
    while (first != NULL) {
        if (first->val == n) return true;
        first = first->next;
    }
    return false;
}

void insert_n(node *&first, int n) {
    node *p = new node;
    p->val = n;
    p->next = NULL;

    if (first == NULL) //jezeli jest pusta to dodajemy na pierwsze miejsce
    {
        first = p;
        return;
    }

    if (first->val == n) return; // jezeli pierwszy wyraz jest rowny n to wychodzimy
    if (first->val > n) // jezeli wartosc pierwszego elementu jest wieksza od n to wstawiamy n na poczatek
    {
        p->next = first;
        first = p;
        return;
    }
    node *q = first;
    while (q->next != NULL && q->next->val < n) q = q->next; //szukamy elementu mniejszego od n
    if (q->next != NULL && q->next->val == n) return; // jezeli ten element jest rowny n to nie dodajemy n

    p->next = q->next; // jezeli jest rozny od n to dodajemy n miedzy mniejszy od niego a wiekszy
    q->next = p;
}


void delete_n(node *&first, int n) {
    if (first == NULL) return;
    node *q = first;

    if (first->val == n) //usuwamy pierwszy element
    {
        first = first->next;
        delete q;
        return;
    }
    if (q->next != NULL) {
        while (q->next->next != NULL && q->next->val < n) q = q->next;
        if (q->next->val == n) //to usuwamy
        {
            node *p = q->next;
            q->next = q->next->next;
            delete p;
        }
    }
}

void write_list(node *first) {
    node *current = first;
    if (current != NULL) {
        cout << current->val << " ";
        current = current->next;

        while (current != NULL && current->next != NULL) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << current->val << endl;
    } else
        cout << "Lista jest pusta" << endl;
}

int main() {
    node *first = new node;
    first = NULL;

    insert_n(first, 1);
    insert_n(first, 3);
    insert_n(first, 10);
    insert_n(first, 2);
    insert_n(first, 7);
    insert_n(first, 2);

    write_list(first);

    if (belongs_to(first, 7))
        cout << "7 TAK" << endl;
    else
        cout << "7 NIE" << endl;

    if (belongs_to(first, 20))
        cout << "20 TAK" << endl;
    else
        cout << "20 NIE" << endl;

    return 0;
}