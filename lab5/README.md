# Lab 5

## Zadania obowiązkowe

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 |  Liczby wymierne są reprezentowane przez strukturę: `struct ulamek { int l; // licznik – liczba całkowita int m; // mianownik – liczba większa od 0};` Proszę napisać podstawowe operacje na ułamkach, m.in. dodawanie, odejmowanie, mnożenie, dzielenie, potęgowanie, skracanie, wypisywanie i wczytywanie|[✓](../lab5/zad01.cpp "zad 1")|
|2 | Używając funkcji z poprzedniego zadania proszę napisać funkcję rozwiązującą układ 2 równań o 2 niewiadomych|[✓](../lab5/zad02.cpp "zad 2")|
|3 |  Na szachownicy o wymiarach 100x100 umieszczamy N hetmanów (N<100). Położenie hetmanów jest opisywane przez strukturę dane: `struct hetman { int w; // wiersz 0..99 int k; // kolumna 0..99 };` `struct dane { hetman t[100]; // położenie hetmanów int N; // liczba hetmanów };` Proszę napisać funkcję, która odpowiada na pytanie: czy żadne z dwa hetmany się nie szachują? Do funkcji należy przekazać położenie hetmanów|[✓](../lab5/zad03.cpp "zad 3")|
|4 |  Dana jest tablica ulamek t[100] zawierająca ciąg liczb wymiernych. Proszę napisać funkcję, która policzy występujące w tablicy ciągi arytmetyczne (LA) i geometryczne (LG) o długości większej niż 2. Funkcja powinna zwrócić wartość 1 gdy LA>LG, wartość -1 gdy LA<LG oraz 0 gdy LA=LG|[✓](../lab5/zad04.cpp "zad 4")|
|5 |  Dany jest zbiór punktów leżących na płaszczyźnie opisany przy pomocy struktur: `struct punkt {int x; // zakres wsp. 0..31 int y; // zakres wsp. 0..31 };` `struct dane { punkt t[100]; // położenia punktów int N; // liczba punktów };` Proszę napisać funkcję, która zwraca wartość true jeżeli zborze istnieją 4 punkty wyznaczające kwadrat o bokach równoległych do osi układu współrzędnych, a wewnątrz tego kwadratu nie ma żadnych innych punktów. Do funkcji należy przekazać strukturę opisującą położenie punktów| |
       
## Zadania dodatkowe
| Nr| Polecenie |Zrobione |
|--|--|--|
|6 |  Liczby zespolone są reprezentowane przez strukturę: `struct ulamek { double re; double im; };` Proszę napisać podstawowe operacje na liczbach zespolonych, m.in. dodawanie, odejmowanie, mnożenie, dzielenie, potęgowanie, wypisywanie i wczytywanie| |
|7 | Używając funkcji z poprzedniego zadania proszę napisać funkcję rozwiązującą równanie kwadratowe o współczynnikach zespolonych | |