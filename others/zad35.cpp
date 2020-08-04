#include <iostream>

using namespace std;

struct wsp {
    int r;
    int c;
};
const int N = 5;

bool good_position(int i, int j, int d, int k, int t[N][N]) {
    if (i + d >= N || j + d >= N) return false;
    if (t[i][j] * t[i + d][j] * t[i][j + d] * t[i + d][j + d] == k) return true;
    return false;
}

wsp square(int t[N][N], int k) {
    wsp result;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < N - 2; j++) {
            for (int d = 2; d < N; d++) {
                if (good_position(i, j, d, k, t)) {
                    result.r = i + d / 2;
                    result.c = j + d / 2;
                    return result;
                }
            }
        }
    }
    result.r = -1;
    result.c = -1;
    return result;
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    int k;
    cin >> k;
    wsp result = square(t, k);
    cout << result.r << " " << result.c;

}