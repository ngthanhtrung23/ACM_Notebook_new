#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-6;

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

typedef vector<Point> Polygon;

inline int iabs(int x) { if (x < 0) return -x; else return x; }

#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
bool in_convex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);
    if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
    while(iabs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    return Det(l[a], l[b], p) < 0;
}

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

