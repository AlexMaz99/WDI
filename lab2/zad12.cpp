#include <iostream>

using namespace std;


bool increasing_digits(int n) {
    int digits[10];
    digits[0] = n % 10;
    n = n / 10;
    int i = 1;
    while (n > 0) {
        digits[i] = n % 10;
        if (digits[i] >= digits[i - 1]) return false;
        n = n / 10;
        i++;
    }
    return true;
}

int main() {
    int number;
    cin >> number;
    if (increasing_digits(number)) cout << "INCREASING";
    else cout << "NOT INCREASING";
    return 0;
}