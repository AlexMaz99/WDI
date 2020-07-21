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

int NWW(int x, int y) {
    return x * y / NWD(x, y);
}

int main() {
    cout << "Enter 3 numbers: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    return NWW(NWW(a, b), c);
}