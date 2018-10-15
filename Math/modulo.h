/**
 * When MOD < 2^63, use following mulMod:
 * Source: https://en.wikipedia.org/wiki/Modular_arithmetic#Example_implementations
 * On computer architectures where an extended precision format with at least 64 bits
 * of mantissa is available (such as the long double type of most x86 C compilers),
 * the following routine is faster than any algorithmic solution, by employing the
 * trick that, by hardware, floating-point multiplication results in the most
 * significant bits of the product kept, while integer multiplication results in the
 * least significant bits kept
 */
uint64_t mulMod(uint64_t a, uint64_t b, uint64_t m) {
    long double x;
    uint64_t c;
    int64_t r;

    if (a >= m) a %= m;
    if (b >= m) b %= m;

    x = a;
    c = x * b / m;
    r = (int64_t)(a * b - c * m) % (int64_t)m;
    return r < 0 ? r + m : r;
}

/** Calculates a^b % m */
uint64_t powMod(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r = m==1?0:1; // make it works when m == 1.
    while (b > 0) {
        if (b & 1) r = mulMod(r, a, m);
        b = b >> 1;
        a = mulMod(a, a, m);
    }
    return r;
}

