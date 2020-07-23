#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, sum, number;
    double power;
    cin >> N;

    for (int i = pow(10, N - 1); i < pow(10, N + 1); i++) {
        sum = 0;
        number = i;
        while (number > 0) {
            power = pow(number % 10, N);
            sum = sum + power;
            number = number / 10;
        }
        if (i == sum) cout << i << endl;
    }

    return 0;
}