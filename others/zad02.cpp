bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int b = 5;

    while (b <= sqrt(n)) {
        if (n % b == 0) return false;
        b += 2;
        if (n % b == 0) return false;
        b += 4;
    }
    return true;
}