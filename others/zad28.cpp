#include <iostream>
#include<string>
#include <cmath>

using namespace std;

int change_digits(int n) {
    int last = n % 10;
    n = n / 10;
    int before = n % 10;
    n = n * 10 + 10 * last + before;
    return n;
}

int remove_first_digit(int n) {
    int k = n;
    int digits = 0, last = 0, multiplication;
    while (k != 0) {
        digits++;
        last = k % 10;
        k /= 10;
    }

    multiplication = pow(10, digits - 1);
    return (n - (last * multiplication));
}

bool can_find_sequence(int x, int y, string sequence, string &result) {
    if (x == y) {
        result = sequence;
        return true;
    }
    if (sequence.size() >= 7) return false;

    if (x > 9)
        if (can_find_sequence(remove_first_digit(x), y, sequence + "C", result)) return true;

    if (x > 9)
        if (can_find_sequence(change_digits(x), y, sequence + "A", result)) return true;

    if (can_find_sequence(3 * x, y, sequence + "B", result)) return true;

}

string find_sequence(int x, int y) {
    string result = "";
    can_find_sequence(x, y, "", result);
    return result;
}

int main() {
    int x, y;
    cin >> x >> y;

    cout << find_sequence(x, y);
    return 0;
}