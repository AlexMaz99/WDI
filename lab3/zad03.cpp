#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool tab[10000];

    for (int i = 0; i < N; i++) {
        tab[i] = true;
    }

    for (int i = 2; i <= sqrt(N); i++) {
        if (tab[i]) {
            for (int j = i * i; j < N; j += i) {
                tab[j] = false;
            }
        }
    }
    for (int k = 2; k < N; k++) {
        if (tab[k])cout << k << " ";
    }


    return 0;
}