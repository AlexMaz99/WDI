#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct node {
    string txt;
    node *next;
};

bool txt_not_exist(node *first, string new_txt) //sprawdza czy nie ma juz takiego wyrazu
{
    if (first == NULL) return true;
    while (first != NULL && first->txt[0] <= new_txt[0]) {
        if (first->txt == new_txt) return false;
        first = first->next;
    }
    return true;
}

bool first_is_smaller(string a, string b) //jezeli pierwsza jest mniejsza zwraca prawde
{
    if (a[0] < b[0]) return true;
    if (a[0] > b[0]) return false;
    unsigned int i = 1;
    while (i < a.size() && i < b.size() && a[i] == b[i]) i++;
    if (i == a.size()) return true;
    if (i == b.size()) return false;
    if (a[i] < b[i]) return true;
    return false;
}

bool can_add(node *&first, string new_txt) {
    if (!txt_not_exist(first, new_txt)) return false; //jezeli jest juz taki wyraz to wychodze
    node *p = new node;
    p->txt = new_txt;
    p->next = NULL;
    if (first == NULL) //jezeli lista jest pusta to dodaje na poczatek
    {
        first = p;
        return true;
    }
    if (!first_is_smaller(first->txt,
                          new_txt)) // jezeli pierwszy wyraz jest wiekszy od nowego do dodaje nowy na miejsce pierwszego
    {
        p->next = first;
        first = p;
        return true;
    }

    node *q = first;
    while (q->next != NULL && first_is_smaller(q->next->txt, new_txt)) q = q->next; //szukam miejsca dla nowego wyrazu
    if (q->next == NULL) {
        q->next = p;
        return true;
    }
    p->next = q->next;
    q->next = p;
    return true;

}

int main() {
    node *first = new node;
    node *p = new node;
    node *q = new node;
    node *y = new node;
    first->txt = "aabc";
    first->next = p;
    p->txt = "aacc";
    p->next = q;
    q->txt = "ab";
    q->next = y;
    y->txt = "abba";
    y->next = NULL;

    string x;
    cin >> x;
    if (can_add(first, x)) {
        while (first != NULL) {
            cout << first->txt << " ";
            first = first->next;
        }
    }
}