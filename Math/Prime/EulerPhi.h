long long eulerPhi(long long n) { // = n (1-1/p1) ... (1-1/pn)
    if (n == 0) return 0;
    long long ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
// LookUp Version
const int N = 1000000;
int eulerPhi_lookup(int n) {
    static int lookup = 0, p[N], f[N];
    if (!lookup) {
        REP(i,N) p[i] = 1, f[i] = i;
        for (int i = 2; i < N; ++i) {
            if (p[i]) {
            f[i] -= f[i] / i;
                for (int j = i+i; j < N; j+=i)
                    p[j] = 0, f[j] -= f[j] / i;
            }
        }
        lookup = 1;
    }
    return f[n];
}

// Segmented sieve version, compute phi(i) for i in [l, r]
// Tested: https://www.spoj.com/problems/ETFS/
namespace EulerPhiSegmented {
vector<int> primes;    // NOTE: must initialize this
const int N = 100111;  // >= r - l + 1

long long phi[N], val[N];  // phi[i-l] = euler_phi(i)
void eulerPhi_segmentedSieve(long long l, long long r) {
    assert(!primes.empty());  // must precompute primes upto sqrt(r)

    for (auto i = l; i <= r; ++i) {
        phi[i-l] = i;
        val[i-l] = i;
    }
    
    for (auto p : primes) {
        if (p > r) break;
        long long first = (l / p) * p;
        if (first < l) first += p;

        while (first <= r) {
            phi[first - l] -= phi[first - l] / p;
            while (val[first - l] % p == 0) val[first - l] /= p;
            first += p;
        }
    }

    for (auto i = l; i <= r; ++i) {
        if (val[i-l] > 1) {
            phi[i-l] -= phi[i-l] / val[i-l];
        }
    }
}
}
