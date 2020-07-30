#include <iostream>

using namespace std;

const int N = 3;

bool can_move(int k) {
    if (k < 0 || k >= N) return false;
    return true;
}

int king_move(int row, int col, int sum, int tab[N][N], int &MIN) {
    if (row == N || sum > MIN) {
        if (sum < MIN) MIN = sum;
        return MIN;
    }
    sum += tab[row][col];
    if (can_move(col - 1)) krol(row + 1, col - 1, sum, tab, MIN);
    if (can_move(col + 1)) krol(row + 1, col + 1, sum, tab, MIN);
    king_move(row + 1, col, sum, tab, MIN);
}

int king(int tab[N][N], int k) {
    int MIN = 1000000;
    return king_move(0, k, 0, tab, MIN);
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];

    int k;
    cin >> k;

    return king(t, k);
}
