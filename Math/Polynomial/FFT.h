// Let's just not use this inefficient code and use dacin21's code here:
// https://github.com/dacin21/dacin21_codebook/blob/master/nt/polynomials_2.0.cpp
//
// Example with using Fft class directly (maybe it's easier to use dacin21's class Polynomial):
//
// const int MOD = 1e9 + 7;
// vector<int64_t> a, b;
// vector<int64_t> res;
// 
// // res = a * b:
// if (mod <= 5000) Fft<Complex<double>>::poly_mul_faster(res, a, b, MOD);
// else Fft<Complex<double>>::poly_mul_split(res, a, b, MOD);
//
// // res = a * a;
// if (mod <= 5000) Fft<Complex<double>>::poly_mul_faster(res, a, a, MOD);
// else Fft<Complex<double>>::poly_square_split(res, a, MOD);







// Below code is my inefficient implementation:
// Tested:
// - FBHC 2016 R3 - Problem E
// - https://open.kattis.com/problems/polymul2 (need long double)
// Note:
// - a[2] will have size <= 2*n
// - When rounding, careful with negative numbers:
int my_round(double x) {
    if (x < 0) return -my_round(-x);
    return (int) (x + 1e-3);
}

const double PI = acos((double) -1.0);

typedef complex<double> cplex;
int rev[MN];
cplex wlen_pw[MN], fa[MN], fb[MN];

void fft(cplex a[], int n, bool invert) {
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap (a[i], a[rev[i]]);

    for (int len = 2; len <= n; len <<= 1) {
        double alpha = 2 * PI / len * (invert ? -1 : +1);
        int len2 = len >> 1;

        wlen_pw[0] = cplex(1, 0);
        cplex wlen(cos(alpha), sin(alpha));
        for (int i = 1; i < len2; ++i) wlen_pw[i] = wlen_pw[i-1] * wlen;

        for (int i = 0; i < n; i += len) {
            cplex t, *pu = a+i, *pv = a + i + len2,
                    *pu_end = a + i + len2, *pw = wlen_pw;
            for (; pu != pu_end; ++pu, ++pv, ++pw) {
                t = *pv * *pw;
                *pv = *pu - t;
                *pu += t;
            }
        }
    }

    if (invert) REP(i, n) a[i] /= n;
}

void calcRev(int n, int logn) {
    REP(i, n) {
        rev[i] = 0;
        REP(j, logn) if (i & (1 << j)) rev[i] |= 1 << (logn - 1 - j);
    }
}

void mulpoly(int a[], int b[], ll c[], int na, int nb, int &n) {
    int l = max(na, nb), logn = 0;
    for (n = 1; n < l; n <<= 1) ++logn;
    n <<= 1; ++logn;
    calcRev(n, logn);

    REP(i,n) fa[i] = fb[i] = cplex(0);
    REP(i,na) fa[i] = cplex(a[i]);
    REP(i,nb) fb[i] = cplex(b[i]);

    fft(fa, n, false);
    fft(fb, n, false);

    REP(i,n) fa[i] *= fb[i];
    fft(fa, n, true);

    REP(i,n) c[i] = (ll)(fa[i].real() + 0.5);
}
