# Lab 2

## Zadania obowiązkowe

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 |  Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
     czy liczba ta jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego | ✓|
|2 |  Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
      czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem
      A(n)=n*n+n+1| ✓|
|3 |  Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
      czy liczba naturalna jest palindromem, a następnie czy jest palindromem w systemie
      dwójkowym| ✓|
|4 |  Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych
      czynników niż 2,3,5. Jedynka też jest taką liczbą. Napisz program, który wylicza
      ile takich liczb znajduje się w przedziale od 1 do N włącznie| ✓|
|5 |  Napisać program, który wyznacza ostatnia niezerową cyfra N! Program powinien
      działać dla N rzędu 1000000| ✓|
|6 |  Dana jest liczba naturalna o niepowtarzających się cyfrach pośród których nie ma
      zera. Ile różnych liczb podzielnych np. przez 7 można otrzymać poprzez
      wykreślenie dowolnych cyfr w tej liczbie. Np. dla 2315 będą to 21, 35, 231, 315| ✓|
|7 |  Napisać program wczytujący liczbę naturalną z klawiatury i rozkładający ją na
      iloczyn 2 liczb o najmniejszej różnicy. Np. 30=5*6, 120=10*12| ✓|
|8 |  Napisać program wczytujący trzy liczby naturalne a,b,n i wypisujący rozwinięcie
      dziesiętne ułamka a/b z dokładnością do n miejsc po kropce dziesiętnej. (n jest
      rzędu 100)| ✓|
|9 |  Pewnych liczb nie można przedstawić jako sumy elementów spójnych fragmentów ciągu
      Fibonacciego, np. 9,14,15,17,22. Proszę napisać program, który wczytuje liczbę
      naturalną n, wylicza i wypisuje następną taką liczbę większą od n. Można założyć,
      że 0<n<1000| ✓|
|10 |   Napisać program, który oblicza pole figury pod wykresem funkcji y=1/x w przedziale
       od 1 do k, metodą prostokątów| ✓|
       
## Zadania dodatkowe
| Nr| Polecenie |Zrobione |
|--|--|--|
|11| Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
     czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem A(n)=3*A(n1)+1, a pierwszy wyraz jest równy 2|✓|
|12|  Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
     czy jej cyfry stanowią ciąg rosnący|✓|
|13| Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb
     naturalnych zakończonych zerem stanowiącym wyłącznie znacznik końca danych. Program
     powinien wypisać te elementy ciągu które są równe średniej arytmetycznej z 4
     najbliższych sąsiadów. Na przykład dla ciągu: 2,3,2,7,1,2,4,8,5,2,2,4,3,9,5,4,0
     powinny zostać wypisane podkreślone liczby. Można założyć, że w ciągu znajduje się
     co najmniej 5 elementów|✓|
|14| Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
     czy liczba ta zawiera cyfrę równą liczbie swoich cyfr|✓|
|15| Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
     czy liczba zakończona jest unikalną cyfrą|✓|
|16| Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej
     liczbie muszą wystąpić wszystkie cyfry występujące w liczbach wejściowych.
     Wzajemna kolejność cyfr każdej z liczb wejściowych musi być zachowana. Na przykład
     mając liczby 123 i 75 możemy zbudować liczby 12375, 17523, 75123, 17253,itd. Proszę
     napisać funkcję która wyznaczy ile liczb pierwszych można zbudować z dwóch zadanych 
     liczb|✓|
|17|  Napisać program znajdujący wszystkie liczby N-cyfrowe dla których suma N-tych potęg
     cyfr liczby jest równa tej liczbie, np. 153=1^3+5^3+3^3|✓|
|18| Liczba Smitha to taka, której suma cyfr jest równa sumie cyfr wszystkich liczb
     występujących w jej rozkładzie na czynniki pierwsze. Na przykład: 85=5*17,
     8+5=5+1+7. Napisać program wypisujący liczby Smitha mniejsze od 1000000|✓|
|19| Napisać program poszukujący trójkątów Pitagorejskich|✓|
|20|  Napisać program wyliczający pierwiastek równania x^x=2017 metodą stycznych| |
|21| Mamy dane dwa ciągi o następujących zależnościach:
     A: a0 = 0, a1 = 1, an = an-1 - bn-1 * an-2
     B: b0 = 2, bn = bn-1 + 2 * an-1
     Proszę napisać program, który czyta liczby typu int ze standardowego wejścia i tak
     długo jak liczby te są kolejnymi wyrazami ciągu An (tj. a0, a1, a2, ...) wypisuje na
     standardowe wyjście wyrazy drugiego ciągu Bn (tj. b0, b1, b2, ...)|✓|
|22| Napisać program wczytujący dwie liczby naturalne a,b i wypisujący rozwinięcie
     dziesiętne ułamka a/b w postaci ułamka okresowego. Na przykład 1/3 = 0.(3), 1/6 =
     0.1(6), 1/7 = 0.(142857)| |
|23| Dwie liczby naturalne są różno-cyfrowe jeżeli nie posiadają żadnej wspólnej cyfry.
     Proszę napisać program, który wczytuje dwie liczby naturalne i poszukuje
     najmniejszej podstawy systemu (w zakresie 2-16) w którym liczby są różno-cyfrowe.
     Program powinien wypisać znalezioną podstawę, jeżeli podstawa taka nie istnieje
     należy wypisać komunikat o jej braku. Na przykład: dla liczb 123 i 522 odpowiedzią
     jest podstawa 11 bo 123(10)=102(11) i 522(10)=435(11)|✓|
