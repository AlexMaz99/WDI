#include <iostream>

using namespace std;

const int N = 10;

bool is_palindrome(int start, int end, int t[N]) {
    while (start < end) {
        if (t[start] != t[end] || t[start] % 2 == 0 || t[end] % 2 == 0) return false;
        end--;
        start++;
    }
    return true;
}

int sub_list(int t[N]) {
    int length, max_length = 0, j;
    for (int i = 0; i < N; i++) {
        if (t[i] % 2 == 1) {
            length = 1;
            j = i + 1;
            while (j < N) {
                if (is_palindrome(i, j, t)) length = j - i + 1;
                if (max_length < length) max_length = length;
                j++;
            }
        }
    }
    return max_length;
}

int main() {
    int tab[N];
    for (int i = 0; i < N; i++) cin >> tab[i];
    return sub_list(tab);
}