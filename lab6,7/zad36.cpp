#include <iostream>
#include <string>

using namespace std;

void palindrome(int a, int b, string name) {
    cout << name << endl;
    if (a >= 2) palindrome(a - 2, b, "A" + name + "A");
    if (b >= 2) palindrome(a, b - 2, "B" + name + "B");
}

void find_palindromes(int a, int b) {
    palindrome(a, b, "");
    if (a > 0) palindrome(a - 1, b, "A");
    if (b > 0) palindrome(a, b - 1, "B");
}

int main() {
    find_palindromes(3, 2);
    return 0;
}