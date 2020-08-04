#include <iostream>

using namespace std;

const int N = 3;

void rewrite(int t1[N][N], int t[N * N]) {
    int indexes[N];
    for (int i = 0; i < N; i++) indexes[i] = 0;


    for (int i = 0; i < N * N; i++) {
        int min = 1000;
        int j_min = 0;
        for (int j = 0; j < N; j++) {
            if (indexes[j] < N && t1[j][indexes[j]] < min) {
                min = t1[j][indexes[j]];
                j_min = j;
            }
        }
        indexes[j_min]++;
        t[i] = min;
    }
}

int main() {
    int t1[N][N];
    int t2[N * N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t1[i][j];
    rewrite(t1, t2);
    cout << endl;
    for (int i = 0; i < N * N; i++) cout << t2[i] << " ";

}