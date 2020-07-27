#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 10;

int main() {
    int t[N], result_positive = 0, result_negative = 0, nominator_positive, nominator_negative, difference;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        t[i] = rand() % 99 + 1;
        if (t[i] % 2 == 0) t[i] += 1;
        cout << t[i] << endl;
    }

    for (int i = 1; i < N; i++) {
        nominator_positive = 0;
        nominator_negative = 0;
        difference = t[i] - t[i - 1];

        if (difference > 0) {
            nominator_positive = 2;
            while (i < N && t[i + 1] - t[i] == difference) //szukamy najdluzszego ciagu o dodatniej roznicy
            {
                nominator_positive++;
                i++;
            }
            if (result_positive <= nominator_positive) result_positive = nominator_positive;
        }
        if (difference < 0) {
            nominator_negative = 2;
            while (i < N && t[i + 1] - t[i] == difference) // szukamy najdluzszego ciagu o ujemnej roznicy
            {
                nominator_negative++;
                i++;
            }
            if (result_negative <= nominator_negative) result_negative = nominator_negative;
        }
    }
    cout << result_positive - result_negative;

    return 0;
}