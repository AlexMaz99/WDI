#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 4;

int same_values(int tab[N][N]) {
    int length, row = 0, result = 0, max_length = 0;

    for (int i = 0; i < N; i++) {
        length = 1;
        for (int j = 0; j < N - 1; j++) {
            if (tab[i][j] == tab[i][j + 1]) {
                length++;
                row = i;
            }
        }
        if (length > max_length) {
            max_length = length;
            result = row;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    int t[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            t[i][j] = rand() % 20 + 1;

    }

    cout << "Jest to wiersz o indeksie: " << same_values(t);

    return 0;
}