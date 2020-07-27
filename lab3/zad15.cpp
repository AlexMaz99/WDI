#include <iostream>

using namespace std;

int main() {
    double x, opossed;

    for (int j = 20; j <= 40; j++) {

        opossed = 1;

        for (int i = 0; i < j; i++) {
            x = i;
            opossed = opossed * ((365 - x) / 365);
        }

        cout << "Dla " << j << " prawdopodobienstwo wynosi: " << 1 - opossed << endl;
    }

    return 0;
}