#include <iostream>

using namespace std;

int main() {
    const int MAX = 10;
    int tab[MAX];
    for (int i = 0; i < MAX; i++) cin >> tab[i];

    int result = 0;
    for (int i = 1; i < MAX; i++) {
        int counter = 1;
        while (i < MAX && tab[i] > tab[i - 1]) {
            counter++;
            i++;
        }
        if (result <= counter)result = counter;
    }

    cout << result;
    return 0;

}