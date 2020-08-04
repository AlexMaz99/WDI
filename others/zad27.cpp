#include <iostream>
#include <cmath>

using namespace std;

const int N = 4;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 or n == 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;
    int b = 5;
    int c = sqrt(n);

    while (b <= c) {
        if (n % b == 0) return false;
        b += 2;
        if (n % b == 0) return false;
        b += 4;
    }
    return true;
}

void find_sum(int t1[N], int t2[N], bool t11[N], bool t22[N], int index, int sum, int &counter) {
    if (index == N) {
        if (is_prime(sum)) {
            for (int i = 0; i < N; i++) {
                if (t11[i]) cout << t1[i] << " ";
                if (t22[i]) cout << t2[i] << " ";
            }
            cout << "SUM: " << sum << endl;
            counter++;
        }
        return;
    }
    t11[index] = true;
    find_sum(t1, t2, t11, t22, index + 1, sum + t1[index], counter);
    t11[index] = false;
    t22[index] = true;
    find_sum(t1, t2, t11, t22, index + 1, sum + t2[index], counter);
    t11[index] = true;
    find_sum(t1, t2, t11, t22, index + 1, sum + t1[index] + t2[index], counter);
    t11[index] = t22[index] = false;
}

int find_correct_sum(int t1[N], int t2[N]) {
    int counter = 0;
    bool t11[N], t22[N];
    for (int i = 0; i < N; i++) {
        t11[i] = t22[i] = false;
    }
    find_sum(t1, t2, t11, t22, 0, 0, counter);
    return counter;
}

int main() {
    int t1[N] = {1, 3, 2, 4};
    int t2[N] = {9, 7, 4, 8};

    return find_correct_sum(t1, t2);

}