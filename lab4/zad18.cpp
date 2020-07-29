#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int MAX = 12;

int max_sum(int tab[MAX][MAX]) {
    int sum_col, sum_row, max_sum_col = 0, max_sum_row = 0, k, l;
    for (int i = 0; i < MAX; i++) {
        sum_col = 0;
        sum_row = 0;
        k = 0;
        l = 0;
        for (int j = 0; j < MAX; j++) {
            if (j >= 10) {
                if (tab[i][k] < tab[i][j]) {
                    sum_col = sum_col - tab[i][k] + tab[i][j];
                    k++;
                }
                if (tab[l][i] < tab[j][i]) {
                    sum_row = sum_row - tab[l][i] + tab[j][i];
                    l++;
                }
            } else {
                sum_col = sum_col + tab[i][j];
                sum_row = sum_row + tab[j][i];
            }
        }
        if (max_sum_row < sum_row) max_sum_row = sum_row;
        if (max_sum_col < sum_col) max_sum_col = sum_col;
    }
    return max(max_sum_col, max_sum_row);

}

int main() {
    srand(time(NULL));
    int t[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            t[i][j] = rand() % 10 + 1;
            cout << t[i][j] << " ";
        }
        cout << endl;
    }


    return max_sum(t);
}