// Solve linear congruences equation:
// - a[i] * x = b[i] MOD m[i] (mi don't need to be co-prime)
// Tested:
// - https://open.kattis.com/problems/generalchineseremainder
// - https://oj.vnoi.info/problem/icpc21_mt_d
template<typename T>
bool linearCongruences(
        const vector<T> &a,
        const vector<T> &b,
        const vector<T> &m,
        T &x,
        T &M
) {
    int n = a.size();
    x = 0; M = 1;
    for (int i = 0; i < n; i++) {
        T a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];
        T y, t, g = extgcd<T>(a_, m_, y, t);
        if (b_ % g) return false;
        b_ /= g; m_ /= g;
        x += M * (y * b_ % m_);
        M *= m_;
    }
    x = (x + M) % M;
    return true;
}
