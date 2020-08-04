# include <iostream>

using namespace std;

const int N = 4;

struct wsp {
    int r1;
    int c1;
    int r2;
    int c2;
};

int count_sum(int t[N][N], int r1, int c1, int r2, int c2) {
    bool board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = false;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i != r1) board[i][c1] = true;
        if (i != c1) board[r1][i] = true;
        if (i != r2) board[i][c2] = true;
        if (i != c2) board[r2][i] = true;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j]) sum += t[i][j];
    return sum;
}

wsp place_towers(int t[N][N]) {
    int biggest_sum = 0, sum;
    wsp towers;

    for (int r1 = 0; r1 < N; r1++) {
        for (int c1 = 0; c1 < N; c1++) {
            for (int r2 = 0; r2 < N; r2++) {
                for (int c2 = 0; c2 < N; c2++) {
                    sum = count_sum(t, r1, c1, r2, c2);
                    if (biggest_sum < sum) {
                        biggest_sum = sum;
                        towers.r1 = r1;
                        towers.r2 = r2;
                        towers.c1 = c1;
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
    cout << towers.r1 << " " << towers.c1 << " " << towers.r2 << " " << towers.c2;
    return 0;
}