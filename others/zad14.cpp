#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(NULL));
    const int MAX = 15;
    int biggest_ten[10];
    int tab[MAX];
    for (int i = 0; i < 10; i++) {
        biggest_ten[i] = 0;
    }
    int counter = 0;
    while (counter < MAX) {
        tab[counter] = rand() % 1000 + 1;
        int smallest = biggest_ten[0];
        int index = 0;
        for (int i = 1; i < 10; i++) {
            if (biggest_ten[i] < smallest) {
                smallest = biggest_ten[i];
                index = i;
            }
        }
        if (tab[counter] > biggest_ten[index]) {
            biggest_ten[index] = tab[counter];
        }
        counter++;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = sum + biggest_ten[i];
    }
    return sum;
}
