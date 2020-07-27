#include<iostream>

using namespace std;

int main() {
    int tab[10];
    for (int i = 0; i < 10; i++) tab[i] = 0;
    int number;

    while (true) {
        cin >> number;
        if (number == 0) break;

        int candidate = tab[0], index = 0;

        for (int i = 1; i < 10; i++) {
            if (tab[i] < candidate) {
                candidate = tab[i];
                index = i;
            }

        }

        if (number > tab[index]) {
            tab[index] = number;
        }

    }

    int smallest_number = tab[0];
    for (int i = 1; i < 10; i++) {
        if (tab[i] < smallest_number) smallest_number = tab[i];
    }
    cout << "10 co do wielkosci wartosc to: " << smallest_number;
    return 0;
}