// sqrtMod(X, q), with q is prime, returns:
// a where a*a = X
// -1 if no solution
//
// Note:
// - there are either 1 or 2 solutions, a and p - a (which can be same).
//   This code return smaller solution
//
// Copied from https://judge.yosupo.jp/submission/59210
//
// Tested:
// - (p <= 10^9) https://judge.yosupo.jp/problem/sqrt_mod
// - (print all sols) https://oj.vnoi.info/problem/jacobi
// - https://oj.vnoi.info/problem/newj

using ll = long long;
ll euclid(ll x, ll y, ll &k, ll &l) {
    if (y == 0) {
        k = 1;
        l = 0;
        return x;
    }
    ll g = euclid(y, x % y, l, k);
    l -= k * (x / y);
    return g;
}

ll mult(ll x, ll y, ll md) {
    return x * y % md;
}
ll bin_pow(ll x, ll p, ll md) {
    if (p == 0) return 1;
    if (p & 1) return mult(x, bin_pow(x, p - 1, md), md);
    return bin_pow(mult(x, x, md), p / 2, md);
}

ll Cipolla(ll X, ll q) {
    ll pw = (q - 1) / 2;
    int K = 60;
    while((1LL << K) > pw) K--;
    while(true) {
        ll t = get_rand(q);
        ll a = 0, b = 0, c = 1;
        for (int k = K; k >= 0; k--) {
            a = b * b % q;
            b = 2 * b * c % q;
            c = (c * c + a * X) % q;
            if (((pw >> k) & 1) == 0) continue;
            a = b;
            b = (b * t + c) % q;
            c = (c * t + a * X) % q;
        }
        if (b == 0) continue;
        c = (c + q - 1) % q;
        ll k, l;
        euclid(b, q, k, l);
        c = -c * k % q;
        if (c < 0) c += q;
        if (c * c % q == X) return c;
    }
    assert(false);
}

ll sqrtMod(ll X, ll q) {
    X %= q;
    if (q == 2 || X == 0) return min(X, q-X);
    if (bin_pow(X, (q - 1) / 2, q) != 1) return -1;
    if (q % 4 == 3) {
        ll res = bin_pow(X, (q + 1) / 4, q);
        return min(res, q - res);
    }
    auto res = (Cipolla(X, q) % q + q) % q;
    return min(res, q-res);
}
