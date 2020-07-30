#include <iostream>

using namespace std;
const int N = 5;


int find_n(int current, int result, int index, int tab[N]) {
    if (current == result) return 1;
    if (index >= N) return 0;
    return find_n(current * tab[index], result, index + 1, tab) + find_n(current, result, index + 1, tab);
}

int count_n(int t[N], int n) {
    return find_n(1, n, 0, t);
}

int main() {
    int t[N] = {1, 3, 4, 2, 6};
    int result;
    cin >> result;
    return count_n(t, result);
}