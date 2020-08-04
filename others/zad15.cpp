#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int a[1000], b[1000], k;
    int smallest_difference = 100, number = 0;
    string result;
    cin >> k;
    a[0] = 1;
    b[0] = 2;

    if (k == 1) {
        cout << "a0";
        return 0;
    }
    if (k == 2) {
        cout << "b0";
        return 0;
    }

    for (int n = 1; n < 100; n++) {
        b[n] = b[n - 1] + a[n - 1];
        a[n] = a[n - 1] + b[n] / 3;
        cout << "a[" << n << "]=" << a[n] << "\t";
        cout << "b[" << n << "]=" << b[n] << "\t";

        if (smallest_difference > abs(k - a[n])) {
            smallest_difference = abs(k - a[n]);
            number = n;
            result = "a";
        }
        if (smallest_difference > abs(k - b[n])) {
            smallest_difference = abs(k - b[n]);
            number = n;
            result = "b";
        }
        if (b[n] > k) break;
    }

    cout << result << number;
    return 0;

}
