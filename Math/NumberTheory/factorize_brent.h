// This seems to only work fine for random test cases
// - AC (20 digits) https://www.spoj.com/problems/FACT1/
// - TLE https://judge.yosupo.jp/problem/factorize

// brent {{{
#include "../../Misc/int128.h"

i128 brute(i128 n) {
    for (int i=2; i*i <= n; ++i) {
        if (n % i == 0) return i;
    }
    return n;
}

// returns random int in range [1, n-1]
i128 rand(i128 n) {
    return rng() % (n-1) + 1;
}

// return one divisor of n
i128 brent(i128 n) {
    if (n % 2 == 0) return 2;
    if (n < 200) return brute(n);

    i128 y = rand(n), c = rand(n), m = rand(n);
    auto sq_c = [c, n] (auto y) {
        return ((y*y) % n + c) % n;
    };

    i128 g = 1, r = 1, q = 1, x, ys;

    while (g == 1) {
        x = y;
        for (int i = 0; i < r; ++i) y = sq_c(y);

        int64_t k = 0;
        while (k < r && g == 1) {
            ys = y;
            for (int i = 0; i < min(m, r-k); ++i) {
                y = sq_c(y);
                q = q * my_abs(x - y) % n;
            }
            g = gcd(q, n);
            k += m;
        }
        r *= 2;
    }

    if (g == n) {
        while (true) {
            ys = sq_c(ys);
            g = gcd(my_abs(x - ys), n);
            if (g > 1) break;
        }
    }
    return g;
}

void factorize(i128 n, vector<i128>& fs) {
    if (n == 1) return;

    auto divisor = brent(n);
    if (divisor == n) {
        fs.push_back(divisor);
        return;
    }

    factorize(divisor, fs);
    factorize(n/divisor, fs);
}

vector<i128> factorize(i128 a) {
    if (a == 1) return {};

    vector<i128> res;
    factorize(a, res);
    sort(res.begin(), res.end());
    return res;
}
// }}}
