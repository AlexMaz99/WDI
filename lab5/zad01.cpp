#include <iostream>
#include <cmath>

using namespace std;

struct fraction {
    int l; //licznik
    int m; //mianownik
};

int NWD(int a, int b) {
    while (a != b) {
        if (a > b) a = a - b;
        if (b > a) b = b - a;
    }
    return a;
}

fraction add(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.m + u2.l * u1.m;
    result.m = u1.m * u2.m;
    return result;
}

fraction subtract(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.m - u2.l * u1.m;
    result.m = u1.m * u2.m;
    return result;
}

fraction multiply(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.l;
    result.m = u1.m * u2.m;
    return result;
}

fraction divide(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.m;
    result.m = u1.m * u2.l;
    return result;
}

fraction pow(fraction a, int n) {
    fraction result;
    result.l = pow(a.l, n);
    result.m = pow(a.m, n);
    return result;
}

fraction shortening(fraction a) {
    if (a.l == 0) return a;
    int divider = NWD(abs(a.l), a.m);
    a.l /= divider;
    a.m /= divider;
    return a;
}

fraction read(fraction u) {
    cin >> u.l >> u.m;
    return u;
}

void write(fraction u) {
    cout << u.l << "/" << u.m;
}

int main() {
    fraction u = read(u);
    fraction w = read(w);
    fraction result = add(u, w);
    write(result);

    return 0;

}