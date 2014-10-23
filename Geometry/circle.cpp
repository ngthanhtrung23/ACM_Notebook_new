#include "../template.h"
#include "basic.h"
#include "circle.h"

int main() {
    // Example: Check point inside circle
    Circle C1(2, 2, 7);
    assert(cmp((C1 - Point(8, 2)).norm(), C1.r * C1.r) < 0);
    assert(cmp((C1 - Point(9, 2)).norm(), C1.r * C1.r) == 0);
    assert(cmp((C1 - Point(10, 2)).norm(), C1.r * C1.r) > 0);

    // Find common tangents
    Circle c2(1, 2, sqrt(5.0));
    Circle c3(5, 0, 0);

    vector<Line> t = tangents(c2, c3);
    assert(t.size() == 2);
    assert(cmp(t[0].f(Point(5, 0)), 0) == 0);
    assert(cmp(t[1].f(Point(5, 0)), 0) == 0);
    cout << "All tests passed" << endl;
}
