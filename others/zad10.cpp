#include <iostream>

using namespace std;

const int N = 1000;


int odd_palindrome(int tab[], int n) {
    int i = 0, j;
    int max_length = 0;
    int a, b;
    bool is_palindrome;
    while (i < n) {

        if (tab[i] % 2 == 1 && max_length < 1) max_length = 1;
        j = i + 1;

        while (tab[i] % 2 == 1 && tab[j] % 2 == 1) //Sprawdza czy granice podciagu sa liczbami nieparzystymi
        {
            a = i;
            b = j;
            is_palindrome = true;
            while (a <= b && is_palindrome)//Sprawdza czy dany podciag jest palindromem
            {
                if (tab[a] != tab[b]) is_palindrome = false;
                a++;
                b--;
            }
            if (is_palindrome && max_length < j - i + 1) max_length = j - i + 1;
            j++;
        }
        i++;
    }
    return max_length;

}


int main() {
    int tab[N] = {1, 532, 7, 1, 3, 5, 7, 5, 3, 1, 7, 8, 11, 1515, 1};

    cout << sprPali(tab, N);//9
}