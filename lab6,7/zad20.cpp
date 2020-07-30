#include <iostream>

using namespace std;
const int N = 3;
int t[N][N];

bool can_sum(int t[N][N], int sum, int current_sum, int r, int c, bool rows[N], bool cols[N]) {

    if (sum == current_sum) return true;
    if (current_sum > sum) return false;

    if (c >= N) {
        r = r + 1;
        c = 0;
    }
    if (r >= N) return false;
    if (!rows[r] && !cols[c]) {
        rows[r] = true;
        cols[c] = true;
        if (can_sum(t, sum, current_sum + t[r][c], r, c + 1, rows, cols)) return true;
        rows[r] = false;
        cols[c] = false;
    }
    if (can_sum(t, sum, current_sum, r, c + 1, rows, cols)) return true;

    return false;
}

bool can_choose(int t[N][N], int sum) {
    bool rows[N], cols[N];
    for (int i = 0; i < N; i++) rows[i] = cols[i] = false;
    return can_sum(t, sum, 0, 0, 0, rows, cols);
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];

    return can_choose(t, 10);
}
