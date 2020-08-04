# include <iostream>
# include <cmath>

using namespace std;

const int N = 5;
int t[N][N];

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int k = 5;
    while (k <= sqrt(n)) {
        if (n % k == 0) return false;
        k += 2;
        if (n % k == 0) return false;
        k += 4;
    }
    return true;
}

struct wsp {
    int x;
    int y;
};

bool can_move(int t[N][N]) {
    wsp movement[4] = {{2,  -1},
                       {-2, -1},
                       {1,  -2},
                       {-1, -2}};
    for (int w = 0; w < N; w++) {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < 4; i++) {
                int nx = w + movement[i].x;
                int ny = k + movement[i].y;
                if (nx > -1 && nx < N && ny > -1 && ny < N)
                    if (is_prime(t[w][k] + t[nx][ny])) return true;
            }
        }
    }
    return false;

}


int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    return can_move(t);
}