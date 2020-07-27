#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

bool exist(int t[10]) {
    int smallest_number = t[0];
    int biggest_number = t[0];
    int index_of_smallest = 0;
    int index_of_biggest = 0;
    for (int i = 1; i < 10; i++) {
        if (t[i] < smallest_number)
        {
            smallest_number = t[i];
            index_of_smallest = i;
        }
        if (t[i] > biggest_number)
        {
            biggest_number = t[i];
            index_of_biggest = i;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (i != index_of_smallest && smallest_number == t[i])
            return false;
        if (i != index_of_biggest && biggest_number == t[i]) return false;
    }
    return true;
}


int main() {
    srand(time(NULL));
    int tab[10];
    for (int i = 0; i < 10; i++) {
        tab[i] = rand() % 1000 - 500;
        cout << tab[i] << " ";
    }
    if (exist(tab)) cout << "YES";
    else cout << "NO";
    return 0;
}