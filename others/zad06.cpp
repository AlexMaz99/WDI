#include <iostream>

using namespace std;

const int N = 15;

int cycle_length(int tab[N]) {
    int length = 0, max_length = 0, c;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            c = i;
            length = 0;
            while (j < N && tab[c] == tab[j]) {
                c++;
                length++;
                j++;
            }
        }
        if (length > max_length) max_length = length;
    }
    return max_length;
}

int reverse(int tab[N]) {
    int length = 0, max_length = 0, c;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            length = 0;
            c = i;
            while (c < N && j >= 0 && tab[c] == tab[j]) {
                length++;
                c++;
                j--;
            }
            if (length > max_length) max_length = length;
        }
        if (length > max_length) max_length = length;
    }
    return max_length;
}

bool row_is_cycle(int tab[N]) {
    int c = 0;
    for (int j = c + 3; j < N / 2; j++) {
        c = 0;
        while (j < N && tab[c] == tab[j]) {
            c++;
            j++;
        }
        if (j == N) return true;
    }
    return false;
}

int cycle_in_row(int t[N][N]) {
    int c;
    for (int w = 0; w < N; w++) {
        for (int j = 3; j < N / 2; j++) {
            c = 0;
            while (j < N && t[w][c] == t[w][j]) {
                j++;
                c++;
            }
            if (j == N) return w;
        }
    }
    return -1;
}

int reverse_min_6(int t[N]) {
    int length, c;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            length = 0;
            c = i;
            while (j >= c && t[j] == t[c]) {
                c++;
                j--;
                length++;
            }
            if (length >= 6) return length;

        }
    }
    return 0;
}

int main() {
    int tab[N];
    int t[N][N];
    for (int i = 0; i < N; i++) cin >> tab[i];
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            cin >> t[i][j];
//    return cycle_in_row(t);
//    return row_is_cycle(tab);
    return reverse_min_6(tab);
}