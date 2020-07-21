#include <iostream>

using namespace std;


int main() {
    int a[10000];
    int counter;
    int start, i;
    int counter_2 = 0;
    int start_2 = 0;
    for (int k = 2; k <= 10000; k++) {
        a[0] = k;
        i = 2;
        start = k;
        counter = 0;

        while (a[i - 2] != 1) {
            a[i - 1] = (a[i - 2] % 2) * (3 * a[i - 2] + 1) + (1 - a[i - 2] % 2) * a[i - 2] / 2;
            i++;
            counter++;
        }
        if (counter > counter_2) {
            counter_2 = counter;
            start_2 = start;
        }

    }
    return start_2;
}