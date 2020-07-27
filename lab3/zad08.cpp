#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

bool all_odd(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0)return false;
        n = n / 10;
    }
    return true;
}

int main() {
    srand(time(NULL));
    const int MAX = 10;
    int tab[MAX];

    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % 1000 + 1;
        cout << tab[i] << " ";
    }

    cout << endl;

    int i = 0;

    while (i < MAX) {
        if (all_odd(tab[i])) {
            cout << "yes";
            return 0;
        }
        i++;
    }
    cout << "no";
    return 0;

}