#include <iostream>

using namespace std;


void is_palindrome(int i, int tab[]) {
    bool palindrome = true;

    int p = 0;
    if (i % 2 == 1) p = 1;

    for (int j = 0; i != j - p && palindrome; j++) {
        if (tab[j] != tab[i - 1]) palindrome = false;
        i--;
    }

    if (palindrome) cout << "YES";
    else cout << "NO ";
}


int main() {
    int number = 0, tmp = 0, i;
    int tab10[1000], tab2[1000];
    cin >> number;
    tmp = number;

    for (i = 0; number > 0; i++) {
        tab10[i] = number % 10;
        number = number / 10;
    }
    is_palindrome(i, tab10);


    int j;
    for (j = 0; tmp != 0; j++) {
        tab2[j] = tmp % 2;
        tmp = tmp / 2;
    }

    is_palindrome(j, tab2);
}