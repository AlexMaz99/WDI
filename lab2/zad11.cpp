#include <iostream>

using namespace std;

bool check(int n) {
    int a = 2;
    if (n == 2) return true;
    for (int i = 0; n >= a; i++) {
        a = 3 * a + 1;
        if (n % a == 0) return true;
    }
    return false;
}

int main() {
    int number;
    cin >> number;
    if (check(number))cout << "YES";
    else cout << "NO";

    return 0;
}