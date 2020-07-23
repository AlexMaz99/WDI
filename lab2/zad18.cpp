#include <iostream>

using namespace std;

int main() {
    int k, sum, sum2, number, number2, tmp;

    for (int i = 3; i < 10000; i++) {
        k = 2;
        sum = 0;
        sum2 = 0;
        number = i;
        number2 = i;
        while (number > 1) //rozklada liczbe na czynniki pierwsze
        {
            if (i == k) break; // jezeli liczba jest pierwsza to wychodzi
            while (number % k == 0) {
                tmp = k;
                while (tmp > 0) // dodaje cyfry tych liczb, ktore dziela oryginalna liczbe
                {
                    sum = sum + tmp % 10;
                    tmp = tmp / 10;
                }
                number = number / k;
            }
            k++;
        }
        while (number2 > 0) //sum2 to suma cyfr liczby
        {
            sum2 = sum2 + number2 % 10;
            number2 = number2 / 10;
        }
        if (sum == sum2) {
            cout << i << endl;
        }
    }
    return 0;
}