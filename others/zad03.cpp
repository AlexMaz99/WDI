#include <iostream>
#include <cmath>

using namespace std;

void decimal_to_binary(int n) {
    int i = 0;
    int tab[31];
    while (n != 0) {
        tab[i] = n % 2;
        n /= 2;
        i++;
    }
    i--;
    for (i; i >= 0; i--) {
        cout << tab[i];
    }
}

const int N = 8;

int binary_to_decimal(int tab[N], int start, int end) {
    int sum = 0;
    int j = end - start;
    while (start != end + 1) {
        sum += tab[start] * pow(2, j);
        start++;
        j--;
    }
    return sum;
}

int binary_to_decimal2(int n) {
    int sum = 0;
    int i = 0;
    while (n != 0) {
        sum += n % 10 * pow(2, i);
        n /= 10;
        i++;
    }
    return sum;
}


int main() {
    decimal_to_binary(20);
    int t[N] = {1, 0, 1, 1, 0, 0, 1, 0};
    cout << endl << binary_to_decimal2(10010) << endl;
    cout << binary_to_decimal(t, 3, 6);
    return 0;
}