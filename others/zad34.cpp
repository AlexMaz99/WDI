#include <iostream>

using namespace std;

struct movement {
    int r;
    int c;
};
const int N = 5;

bool has_any_friend(int a, int b) {
    bool tab[10];
    int c = b;
    for (int i = 0; i < 10; i++) tab[i] = false;
    while (a != 0) {
        tab[a % 10] = true;
        a /= 10;
    }
    while (b != 0) {
        if (!tab[b % 10]) return false;
        b /= 10;
    }
    while (c != 0) {
        tab[c % 10] = false;
        c /= 10;
    }
    for (int i = 0; i < 10; i++)
        if (tab[i]) return false;
    return true;
}

bool good_position(int row, int col) {
    if (row < 0 || col < 0 || row >= N || col >= N) return false;
    return true;

}

int neighbours(int t[N][N]) {
    int counter = 0;
    bool has_friends;
    movement s[8] = {{1,  0},
                     {1,  1},
                     {0,  1},
                     {-1, 1},
                     {-1, 0},
                     {-1, 1},
                     {0,  -1},
                     {1,  -1}};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            has_friends = true;
            for (int x = 0; x < 8 && has_friends; x++) {
                if (good_position(i + s[x].r, j + s[x].c)) {
                    if (!has_any_friend(t[i][j], t[i + s[x].r][j + s[x].c])) has_friends = false;
                }
            }
            if (has_friends) counter++;
        }
    }
    return counter;
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    return neighbours(t);
}