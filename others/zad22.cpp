# include <iostream>
# include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n == 1 || n == 4 || n == 6 || n == 8 || n == 9) return false;
    return true;
}

void chose_digits(int t[9], int index, bool counters[9]) {
    if (index == 9) {
        for (int i = 0; i < 9; i++)
            cout << t[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 2; i < 10; i++) {
        if (!counters[i - 1] && abs(i - t[index - 1] >= 2) && (!is_prime(t[index - 1]) || !is_prime(i))) {
            t[index] = i;
            counters[i - 1] = true;
            chose_digits(t, index + 1, counters);
            t[index] = 0;
            counters[i - 1] = false;
        }
    }
}

void digits(int t[9]) {
    t[0] = 1;
    bool counter[9];
    counter[0] = true;
    for (int i = 1; i < 9; i++) {
        t[i] = 0;
        counter[i] = false;
    }
    chose_digits(t, 1, counter);
}

int main() {
    int t[9];
    digits(t);
}