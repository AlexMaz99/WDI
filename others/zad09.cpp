#include <iostream>

using namespace std;

//9,14,15,17,22

int main() {
    int fib[100], n, sum, k;
    fib[0] = fib[1] = 1;
    cin >> n;

    for (int i = 2; i < 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int j = n + 1; j < 100; j++) {
        sum = 0;
        k = 0;
        for (int i = 0; sum < j; i++) {
            sum += fib[i];
        }
        while (sum > j) {
            sum = sum - fib[k];
            k++;
        }
        if (sum != j) {
            return j;
        }
    }

    return 0;
}