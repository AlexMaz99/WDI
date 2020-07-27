#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

bool contains_odd_digit(int n) {
    while (n > 0) {
        if (n % 2 == 1)return true;
        n = n / 10;
    }
    return false;
}

const int MAX = 10;

int main() {
    srand(time(NULL));
    int tab[MAX];

    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % 1000 + 1;
        cout << tab[i] << " ";
    }

    cout << endl;

    bool exist = true;


    for (int i = 0; i < MAX && exist; i++) {
        if (!contains_odd_digit(tab[i])) exist = false;

    }
    if (exist) cout << "yes";
    else cout << "no";
    return 0;
}