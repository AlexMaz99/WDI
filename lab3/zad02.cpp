#include <iostream>

using namespace std;

int main() {
    //tablica ilości wystąpień cyfr
    int tab[10];
    for (int i = 0; i < 10; i++)tab[i] = 0;

    int a, b;
    cin >> a >> b;

    while (a > 0) {
        tab[a % 10]++;
        tab[b % 10]--;
        a /= 10;
        b /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (tab[i] != 0) {
            cout << "nie maja takich samych cyfr";
            return 0;
        }
    }

    if (a == 0 && b == 0)cout << "maja takie same cyfry";
    else cout << "nie maja takich samych cyfr";

    return 0;
}