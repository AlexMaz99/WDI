#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

bool is_composite(int n) //sprawdza czy liczba jest zlozona
{
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return true;
    }
    return false;
}

int const MAX = 10;

bool fib(int tab[MAX]) {
    int i = 1;
    int a = 1;
    while (i < MAX) {
        if (!is_composite(tab[i])) return false; //jezeli nie wszystkie liczby o indeksach fib sa zlozone to zwraca false
        i = i + a;
        a = i - a;
    }
    for (int j = 0; j <
                    MAX; j++) //jezeli nie zwrocila false to znaczy ze wszystkie fib sa zlozone i teraz sprawdzamy czy ktoras jest pierwsza
    {
        if (!is_composite(tab[j])) return true;
    }
    return false;
}

int main() {
    srand(time(NULL));
    int tab[MAX];
    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % 1000;
        cout << tab[i] << " ";
    }
    if (fib(tab)) cout << "yes";
    else cout << "no";
    return 0;

}