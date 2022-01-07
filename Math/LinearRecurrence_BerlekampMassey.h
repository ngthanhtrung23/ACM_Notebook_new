// Berlekamp Massey
// Given sequence s0, ..., s(N-1)
// Find sequence c1, ..., cd with minimum d (d >= 0), such that:
//   si = sum(s(i-j) * c(j), for j = 1..d)
//
// Tutorial: https://mzhang2021.github.io/cp-blog/berlekamp-massey/
// If we have the linear recurrence, we can compute s(n):
// - O(n*d) naively
// - O(d^3 * log(n)) with matrix exponentiation
// - O(d*log(d)*log(k)) with generating function (tutorial above)
//
// Solving problems where we need to compute f(n) mod P (e.g. VOJ SELFDIV)
// - Guess that f is a linear recurrence
// - Compute f(n) for small n
// - Run Berlekamp Massey to find C (we must have 2*|C| < n, otherwise it's wrong)
//
// Note:
// - should be calculated in prime modulo (i.e. T=modint), as it
//   requires modular inverse
// - when modulo is not prime --> https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/linear-recurrence.cc
//   but this comment says it doesn't work on some problem: https://codeforces.com/blog/entry/61306?#comment-454682
//
// Tested:
// - (BM) https://judge.yosupo.jp/problem/find_linear_recurrence
// - (BM + find_kth) https://oj.vnoi.info/problem/selfdiv
// - (find_kth) https://oj.vnoi.info/problem/errichto_matexp_fibonacci
// - (find_kth) https://cses.fi/problemset/task/2181/

// Returns c1, ..., cd
template<typename T>
vector<T> berlekampMassey(vector<T> s) {
    if (s.empty()) return {};

    int n = s.size(), L = 0, m = 0; // m = i - f
    vector<T> C(n), D(n), oldC;
    C[0] = D[0] = 1;
    T df1 = 1;  // d(f+1)
    for (int i = 0; i < n; i++) {
        ++m;
        // check if C(i) == a(i)
        // delta = s_i - sum( cj * s(i-j) ) = d(f+1)?
        T delta = s[i];
        for (int j = 1; j <= L; j++) {
            delta += C[j] * s[i-j];  // C(j) is already multiplied by -1
        }
        if (delta == 0) continue;  // C(i) is correct

        // Update c = c + d
        oldC = C;
        T coeff = delta * df1.inv();
        for (int j = m; j < n; j++) {
            C[j] -= coeff * D[j - m];  // prepend D with m zeroes, multiply by coeff and add to C
        }
        if (2*L > i) continue;
        L = i + 1 - L, D = oldC, df1 = delta, m = 0;
    }
    C.resize(L + 1);
    C.erase(C.begin());
    for (auto& x : C) x = -x;
    return C;
}

// Helper function
template<typename T>
vector<T> mul(const vector<T> &a, const vector<T> &b, const vector<T>& c) {
    vector<T> ret(a.size() + b.size() - 1);
    // ret = a * b
    for (int i=0; i<(int)a.size(); i++)
        for (int j=0; j<(int)b.size(); j++)
            ret[i+j] += a[i] * b[j];

    int n = c.size();
    // reducing ret mod f(x)
    for (int i=(int)ret.size()-1; i>=n; i--)
        for (int j=n-1; j>=0; j--)
            ret[i-j-1] += ret[i] * c[j];
    ret.resize(min((int) ret.size(), n));
    return ret;
}

// Find k-th element in linear recurrence: O(d^2 * logn)
// Need faster code? See https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
//   (but usually not needed since bottleneck is BerlekampMassey
//
// Params:
// - c: as returned by berlekampMassey
// - s: s0, s1, ..., s(N-1)
// Returns: s(k)
template<typename T>
T solve(const vector<T> &c, const vector<T> &s, long long k) {
    int n = (int) c.size();
    assert(c.size() <= s.size());

    vector<T> a = n == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};
    for (; k>0; k/=2) {
        if (k % 2)
            x = mul(x, a, c);  // mul(a, b) computes a(x) * b(x) mod f(x)
        a = mul(a, a, c);
    }
    x.resize(n);

    T ret = 0;
    for (int i=0; i<n; i++)
        ret += x[i] * s[i];
    return ret;
}
