#include <iostream>
#include <cmath>


using namespace std;

int main() {
    double n;
    cin >> n;
    double EPS = 1e-5;
    double x = n / 2;
    while (abs(n / x - x) > EPS) {
        x = (n / x + x) / 2;
    }
    cout << x;
    return 0;
}