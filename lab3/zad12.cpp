#include <iostream>

using namespace std;

int main() {
    const int MAX = 10;
    double tab[MAX];
    for (int i = 0; i < MAX; i++) cin >> tab[i];

    int result = 0;
    for (int i = 1; i < MAX; i++) {
        double quotient = tab[i] / tab[i - 1];
        int counter = 2;
        while (i < MAX && tab[i + 1] / tab[i] == quotient) {
            counter++;
            i++;
        }
        if (result <= counter)result = counter;
    }

    cout << result;
    return 0;

}