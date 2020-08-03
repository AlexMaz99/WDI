# Lab 9, 10

## Zadania na ćwiczenia 9

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 |  Zaimplementuj zbiór mnogościowy liczb naturalnych korzystając ze struktury listy: czy element należy do zbioru, dodanie elementu do zbioru, usunięcie elementu ze zbioru|[✓](../lab9,10/zad01.cpp "zad 1")|
|2 | Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać trzy funkcje: `void init(node *&tab)` – inicjalizującą tablicę, `int value(node *tab, int n)` – zwracającą wartość elementu o indeksie n, `void set(node *&tab, int n, int value)` – postawiającą wartość value pod indeks n.|[✓](../lab9,10/zad02.cpp "zad 2")|

## Zadania na ćwiczenia 10

| Nr| Polecenie |Zrobione |
|--|--|--|
|3 |  Proszę napisać funkcję scalającą dwie posortowane listy w jedną posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy: funkcja iteracyjna, funkcja rekurencyjna|[✓](../lab9,10/zad03.cpp "zad 3")|
|4 | Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej elementów|[✓](../lab9,10/zad04.cpp "zad 4")|
|5 | Proszę napisać funkcję, która rozdziela elementy listy wejściowej do 10 list, według ostatniej cyfry pola val. W drugim kroku powstałe listy należy połączyć w jedną listę, która jest posortowana niemalejąco według ostatniej cyfry pola val |[✓](../lab9,10/zad05.cpp "zad 5")|

