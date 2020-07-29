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
    result = skracaj(result);
    return result;
}


fraction multiply(fraction u1, fraction u2) {
    fraction result;
    result.l = u1.l * u2.l;
    result.m = u1.m * u2.m;
    result = skracaj(result);
    return result;
}


bool equals(fraction a, fraction b) {
    return a.l == b.l && a.m == b.m;
}


const int N = 10;

int series(fraction t[N]) {
    int LA = 0;
    int LG = 0;
    fraction two;
    two.l = 2;
    two.m = 1;
    bool A = false;
    bool G = false;

    for (int i = 1; i < N - 1; i++) {
        if (equals(multiply(t[i], two), add(t[i - 1], t[i + 1]))) {
            if (!A) {
                LA++;
                A = true;
            } else A = false;
        }

        if (equals(multiply(t[i], t[i]), multiply(t[i - 1], t[i + 1]))) {
            if (!G) {
                LG++;
                G = true;
            } else G = false;
        }
    }

    if (LA > LG) return 1;
    if (LA < LG) return -1;
    return 0;
}

int main() {
    fraction t[N];
    for (int i = 0; i < N; i++) {
        cin >> t[i].l >> t[i].m;
    }

    return series(t);
}