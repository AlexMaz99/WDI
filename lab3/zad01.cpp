#include <iostream>
#include <string>

using namespace std;

int main() {
    int number, base;
    string result = "";
    cin >> number >> base;

    while (number != 0) {
        if (number % base < 10) result = char(number % base + 48) + result;
        else result = char(number % base + 55) + result;

        number = number / base;

    }
    cout << result;
}