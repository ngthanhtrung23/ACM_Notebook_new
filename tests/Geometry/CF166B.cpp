// Problem: http://codeforces.com/contest/166/problem/B

#include "template.h"
#include "Geometry/basic.h"
#include "Geometry/polygon.h"

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    int na, nb;
    while (cin >> na) {
        Polygon a, b;
        while (na--) {
            int x, y; cin >> x >> y;
            a.push_back(Point(x, y));
        }
        cin >> nb;
        while (nb--) {
            int x, y; cin >> x >> y;
            b.push_back(Point(x, y));
        }

        bool ok = true;
        for(int i = 0; i < b.size(); ++i) 
            if (!in_convex(a, b[i])) {
                ok = false;
                break;
            }
        if (ok) cout << "YES"; else cout << "NO";
        cout << endl;
    }
}
