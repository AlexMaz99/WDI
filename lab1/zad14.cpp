#include <iostream>

using namespace std;

int a, b, c, d;

int NWD(int x, int y) {
    for (int r; r--; r <= 0) {
        d = x / y;
        r = x - y * d;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    cout << "Enter 3 numbers: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    return NWD(NWD(a, b), c);
}