// Problem: http://vn.spoj.com/problems/KMIX/
#include "template.h"
#include "Geometry/basic.h"
#include "Geometry/polygon.h"

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    int n;
    while (cin >> n) {
        Polygon a;
        REP(i,n) {
            int x, y; cin >> x >> y;
            a.push_back(Point(x, y));
        }
        a = convex_hull(a);

        int q; cin >> q;
        while (q--) {
            int x, y; cin >> x >> y;
            if (in_convex(a, Point(x, y))) cout << "YES";
            else cout << "NO";
            cout << "\n";
        }
    }
    return 0;
}
