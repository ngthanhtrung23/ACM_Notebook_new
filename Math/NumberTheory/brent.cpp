long long brent(long long n) { 
    if (!(n & 1)) return 2;
    if (!(n % 3)) return 3;

    const int p[3] = {1, 3, 5};
    long long y, q, x, ys, g, my = 3;
    int i, j, k, m, r, c;

    for (i = 0; i < my; ++i) {
        y = 1; r = 1; q = 1; m = 111; c = p[i];

        do {
            x = y; k = 0;
            for (j = 1; j <= r; ++j) y = (mul(y, y, n) + c) % n;
            do {
                ys = y;
                for (j = 1; j <= min(m, r-k); ++j) {
                    y = (mul(y, y, n) + c) % n;
                    q = mul(q, abs(x - y), n);
                }
                g = gcd(q, n); k += m;
            } while (k < r && g < 2);
            r <<= 1;
        } while (g < 2);

        if (g == n)
            do {
                ys = (mul(ys, ys, n) + c) % n;
                g = gcd(abs(x - ys), n);
            } while (g < 2);

        if (g != n) return g;
    }
    return n;
}
