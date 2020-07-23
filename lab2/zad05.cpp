#include <iostream>

using namespace std;

int main() {
    int x = 0;
    cout << "Enter number" << endl;
    cin >> x;
    long long int result = 1;

    for (int i = 1; i <= x; i++) {
        result = result * i;
        while (result % 10 == 0) {
            result /= 10;
        }
        result = result % 1000000;
    }
    cout << result % 10;
}
