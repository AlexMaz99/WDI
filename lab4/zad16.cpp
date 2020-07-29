#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

bool has_prime_digits(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0 || digit == 1 || digit == 4 || digit == 6 || digit == 8 || digit == 9) return false;
        n = n / 10;
    }
    return true;

}

int main() {
    const int MAX = 4;
    int tab[MAX][MAX];
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            tab[i][j] = rand() % 1000 + 1;
            //cout<<tab[i][j]<<"\t";
            cin >> tab[i][j];
        }
        cout << endl;
    }

    bool row = true;

    for (int i = 0; i < MAX && row; i++) {
        row = false;
        for (int j = 0; j < MAX && !row; j++) {
            if (has_prime_digits(tab[i][j])) {
                row = true;

            }
        }
    }
    return row;
}
