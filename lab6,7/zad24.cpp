# include <iostream>
#include <cmath>

using namespace std;

const int N = 6;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int k = 5;
    while (k <= sqrt(n)) {
        if (n % k == 0) return false;
        k += 2;
        if (n % k == 0) return false;
        k += 4;
    }
    return true;
}

void build(int N, int n, int number, int index) {
    if (number > 9 && number < N && is_prime(number)) cout << number << endl;
    if (n == 0) return;
    build(N, n / 10, number + (n % 10) * index, index * 10);
    build(N, n / 10, number, index);
}

void write_numbers(int n) {
    build(n, n, 0, 1);
    return;
}

int main() {
    int n;
    cin >> n;
    write_numbers(n);
    return 0;
}