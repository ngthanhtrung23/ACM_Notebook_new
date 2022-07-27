#include <vector>

// Given array D[i]
// Calculate D'[i] = sum( D[j] | j is subset of i )
void sum_of_subset(std::vector<int>& D, int K) {
    for (int i = 0; i < K; ++i)
        for (int mask = 0; mask < (1 << K); ++mask)
            if ((mask >> i) & 1) D[mask] += D[mask ^ (1 << i)];
}

// Given array D[i]
// Calculate D'[i] = sum( D[j] | j is superset of i )
void sum_of_superset(std::vector<int>& D, int K) {
    std::reverse(D.begin(), D.end());
    for (int i = 0; i < K; ++i)
        for (int mask = 0; mask < (1 << K); ++mask)
            if ((mask >> i) & 1) D[mask] += D[mask ^ (1 << i)];
    std::reverse(D.begin(), D.end());
}
