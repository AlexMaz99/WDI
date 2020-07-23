#include <iostream>
#include <string>

using namespace std;

string change_base(int number, int base) {
    string result = "";
    while (number != 0) {
        if (number % base < 10) result = char(number % base + 48) + result;
        else result = char(number % base + 55) + result;

        number = number / base;

    }
    return result;
}

bool different_digits(string a, string b) {
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) return false;
        }
    }
    return true;
}

int main() {
    int number, number2;
    cin >> number >> number2;
    string x, y;
    for (int i = 2; i <= 16; i++) {
        x = change_base(number, i);
        y = change_base(number2, i);

        if (different_digits(x, y)) {
            cout << i;
            return 0;
        }
    }
    cout << "Nie ma takiej podstawy";

    return 0;
}