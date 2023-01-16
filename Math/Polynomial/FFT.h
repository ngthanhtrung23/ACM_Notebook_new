// Note:
// - When convert double -> int, use my_round(x) which handles negative numbers
//   correctly.
//
// Tested:
// - https://open.kattis.com/problems/polymul2
// - https://www.spoj.com/problems/TSUM/
// - (bigint mul) https://www.spoj.com/problems/VFMUL/
// - (bigint mul) https://www.spoj.com/problems/MUL/
// - (string matching) https://www.spoj.com/problems/MAXMATCH
//
// FFT {{{
// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h

using ld = double;
// Can use std::complex<ld> instead to make code shorter (but it will be slightly slower)
struct Complex {
    ld x[2];

    Complex() { x[0] = x[1] = 0.0; }
    Complex(ld a) { x[0] = a; }
    Complex(ld a, ld b) { x[0] = a; x[1] = b; }
    Complex(const std::complex<ld>& c) {
        x[0] = c.real();
        x[1] = c.imag();
    }

    Complex conj() const {
        return Complex(x[0], -x[1]);
    }

    Complex operator + (const Complex& c) const {
        return Complex {
            x[0] + c.x[0],
            x[1] + c.x[1],
        };
    }
    Complex operator - (const Complex& c) const {
        return Complex {
            x[0] - c.x[0],
            x[1] - c.x[1],
        };
    }
    Complex operator * (const Complex& c) const {
        return Complex(
            x[0] * c.x[0] - x[1] * c.x[1],
            x[0] * c.x[1] + x[1] * c.x[0]
        );
    }

    Complex& operator += (const Complex& c) { return *this = *this + c; }
    Complex& operator -= (const Complex& c) { return *this = *this - c; }
    Complex& operator *= (const Complex& c) { return *this = *this * c; }
};
void fft(vector<Complex>& a) {
    int n = a.size();
    int L = 31 - __builtin_clz(n);
    static vector<Complex> R(2, 1);
    static vector<Complex> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = Complex(polar(ld(1.0), acos(ld(-1.0)) / k));
        for (int i = k; i < 2*k; ++i) {
            rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
        }
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) rev[i] = (rev[i/2] | (i&1) << L) / 2;
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2*k) {
            for (int j = 0; j < k; ++j) {
                auto x = (ld*) &rt[j+k].x, y = (ld*) &a[i+j+k].x;
                Complex z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}
vector<ld> multiply(const vector<ld>& a, const vector<ld>& b) {
    if (a.empty() || b.empty()) return {};
    vector<ld> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1<<L;
    vector<Complex> in(n), out(n);

    for (size_t i = 0; i < a.size(); ++i) in[i].x[0] = a[i];
    for (size_t i = 0; i < b.size(); ++i) in[i].x[1] = b[i];

    fft(in);
    for (Complex& x : in) x *= x;

    for (int i = 0; i < n; ++i) out[i] = in[-i & (n-1)] - in[i].conj();
    fft(out);

    for (size_t i = 0; i < res.size(); ++i) res[i] = out[i].x[1] / (4*n);
    return res;
}
long long my_round(ld x) {
    if (x < 0) return -my_round(-x);
    return (long long) (x + 1e-2);
}
vector<long long> multiply(const vector<int>& a, const vector<int>& b) {
    vector<ld> ad(a.begin(), a.end());
    vector<ld> bd(b.begin(), b.end());
    auto rd = multiply(ad, bd);
    vector<long long> res(rd.size());
    for (int i = 0; i < (int) res.size(); ++i) {
        res[i] = my_round(rd[i]);
    }
    return res;
}
// }}}
