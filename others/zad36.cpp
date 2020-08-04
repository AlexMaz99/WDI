#include <iostream>

using namespace std;

const int N = 4;

int geo_seq(int r, int c, int t[N][N]) {
    int q = t[r + 1][c + 1] / t[r][c];
    r++;
    c++;
    int d = 2;
    while (r + 1 < N && c + 1 < N && q == t[r + 1][c + 1] / t[r][c]) {
        d++;
        r++;
        c++;
    }
    return d;

}

int biggest_geo_seq(int t[N][N]) {
    int length;
    int max_length = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < N - 2; j++) {
            length = geo_seq(i, j, t);
            if (max_length < length) max_length = length;
        }
        if (max_length >= N - i - 1) return max_length;
    }
    if (max_length > 2) return max_length;
    return 0;
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    return biggest_geo_seq(t);
}