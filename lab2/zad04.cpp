#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int counter = 1;
    int number;

    for (int i = 2; i <= N; i++) {
        number = i;
        while (number % 2 == 0) number = number / 2;
        while (number % 3 == 0) number = number / 3;
        while (number % 5 == 0) number = number / 5;
        if (number == 1) counter++;

    }
    cout << counter;
}
