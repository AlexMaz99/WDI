#include <iostream>

using namespace std;

bool unique(int n) {
    int last_digit = n % 10;
    n = n / 10;
    while (n > 0) {
        if (last_digit == n % 10) return false;
        n = n / 10;
    }
    return true;

}

int main() {
    int number;
    cin >> number;
    if (unique(number)) cout << "YES";
    else cout << "NO";

    return 0;
}