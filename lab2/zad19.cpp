#include <iostream>

using namespace std;


int main() {
    int a, b, c, n;

    cin >> n;

    for (a = 1; a <= n - 2; a++)
        for (b = a + 1; b <= n - 1; b++)
            for (c = b + 1; c <= n; c++)
                if (a * a + b * b == c * c) cout << a << " " << b << " " << c << endl;
    return 0;
}


