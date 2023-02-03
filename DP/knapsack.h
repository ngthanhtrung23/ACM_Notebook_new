// Knapsack 01 {{{
// Select subset of items, such that sum(weights) <= capacity
// and sum(values) is maximum
int knapsack01(
        int capacity,
        const std::vector<int>& weights,
        const std::vector<int>& values) {
    int n = weights.size();
    std::vector<int> f(capacity + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = capacity; j >= weights[i]; --j) {
            f[j] = max(f[j], f[j-weights[i]] + values[i]);
        }
    }

    return *max_element(f.begin(), f.end());
}
// }}}
// Knapsack unbounded {{{
// Select subset of items, such that sum(weights) <= capacity
// and sum(values) is maximum
// An item can be selected unlimited number of times
int knapsack_unbounded(
        int capacity,
        const std::vector<int>& weights,
        const std::vector<int>& values) {
    int n = weights.size();
    std::vector<int> f(capacity + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = weights[i]; j <= capacity; ++j) {
            f[j] = max(f[j], f[j-weights[i]] + values[i]);
        }
    }

    return *max_element(f.begin(), f.end());
}
// }}}
