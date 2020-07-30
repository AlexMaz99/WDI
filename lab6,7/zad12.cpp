#include <iostream>
#include <string>

using namespace std;

void find_components(int n, string result,
                     int bound) //jezeli ma byc konkretna ilosc skladnikow to + int number_of_components
{
    cout << "Components(" << n << "," << result << "," << bound << ")" << endl;
    if (n == 0) cout << result << endl; // && number_of_components > 1

    for (int i = bound; i <= n; i++) {
        char c = i + 48;
        find_components(n - i, result + " " + c, i); // number_of_components + 1
    }
}

void components(int n) {
    find_components(n, "", 1);
}

int main() {
    int n;
    cin >> n;
    components(n);
    return 0;
}