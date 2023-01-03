// bitmask utils {{{
inline uint64_t two(int b) {
    return 1ULL << b;
}
inline uint64_t flip_bit(uint64_t mask, int b) {
    return mask ^ two(b);
}
inline int get_bit(uint64_t mask, int b) {
    return (mask >> b) & 1ULL;
}
inline uint64_t set_bit(uint64_t mask, int b, int new_val) {
    return mask + (new_val - get_bit(mask, b)) * two(b);
}
inline int popcount(uint64_t mask) {
    return __builtin_popcountll(mask);
}
inline int ctz(uint64_t mask) {
    return __builtin_ctzll(mask);
}
template<typename F>
inline void for_each_submask(uint64_t mask, F f) {
    for (uint64_t submask = mask; submask > 0; submask = (submask - 1) & mask) {
        f(submask);
    }
}
// }}}
