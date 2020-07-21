#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
    const double eps = 1e-8;
    double a = 2.0;
    double b = 3.0;
    double x = (a + b) / 2;

    while (b - a > eps) {
        double y = exp(exp(x * log10(x)) * log10(x));
        if (y > 2018) {
            a = x;
        } else b = x;
    }
    cout << (a + b) / 2;
    return 0;
}
