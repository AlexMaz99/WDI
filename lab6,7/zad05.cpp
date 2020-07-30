#include <iostream>

using namespace std;

const int N = 5;

struct vector {
    int x;
    int y;
};

vector movement[8] = {{2,  1},
                      {2,  -1},
                      {-2, 1},
                      {-2, -1},
                      {1,  2},
                      {1,  -2},
                      {-1, 2},
                      {-1, -2}};


bool can_move(int x, int y, int tab[N][N]) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;

    if (tab[x][y] > 0 && tab[x][y] != 0) return false;

    return true;
}

bool jumper(int current_x, int current_y, int tab[N][N], int counter) {
    tab[current_x][current_y] = counter;
    if (counter == N * N)
        return true;

    for (int i = 0; i < 8; i++) {
        int new_x = current_x + movement[i].x;
        int new_y = current_y + movement[i].y;
        if (can_move(new_x, new_y, tab))
            if (jumper(new_x, new_y, tab, counter + 1))
                return true;
    }

    tab[current_x][current_y] = 0;
    return false;
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            t[i][j] = 0;

    jumper(0, 0, t, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}