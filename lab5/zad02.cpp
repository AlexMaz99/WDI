#include <iostream>

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

fraction shortening(fraction a) {
    if (a.l == 0) return a;
    int divider = NWD(abs(a.l), a.m);
    a.l /= divider;
    a.m /= divider;
    return a;
}

fraction add(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.m + u2.l * u1.m;
    result.m = u1.m * u2.m;
    result = shortening(result);
    return result;
}

fraction subtract(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.m - u2.l * u1.m;
    result.m = u1.m * u2.m;
    result = shortening(result);
    return result;
}

fraction multiply(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.l;
    result.m = u1.m * u2.m;
    result = shortening(result);
    return result;
}

fraction divide(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.m;
    result.m = u1.m * u2.l;
    result = shortening(result);
    return result;
}


fraction read(fraction u) {
    cin >> u.l >> u.m;
    return u;
}

void write(fraction u) {
    cout << u.l << "/" << u.m;
}

int main() {
    fraction x, y, a, b, c, d, e, f;
    fraction W, W_x, W_y;

    a.l = 7;
    b.l = 2;
    c.l = 1;
    d.l = 3;
    e.l = 4;
    f.l = 2;

    a.m = b.m = c.m = d.m = e.m = f.m = 1;

    W = subtract(multiply(a, e), multiply(b, d));
    W_x = subtract(multiply(c, e), multiply(b, f));
    W_y = subtract(multiply(a, f), multiply(c, d));
    x = divide(W_x, W);
    y = divide(W_y, W);

    write(x);
    cout << endl;
    write(y);


    return 0;

}