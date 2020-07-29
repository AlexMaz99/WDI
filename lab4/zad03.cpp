#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

bool contain_odd_digit(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) return true;
        n = n / 10;
    }
    return false;

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

    bool row = false;

    for (int i = 0; i < MAX && !row; i++) {
        row = true;
        for (int j = 0; j < MAX && row; j++) {
            if (!contain_odd_digit(tab[i][j])) {
                row = false;

            }
        }
    }
    if (row) cout << "TAK";
    else cout << "NIE";


    return 0;
}