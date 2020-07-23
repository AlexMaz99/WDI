#include <iostream>
#include <cmath>

using namespace std;

int reverse(int n) {
    int new_n = 0;
    int last;
    while (n > 0) {
        last = n % 10;
        n /= 10;
        new_n = new_n * 10 + last;
    }
    return new_n;
}

int divided_by_k(int n, int k) {
    n = reverse(n);
    int suma = 0;
    int c_n = n;
    int c_mask;
    int max_mask = 1;
    int counter = 0;

    while (c_n > 0) {
        c_n /= 10;
        max_mask *= 2;
    }

    for (int mask = 1; mask < max_mask; mask++) {
        c_n = n;
        c_mask = mask;
        suma = 0;
        while (c_n > 0) {
            if (c_mask % 2 == 1)
                suma = suma * 10 + c_n % 10;
            c_mask /= 2;
            c_n /= 10;
        }
        cout << suma << "\t";
        if (suma % k == 0) counter++;
    }
    return counter;
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    return divided_by_k(n, k);
}

// VERSION 2

/*
int main() {
    int n;
    cin >> n;
    int n_copy = n, n_length = 0;
    while (n_copy != 0) {
        n_length++;
        n_copy /= 10;
    }

    for (int binary_seq = (1 << n_length) - 1, binary_seq != 1, binary_seq--){
        int subnumber = 0;
        for (int i = n_length - 1, i >=0, i--){
            if ((binary_seq >> i) % 2 == 1) {
                subnumber *= 10;
                subnumber += (n / pow(10, i) % 10);
            }
        }
        if (subnumber % 7 == 0)
            cout << subnumber << " ";
    }
}*/