## Podstawowe operacje na listach

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 | Dodanie pierwszego ostatniego elementu, długość listy, sprawdzenie czy lista jest pusta, usunięcie pierwszego i ostatniego elementu, usunięcie elementu o podanej wartości, usunięcie co drugiego elementu|[✓](../lab9,10/zad00.cpp "zad 1")|
|2 | Sortowanie listy|[✓](../lab9,10/zad00'.cpp "zad 2")|
       
## Zadania dodatkowe
Dane są deklaracje:

`struct node {
    int val;
    node* next;
};`

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 | Proszę napisać funkcję wstawiającą na koniec listy nowy element. Do funkcji należy przekazać wskazanie na pierwszy element listy oraz wstawianą wartość |[✓](../lab9,10/zad01'.cpp "zad 1")|
|2 |  Proszę napisać funkcję usuwającą ostatni element listy. Do funkcji należy przekazać wskazanie na pierwszy element listy|[✓](../lab9,10/zad02'.cpp "zad 2")|
|3 |Dana jest niepusta lista, proszę napisać funkcję usuwającą co drugi element listy. Do funkcji należy przekazać wskazanie na pierwszy element listy  |[✓](../lab9,10/zad03'.cpp "zad 3")|
|4 |  Dana jest niepusta lista reprezentująca liczbę naturalną. Kolejne elementy listy przechowują kolejne cyfry. Proszę napisać funkcję zwiększającą taką liczbę o 1|[✓](../lab9,10/zad04'.cpp "zad 4")|
|5 |  Liczby naturalne reprezentowane jak poprzednim zadaniu. Proszę napisać funkcję dodającą dwie takie liczby. W wyniku dodawania dwóch liczb powinna powstać nowa lista|[✓](../lab9,10/zad05'.cpp "zad 5")|
|6 |  Lista zawiera niepowtarzające się elementy. Proszę napisać funkcję do której przekazujemy wskaźnik na początek oraz wartość klucza. Jeżeli element o takim kluczu występuje w liście należy go usunąć z listy. Jeżeli elementu o zadanym kluczu brak w liście należy element o takim kluczu wstawić do listy|[✓](../lab9,10/zad06.cpp "zad 6")|
|7 | Zbiór mnogościowy zawierający napisy jest reprezentowany w postaci jednokierunkowej listy. Napisy w łańcuchu są uporządkowane leksykograficznie. Proszę napisać stosowne definicje typów oraz funkcję dodającą napis do zbioru. Do funkcji należy przekazać wskaźnik do listy oraz wstawiany napis, funkcja powinna zwrócić wartość logiczną wskazującą, czy w wyniku operacji moc zbioru uległa zmianie |[✓](../lab9,10/zad07.cpp "zad 7")|
|8 | Proszę napisać funkcję, która podanej listy odwraca kolejność jej elementów |[✓](../lab9,10/zad08.cpp "zad 8")|
|9 |  Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy element listy o wartościach typu int, usuwającą wszystkie elementy, których wartość jest mniejsza od wartości bezpośrednio poprzedzających je elementów|[✓](../lab9,10/zad09.cpp "zad 9")|
|10| Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy element listy o wartościach typu int, usuwającą wszystkie elementy, których wartość dzieli bez reszty wartość bezpośrednio następujących po nich elementów|[✓](../lab9,10/zad10.cpp "zad 10")|
|11|  Proszę napisać funkcję, która otrzymując jako parametr wskazujący na początek listy jednokierunkowej, usuwa z niej wszystkie elementy, w których wartość klucza w zapisie trójkowym ma większą ilość jedynek niż dwójek|[✓](../lab9,10/zad11.cpp "zad 11")|
|12|  Proszę napisać funkcję, która otrzymując jako parametr wskazujący na początek listy jednokierunkowej, przenosi na początek listy te z nich, które mają parzystą ilość piątek w zapisie ósemkowym|[✓](../lab9,10/zad12.cpp "zad 12")|
|13| Proszę napisać funkcję, która otrzymując jako parametr wskazujący na początek listy dwukierunkowej, usuwa z niej wszystkie elementy, w których wartość klucza w zapisie binarnym ma nieparzystą ilość jedynek |[✓](../lab9,10/zad13.cpp "zad 13")|
|14|  Proszę napisać funkcję, która rozdziela elementy listy wejściowej do 10 list, według ostatniej cyfry pola val. W drugim kroku powstałe listy należy połączyć w jedną listę, która jest posortowana niemalejąco według ostatniej cyfry pola val|[✓](../lab9,10/zad14.cpp "zad 14")|
|15|  Proszę napisać funkcję, która pozostawia w liście wyłącznie elementy unikalne. Do funkcji należy przekazać wskazanie na pierwszy element listy|[✓](../lab9,10/zad15.cpp "zad 15")|
|16| Elementy w liście są uporządkowane według wartości klucza. Proszę napisać funkcję usuwającą z listy elementy o nieunikalnym kluczu. Do funkcji przekazujemy wskazanie na pierwszy element listy, funkcja powinna zwrócić liczbę usuniętych elementów |[✓](../lab9,10/zad16.cpp "zad 16")|
|17|  Dana jest lista zawierająca ciąg obustronnie domkniętych przedziałów. Krańce przedziałów określa uporządkowana para liczb całkowitych. Proszę napisać stosowne deklaracje oraz funkcję redukującą liczbę elementów listy. Na przykład lista: [15,19] [2,5] [7,11] [8,12] [5,6] [13,17] powinien zostać zredukowany do listy: [13,19] [2,6] [7,12]|[✓](../lab9,10/zad10.cpp "zad 17")|
|18|  Kolejne elementy listy o zwiększającej się wartości pola val nazywamy podlistą rosnącą. Proszę napisać funkcję, która usuwa z listy wejściowej najdłuższą podlistę rosnącą. Warunkiem usunięcia jest istnienie w liście dokładnie jednej najdłuższej podlisty rosnącej|[✓](../lab9,10/zad18.cpp "zad 18")|
|19| Dana jest lista, który być może zakończona jest cyklem. Napisać funkcję, która sprawdza ten fakt |[✓](../lab9,10/zad19.cpp "zad 19")|
|20|  Dana jest lista, który zakończona jest cyklem. Napisać funkcję, która zwraca liczbę elementów w cyklu|[✓](../lab9,10/zad20.cpp "zad 20")|
|21| Dana jest lista, który zakończona jest cyklem. Napisać funkcję, która zwraca liczbę elementów przed cyklem |[✓](../lab9,10/zad21.cpp "zad 21")|
|22| Proszę napisać funkcję, która sprawdza czy jedna lista zawiera się w drugiej. Do funkcji należy przekazać wskazania na pierwsze elementy obu list, funkcja powinna zwrócić wartość logiczną |[✓](../lab9,10/zad22.cpp "zad 22")|
|23| Proszę napisać funkcję scalającą dwie posortowane listy w jedną posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy: funkcja iteracyjna, funkcja rekurencyjna |[✓](../lab9,10/zad23.cpp "zad 23")|
|24|  Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby naturalne. W pierwszej liście liczby są posortowane rosnąco, a w drugiej nie. Proszę napisać funkcję usuwającą z obu list liczby występujące w obu listach. Do funkcji należy przekazać wskazania na obie listy, funkcja powinna zwrócić łączną liczbę usuniętych elementów|[✓](../lab9,10/zad24.cpp "zad 24")|
|25| Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby naturalne. W obu listach liczby są posortowane rosnąco. Proszę napisać funkcję usuwającą z każdej listy liczby nie występujące w drugiej. Do funkcji należy przekazać wskazania na obie listy, funkcja powinna zwrócić łączną liczbę usuniętych elementów |[✓](../lab9,10/zad25.cpp "zad 25")|
|26|  Dane są dwie niepuste listy, z których każda zawiera niepowtarzające się elementy. Elementy w pierwszej liście są uporządkowane rosnąco, w drugiej elementy występują w przypadkowej kolejności. Proszę napisać funkcję, która z dwóch takich list stworzy jedną, w której uporządkowane elementy będą stanowić sumę mnogościową elementów z list wejściowych. Do funkcji należy przekazać wskazania na obie listy, funkcja powinna zwrócić wskazanie na listę wynikową. Na przykład dla list: 2 -> 3 -> 5 ->7-> 11 i 8 -> 2 -> 7 -> 4 powinna pozostać lista: 2 -> 3 -> 4 -> 5 ->7-> 8 -> 11|[✓](../lab9,10/zad26.cpp "zad 26")|
|27|  Proszę napisać funkcję, która rozdziela listę na dwie listy. Pierwsza powinna zawierać klucze parzyste dodatnie, drugi klucze nieparzyste ujemne, pozostałe elementy należy usunąć z pamięci. Do funkcji należy przekazać wskaźniki na listę z danymi oraz wskaźniki na listy wynikowe. Funkcja powinna zwrócić liczbę usuniętych elementów|[✓](../lab9,10/zad27.cpp "zad 27")|
|28| Lista reprezentuje wielomian o współczynnikach całkowitych. Elementy w liście ułożone są według rosnących potęg. Proszę napisać funkcję obliczającą różnicę dwóch dowolnych wielomianów. Wielomiany reprezentowane są przez wyżej opisane listy. Procedura powinna zwracać wskaźnik do nowo utworzonej listy reprezentującej wielomian wynikowy. Listy wejściowe powinny pozostać niezmienione |[✓](../lab9,10/zad28.cpp "zad 28")|
|29|  Napis s1 poprzedza napis s2 jeżeli ostatnia litera s1 jest „mniejsza” od pierwszej litery s2. Według tej zasady rozmieszczono napisy w liście cyklicznej. Proszę napisać stosowne definicje typów oraz funkcję wstawiającą do listy napis z zachowaniem zasady poprzedzania. Do funkcji należy przekazać wskaźnik do listy oraz wstawiany napis, funkcja powinna zwrócić wartość logiczną wskazującą, czy udało się wstawić napis do listy. Po wstawieniu elementu wskaźnik do listy powinien wskazywać na nowo wstawiony element|[✓](../lab9,10/zad29.cpp "zad 29")|
|30|  Proszę napisać funkcję, która usuwa z listy cyklicznej elementy, których klucz występuje dokładnie k razy. Do funkcji należy przekazać wskazanie na jeden z elementów listy, oraz liczbę k, funkcja powinna zwrócić informację czy usunięto jakieś elementy z listy|[✓](../lab9,10/zad30.cpp "zad 30")|
|31|  A teraz proszę rozwiązać wszystkie powyższe zadania przy założeniu że listy zawierają wartownika||