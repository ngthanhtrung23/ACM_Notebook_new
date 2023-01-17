// Returns number of ways we can exchange k using set of coins {{{
template<typename T>
T coin_exchange(int k, std::vector<int> coins) {
    std::vector<T> f(k + 1);
    f[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= k; ++i) {
            f[i] += f[i-coin];
        }
    }
    return f.back();
}
// }}}
