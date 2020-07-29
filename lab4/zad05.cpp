#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main() {
    const int MAX = 3;
    double t[MAX][MAX];
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            t[i][j] = rand() % 10000 - 5000;
            //cout<<t[i][j]<<"\t";
            cin >> t[i][j];
        }
        cout << endl;
    }

    double sum_col[MAX], sum_row[MAX];
    double quotient[MAX][MAX];
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

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (sum_row[i] != 0) quotient[i][j] = sum_col[j] / sum_row[i];
            else quotient[i][j] = 0;
        }
    }
    double max_result = quotient[0][0];
    int row = 0, column = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (quotient[i][j] > max_result) {
                max_result = quotient[i][j];
                row = i;
                column = j;
            }
        }
    }
    cout << row << endl << column;


    return 0;
}