struct Matrix {
    vector< vector<long long> > x;
    int m, n;

    Matrix(int m = 0, int n = 0) : m(m), n(n) {
        x.resize(m);
        REP(i,m) {
            x[i].resize(n);
            REP(j,n) x[i][j] = 0;
        }
    }
    void print() {
        REP(i,m) {
            REP(j,n) cout << x[i][j] << ' ';
            cout << endl;
        }
    }
};
Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c(a.m, b.n);
    REP(i,c.m) REP(j,c.n) {
        REP(k,a.n)
            c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
    }
    return c;
}

Matrix identity(int n) {
    Matrix res(n, n);
    REP(i,n) res.x[i][i] = 1;
    return res;
}
