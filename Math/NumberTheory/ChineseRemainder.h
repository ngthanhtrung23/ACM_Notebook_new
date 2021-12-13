// Solve linear congruences equation:
// - a[i] * x = b[i] MOD m[i] (mi don't need to be co-prime)
// Tested:
// - https://open.kattis.com/problems/generalchineseremainder
// - https://oj.vnoi.info/problem/icpc21_mt_d
bool linearCongruences(
        const vector<long long> &a,
        const vector<long long> &b,
        const vector<long long> &m,
        long long &x,
        long long &M
) {
    long long n = a.size();
    x = 0; M = 1;
    REP(i, n) {
        long long a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];
        long long y, t, g = extgcd(a_, m_, y, t);
        if (b_ % g) return false;
        b_ /= g; m_ /= g;
        x += M * (y * b_ % m_);
        M *= m_;
    }
    x = (x + M) % M;
    return true;
}
