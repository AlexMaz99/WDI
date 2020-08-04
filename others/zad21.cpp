# include <iostream>

using namespace std;

const int N = 4;

int tower(int t[N][N], int w1, int k1, int w2, int k2) {
    bool board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = false;
    for (int i = 0; i < N; i++) {
        if (i != w1) board[i][k1] = true;
        if (i != k1) board[w1][i] = true;
        if (i != w2) board[i][k2] = true;
        if (i != k2) board[w2][i] = true;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j]) sum += t[i][j];
    cout << sum << endl;
    return sum;
}

bool can_increase_sum(int t[N][N], int w1, int k1, int w2, int k2) {
    int sum = tower(t, w1, k1, w2, k2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i != w2 || j != k2) && !(i == w1 && j == k1))
                if (tower(t, i, j, w2, k2) > sum) {
                    cout << i << " " << j;
                    return true;
                }

            if ((i != w1 || j != k1) && !(i == w2 && j == k2))
                if (tower(t, w1, k1, i, j) > sum) {
                    cout << i << " " << j;
                    return true;
                }

        }
    }
    return false;
}

int main() {
    int tab[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> tab[i][j];

    int w1 = 2, k1 = 0, w2 = 3, k2 = 1;

    return can_increase_sum(tab, w1, k1, w2, k2);
}

// version 2

//# include <iostream>
//
//using namespace std;
//
//const int N = 4;
//
//int tower(int t[N][N], int w1, int k1, int w2, int k2, int rows[N], int cols[N]) {
//    int sum = 0;
//    if (w1 == w2) sum = rows[w1] + cols[k1] + cols[k2] - 2 * t[w1][k1] - 2 * t[w2][k2];
//    else if (k1 == k2) sum = cols[k1] + rows[w1] + rows[w2] - 2 * t[w1][k1] - 2 * t[w2][k2];
//    else sum = rows[w1] + rows[w2] + cols[k1] + cols[k2] - t[w1][k1] - t[w2][k2] - t[w1][k2] - t[w2][k1];
//    return sum;
//}
//
//bool can_increase_sum(int t[N][N], int w1, int k1, int w2, int k2) {
//    int rows[N];
//    int cols[N];
//    for (int i = 0; i < N; i++) {
//        rows[i] = cols[i] = 0;
//        for (int j = 0; j < N; j++) {
//            rows[i] += t[i][j];
//            cols[i] += t[j][i];
//        }
//    }
//    int sum = tower(t, w1, k1, w2, k2);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if ((i != w2 || j != k2) && !(i == w1 && j == k1))
//                if (tower(t, i, j, w2, k2) > sum) {
//                    cout << i << " " << j;
//                    return true;
//                }
//
//            if ((i != w1 || j != k1) && !(i == w2 && j == k2))
//                if (tower(t, w1, k1, i, j) > sum) {
//                    cout << i << " " << j;
//                    return true;
//                }
//
//        }
//    }
//    return false;
//}
//
//int main() {
//    int tab[N][N];
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            cin >> tab[i][j];
//
//    int w1 = 2, k1 = 0, w2 = 3, k2 = 1;
//
//    return can_increase_sum(tab, w1, k1, w2, k2);
//}