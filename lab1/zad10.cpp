#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    float result = 1, tmp;
    result = sqrt(0.5);

    for (int i = n - 1; i > 0; i--) {
        tmp = sqrt((1 + tmp) / 2);
        result = result * tmp;
    }
    float pi;
    pi = 2 / result;
    cout << pi;
    return 0;
}