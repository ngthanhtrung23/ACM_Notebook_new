// Problem: http://vn.spoj.com/problems/EARTHQK/
#include "template.h"
#include "Geometry/basic.h"
#include "Geometry/polygon.h"

int test, x, y, m, n;

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);

    cin >> test;
    while (test --) {
        Polygon a;

        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> x >> y;
            a.push_back(Point(x, y));
        }

        cin >> x >> y;
        Point p = Point(x, y);

        cin >> m;
        for (int i = 1; i <= m; i ++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int k = ccw(Point(x1, y1), Point(x2, y2), p);
            Line l = (k != -1) ? Line(Point(x1, y1), Point(x2, y2))
                               : Line(Point(x2, y2), Point(x1, y1));
            a = polygon_cut(a, l);
        }

        cout << (long long) (area(a) * 100) << endl;
    }
}
