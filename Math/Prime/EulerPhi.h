int eulerPhi(int n) { // = n (1-1/p1) ... (1-1/pn)
    if (n == 0) return 0;
    int ans = n;
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
int eulerPhi(int n) {
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
