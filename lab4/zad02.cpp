#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

bool odd_digits(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) return false;
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
            cout << tab[i][j] << "\t";
            // cin >> tab[i][j];
        }
        cout << endl;
    }

    int k = 0;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (odd_digits(tab[i][j])) {
                k++;
                break;
            }
        }
    }
    if (k == MAX) cout << "YES";
    else cout << "NO";


    return 0;
}
