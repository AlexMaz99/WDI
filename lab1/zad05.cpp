#include <iostream>

using namespace std;

int main() {
    int number;
    int n = 0;
    int k = 1;
    int s = 0;

    cin >> number;
    while (s < number) {
        s = s + k;
        k = k + 2;
        n++;

    }
    cout << n;
    return 0;
}