#include <iostream>

using namespace std;

int main() {
    int a = 2018;
    int b = 1247;
    int c = 0;

    while (a > b) {
        c = a;
        a = b;
        b = c - a;
    }
    cout << a << endl;
    cout << c;
    return 0;
}
