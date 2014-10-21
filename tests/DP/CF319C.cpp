#include "template.h"
#include "DP/convex_hull.h"

int n;
long long a[MAXN], b[MAXN];
long long f[MAXN];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    while (cin >> n) {
        FOR(i,1,n) cin >> a[i];
        FOR(i,1,n) cin >> b[i];

        Hull hull;
        FOR(i,1,n) {
            f[i] = hull.get(a[i]);
            hull.add(b[i], f[i]);
        }
        cout << f[n] << endl;
    }
}
