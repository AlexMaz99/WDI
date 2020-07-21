#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 or n == 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;
    int b = 5;
    int c = sqrt(n);
    while (b <= c) {
        if (n % b == 0) return false;
        b += 2;
        if (n % b == 0) return false;
        b += 4;
    }
    return true;
}

int main() {
    int number;
    cin >> number;
    if (is_prime(number)) cout << "number is first";
    else cout << "number is not first";
    return 0;
}
