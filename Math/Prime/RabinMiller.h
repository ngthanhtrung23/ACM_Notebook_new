// Use isPrime in Pollard.h instead

// Tested:
// - (up to 10^19) https://oj.vnoi.info/problem/icpc22_national_c
//
// If TLE, try:
// 1. If numbers are <= 7.2e18 -> use modMul from KACTL:
//    https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h
// 2. Sieve and check for small primes separately
// 3. Check divisible by first 50 primes (see https://oj.vnoi.info/src/1816262)

#include <initializer_list>

using uint = unsigned long long;
uint mult(uint x, uint y, uint mod) {
    return __int128_t(x) * y % mod;
}

uint powMod(uint x, uint p, uint mod) {
    if (p == 0) return 1;
    if (p % 2) return mult(x, powMod(x, p - 1, mod), mod);
    return powMod(mult(x, x, mod), p / 2, mod);
}

bool checkMillerRabin(uint x, uint mod, uint s, int k) {
    x = powMod(x, s, mod);
    if (x == 1) return true;
    while(k--) {
        if (x == mod - 1) return true;
        x = mult(x, x, mod);
        if (x == 1) return false;
    }
    return false;
}

bool is_prime(uint x) {
    if (x == 2 || x == 3 || x == 5 || x == 7) return true;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;
    if (x < 121) return x > 1;

    uint s = x - 1;
    int k = 0;
    while (s % 2 == 0) {
        s /= 2;
        k++;
    }
    if (x < 1LL << 32) {
        for (uint z : {2, 7, 61}) {
            if (!checkMillerRabin(z, x, s, k)) return false;
        }
    } else {
        for (uint z : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            if (!checkMillerRabin(z, x, s, k)) return false;
        }
    }
    return true;
}
