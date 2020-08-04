#include <iostream>
#include <cmath>

using namespace std;

const int N = 5;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int k = 5;
    while (k < sqrt(n)) {
        if (n % k == 0) return false;
        k += 2;
        if (n % k == 0) return false;
        k += 4;
    }
    return true;
}

int find_subset(int t[N][N]) {
    int length, r;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            if (is_prime(t[i][j]) && is_prime(t[i][j + 1])) {
                r = t[i][j + 1] - t[i][j];
                if (is_prime(t[i][j + 2]) && r == t[i][j + 2] - t[i][j + 1]) {
                    j = j + 2;
                    length = 3;
                    while (j + 1 < N && is_prime(t[i][j + 1] && r == t[i][j + 1] - t[i][j])) {
                        j++;
                        length++;
                    }
                    cout << "wiersz: " << i << endl;
                    return length;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            if (is_prime(t[j][i]) && is_prime(t[j + 1][i])) {
                r = t[j + 1][i] - t[j][i];
                if (is_prime(t[j + 2][i]) && r == t[j + 2][i] - t[j + 1][i]) {
                    j = j + 2;
                    length = 3;
                    while (j + 1 < N && is_prime(t[j + 1][i] && r == t[j + 1][i] - t[j][i])) {
                        j++;
                        length++;
                    }
                    cout << "kolumna: " << i << endl;
                    return length;
                }
            }
        }
    }
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    return find_subset(t);
}