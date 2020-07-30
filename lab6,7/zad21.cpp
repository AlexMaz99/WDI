# include <iostream>
# include <cmath>

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

bool can_jump(int t[N], int i, int k, bool tab[N]) {
    if (i == N - 1) return true;
    if (i > N - 1 || k > N - 1 || i + k > N - 1) return false;

    if (k < t[i] && t[i] % k == 0 && is_prime(k)) {
        tab[i + k] = true;
        if (can_jump(t, i + k, 1, tab)) return true;
        tab[i + k] = false;
    }
    if (can_jump(t, i, k + 1, tab)) return true;
    return false;
}

int can_go(int t[N]) {
    bool tab[N];
    for (int i = 0; i < N; i++) tab[i] = false;
    if (can_jump(t, 0, 1, tab)) {
        int counter = 0;
        for (int i = 0; i < N; i++)
            if (tab[i]) counter++;
        return counter;
    }
    return -1;
}

int main() {
    int t[N] = {6, 3, 3, 6, 3, 2};

    return can_go(t);
}