#include <iostream>

using namespace std;

int main() {
    int sum[17] = {};
    int tab[152] = {};
    bool result[5000] = {false};
    int n;
    sum[0] = 1;
    sum[1] = 2;
    sum[2] = 4;
    //znajduje wszystkie sumy podciągów od 1 wyrazu do n
    for (int i = 3; i < 17; i++) {
        sum[i] = 2 * sum[i - 1] - sum[i - 3];
    }

    //znajduje wszystkie możliwe sumy podciągów
    tab[0] = 1;
    tab[1] = 2;
    int licznik = 2;
    for (int i = 2; i < 17; i++) {
        tab[licznik++] = sum[i];
        for (int j = 0; j < i; j++) {
            tab[licznik++] = sum[i] - sum[j];
        }
    }
    //które liczby mogą być a które nie)
    for (int i = 0; i < 152; i++) {
        result[tab[i]] = true;
    }

    //wynik
    cin >> n;
    for (int i = n + 1; i < 5000; i++) {
        if (!result[i]) {
            cout << i;
            return 0;
        }
    }
}
