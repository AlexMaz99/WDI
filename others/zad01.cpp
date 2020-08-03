int NWD(int a, int b) {
    int c;
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int NWW(int a, int b) {
    return a * b / NWD(a, b);
}