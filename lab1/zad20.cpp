#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a[1000];
    double b[1000];
    cin >> a[0] >> b[0];
    if (a[0] == b[0]) {
        cout << "0";
        return 0;
    }
    a[1] = sqrt(a[0] * b[0]);
    b[1] = (a[0] + b[0]) / 2.0;
    int n = 1;

    while (a[n] != b[n]) {
        a[n + 1] = sqrt(a[n] * b[n]);
        b[n + 1] = (a[n] + b[n]) / 2.0;
        n++;
    }
    cout << n;
}