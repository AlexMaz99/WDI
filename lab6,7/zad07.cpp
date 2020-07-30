#include <iostream>

using namespace std;

const int N = 6;

int sum(int current_sum, int index_sum, int index, int tab[N], int current_quantity, int &min_quantity, int &result) {
    if (current_sum == index_sum && current_sum > 0 && current_quantity < min_quantity) {
        min_quantity = current_quantity;
        result = current_sum;
        return result;
    }

    if (index == N) return result;
    sumuj(current_sum + tab[index], index_sum + index, index + 1, tab, current_quantity + 1, min_quantity, result);
    sumuj(current_sum, index_sum, index + 1, tab, current_quantity, min_quantity, result);
}

int find_result(int tab[N]) {
    int result = 0;
    int min_quantity = N + 1;
    return sum(0, 0, 0, tab, 0, min_quantity, result);

}

int main() {
    int t[N] = {1, 7, 3, 5, 11, 2};

    return find_result(t);
}