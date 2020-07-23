#include <iostream>

using namespace std;

int main() {
    int number = 0;
    int value = 0;
    cin >> number;

    for (int i = 1; value < number; i++) {
        value = i * i + i + 1;

        if (number % value == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}