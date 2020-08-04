#include <iostream>

using namespace std;

const int N = 2;

void rewrite(int t1[10][N], int t[10 * N]) {
    int indexes[10];
    for (int i = 0; i < 10; i++) indexes[i] = 0;

    int counter = 0;
    int l;

    for (int i = 0; i < 10 * N; i++) {
        int min = INT_MAX;
        l = 0;
        for (int j = 0; j < 10; j++) //szukamy minimalnej wartosci
        {
            if (indexes[j] < N && t1[j][indexes[j]] < min)
                min = t1[j][indexes[j]];
        }

        for (int k = 0; k <
                        10; k++) //sprawdzamy czy ta minimalna wartosc sie nie powtarza, jezeli tak, to przesuwamy sie o jeden indeks w prawo
        {
            if (indexes[k] < N && t1[k][indexes[k]] == min) {
                indexes[k]++;
                l++;
            }
        }


        if (l == 1) //jezeli minimalna wartosc byla jedna to ja wpisujemy
        {
            t[counter] = min;
            counter++;
        }
    }
    while (counter < 10 * N) {
        t[counter] = 0;
        counter++;
    }
}

int main() {
    int t1[10][N];
    int t2[10 * N];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < N; j++)
            cin >> t1[i][j];
    rewrite(t1, t2);
    cout << endl;
    for (int i = 0; i < 10 * N; i++) cout << t2[i] << " ";

}