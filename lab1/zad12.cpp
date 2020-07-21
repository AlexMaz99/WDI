#include <iostream>

using namespace std;

int main() {
    for (long long int i = 2; i++; i < 1000000) {
        long long int sum = 0;
        for (long long int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum = sum + j;
            }
        }
        if (sum == i) cout << i << endl;
    }

    return 0;

}