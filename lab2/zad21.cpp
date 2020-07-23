#include <iostream>

using namespace std;

int main() {
    int a[1000];
    int b[1000];

    a[0] = 0;
    a[1] = 1;
    b[0] = 2;
    b[1] = 2;
    int x = 0, n = 0;
    while (true) {
        if (n >= 2) {
            a[n] = a[n - 1] - b[n - 1] * a[n - 2];
            b[n] = b[n - 1] + 2 * a[n - 1];
        }
        cin >> x;
        if (x == a[n]) cout << b[n] << endl;
        else break;
        n++;
    }
    return 0;
}