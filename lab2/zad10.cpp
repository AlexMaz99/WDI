#include <iostream>

using namespace std;

int main() {
    double k, x, center, field = 0, result;
    cin >> k >> result;

    x = (k - 1) / result;
    center = (k + 3) / 4;

    for (int i = 0; i < result; i++) {
        field = field + x * (1 / (center + x * i));
    }

    cout << field;
}