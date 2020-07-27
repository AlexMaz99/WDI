#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int tab[2600], rest = 0, quantity = 0;
    for (int i = 0; i < 2600; i++) tab[i] = 0;

    tab[0] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= quantity; j++) {
            tab[j] = tab[j] * i + rest;
            rest = 0;
            if (tab[j] >= 10) {
                rest = tab[j] / 10;
                tab[j] = tab[j] % 10;
                if (j == quantity)quantity++;
            }
        }
    }

    for (quantity; quantity >= 0; quantity--) cout << tab[quantity];

    return 0;
}
