#include "template.h"
#include "basic.h"
#include "circle.h"
#include "SmallestEnclosingCircle.h"

int main() {
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector< Point > p;
        while (n--) {
            double x, y; cin >> x >> y;
            p.push_back(Point(x, y));
        }

        Circle *c = smallestClosingCircle.makeCircle(p);
        cout << (fixed) << setprecision(2) << c->r << "\n" << c->x << ' ' << c->y << "\n";
    }
}

