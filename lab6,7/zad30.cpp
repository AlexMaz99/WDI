#include <iostream>
#include <cmath>

using namespace std;

bool is_composite(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3 || n == 5) return false;
    if (n % 2 == 0 || n % 3 == 0) return true;
    int b = 5;

    while (b <= sqrt(n)) {
        if (n % b == 0) return true;
        b += 2;
        if (n % b == 0) return true;
        b += 4;
    }
    return false;
}

int build_numbers(int ones, int zeros, int index, int number) {
    if (ones == 0 && zeros == 0 && is_composite(number)) {
        cout << number << endl;
        return 1;
    }
    if (index < 0) return 0;
    return build_numbers(ones - 1, zeros, index - 1, number + pow(2, index)) +
           build_numbers(ones, zeros - 1, index - 1, number);
}

int count_numbers(int A, int B) {
    return build_numbers(A - 1, B, A + B - 2, pow(2, A + B - 1));
}

int main() {
    return count_numbers(2, 3);

}