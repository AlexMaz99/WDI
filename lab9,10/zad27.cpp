#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};


int divide_elements(node *&list, node *&even, node *&odd) {
    if (list == NULL) return 0;
    int counter = 0;
    node *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        if (tmp->val > 0 && tmp->val % 2 == 0) //-2 4 -3 5 -1 -8 -9 10 6
        {
            tmp->next = even;
            even = tmp;
        } else if (tmp->val < 0 && tmp->val % 2 != 0) {
            tmp->next = odd;
            odd = tmp;
        } else {
            delete tmp;
            counter++;
        }
    }
    return counter;
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
    node *list = new node;
    list = NULL;
    node *even = new node;
    even = NULL;
    node *odd = new node;
    odd = NULL;

    insert_last(list, -2);
    insert_last(list, 4);
    insert_last(list, -3);
    insert_last(list, 5);
    insert_last(list, -1);
    insert_last(list, -8);
    insert_last(list, -9);
    insert_last(list, 10);
    insert_last(list, 6);


    cout << divide_elements(list, even, odd) << endl;
    while (even != NULL) {
        cout << even->val << " ";
        even = even->next;
    }
    cout << endl;
    while (odd != NULL) {
        cout << odd->val << " ";
        odd = odd->next;
    }

    return 0;
}