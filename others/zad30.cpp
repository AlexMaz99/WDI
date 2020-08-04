#include <iostream>
#include <cmath>

using namespace std;

const int N = 201;
const int M = 100;

struct wsp {
    int r;
    int c;
    int length;
};

bool find_kings(wsp kings[M]) {
    for (int i = 0; i < M; i++) {
        cin >> kings[i].r >> kings[i].c;
        kings[i].length = max(abs(M - kings[i].r), abs(M - kings[i].c));

        for (int j = i - 1; j >= 0; j--) {
            if (kings[i].length == kings[j].length) {
                cout << kings[i].r << " " << kings[i].c << " " << kings[j].r << " " << kings[j].c << " " << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    wsp kings[M];

    return find_kings(kings);
}
