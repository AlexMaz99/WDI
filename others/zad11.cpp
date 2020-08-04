#include <iostream>

using namespace std;

const int N = 10;

int equals_sum(int t[N]) {
    int sum, index_sum, length, max_length = 0, j;

    for (int i = 0; i < N - 1; i++) {
        sum = t[i];
        index_sum = i;
        length = 1;
        j = i;
        while (j < N - 1 && t[j] < t[j + 1]) {
            sum += t[j + 1];
            index_sum += j + 1;
            length++;
            if (sum == index_sum && max_length < length) max_length = length;
            j++;
        }
    }
    return max_length;
}

int main() {
    int tab[N];
    for (int i = 0; i < N; i++) cin >> tab[i];
    return equals_sum(tab);
}