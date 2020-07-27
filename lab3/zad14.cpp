#include <iostream>

using namespace std;

int main() {
    int tab[10], result = 0, x, y, counter;
    for (int i = 0; i < 10; i++) {
        cin >> tab[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 9; j > i; j--) {
            counter = 1;
            x = i;
            y = j;
            while (x < 10 && y > 0 && tab[x] == tab[y]) {
                x++;
                y--;
                if (tab[x] == tab[y]) {
                    counter++;
                }
            }
            if (counter > result) result = counter;
        }
    }
    cout << result;

    return 0;
}