#include <iostream>

using namespace std;

const int N = 3;

bool is_possible(int bin[N], int index, int sum1, int sum2, int sum3) {
    if (sum1 > 0 && sum1 == sum2 && sum2 == sum3) return true;
    if (index == N) return false;
    return is_possible(bin, index + 1, sum1 + bin[index], sum2, sum3) ||
           is_possible(bin, index + 1, sum1, sum2 + bin[index], sum3) ||
           is_possible(bin, index + 1, sum1, sum2, sum3 + bin[index]);
}

bool can_divide(int t[N]) {
    int bin[N];
    for (int i = 0; i < N; i++) {
        bin[i] = 0;
        while (t[i] != 0) {
            if (t[i] % 2 == 1) bin[i]++;
            t[i] /= 2;
        }
    }
    return is_possible(bin, 0, 0, 0, 0);
}

int main() {
    int t[N] = {2, 3, 5, 7, 15};
    return can_divide(t);
}