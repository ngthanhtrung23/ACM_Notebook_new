// Tested:
// - https://www.spoj.com/problems/PRIC/

#include <cstdint>
// Rabin Miller for 32-bit numbers {{{
inline unsigned mod_mult(unsigned a, unsigned b, unsigned m) {
    return (uint64_t)a*b%m;
}
 
unsigned mod_pow(unsigned a, uint64_t b, unsigned m) {
    unsigned ret = 1;
    for(;;) {
        if (b&1) ret = mod_mult(ret, a, m);
        if (!(b>>=1)) return ret;
        a = mod_mult(a, a, m);
    }
}
 
bool is_prime(unsigned n) {
    if (n <= 3) return (n >= 2);
    static const unsigned small[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
    };
    for (size_t i = 0; i < sizeof(small)/sizeof(unsigned); i++) {
        if (n%small[i] == 0) return n == small[i];
    }
 
    // Jaeschke93 showed that 2,7,61 suffice for n < 4,759,123,141.
    static const unsigned millerrabin[] = {2, 7, 61};
    unsigned s = n-1, r = 0;
    while (s%2 == 0) {s /= 2; r++;}
 
    for (size_t i = 0, j; i < sizeof(millerrabin)/sizeof(unsigned); i++) {
        unsigned md = mod_pow(millerrabin[i], s, n);
        if (md == 1) continue;
        for (j = 1; j < r; j++) {
            if (md == n-1) break;
            md = mod_mult(md, md, n);
        }
        if (md != n-1) return false;
    }
 
    return true;
}
// }}}
