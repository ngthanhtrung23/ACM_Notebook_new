// Tested:
// - double -> https://oj.vnoi.info/problem/dtl_lsr
// - ins -> TODO

template<typename T>
struct Matrix {
    vector< vector<T> > x;

    Matrix() {
        x.clear();
    }
    Matrix(int m, int n) {
        x.resize(m);
        REP(i,m) {
            x[i].resize(n);
            REP(j,n) x[i][j] = 0;
        }
    }

    const vector<T>& operator [] (size_t i) const {
        return x[i];
    }
    
    vector<T>& operator [] (size_t i) {
        return x[i];
    }

    void print() {
        REP(i,SZ(x)) {
            REP(j,SZ(x[i])) cout << x[i][j] << ' ';
            cout << endl;
        }
    }

    Matrix transpose() const {
        int nRow = SZ(x);
        int nCol = SZ(x[0]);

        Matrix res(nCol, nRow);
        REP(i,nCol) REP(j,nRow) {
            res.x[i][j] = x[j][i];
        }
        return res;
    }

    // make matrix upper triangle
    // - if all rows are independent, it becomes identity matrix
    //   -> can be used to solve linear equation (remember to append column b)
    // copied from cp-algorithms
    // https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
    void gauss() {
        int n = SZ(x);
        if (n == 0) return;

        int m = SZ(x[0]);

        vector<int> where(m, -1);
        for (int col = 0, row = 0; col < m && row < n; ++col) {
            int sel = row;
            for (int i = row; i < n; ++i) {
                if (abs(x[i][col]) > abs(x[sel][col]))
                    sel = i;
            }
            if (abs(x[sel][col]) < 1e-9)   // change this for int?
                continue;

            for (int i = col; i < m; ++i)
                swap(x[sel][i], x[row][i]);
            where[col] = row;

            for (int i = 0; i < n; ++i)
                if (i != row) {
                    T c = x[i][col] / x[row][col];  // change this for int?
                    for (int j = col; j < m; ++j)
                        x[i][j] -= x[row][j] * c;
                }

            // normalize this row to [0 ... 0 1 ....]
            // needed for matrix inverse
            T coef = x[row][col];
            if (coef > 1e-9) {
                for (int j = 0; j < m; ++j)
                    x[row][j] /= coef;
            }
            ++row;
        }
    }
};

template<typename T>
Matrix<T> operator * (const Matrix<T> &a, const Matrix<T> &b) {
    if (SZ(a.x) == 0 || SZ(b.x) == 0) return Matrix<T>(); // not sure if make sense?

    Matrix<T> c(SZ(a.x), SZ(b[0]));
    REP(i,SZ(c.x)) REP(j,SZ(c[0])) {
        REP(k,SZ(a[0]))
            c[i][j] += a[i][k] * b[k][j];
    }
    return c;
}

// https://en.wikipedia.org/wiki/Gaussian_elimination#Finding_the_inverse_of_a_matrix
// Only works if matrix is invertible
template<typename T>
Matrix<T> inverse(Matrix<T> a) {
    assert(SZ(a.x) == SZ(a[0]));
    int n = SZ(a.x);

    REP(i,n) {
        vector<T> tmp(n);
        tmp[i] = 1;
        a[i].insert(a[i].end(), tmp.begin(), tmp.end());
    }

    a.gauss();

    Matrix<T> inv(n, n);
    REP(i,n) REP(j,n) {
        inv[i][j] = a[i][j+n];
    }
    return inv;
}

template<typename T>
Matrix<T> identity(int n) {
    Matrix<T> res(n, n);
    REP(i,n) res.x[i][i] = 1;
    return res;
}
