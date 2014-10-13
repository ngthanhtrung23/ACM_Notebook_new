long long mult(long long a, long long b, long long n) {
    if (b == 0) return 0;
    if (b == 1) return a % n;
    long long mid = mult(a, b >> 1, n);
    mid = (mid + mid) % n;
    if (b & 1) return (a + mid) % n;
    else return mid;
}

long long powMod(long long a, long long d, long long n) {
    if (d == 0) return 1 % n;
    if (d == 1) return a % n;
    long long mid = powMod(a, d >> 1, n);
    mid = mult(mid, mid, n);
    if (d & 1) return mult(a, mid, n);
    else return mid;
}

bool suspect(long long a, int s, long long d, long long n) {
    long long x = powMod(a, d, n);
    if (x == 1) return true;
    for(int r = 0; r < s; ++r) {
        if (x == n-1) return true;
        x = x * x % n;
    }
    return false;
}

// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(long long n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    int test[] = {2,3,5,7,11,13,17,19,23,-1};
    long long d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
}
