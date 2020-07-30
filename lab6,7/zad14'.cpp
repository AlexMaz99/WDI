#include <iostream>
#include <cmath>

using namespace std;

const int N = 8;

int pos_y[N];
int counter = 1;

bool is_free(int x, int y) {
    for (int i = 0; i < x; i++) {
        if (y == pos_y[i] || abs(x - i) == abs(y - pos_y[i])) return false;
    }
    return true;

}

void write() {
    cout << "\t\t\t" << counter << ")\t";
    for (int i = 0; i < N; i++)
        cout << static_cast<char>('A' + i) << pos_y[i] + 1 << " ";
    cout << endl;
}

void hetman(int col = 0) {
    for (int i = 0; i < N; i++) {
        if (is_free(col, i)) {
            pos_y[col] = i;
            if (col == N - 1) {
                write();
                counter++;
                return;
            }
            hetman(col + 1);
        }
    }
}

int main() {
    hetman();
    cout << "\nIstnieje " << counter - 1
         << " mozliwosci ustawienia 8 hetmanow na szachownict tak, aby sie \nwzajemnie nie atakowaly.";
    return 0;

}