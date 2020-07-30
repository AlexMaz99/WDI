#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int b = 5;

    while (b <= sqrt(n)) {
        if (n % b == 0) return false;
        b += 2;
        if (n % b == 0) return false;
        b += 4;
    }
    return true;
}

int build_number(int a, int b, int result = 0, int index = 1) {
    int sum = 0;
    if (a == 0 && b == 0 && is_prime(result)) return 1;
    if (a > 0) sum += build_number(a / 10, b, result + index * (a % 10), index * 10);
    if (b > 0) sum += build_number(a, b / 10, result + index * (b % 10), index * 10);
    return sum;
}


int main() {
    int a, b;
    cin >> a >> b;
    return build_number(a, b);
}
