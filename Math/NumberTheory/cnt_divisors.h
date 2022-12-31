#include "Pollard.h"
#include "../Prime/Sieve.h"

// Tested: https://www.spoj.com/problems/NUMDIV/
int64_t cnt_divisors(int64_t n) {
    assert(n > 0);
    auto ps = factorize(n);
    int cnt_ps = ps.size();
    int i = 0;
    int64_t res = 1;
    while (i < cnt_ps) {
        int j = i;
        while (j+1 < cnt_ps && ps[j+1] == ps[j]) ++j;
        res *= j - i + 2;
        i = j + 1;
    }
    return res;
}

// Count divisors Using Segmented Sieve O(sieve(sqrt(R)) + (R-L)*log) {{{
// Returns vector of length (r - l + 1), where the i-th element is number of
// divisors of i - l
vector<int> cnt_divisors_segmented_sieve(int l, int r) {
    int s = sqrt(r + 0.5);
    vector<int> primes;
    auto newPrime = [&] (int p) { primes.push_back(p); };
    sieve(s, newPrime);

    vector<int> cnt(r - l + 1, 1), cur(r - l + 1);
    std::iota(cur.begin(), cur.end(), l);

    for (int p : primes) {
        if (p > r) break;

        int u = (l + p - 1) / p * p;
        for (int i = u; i <= r; i += p) {
            int k = 0;
            while (cur[i-l] % p == 0) cur[i-l] /= p, ++k;

            cnt[i - l] *= k + 1;
        }
    }
    for (int i = l; i <= r; ++i) {
        if (cur[i-l] > 1) cnt[i-l] *= 2;
    }
    return cnt;
}
// }}}
