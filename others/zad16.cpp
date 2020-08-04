#include <iostream>

using namespace std;

int main() {
    int a[1000], b[1000], c[1000], k, m = 3;

    a[0] = a[1] = b[0] = b[1] = b[2] = 1;
    a[2] = 2;
    c[0] = 1;
    c[1] = 2;
    c[2] = 3;

    cin >> k;

    for (int n = 3; m < k; n++) {
        a[n] = a[n - 1] + a[n - 2];
        b[n] = b[n - 1] + b[n - 2] + b[n - 3];
        if (c[m - 1] != a[n]) {
            c[m] = a[n];
            m++;
        }
        if (c[m - 1] != b[n]) {
            c[m] = b[n];
            m++;
        }
    }

    cout << c[k - 1];
    return 0;
}