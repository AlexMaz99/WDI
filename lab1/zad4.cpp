#include <iostream>

using namespace std;

//1,1,2,3,5,8,13,21
int main() {
    int number;
    cin >> number;
    int fib[100];
    fib[0] = 1;
    fib[1] = 1;
    int sum = 2;
    bool exist = false;
    if (number == 1 || number == 2) exist = true;

    for (int i = 2; i < 100 && !exist; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        sum = sum + fib[i];
        if (number == sum) exist = true;
        if (number < sum) break;
    }

    for (int i = 0; number < sum && !exist; i++) {
        sum = sum - fib[i];
        if (number == sum) exist = true;
    }

    if (exist) cout << "yes";
    else cout << "no";
    return 0;
}