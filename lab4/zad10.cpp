#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int main() {
    const int MAX = 4;
    double t[MAX][MAX];
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            t[i][j] = rand() % 10000 - 5000;
            cout << t[i][j] << "\t";
            //cin>>t[i][j];
        }
        cout << endl;
    }

    bool row = true;
    bool col = true;

    for (int i = 0; i < MAX && row && col; i++) {
        row = false;
        col = false;
        for (int j = 0; j < MAX && !row; j++) {
            if (t[i][j] == 0) row = true;
        }
        for (int j = 0; j < MAX && !col; j++) {
            if (t[j][i] == 0) col = true;
        }
    }

    return row && col;
}