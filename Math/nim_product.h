// Nim product
// Works for 0 <= x, y < 2^64
//
// Copied from https://judge.yosupo.jp/submission/64825
//
// Tested:
// - https://oj.vnoi.info/problem/winstrat
// - https://judge.yosupo.jp/problem/nim_product_64
using ull = unsigned long long;
ull _naive_rec(ull x, ull y) {
    if (x == 0 || y == 0) return 0;
    if (x < y) swap(x, y);
    if (y == 1) return x;

    for (int shift = 32; ; shift /= 2) {
        ull mask = (1ull << shift) - 1;
        if (y >> shift) {
            ull v00 = _naive_rec(x & mask, y & mask);
            ull v01 = _naive_rec(x & mask, y >> shift);
            ull v10 = _naive_rec(x >> shift, y & mask);
            ull v11 = _naive_rec(x >> shift, y >> shift);
            return v00 ^ ((v01 ^ v10 ^ v11) << shift) ^ _naive_rec(v11, 1ULL << (shift - 1));
        } else if (x >> shift) {
            return (_naive_rec(x >> shift, y) << shift) ^ _naive_rec(x & mask, y);
        }
    }
}
const array<array<unsigned, 256>, 256> smalls = []() {
    array<array<unsigned, 256>, 256> res;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            res[i][j] = _naive_rec(i, j);
        }
    }
    return res;
}();
const array<array<array<ull, 256>, 8>, 8> f = []() {
    array<array<array<ull, 256>, 8>, 8> res;
    for (int d = 0; d < 8; d++) {
        for (int e = 0; e < 8; e++) {
            ull p = _naive_rec(1ull << (8*d), 1ull << (8*e));
            for (int i = 0; i < 256; i++) res[d][e][i] = _naive_rec(p, i);
        }
    }
    return res;
}();

ull mult(ull x, ull y) {
    ull res = 0;
    for (int d = 0; d < 8; d++) {
        for (int e = 0; e < 8; e++) {
            res ^= f[d][e][smalls[(x >> (d * 8)) & 255][(y >> (e * 8)) & 255]];
        }
    }
    return res;
}

