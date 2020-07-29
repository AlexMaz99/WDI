# Lab 3

## Zadania obowiązkowe

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 | Napisać program zamieniający liczbę naturalną z systemu 10 na podstawę 2-16| ✓|
|2 | Napisać program wczytujący dwie liczby naturalne i odpowiadający na pytanie czy są one zbudowane z takich samych cyfr, np. 123 i 321, 1255 i 5125, 11000 i 10001| ✓|
|3 |  Napisać program generujący i wypisujący liczby pierwsze mniejsze od N metodą Sita Eratostenesa| ✓|
|4 |  Napisać program obliczający i wypisujący wartość N! dla N z zakresu od 1 do 1000| ✓|
|5 |  Obliczanie stałej e z rozwinięcia w szereg e=1/0!+1/1!+1/2!+1/3!+... z dokładnością do np. 1000 cyfr dziesiętnych| ✓|
|6 |  Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych zakończonych zerem stanowiącym wyłącznie znacznik końca danych. Program powinien wypisać 10 co do wielkości wartość, jaka wystąpiła w ciągu. Można założyć, że w ciągu znajduje się wystarczająca liczba elementów| ✓|
       
## Zadania dodatkowe
| Nr| Polecenie |Zrobione |
|--|--|--|
|7 | Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 i sprawdzający czy każdy element tablicy zawiera co najmniej jedną cyfrę nieparzystą | ✓|
|8 |  Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 i sprawdzający czy istnieje element tablicy zawierający wyłącznie cyfry nieparzyste| ✓|
|9 | Dana jest tablica int t[N] zawierająca liczby naturalne. W tablicy możemy przeskoczyć z pola o indeksie k o n pól w prawo jeżeli wartość n jest czynnikiem pierwszym liczby t[k]. Napisać funkcję sprawdzającą czy jest możliwe przejście z pola 0 na pole N-1 | ✓|
|10 |   Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza długość najdłuższego, spójnego podciągu rosnącego| ✓|
|11| Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza długość najdłuższego, spójnego podciągu arytmetycznego|✓|
|12|  Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza długość najdłuższego, spójnego podciągu geometrycznego|✓|
|13| Proszę napisać program, który wypełnia tablicę t[N] pseudolosowymi liczbami nieparzystymi z zakresu [1..99], a następnie Wyznacza i wypisuje różnicę pomiędzy długością najdłuższego znajdującego się w niej ciągu arytmetycznego o dodatniej różnicy, a długością najdłuższego ciągu arytmetycznego o ujemnej różnicy, przy założeniu, że kolejnymi wyrazami ciągu są elementy tablicy o kolejnych indeksach|✓|
|14| Proszę napisać program, który wypełnia tablice int tab[MAX] trzycyfrowymi liczbami pseudolosowymi, a następnie wyznacza i wypisuje długość najdłuższego podciągu spójnego znajdującego się w tablicy dla którego w tablicy występuje również rewers tego ciągu. Na przykład dla tablicy: 2,9,3,1,7,11,9,6,7,7,1,3,9,12,15 odpowiedzią jest liczba 4|✓|
|15|Napisać program wyznaczający na drodze eksperymentu prawdopodobieństwo tego, że w grupie N przypadkowo spotkanych osób, co najmniej dwie urodziły się tego samego dnia roku. Wyznaczyć wartości prawdopodobieństwa dla N z zakresu 20-40 |✓|
|16| Dana jest duża tablica int t[MAX]. Proszę napisać funkcję, która zwraca informację czy w tablicy zachodzi następujący warunek: „wszystkie elementy, których indeks jest elementem ciągu Fibonacciego są liczbami złożonymi, a wśród pozostałych przynajmniej jedna jest liczbą pierwszą”|✓|
|17| Mamy zdefiniowaną n-elementową tablicę liczb całkowitych. Proszę napisać funkcję zwracającą wartość typu bool oznaczającą, czy w tablicy istnieje dokładnie jeden element najmniejszy i dokładnie jeden element największy (liczba elementów najmniejszych oznacza liczbę takich elementów o tej samej wartości)|✓|
|18| Funkcja wyznacza różnicę pomiędzy wartością maksymalną a minimalną. Ile minimalnie porównań trzeba wykonać?|✓|
|19| Napisać funkcję, do której przekazujemy licznik i mianownik ułamka. Funkcja powinna wypisać wartość ułamka jako rozwinięcie dziesiętne uwzględniające okres, np. 1/3=0.(3), 1/6=0.1(6)| |
|20| Dane są dwie tablice t1[N] i t2[N] zawierające liczby naturalne. Z wartości w obu tablicach możemy tworzyć sumy. „Poprawna” suma to taka, która zawiera co najmniej jeden element (z tablicy t1 lub t2) o każdym indeksie. Na przykład dla tablic: t1 = [1,3,2,4] i t2 = [9,7,4,8] poprawnymi sumami są na przykład 1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8. Proszę napisać funkcje generującą i wypisująca wszystkie poprawne sumy, które są liczbami pierwszymi. Do funkcji należy przekazać dwie tablice, funkcja powinna zwrócić liczbę znalezionych i wypisanych sum| |
|21|Dane są deklaracje:  const int N=1000;  int tab[N]; Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać funkcję, która zwraca długość najdłuższego spójnego podciągu będącego palindromem złożonym wyłącznie z liczb nieparzystych. Do funkcji należy przekazać tablicę, funkcja powinna zwrócić długość znalezionego podciągu lub wartość 0 jeżeli taki podciąg nie istnieje| |
|22| Dane są deklaracje: const int N=1000; int tab[N]; Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać funkcję, która zwraca długość najdłuższego, spójnego podciągu rosnącego dla którego suma jego elementów jest równa sumie indeksów tych elementów. Do funkcji należy przekazać tablicę, funkcja powinna zwrócić długość znalezionego podciągu lub wartość 0 jeżeli taki podciąg nie istnieje|✓|
|23|Dana jest tablica int t[N] zawierająca liczby naturalne mniejsze od 1000. Proszę napisać funkcję, która zwraca długość najdłuższego, spójnego fragmentu tablicy, dla którego w iloczynie jego elementów każdy czynniki pierwszy występuje co najwyżej raz. Na przykład dla tablicy [2,23,33,35,7,4,6,7,5,11,13,22] wynikiem jest wartość 5 | |