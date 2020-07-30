#include <iostream>

using namespace std;
const int N = 6;


bool can_divide(int t[N], int index, int sum, int counter1, int counter2, int k) {
    if (sum == 0 && counter1 + counter2 == k) return true;
    if (index == N) return false;
    return can_divide(t, index + 1, sum + t[index], counter1 + 1, counter2, k) ||
           can_divide(t, index + 1, sum, counter1, counter2, k) ||
           can_divide(t, index + 1, sum - t[index], counter1, counter2 + 1, k);
}

int main() {
    int t[N] = {8, 3, 2, 5, 1, 1};
    int k;
    cin >> k;
    return can_divide(t, 0, 0, 0, 0, k);
}