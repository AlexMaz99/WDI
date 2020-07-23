#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;
    cin >> number;
    int counter = 0;
    int digit;
    int tmp = number;
    bool result = false;

    while (number > 0) {
        number = number / 10;
        counter++;
    }
    while (tmp > 0 && !result) {
        digit = tmp % 10;
        if (digit == counter) {
            result = true;
        }
        tmp = tmp / 10;
    }
    cout << counter << endl;

    if (result) cout << "YES";
    else cout << "NO";
}