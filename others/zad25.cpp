# include <iostream>

using namespace std;


int NWD(int a, int b) {
    int c;
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int pairs(int N, int a, int b, int wyk1, int wyk2) {
    if (N == 0 && a > 0 && b > 0 && NWD(a, b) == 1) {
        cout << a << " " << b << endl;
        return 1;
    }
    if (N == 0) return 0;

    return pairs(N / 10, a + (N % 10) * wyk1, b, wyk1 * 10, wyk2) +
           pairs(N / 10, a, b + (N % 10) * wyk2, wyk1, wyk2 * 10);
}

int divide(int N) {
    return pairs(N, 0, 0, 1, 1);
}

int main() {
    return divide(21523);

}