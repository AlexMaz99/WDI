#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int factorial = 1, nominator = 2, denominator = 1;

    for (int i = 2; i <= 19; i++) {
        factorial = factorial * i;
        nominator = nominator * (factorial / denominator) + 1;
        denominator = factorial;
    }

    cout << nominator / denominator << ".";
    while (n > 0) {
        nominator = nominator % denominator;
        nominator = nominator * 10;
        cout << nominator / denominator;
        n--;
    }

    return 0;
}
