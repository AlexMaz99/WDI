# include <iostream>

using namespace std;

const int N = 4;
int t[N];

bool can_divide(int t[N], int index, int sum, int counter1, int counter2) {
    if (sum == 0 && counter1 > 0 && counter1 == counter2) return true;
    if (index == N) return false;
    return can_divide(t, index + 1, sum + t[index], counter1 + 1, counter2) ||
           can_divide(t, index + 1, sum - t[index], counter1, counter2 + 1) ||
           can_divide(t, index + 1, sum, counter1, counter2);
}

bool can_divide_tab(int t[N]) {
    return can_divide(t, 0, 0, 0, 0);
}

int main() {
    for (int i = 0; i < N; i++)
        cin >> t[i];
    return can_divide_tab(t);
}