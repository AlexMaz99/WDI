# include <iostream>

using namespace std;

const int N = 6;

bool can_connect(int t[N], int sum, int new_sum, int index, int counter) {
    if (new_sum == sum && counter == 3) return true;
    if (index == N || counter > 3) return false;
    return can_connect(t, sum, new_sum + t[index], index + 1, counter + 1) ||
           can_connect(t, sum, new_sum, index + 1, counter);
}

bool can_get_resistance(int t[N], int R) {
    return can_connect(t, R, 0, 0, 0);
}

int main() {
    int t[N] = {10, -5, 1, 7, -2, 2};
    int R;
    cin >> R;

    return can_get_resistance(t, R);
}
