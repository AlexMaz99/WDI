# include <iostream>
# include <cmath>

using namespace std;


bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int b = 5;

    while (b <= sqrt(n)) {
        if (n % b == 0) return false;
        b += 2;
        if (n % b == 0) return false;
        b += 4;
    }
    return true;
}

void count_sum(int t[20], int index, int &sum, int result) {
    sum += result;
    if (result == 0) result = 1;
    cout << result << endl;
    if (index < 0) return;

    count_sum(t, index - 1, sum, result * t[index]);

    count_sum(t, index - 1, sum, result);
    sum -= result;
}

void sum_dividers(int n) {
    int div[20], k = 0;
    for (int i = 0; i < 20; i++) div[i] = 0;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && is_prime(i)) {
            div[k] = i;
            k++;
            while (n % i == 0) n /= i;
        }
    }
    int sum = 0;
    count_sum(div, k - 1, sum, 0);
    cout << sum;

}

int main() {
    sum_dividers(60);
}