// Solve linear congruences equation:
// - a[i] * x = b[i] MOD m[i]
// Tested:
// - https://open.kattis.com/problems/generalchineseremainder
bool linearCongruences(const vector<int> &a, const vector<int> &b, 
        const vector<int> &m, int &x, int &M) {  
    int n = a.size();
    x = 0; M = 1;
    REP(i, n) {
        int a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];
        int y, t, g = extgcd(a_, m_, y, t);
        if (b_ % g) return false;
        b_ /= g; m_ /= g;
        x += M * (y * b_ % m_);
        M *= m_;
    }
    x = (x + M) % M;
    return true;
}
