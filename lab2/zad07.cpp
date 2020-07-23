#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;
    int b;
    int c;

    cin >> number;

    for (int i = 1; i <= floor(sqrt(number)); i++) {
        if (number % i == 0) {
            b = number / i;
            c = i;
        }
    }

    cout << number << "=" << c << "*" << b;
    return 0;
}