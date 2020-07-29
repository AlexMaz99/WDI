#include <iostream>

using namespace std;

const int MAX = 100;

struct hetman {
    int row; //wierszk 0-99
    int col; //kolumna 0-99
};

struct dane {
    hetman t[100];
    int N; //liczba hetmanow
};

bool check(dane data) {
    bool rows[MAX], cols[MAX], left_diagonal[2 * MAX - 1], right_diagonal[2 * MAX - 1];
    for (int i = 0; i < MAX; i++) rows[i] = cols[i] = false;
    for (int i = 0; i < 2 * MAX - 1; i++) left_diagonal[i] = right_diagonal[i] = false;

    for (int i = 0; i < data.N; i++) {
        int row = data.t[i].row;
        int col = data.t[i].col;
        if (row[row] || col[col] || left_diagonal[row + col] ||
            right_diagonal[row - col + MAX - 1])
            return true;
        row[row] = true;
        col[col] = true;
        left_diagonal[row + col] = true;
        right_diagonal[row - col + MAX - 1] = true;
    }
    return false;

}

int main() {

    dane data;
    data.N = 10;
    for (int i = 0; i < data.N; i++) {
        cin >> data.t[i].row;
        cin >> data.t[i].col;
    }

    return check(data);

}