#include <iostream>
#include <cmath>

using namespace std;

const int N = 6;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 or n == 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;
    int k = 5;
    while (k >= sqrt(n)) {
        if (n % k == 0) return false;
        k += 2;
        if (n % k == 0) return false;
        k += 4;
    }
    return true;
}

int change_base(int tab[N], int start, int end) {
    int n = 0;
    int k = 1;

    while (start <= end) {
        if (tab[end] == 1) n += k;
        k *= 2;
        end--;
    }
    return n;
}

bool can_divide(int tab[N], int start = 0) {
    if (start == N) return true;
    if (tab[start] == 0) return false;

    for (int i = start; i < N && i - start < 30; i++) {
        if (is_prime(change_base(tab, start, i)))
            if (can_divide(tab, i + 1))
                return true;
    }
    return false;
}


int main() {
    int t[N] = {1, 1, 0, 1, 1, 0};

    return mozliwy_podzial(t);
}
