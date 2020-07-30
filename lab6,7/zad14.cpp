#include <iostream>

using namespace std;

//hetman bije w poziomie, pionie i po skosie; suma pp jest od 0 do 14 czyli razem 15; suma pl jest od -7 do 7 czyli tez 15

void postaw(int het[8], bool wiersz[8], bool pp[15], bool pl[15],
            int k) // w tablicy het indeksy to kolumny, przypisany im jest nr wiersza, pp-prawa przekatna, pl-lewa przekatna, k-kolumna
{
    if (k > 7) {
        for (int i = 0; i < 8; i++)
            cout << het[i] << " ";
        cout << endl;
        return;
    }
    for (int w = 0; w < 8; w++) {
        if (!wiersz[w] && !pp[w + k] &&
            !pl[7 + w - k]) // jezeli w ktorejs z tablicy jest wartosc true to znaczy ze jest zajeta i musimy sie cofnac
        {
            het[k] = w;
            wiersz[w] = pp[w + k] = pl[7 + w - k] = true;
            postaw(het, wiersz, pp, pl, k + 1);
            wiersz[w] = pp[w + k] = pl[7 + w - k] = false;
        }
    }
}

void Hetmani() {
    int het[8];
    bool wiersz[8];
    bool pp[15];
    bool pl[15];
    for (int i = 0; i < 8; i++) {
        het[i] = 0;
        wiersz[i] = false;
    }
    for (int i = 0; i < 15; i++) {
        pp[i] = pl[i] = false;
    }
    postaw(het, wiersz, pp, pl, 0);
    return;
}

int main() {
    Hetmani();
    return 0;
}