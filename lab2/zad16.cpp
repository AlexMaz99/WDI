#include <iostream>
#include <cmath>


using namespace std;

bool is_prime(int n) {
    if (n == 2 or n == 3) return true;
    if (n == 1 or n % 2 == 0 or n % 3 == 0) return false;
    int k = 3;
    while (k <= sqrt(n)) {
        if (n % k == 0) return false;
        k += 2;
        if (n % k == 0) return false;
        k += 4;
    }
    return true;
}

int rotate(int n) {
    int obr_n = 0;
    while (n > 0) {
        obr_n = obr_n * 10 + (n % 10);
        n /= 10;
    }
    return obr_n;
}

int length(int n) {
    int length_n = 0;
    int c_n = n;

    while (c_n > 0) {
        length_n++;
        c_n /= 10;
    }
    return length_n;
}


int main() {
    int n, m, c_n, c_m;
    int new_length = 0;
    int max_mask = 1;
    int prime_counter = 0;


    cin >> n >> m;

    int m_length = length(m);
    new_length = length(m) + length(n);

    for (int i = 0; i < new_length; i++)
        max_mask *= 2;

    int current_mask;
    int sum;
    int new_num;
    for (int i = 0; i < max_mask; i++) {
        c_n = n;
        c_m = m;
        new_num = 0;
        sum = 0;
        current_mask = i;
        for (int j = 0; j < new_length; j++) {
            if (current_mask % 2 == 1) sum++;
            current_mask /= 2;
        }
        if (sum == m_length) {
            current_mask = i;
            for (int j = 0; j < new_length; j++) {
                if (current_mask % 2 == 1) {
                    new_num = new_num * 10 + (c_m % 10);
                    c_m /= 10;
                } else {
                    new_num = new_num * 10 + (c_n % 10);
                    c_n /= 10;
                }
                current_mask /= 2;
            }
            new_num = rotate(new_num);
            cout << new_num << "\t";
            if (is_prime(new_num)) {
                prime_counter++;
            }
        }

    }
    return prime_counter;
}