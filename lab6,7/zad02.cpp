#include <iostream>

using namespace std;


const int N = 5;

bool can_be_weight(int current, const int weight, int index, int t[N]) {
    if (current == weight) return true;
    if (index >= N) return false;
    return can_be_weight(current + t[index], weight, index + 1, t) ||
           can_be_weight(current - t[index], weight, index + 1, t) ||
           can_be_weight(current, weight, index + 1, t);

}

int main() {
    int t[N], weight;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    cin >> weight;

    return can_be_weight(0, weight, 0, t);
}