#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int MAX = 10;
    int t[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = i; j < MAX - i; j++) {
            t[i][j] = n;
            n++;
        }
        n--;

        for (int j = i; j < MAX - i; j++) {
            t[j][MAX - i - 1] = n;
            n++;
        }
        n--;

        for (int j = MAX - i - 1; j >= i; j--) {
            t[MAX - i - 1][j] = n;
            n++;
        }
        n--;

        for (int j = MAX - i - 1; j > i; j--) {
            t[j][i] = n;
            n++;
        }
        if (n >= MAX * MAX) break;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << t[i][j] << "\t";
        }
        cout << '\n';
    }


    return 0;
}