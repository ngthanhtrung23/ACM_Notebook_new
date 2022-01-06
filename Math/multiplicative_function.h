// Multiplicative function
template<int N>
struct MultiplicativeFunction {
    // Init sieve and pk
    MultiplicativeFunction() {
        // Init sieve
        for (int i = 2; i*i < N; i++) {
            if (!sieve[i]) {
                for (int j = i*i; j < N; j += i) {
                    sieve[j] = i;
                }
            }
        }

        // Init pk
        for (int i = 2; i < N; i++) {
            if (!sieve[i]) {
                pk[i] = {i, 1};
            } else {
                int p = sieve[i];

                if (pk[i/p].first == p) { // i = p^k
                    pk[i] = {p, pk[i/p].second + 1};
                } else {
                    pk[i] = {-1, 0};
                }
            }
        }
    }

    // Tested: https://cses.fi/problemset/task/1713
    array<int, N> divisors() {
        array<int, N> res;
        res[1] = 1;

        for (int i = 2; i < N; i++) {
            if (pk[i].first > 0) {  // i = p^k
                res[i] = pk[i].second + 1;
            } else {
                // i = u * v, gcd(u, v) = 1
                int u = i, v = 1;
                int p = sieve[i];
                while (u % p == 0) {
                    u /= p;
                    v *= p;
                }
                res[i] = res[u] * res[v];
            }
        }

        return res;
    }

// private:
    // sieve[i] == 0 if i is prime,
    // sieve[i] = any prime factor p otherwise
    array<int, N> sieve;

    // pk[i] = {p, k} if i == p^k
    // pk[i] = {-1, 0} otherwise
    array<pair<int,int>, N> pk;
};
