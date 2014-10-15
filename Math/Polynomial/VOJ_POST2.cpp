#include "../../template.h"

const int MN = 1000111;
#include "FFT.h"

int cnt_a[MN], cnt_b[MN];
Base a[3][MN];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    FOR(i,1,n) {
        int u; cin >> u;
        ++cnt_a[u + 50000];
    }
    FOR(i,1,n) {
        int u; cin >> u;
        ++cnt_b[u + 50000];
    }

    FOR(i,0,100000) {
        a[0][i] = Base(cnt_a[i], 0);
        a[1][i] = Base(cnt_b[i], 0);
    }
    multiply(a, 100000);

    long long res = 0;
    FOR(i,1,n) {
        int u; cin >> u;
        res += (long long) (a[2][100000 + u].real() + 0.5);
    }
    cout << res << endl;
}
