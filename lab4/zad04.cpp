#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main() {
    const int MAX = 4;
    int t[MAX][MAX];
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            t[i][j] = rand() % 1000 + 1;
            cout << t[i][j] << "\t";
            // cin>>t[i][j];
        }
        cout << endl;
    }

    int sum_col[MAX], sum_row[MAX];

    for (int i = 0; i < MAX; i++) {
        sum_col[i] = 0;
        sum_row[i] = 0;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            sum_col[i] += t[j][i];
            sum_row[i] += t[i][j];
        }
    }

    int max_sum_col = sum_col[0];
    int min_sum_row = sum_row[0];
    int column = 0, row = 0;

    for (int i = 0; i < MAX; i++) {
        if (sum_col[i] > max_sum_col) {
            max_sum_col = sum_col[i];
            column = i;
        }
        if (sum_row[i] < min_sum_row) {
            min_sum_row = sum_row[i];
            row = i;
        }
    }

    cout << row << endl << column;

    return 0;
}