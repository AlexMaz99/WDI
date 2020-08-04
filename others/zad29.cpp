#include <iostream>
#include <cmath>

using namespace std;

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

void build_numbers(int a, int b, int number, int multiplication, int &counter) {
    if (a == 0 && b == 0) {
        if (is_prime(number)) {
            counter++;
            cout << number << endl;
        }
        return;
    }
    if (a > 0) build_numbers(a / 10, b, a % 10 * multiplication + number, multiplication * 10, counter);
    if (b > 0)build_numbers(a, b / 10, b % 10 * multiplication + number, multiplication * 10, counter);
}

int count_prime_numbers(int a, int b) {
    int counter = 0;
    build_numbers(a, b, 0, 1, counter);
    return counter;
}

int main() {
    return count_prime_numbers(123, 76);
}