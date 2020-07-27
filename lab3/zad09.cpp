#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int MAX = 1000000;
    int t[MAX];
    bool flags[MAX];
    for (int i = 1; i < MAX; i++) flags[i] = false;
    int n;
    cin >> n;
    flags[0] = true;

    for (int i = 0; i < n; i++) cin >> t[i];

    for (int i = 0; i < n; i++) {
        if (flags[i]) {
            //znajduje dzielniki pierwsze liczby
            int divider = 2;
            int element = sqrt(t[i]);
            while (t[i] > 1 && divider <= element) {
                while (t[i] % divider == 0) {
                    //oflagowuje pola na ktore moge sie dostac (jezli nie sa poza tablica)
                    if (i + divider < n)
                        flags[i + divider] = true;

                    t[i] /= divider;
                }
                divider++;
            }
            if (t[i] > 1 && i + t[i] < n) flags[i + t[i]] = true;

        }
    }

    cout << flags[n - 2];
}
