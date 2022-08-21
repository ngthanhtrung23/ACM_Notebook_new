// CRT {{{
// Tested:
// - https://oj.vnoi.info/problem/icpc21_mt_d
// - (__int128_t) https://judge.yosupo.jp/problem/convolution_mod_1000000007
template<typename T>
struct CRT {
    T res;

    CRT() {
        res = 0, prd = 1;
    }
    
    // Add condition: res % p == r
    void add(T p, T r) {
        res += mul(r - res % p + p, euclid(prd, p).first + p, p) * prd;
        prd *= p;
        if (res >= prd) res -= prd;
    }

private:
    T prd;
    T mul(T a, T b, T p) {
        a %= p, b %= p;
        T q = (T) ((long double) a * b / p);
        T r = a * b - q * p;
        while (r < 0) r += p;
        while (r >= p) r -= p;
        return r;
    }
    pair<T, T> euclid(T a, T b) {
        if (!b) return make_pair(1, 0);
        pair<T, T> r = euclid(b, a % b);
        return make_pair(r.second, r.first - a / b * r.second);
    }
};
// }}}
