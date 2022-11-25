#include "Pollard.h"

// Tested: https://www.spoj.com/problems/NUMDIV/
int64_t cnt_divisors(int64_t n) {
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
