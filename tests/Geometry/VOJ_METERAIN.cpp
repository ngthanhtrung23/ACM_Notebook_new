// Problem: http://vn.spoj.com/problems/METERAIN/
#include "template.h"
#include "Geometry/basic.h"
#include "Geometry/polygon.h"

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n;
    while (cin >> n) {
        Polygon a;
        for(int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            a.push_back(Point(x, y));
        }
        int m; cin >> m;
        for(int i = 0; i < m; ++i) {
            int x, y; cin >> x >> y;
            Point P(x, y);

            if (in_convex(a, P)) cout << "YES";
            else cout << "NO";
            cout << "\n";
        }
    }
}

