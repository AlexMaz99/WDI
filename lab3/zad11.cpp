#include <iostream>

using namespace std;

int main() {
    const int MAX = 10;
    int tab[MAX];
    for (int i = 0; i < MAX; i++) cin >> tab[i];

    int result = 0;
    for (int i = 1; i < MAX; i++) {
        int difference = tab[i] - tab[i - 1];
        int counter = 2;
        while (i < MAX && tab[i + 1] - tab[i] == difference) {
            licznik++;
            i++;
        }
        if (result <= licznik)result = licznik;
    }

    cout << result;
    return 0;

}