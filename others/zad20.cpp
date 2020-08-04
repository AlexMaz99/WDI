#include <iostream>

using namespace std;

const int N = 5;

bool is_Fib(int x, int y) {
    int a = 1, b = 1;
    while (b < x) {
        a = a + b;
        b = a - b;
    }
    if (a == y && b == x) return true;
    return false;
}

int fib(int t[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            if (t[i][j] + t[i][j + 1] == t[i][j + 2])
                if (is_Fib(t[i][j], t[i][j + 1])) return i;
        }
    }
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    return fib(t);
}