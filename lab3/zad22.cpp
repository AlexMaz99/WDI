#include <iostream>
#include <string>

using namespace std;

const int N = 10;

int naj(int t[N]) {
    int length = 0, max_length = 0, sum = 0, index_sum = 0;
    if (t[0] == 0) //zaczynamy od indeksu 1
        max_length = 1;
    for (int i = 1; i < N; i++) {
        if (t[i] > t[i - 1]) //tylko rosnace
        {
            sum += t[i - 1];
            index_sum += i - 1;
            length++;
            if (sum + t[i] == index_sum + i) //sprawdzamy czy suma indeksow jest rowna sumie liczb
            {
                if (length + 1 > max_length) max_length = length + 1;
            }
        } else {
            sum = index_sum = length = 0;
        }
        if (t[i] == i) // sprawdzamy czy jeden element  jest ronwy indeksowi
        {
            if (max_length == 0) max_length = 1;
        }
    }
    return max_length;
}

int main() {
    int t[N];
    for (int i = 0; i < N; i++) cin >> t[i];
    cout << naj(t);
    return 0;
}