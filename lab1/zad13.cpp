#include <iostream>

using namespace std;

int main() {
    int tab[100000];
    for (int i = 2; i < 100000; i++) {
        long long int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum = sum + j;
            }
            tab[i] = sum;
        }

    }
    for (int k = 2; k < 100000; k++) {
        for (int l = k + 1; l < 100000; l++) {
            if (k != l && tab[k] == l && tab[l] == k) cout << k << ", " << l << endl;
        }
    }
    return 0;
}