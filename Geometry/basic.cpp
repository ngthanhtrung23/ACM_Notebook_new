#include "../template.h"
#include "basic.h"

int main() {
    Point P1, P2, P3(0, 1);
    assert((P1 == P2) == true);
    assert((P1 == P3) == false);

    vector<Point> P;
    P.push_back(Point(2, 2));
    P.push_back(Point(4, 3));
    P.push_back(Point(2, 4));
    P.push_back(Point(6, 6));
    P.push_back(Point(2, 6));
    P.push_back(Point(6, 5));

    // sorting points demo
    sort(P.begin(), P.end());
    assert(P[0] == Point(2, 2));
    assert(P[1] == Point(2, 4));
    assert(P[2] == Point(2, 6));
    assert(P[3] == Point(4, 3));
    assert(P[4] == Point(6, 5));
    assert(P[5] == Point(6, 6));

    // rearrange the points as shown in the diagram below
    P.clear();
    P.push_back(Point(2, 2));
    P.push_back(Point(4, 3));
    P.push_back(Point(2, 4));
    P.push_back(Point(6, 6));
    P.push_back(Point(2, 6));
    P.push_back(Point(6, 5));
    P.push_back(Point(8, 6));

    /*
    // the positions of these 7 points (0-based indexing)
    6   P4      P3  P6
    5           P5
    4   P2
    3       P1
    2   P0
    1
    0 1 2 3 4 5 6 7 8
    */

    double d = (P[0] - P[5]).len();
    assert(cmp(d, 5.0) == 0);

    // Line equations
    Line l1(P[0], P[1]);
    assert(cmp(l1.a * P[0].x + l1.b * P[0].y + l1.c, 0) == 0);
    assert(cmp(l1.a * P[1].x + l1.b * P[1].y + l1.c, 0) == 0);

    Line l2(P[0], P[2]);
    assert(cmp(l2.a * P[0].x + l2.b * P[0].y + l2.c, 0) == 0);
    assert(cmp(l2.a * P[2].x + l2.b * P[0].y + l2.c, 0) == 0);

    // parallel, same, and Line intersection tests
    Line l3(P[2], P[3]);
    assert(areParallel(l1, l2) == false);
    assert(areParallel(l1, l3) == true);

    Line l4(P[2], P[4]);
    assert(areSame(l1, l2) == false);
    assert(areSame(l2, l4) == true);

    Point p12;
    bool res = areIntersect(l1, l2, p12);
    assert(res);
    assert(p12 == Point(2, 2));

    // other distances
    Point ans;
    d = distToLine(P[0], P[2], P[3], ans);
    assert(cmp(d, 1.788854382) == 0);
    assert(ans == Point(1.2, 3.6));

    closestPoint(l3, P[0], ans);
    assert(cmp(d, 1.788854382) == 0);
    assert(ans == Point(1.2, 3.6));

    d = distToLineSegment(P[0], P[2], P[3], ans);
    assert(cmp(d, 2) == 0);
    assert(ans == Point(2, 4));

    d = distToLineSegment(P[1], P[2], P[3], ans);
    assert(cmp(d, 1.788854382) == 0);
    assert(ans == Point(3.2, 4.6));

    d = distToLineSegment(P[6], P[2], P[3], ans);
    assert(cmp(d, 2) == 0);
    assert(ans == Point(6, 6));

    reflectionPoint(l4, P[1], ans);
    assert(ans == Point(0, 3));

    assert(cmp(RAD_to_DEG(angle(P[0], P[4], P[3])), 90) == 0);
    assert(cmp(RAD_to_DEG(angle(P[0], P[2], P[1])), 63.434948823) == 0);
    assert(cmp(RAD_to_DEG(angle(P[4], P[3], P[6])), 180) == 0);

    assert(ccw(P[0], P[2], P[3]) == -1);
    assert(ccw(P[0], P[3], P[2]) == 1);

    assert(ccw(P[0], P[2], P[3]) != 0);
    assert(ccw(P[0], P[2], P[4]) == 0);

    Point p(3, 7), q(11, 13), r(35, 30);
    assert(ccw(p, q, r) == -1);

    /*
    // the positions of these 6 points
     E<--  4
           3       B D<--
           2   A C
           1
    -4-3-2-1 0 1 2 3 4 5 6
          -1
          -2
    F<--   -3
    */

    // translation
    Point A(2.0, 2.0);
    Point B(4.0, 3.0);
    Point v = B - A;

    Point C(3.0, 2.0);
    Point D = C + v;
    assert(D == Point(5, 3));
    Point E = C + v * 0.5;
    assert(E == Point(4, 2.5));

    // rotation
    assert(B == Point(4, 3));
    Point F = B.rotate(DEG_to_RAD(90));
    assert(F == Point(-3, 4));
    Point G = B.rotate(DEG_to_RAD(180));
    assert(G == Point(-4, -3));

    cout << "All tests passed" << endl;

    return 0;
}
