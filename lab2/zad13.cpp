#include <iostream>

using namespace std;

int main() {
    int tab[100];
    for (int i = 0; i < 100; i++) tab[i] = 0;

    int n = 1, i = -1;
    double average = 0;
    while (n != 0) {
        cin >> n;
        if (n == 0) break;
        i++;
        tab[i] = n;
    }

    for (int j = 0; j <= i; j++) {
        if (j == 0) {
            average = (tab[j + 1] + tab[j + 2] + tab[j + 3] + tab[j + 4]) / 4;
            if (average == tab[j]) cout << tab[j] << " ";
        }
        if (j == 1) {
            average = (tab[j + 1] + tab[j + 2] + tab[j + 3] + tab[j - 1]) / 4;
            if (average == tab[j]) cout << tab[j] << " ";
        }
        if (j == i) {
            average = (tab[j - 4] + tab[j - 2] + tab[j - 3] + tab[j - 1]) / 4;
            if (average == tab[j]) cout << tab[j] << " ";
        }
        if (j == i - 1) {
            average = (tab[j + 1] + tab[j - 2] + tab[j - 3] + tab[j - 1]) / 4;
            if (average == tab[j]) cout << tab[j] << " ";
        }
        if (j > 1 && j < i - 1) {
            average = (tab[j + 1] + tab[j - 2] + tab[j - 1] + tab[j + 2]) / 4;
            if (average == tab[j]) cout << tab[j] << " ";
        }


    }
    return 0;

}