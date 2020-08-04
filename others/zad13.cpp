#include <iostream>

using namespace std;

int NWD(int a, int b) {
    int d;
    int r = 1;
    while (r > 0) {
        d = a / b;
        r = a - b * d;
        a = b;
        b = r;
    }
    return a;
}

int sub_set(int t[10]) {
    int max_length = 0, length;
    for (int i = 0; i < 9; i++) {
        length = 0;
        while (i < 9 && NWD(t[i], t[i + 1]) == 1) {
            length++;
            i++;
        }
        if (max_length < length + 1) max_length = length + 1;

    }
    return max_length;
}

int main() {
    int t[10];
    for (int i = 0; i < 10; i++) {
        cin >> t[i];
    }

    cout << sub_set(t);
    return 0;
}