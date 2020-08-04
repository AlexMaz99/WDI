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

bool has_prime_numbers(string a) {
    for (int j = 0; j < a.length(); j++) {
        if (a[j] == '0' || a[j] == '1' || a[j] == '4' || a[j] == '6' || a[j] == '8' || a[j] == '9') return false;
    }
    return true;
}

int main() {
    int number;
    string result = "";
    cin >> number;
    string x;
    for (int i = 2; i <= 16; i++) {
        x = change_base(number, i);

        if (has_prime_numbers(x)) {
            cout << x << " " << i;
            return 0;
        }
    }
    cout << "Nie ma takiej podstawy";

    return 0;
}