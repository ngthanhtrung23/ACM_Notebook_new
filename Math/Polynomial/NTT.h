// NTT {{{
//
// Faster than NTT_chemthan.h
//
// Usage:
// auto c = multiply(a, b);
// where a and b are vector<ModInt<ANY_MOD>>
// (If mod is NOT NTT_PRIMES, it does 3 NTT and combine result)

constexpr int NTT_PRIMES[] = {998244353, 167772161, 469762049};

// assumptions:
// - |a| is power of 2
// - mint::mod() is a valid NTT primes (2^k * m + 1)
template<typename mint> void ntt(std::vector<mint>& a, bool is_inverse) {
    int n = a.size();
    if (n == 1) return;

    static const int mod = mint::mod();
    static const mint root = mint::get_primitive_root();
    assert(__builtin_popcount(n) == 1 && (mod - 1) % n == 0);

    static std::vector<mint> w{1}, iw{1};
    for (int m = w.size(); m < n / 2; m *= 2) {
        mint dw = root.pow((mod - 1) / (4 * m));
        mint dwinv = dw.inv();
        w.resize(m * 2);
        iw.resize(m * 2);
        for (int i = 0; i < m; ++i) {
            w[m + i] = w[i] * dw;
            iw[m + i] = iw[i] * dwinv;
        }
    }

    if (!is_inverse) {
        for (int m = n; m >>= 1; ) {
            for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {
                for (int i = s; i < s + m; ++i) {
                    mint x = a[i], y = a[i + m] * w[k];
                    a[i] = x + y;
                    a[i + m] = x - y;
                }
            }
        }
    } else {
        for (int m = 1; m < n; m *= 2) {
            for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {
                for (int i = s; i < s + m; ++i) {
                    mint x = a[i], y = a[i + m];
                    a[i] = x + y;
                    a[i + m] = (x - y) * iw[k];
                }
            }
        }
        int n_inv = mint(n).inv().x;
        for (auto& v : a) v *= n_inv;
    }
}

template<typename mint>
std::vector<mint> ntt_multiply(int sz, std::vector<mint> a, std::vector<mint> b) {
    a.resize(sz);
    b.resize(sz);
    if (a == b) { // optimization for squaring polynomial
        ntt(a, false);
        b = a;
    } else {
        ntt(a, false);
        ntt(b, false);
    }
    for (int i = 0; i < sz; ++i) a[i] *= b[i];
    ntt(a, true);
    return a;
}

template<int MOD, typename mint>
std::vector<ModInt<MOD>> convert_mint_and_multiply(
        int sz,
        const std::vector<mint>& a,
        const std::vector<mint>& b) {
    using mint2 = ModInt<MOD>;

    std::vector<mint2> a2(a.size()), b2(b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        a2[i] = mint2(a[i].x);
    }
    for (size_t i = 0; i < b.size(); ++i) {
        b2[i] = mint2(b[i].x);
    }
    return ntt_multiply(sz, a2, b2);
}

long long combine(int r0, int r1, int r2, int mod) {
    using mint2 = ModInt<NTT_PRIMES[2]>;
    static const long long m01 = 1LL * NTT_PRIMES[0] * NTT_PRIMES[1];
    static const long long m0_inv_m1 = ModInt<NTT_PRIMES[1]>(NTT_PRIMES[0]).inv().x;
    static const long long m01_inv_m2 = mint2(m01).inv().x;

    int v1 = (m0_inv_m1 * (r1 + NTT_PRIMES[1] - r0)) % NTT_PRIMES[1];
    auto v2 = (mint2(r2) - r0 - mint2(NTT_PRIMES[0]) * v1) * m01_inv_m2;
    return (r0 + 1LL * NTT_PRIMES[0] * v1 + m01 % mod * v2.x) % mod;
}

template<typename mint>
std::vector<mint> multiply(const std::vector<mint>& a, const std::vector<mint>& b) {
    if (a.empty() || b.empty()) return {};
    int sz = 1, sz_a = a.size(), sz_b = b.size();
    while (sz < sz_a + sz_b) sz <<= 1;
    if (sz <= 16) {
        std::vector<mint> res(sz_a + sz_b - 1);
        for (int i = 0; i < sz_a; ++i) {
            for (int j = 0; j < sz_b; ++j) {
                res[i + j] += a[i] * b[j];
            }
        }
        return res;
    }

    int mod = mint::mod();
    std::vector<mint> res;
    if (std::find(std::begin(NTT_PRIMES), std::end(NTT_PRIMES), mod) != std::end(NTT_PRIMES)) {
        res = ntt_multiply(sz, a, b);
    } else {
        auto c0 = convert_mint_and_multiply<NTT_PRIMES[0], mint> (sz, a, b);
        auto c1 = convert_mint_and_multiply<NTT_PRIMES[1], mint> (sz, a, b);
        auto c2 = convert_mint_and_multiply<NTT_PRIMES[2], mint> (sz, a, b);

        res.resize(sz);
        for (int i = 0; i < sz; ++i) {
            res[i] = combine(c0[i].x, c1[i].x, c2[i].x, mod);
        }
    }

    res.resize(sz_a + sz_b - 1);
    return res;
}
// }}}
