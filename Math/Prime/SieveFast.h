// Tested:
// - (3B+) https://oj.vnoi.info/problem/icpc22_national_c
// - (1B, collect into vector of primes) https://www.spoj.com/problems/KPRIMES2/
// - (1B, print) https://www.spoj.com/problems/PRIMES2/
//
// Note:
// - It's possible to extract code from here to have a fast implementation
//   of segmented sieve for [L, R] where R is very big (e.g. 10^12)
//   See: https://www.spoj.com/status/SUMPRIM2,mr_invincible/
//   However there are several things that need to be fixed:
//   1. Initialization of small primes:
//      - Need to change 256 -> R^0.25
//      - Change 32768 -> R^0.5
//   2. Change N_SMALL_PRIMES
//   3. If R^0.5 is around 10^6, p^2 overflow int, so need to check everywhere..
//   4. si[SIEVE_SIZE] may not have enough elements to sieve small_primes..
//   5. update_sieve(offset) assumes offset is a multiple of SIEVE_SPAN. This
//      is not true if we sieve a segment [L, R]
//   6. Maybe more issues..
//   Essentially if we need to do this, either use SegmentedSieve or copy from
//   https://www.spoj.com/status/SUMPRIM2,mr_invincible/ which I spent like an
//   hour to make it work..

// Segmented sieve with wheel factorization {{{
namespace segmented_sieve_wheel {
const int WHEEL = 3 * 5 * 7 * 11 * 13;
const int N_SMALL_PRIMES = 6536;             // cnt primes less than 2^16
const int SIEVE_SPAN = WHEEL * 64;           // one iteration of segmented sieve
const int SIEVE_SIZE = SIEVE_SPAN / 128 + 1;
 
uint64_t ONES[64];                           // ONES[i] = 1<<i
int small_primes[N_SMALL_PRIMES];            // primes less than 2^16
 
// each element of sieve is a 64-bit bitmask.
// Each bit (0/1) stores whether the corresponding element is a prime number.
// We only need to store odd numbers
// -> 1st bitmask stores 3, 5, 7, 9, ...
uint64_t si[SIEVE_SIZE];
// for each 'wheel', we store the sieve pattern (i.e. what numbers cannot
// be primes)
uint64_t pattern[WHEEL];
 
inline void mark(uint64_t* s, int o) { s[o >> 6] |= ONES[o & 63]; }
inline int test(uint64_t* s, int o) { return (s[o >> 6] & ONES[o & 63]) == 0; }
 
// update_sieve {{{
void update_sieve(uint32_t offset) {
    // copy each wheel pattern to sieve
    for (int i = 0, k; i < SIEVE_SIZE; i += k) {
        k = std::min(WHEEL, SIEVE_SIZE - i);
        memcpy(si + i, pattern, sizeof(*pattern) * k);
    }
 
    // Correctly mark 1, 3, 5, 7, 11, 13 as not prime / primes
    if (offset == 0) {
        si[0] |= ONES[0];
        si[0] &= ~(ONES[1] | ONES[2] | ONES[3] | ONES[5] | ONES[6]);
    }
 
    // sieve for primes >= 17 (stored in `small_primes`)
    for (int i = 0; i < N_SMALL_PRIMES; ++i) {
        uint32_t j = small_primes[i] * (uint32_t) small_primes[i];
        if (j > offset + SIEVE_SPAN - 1) break;
        if (j > offset) j = (j - offset) >> 1;
        else {
            j = small_primes[i] - offset % small_primes[i];
            if ((j & 1) == 0) j += small_primes[i];
            j >>= 1;
        }
        while (j < SIEVE_SPAN / 2) {
            mark(si, j);
            j += small_primes[i];
        }
    }
}
// }}}
 
template<typename F>
void sieve(uint32_t MAX, F func) {
    // init small primes {{{
    for (int i = 0; i < 64; ++i) ONES[i] = 1ULL << i;
 
    // sieve to find small primes
    for (int i = 3; i < 256; i += 2) {
        if (test(si, i >> 1)) {
            for (int j = i*i / 2; j < 32768; j += i) mark(si, j);
        }
    }
    // store primes >= 17 in `small_primes` (we will sieve differently
    // for primes 2, 3, 5, 7, 11, 13)
    {
        int m = 0;
        for (int i = 8; i < 32768; ++i) {
            if (test(si, i)) small_primes[m++] = i*2 + 1;
        }
        assert(m == N_SMALL_PRIMES);
    }
    // }}}
 
    // For primes 3, 5, 7, 11, 13: we initialize wheel pattern..
    for (int i = 1; i < WHEEL * 64; i += 3) mark(pattern, i);
    for (int i = 2; i < WHEEL * 64; i += 5) mark(pattern, i);
    for (int i = 3; i < WHEEL * 64; i += 7) mark(pattern, i);
    for (int i = 5; i < WHEEL * 64; i += 11) mark(pattern, i);
    for (int i = 6; i < WHEEL * 64; i += 13) mark(pattern, i);
 
    // Segmented sieve
    if (2 <= MAX) func(2);
    for (uint32_t offset = 0; offset < MAX; offset += SIEVE_SPAN) {
        update_sieve(offset);
 
        for (uint32_t j = 0; j < SIEVE_SIZE; j++){
            uint64_t x = ~si[j];
            while (x){
                uint32_t p = offset + (j << 7) + (__builtin_ctzll(x) << 1) + 1;
                if (p > offset + SIEVE_SPAN - 1) break;
                if (p <= MAX) {
                    func(p);
                }
                x ^= (-x & x);
            }
        }
    }
}
}
using segmented_sieve_wheel::sieve;
// }}}
