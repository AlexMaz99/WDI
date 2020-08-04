#include <iostream>

using namespace std;

const int N = 4;

struct wsp {
    int r1;
    int c1;
    int r2;
    int c2;
};

int count_sum(int t[N][N], int row[N], int col[N], int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == k2) return 0;
    if (r1 == r2) return col[c1] + col[k2] + row[r1] - 2 * t[r1][c1] - 2 * t[r2][k2];
    if (c1 == k2) return row[r1] + row[r2] + col[c1] - 2 * t[r1][c1] - 2 * t[r2][k2];
    return row[r1] + col[c1] + row[r2] + col[k2] - 2 * t[r1][c1] - 2 * t[r2][k2] - t[r1][k2] - t[r2][c1];
}

wsp place_towers(int t[N][N]) {
    int row[N], col[N];
    int biggest_sum = 0;
    wsp towers;
    for (int i = 0; i < N; i++) {
        row[i] = col[i] = 0;
        for (int j = 0; j < N; j++) {
            row[i] += t[i][j];
            col[i] += t[j][i];
        }
    }

    for (int r1 = 0; r1 < N; r1++) {
        for (int c1 = 0; c1 < N; c1++) {
            for (int r2 = r1; r2 < N; r2++) {
                for (int c2 = 0; c2 < N; c2++) {
                    int sum = count_sum(t, row, col, r1, c1, r2, c2);
                    if (biggest_sum < sum) {
                        biggest_sum = sum;
                        towers.r1 = r1;
                        towers.c1 = c1;
                        towers.r2 = r2;
                        towers.c2 = c2;
                    }
                }
            }
        }
    }
    return towers;
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];

    wsp towers = place_towers(t);
    cout << towers.r1 << " " << towers.c1 << " " << towers.r2 << " " << towers.c2 << " ";

}