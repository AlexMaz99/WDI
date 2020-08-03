#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

// 1 1 1 2 2 3 4 4 5 6 7 7
//  3 5 6 zwroci 9

int not_unique(node *&first) {
    if (first == NULL || first->next == NULL) return 0;
    int result = 0;
    bool to_remove = true;;
    while (to_remove) //sprawdzamy czy pierwsze elemenenty sie powtarzaja
    {
        to_remove = false;
        while (first->next != NULL && first->w == first->next->w) //jezeli sie powtarzaja to usuwamy pierwszy z nich
        {
            to_remove = true;
            node *q = first;
            first = first->next;
            delete q;
            result++;
        }
        if (to_remove) //jezeli sie powtarzaly to usuwamy ten ktory zostal
        {
            node *q = first;
            first = first->next;
            delete q;
            result++;
        }
    }

    if (first == NULL || first->next == NULL || first->next->next == NULL)
        return result; //jezeli usunelismy wszystkie lub zostal jeden lub zostaly dwa to wychodzimu
    node *p = first; //bo jezeli zostaly dwa to my je juz sprawdzilismy wczesnie i one nie sa rowne
    while (p->next != NULL) // teraz wiemy ze sa co najmniej 3 elementy przy czy pierwsze dwa nie sa rowne
    {
        to_remove = false;
        while (p->next->next != NULL &&
               p->next->w == p->next->next->w) // sprawdzamy czy drugi i trzeci sa rowne, jezeli tak to usuwamy drugi
        {
            result++;
            node *q = p->next;
            p->next = q->next;
            delete q;
            to_remove = true;
        }
        if (to_remove) // jezeli usunelismy wczesniej jakis to usuwamy ten co zostal i byl mu rowny
        {
            result++;
            node *q = p->next;
            p->next = q->next;
            delete q;
        } else p = p->next; // jezeli zadnego nie usunelismy to zmieniamy p
    }
    return result;
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

    insert_last(first, 1);
    insert_last(first, 1);
    insert_last(first, 1);
    insert_last(first, 2);
    insert_last(first, 2);
    insert_last(first, 3);
    insert_last(first, 4);
    insert_last(first, 4);
    insert_last(first, 5);
    insert_last(first, 6);
    insert_last(first, 7);
    insert_last(first, 7);


    int x = not_unique(first);

    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
    cout << endl << x;
    return 0;
}