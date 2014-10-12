#include "../template.h"
#include "basic.h"
#include "polygon.h"

int main() {
    cout << (fixed) << setprecision(9);
    Polygon P;
    P.push_back(Point(1, 1));
    P.push_back(Point(3, 3));
    P.push_back(Point(9, 1));
    P.push_back(Point(12, 4));
    P.push_back(Point(9, 7));
    P.push_back(Point(1, 7));

    // Basic methods
    assert(cmp(perimeter(P), 31.638263819) == 0);
    assert(cmp(area(P), 49.00) == 0);
    assert(!is_convex(P));

    // in_polygon
    //7 P5--------------P4
    //6 |                  \
    //5 |                    \
    //4 |   P7                P3
    //3 |   P1___            /
    //2 | / P6    \ ___    /
    //1 P0              P2
    //0 1 2 3 4 5 6 7 8 9 101112

    assert(in_polygon(P, Point(3, 4)));
    assert(!in_polygon(P, Point(3, 2)));

    // Polygon cutting
    //7 P5--------------P4
    //6 |               |  \
    //5 |               |    \
    //4 |               |     P3
    //3 |   P1___       |    /
    //2 | /       \ ___ |  /
    //1 P0              P2
    //0 1 2 3 4 5 6 7 8 9 101112
    // new polygon (notice the index are different now):
    //7 P4--------------P3
    //6 |               |
    //5 |               |
    //4 |               |
    //3 |   P1___       |
    //2 | /       \ ___ |
    //1 P0              P2
    //0 1 2 3 4 5 6 7 8 9

    P = polygon_cut(P, Line(P[2], P[4]));
    assert(cmp(perimeter(P), 29.152982445) == 0);
    assert(cmp(area(P), 40.00) == 0);

    // convex hull
    //7 P3--------------P2
    //6 |               |
    //5 |               |
    //4 |   P7          |
    //3 |               |
    //2 |               |
    //1 P0--------------P1
    //0 1 2 3 4 5 6 7 8 9

    P = convex_hull(P);
    assert(cmp(perimeter(P), 28.00) == 0);
    assert(cmp(area(P), 48.00) == 0);
    assert(is_convex(P));
    assert(in_convex(P, Point(3, 4)));
    assert(in_convex(P, Point(3, 2)));
    assert(!in_convex(P, Point(3, 1)));
    assert(!in_convex(P, Point(3, 0)));

    assert(in_polygon(P, Point(3, 4)));
    assert(in_polygon(P, Point(3, 2)));
    assert(!in_polygon(P, Point(3, 0)));

    P.clear();
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            for(int turn = 0; turn < 3; ++turn)
                P.push_back(Point(i, j));
    P = convex_hull(P);
    assert(P.size() == 4);
    assert(P[0] == Point(0, 0));
    assert(P[1] == Point(0, 9));
    assert(P[2] == Point(9, 9));
    assert(P[3] == Point(9, 0));

    P.clear();
    for(int i = 0; i < 10; ++i)
        P.push_back(Point(7, 7 * i));
    P = convex_hull(P);
    assert(P.size() == 2);
    assert(P[0] == Point(7, 0));
    assert(P[1] == Point(7, 63));

    P.clear();
    for(int i = 0; i < 10; ++i)
        P.push_back(Point(7, 7));
    P = convex_hull(P);
    assert(P.size() == 1);
    assert(P[0] == Point(7, 7));
    cout << "All test passed " << endl;

    return 0;
}
