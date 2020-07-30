#include <iostream>

using namespace std;
const int N = 2;
int t[N][N];

bool can_move(int w1, int k1, int w2, int k2, int t[N][N]) {
    if (k2 >= N || w2 >= N) return false;
    int n = t[w2][k2];
    while (n >= 10) {
        n = n / 10;
    }
    if (t[w1][k1] % 10 < n) return true;
    return false;
}

bool king(int t[N][N], int w, int k) {
    if (w == N - 1 && k == N - 1)
        return true;

    if (can_move(w, k, w + 1, k + 1, t))
        return king(t, w + 1, k +
                              1); // mozna isc w prawy gorny rog, prawo, prawy dolny, dol, lewy dolny
    if (can_move(w, k, w + 1, k, t))
        return king(t, w + 1, k);

    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    return king(t, 0, 0);

}