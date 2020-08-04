#include <iostream>

using namespace std;

const int N = 4;

bool has_any_friend(int a, int b) {
    if (a < 10 || b < 10) return false;
    bool tab[10];
    int counter = 0;
    for (int i = 0; i < 10; i++) tab[i] = false;
    while (a != 0) {
        tab[a % 10] = true;
        a /= 10;
    }
    while (b != 0) {
        if (tab[b % 10]) {
            counter++;
            tab[b % 10] = false;
        }
        b /= 10;
    }
    return counter > 1;
}

int friends(int t[N][N]) {
    int counter = N * N;
    bool has_friends;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            has_friends = false;
            for (int w = 0; w < N && !has_friends; w++) {
                for (int k = 0; k < N && !has_friends; k++)
                    if ((i != w || j != k) && has_any_friend(t[i][j], t[w][k])) has_friends = true;
            }
            if (!has_friends) {
                t[i][j] = 0;
                counter--;
            }
        }
    }
    return counter;
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    cout << has_any_friends(t) << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}