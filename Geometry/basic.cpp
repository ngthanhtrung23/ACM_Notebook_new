#include "../template.h"

#define EPS 1e-6

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator + (Point a) { return Point(x+a.x, y+a.y); }
    Point operator - (Point a) { return Point(x-a.x, y-a.y); }
    Point operator * (double k) { return Point(x*k, y*k); }
    Point operator / (double k) { return Point(x/k, y/k); }

    double operator * (Point a) { return x*a.x + y*a.y; } // dot product
    double operator % (Point a) { return x*a.y - y*a.x; } // cross product

    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    Point conj() { return Point(x, -y); }
    double norm() { return x*x + y*y; }

    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    double len() { return sqrt(norm()); }

    Point rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
    }
};

double angle(Point a, Point o, Point b) { // angle AOB
    a = a - o; b = b - o;
    return acos((a * b) / sqrt(a.norm() * b.norm()));
}

// Distance from p to Line ab (closest Point --> c)
double distToLine(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm();
    c = a + (ab * u);
    return (p-c).len();
}

// Distance from p to segment ab (closest Point --> c)
double distToLineSegment(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm();
    if (u < 0.0) {
        c = Point(a.x, a.y);
        return (p - a).len();
    }
    if (u > 1.0) {
        c = Point(b.x, b.y);
        return (p - b).len();
    }
    return distToLine(p, a, b, c);
}

struct Line {
    double a, b, c;
    Line(Point A, Point B) {
        if (cmp(A.x, B.x) == 0) { // vertical Line
            a = 1.0; b = 0.0; c = -A.x;
        } else {
            // Careful with integer points
            a = -(double)(A.y - B.y) / (A.x - B.x);
            b = 1.0;
            c = -(double)(a * A.x) - A.y;
        }
    }
    Line(Point P, double m) {
        a = -m; b = 1;
        c = -((a * P.x) + (b * P.y));
    }
    double f(Point A) {
        return a*A.x + b*A.y + c;
    }
};

bool areParallel(Line l1, Line l2) {
    // Works because we normalized Line so that a = 0 or b = 0
    return (cmp(l1.a, l2.a) == 0) && (cmp(l1.b, l2.b) == 0);
}

bool areSame(Line l1, Line l2) {
    // Works because we normalized Line so that a = 0 or b = 0
    return areParallel(l1 ,l2) && cmp(l1.c, l2.c) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}

void closestPoint(Line l, Point p, Point &ans) {
    if (fabs(l.b) < EPS) {
        ans.x = -(l.c); ans.y = p.y;
        return;
    }
    if (fabs(l.a) < EPS) {
        ans.x = p.x; ans.y = -(l.c);
        return;
    }
    Line perpendicular(p, 1 / l.a);
    // intersect Line l with this perpendicular Line
    // the intersection Point is the closest Point
    areIntersect(l, perpendicular, ans);
}

// returns the reflection of Point on a Line
void reflectionPoint(Line l, Point p, Point &ans) {
    Point b;
    closestPoint(l, p, b);
    Point v = b - p;
    ans = p + (b - p) * 2;
}

struct Polygon {
    vector<Point> p;
};

int ccw(Point a, Point b, Point c) {
    return cmp((b-a)%(c-a),0);
}

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
    assert(cmp(l1.a, -0.5) == 0);
    assert(cmp(l1.b, 1) == 0);
    assert(cmp(l1.c, -1) == 0);

    Line l2(P[0], P[2]);
    assert(cmp(l2.a, 1) == 0);
    assert(cmp(l2.b, 0) == 0);
    assert(cmp(l2.c, -2) == 0);

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

    return 0;
}
