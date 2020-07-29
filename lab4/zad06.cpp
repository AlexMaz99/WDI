#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main() {
    const int MAX = 4;
    int t1[MAX][MAX], t2[MAX * MAX];
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            t1[i][j] = rand() % 1000 + 1;
            //cout<<tab[i][j]<<"\t";
            cin >> t1[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < MAX * MAX; i++) t2[i] = 0;
    int counter = 0;
    t2[0] = t1[0][0];


    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            t2[counter] = t1[i][j];
            counter++;
        }
    }

    int tmp;
    for (int j = 0; j < MAX * MAX - 1; j++)   // Powtarzamy zamienianie az do momentu gdy sprawdzimy wszystkie liczby
    {
        for (int i = 0; i < MAX * MAX - 1; i++) {
            if (t2[i] == t2[i + 1])t2[i] = 0;
            if (t2[i + 1] < t2[i])    //Zemieniamy miejscami dwie kolejne liczby, jezli nie sa w kolejnosci rosnacej
            {
                tmp = t2[i];
                t2[i] = t2[i + 1];
                t2[i + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < MAX * MAX; i++)
        cout << t2[i] << endl;


    return 0;
}