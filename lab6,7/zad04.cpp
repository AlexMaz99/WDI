#include <iostream>

using namespace std;

const int N = 5;

int weight(int n) {
    int counter = 0;
    int k = 2;
    while (n > 1) {
        if (n % k == 0) counter++;
        while (n % k == 0) n /= k;
        k++;
    }
    return counter;
}

bool can_sum(int sum1, int sum2, int sum3, int i, int tab[N]) {
    if (sum1 > 0 && sum1 == sum2 && sum2 == sum3) return true;
    if (i == N) return false;
    return (can_sum(sum1 + tab[i], sum2, sum3, i + 1, tab) || can_sum(sum1, sum2 + tab[i], sum3, i + 1, tab) ||
            can_sum(sum1, sum2, sum3 + tab[i], i + 1, tab));
}

bool can_divide(int t[N]) {
    int tab[N];
    for (int i = 0; i < N; i++) {
        tab[i] = weight(t[i]) + 1;
    }
    return can_sum(0, 0, 0, 0, tab);
}

int main() {
    int t[N];
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    return can_divide(t);
}