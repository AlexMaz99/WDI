#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = 0; a < 100; i++) {
        a = a + b;
        b = a - b;
    }
    cout << a / b << ".";
    while (a != 0) {
        a = a % b;
        a = a * 10;
        cout << a / b;
    }

    return 0;
}