# include <iostream>

using namespace std;

const int N = 3;

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

bool good_move(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) return false;
    if (r1 < 0 || r1 > 7 || c1 < 0 || c1 > 7 || r2 < 0 || r2 > 7 || c2 < 0 || c2 > 7) return false;
    return true;
}

bool find_place(int t[N][N], int &sum, wsp &towers, int r1, int c1, int r2, int c2) {
    if (r1 > 7 || r2 > 7 || c1 > 7 || c2 > 7) return false;
    if (good_move(r1, c1, r2, c2)) {
        int tmp = count_sum(t, r1, c1, r2, c2);
        if (tmp > sum) {
            sum = tmp;
            towers.r1 = r1;
            towers.r2 = r2;
            towers.c1 = c1;
            towers.c2 = c2;
        }
    }
    return find_place(t, sum, towers, r1 + 1, c1, r2, c2) ||
           find_place(t, sum, towers, r1, c1 + 1, r2, c2) ||
           find_place(t, sum, towers, r1, c1, r2 + 1, c2) ||
           find_place(t, sum, towers, r1, c1, r2, c2 + 1);
}

void place_towers(int t[N][N]) {
    int sum = 0;
    wsp towers;
    find_place(t, sum, towers, 0, 0, 0, 0);
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];

    place_towers(t);
    return 0;
}
