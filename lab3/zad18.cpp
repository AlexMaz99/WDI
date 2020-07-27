#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 10;

int main() {
    srand(time(NULL));
    int tab[N];
    for (int i = 0; i < N; i++) {
        tab[i] = rand() % 100 + 1;
        cout << tab[i] << " ";
    }
    int smallest_number = tab[0];
    int biggest_number = tab[0];

    for (int i = 1; i < N; i++) {
        if (tab[i] < smallest_number) smallest_number = tab[i];
        if (tab[i] > biggest_number) biggest_number = tab[i];
    }
    cout << endl << biggest_number - smallest_number;

    return 0;
}
