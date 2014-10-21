#include "template.h"
#include "DP/convex_hull.h"

const int MN = 100111;

int n, m, nFeed;
long long d[MN], p[MN], h[MN], a[MN], s[MN], t[MN];
long long f[111][MN];

int main() {
    while (cin >> n >> m >> nFeed) {
        FOR(i,2,n) {
            cin >> d[i];
            p[i] = p[i-1] + d[i];
        }
        FOR(i,1,m) {
            cin >> h[i] >> t[i];
            a[i] = t[i] - p[h[i]];
        }
        sort(a+1, a+m+1);
        FOR(i,1,m) s[i] = s[i-1] + a[i];

        // PR(a, m);

        FOR(i,1,nFeed) {
            Hull hull;
            FOR(j,1,m) {
                f[i][j] = hull.get(a[j]) + a[j] * j - s[j];
                if (i > 1) hull.add(-j, f[i-1][j] + s[j]);
            }
            // PR(f[i], m);
        }
        long long res = f[1][m];
        FOR(i,1,nFeed) res = min(res, f[i][m]);
        cout << res << endl;
    }
}

