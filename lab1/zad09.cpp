#include <iostream>
#include <cmath>

using namespace std;
int precision = 20;

double factorial(double x) {
    double result = 1;
    if (x == 1)
        return 1;

    for (int i = 2; i <= x; i++)
        result *= i;

    return result;
}

double cosinus(double x) {
    double i = 0;
    double result = 1;
    while (i < precision) {
        result -= (1 / factorial(i + 2)) * pow(x, i + 2);
        result += (1 / factorial(i + 4)) * pow(x, i + 4);
        i += 4;
    }
    return result;
}

int main() {
    double angle;
    cin >> angle;
    cout << cosinus((angle / 360.0) * 2.0 * M_PI) << endl;

}