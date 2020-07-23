#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    int a = 1, b = 1;
    bool exist = false;
    if (number == 1) exist = true;

    while (b * b < number && !exist) {
        a = a + b;
        b = a - b;
        if (a * b == number) exist = true;
    }
    if (exist) cout << "number exist";
    else cout << "number does not exist";

    return 0;
}
