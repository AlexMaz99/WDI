#include <iostream>

using namespace std;

int main() {
    int number;
    int tab[10000];
    int a = 1, b = 1;
    bool done = false;

    cin >> number;
    tab[0] = 1;

    if (number == 1) done = true;
    for (int i = 1; a + b <= number && !done; i++) {
        b = a + b;
        a = b - a;
        tab[i] = b;

        for (int j = i; j >= 0 && !done; j--) {
            if (tab[j] * tab[i] == number) {
                done = true;
            }
        }
    }
    if (done) cout << "YES";
    else cout << "NO";
}