typedef vector< Point > Polygon;

// Convex Hull: returns minimum number of vertices. Should work when N <= 1 and when all points 
// are collinear
struct comp_hull {
    Point pivot;
    bool operator() (Point q,Point w) {
        Point Q = q - pivot, W = w - pivot;
        double R = Q % W;
        if (cmp(R,0)) return R < 0;
        return cmp(Q*Q,W*W) < 0;
    }
};
Polygon convex_hull(Polygon p) { // minimum vertices
    int j = 0, k, n = p.size();
    Polygon r(n);
    if (!n) return r;
    comp_hull comp;
    comp.pivot = *min_element(p.begin(),p.end());
    sort(p.begin(),p.end(),comp);
    REP(i,n) {
        while (j > 1 && ccw(r[j-1],r[j-2],p[i]) <= 0) j--;
        r[j++] = p[i];
    }
    r.resize(j);
    return r;
}

double signed_area(Polygon p) {
    double area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}
double area(Polygon p) {
    return fabs(signed_area(p));
}
Point centroid(Polygon p) {
    Point c(0,0);
    double scale = 6.0 * signed_area(p);
    for (int i = 0; i < p.size(); i++){
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}
// Inside polygon: O(N). Works with any polygon
bool in_polygon(Point pt, const Polygon &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]) > 0)
            sum += angle(P[i], pt, P[i+1]);
        else sum -= angle(P[i], pt, P[i+1]); }
    return fabs(fabs(sum) - 2*M_PI) < EPS;
}

// Check point in convex polygon, O(logN)
// Source: http://codeforces.com/contest/166/submission/1392387
#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
;
bool in_convex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);
    if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    return Det(l[a], l[b], p) < 0;
}


// Cut a convex polygon with a line. Returns one half.
// To return the other half, reverse the direction of Line l (by negating l.a, l.b)
// The line must be formed using 2 points
Polygon convex_cut(Polygon P, Line l) {
    Polygon Q;
    REP(i,P.size()) {
        Point A = P[i], B = (i == P.size()-1) ? P[0] : P[i+1];
        if (ccw(l.A, l.B, A) != -1) Q.push_back(A);
        if (ccw(l.A, l.B, A)*ccw(l.A, l.B, B) < 0) {
            Point p; areIntersect(Line(A, B), l, p);
            Q.push_back(p);
        }
    }
    return Q;
}

// Find intersection of 2 polygons
// Helper method
bool intersect_1pt(Point a, Point b,
    Point c, Point d, Point &r) {
    double D =  (b - a) % (d - c);
    if (cmp(D, 0) == 0) return false;
    double t =  ((c - a) % (d - c)) / D;
    double s = -((a - c) % (b - a)) / D;
    r = a + (b - a) * t;
    return cmp(t, 0) > 0 && cmp(t, 1) < 0 && cmp(s, 0) > 0 && cmp(s, 1) < 0;
}
Polygon convex_intersect(Polygon P, Polygon Q) {
    const int n = P.size(), m = Q.size();
    int a = 0, b = 0, aa = 0, ba = 0;
    enum { Pin, Qin, Unknown } in = Unknown;
    Polygon R;
    do {
        int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
        double C = (P[a] - P[a1]) % (Q[b] - Q[b1]);
        double A = (P[a1] - Q[b]) % (P[a] - Q[b]);
        double B = (Q[b1] - P[a]) % (Q[b] - P[a]);
        Point r;
        if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {
            if (in == Unknown) aa = ba = 0;
            R.push_back( r );
            in = B > 0 ? Pin : A > 0 ? Qin : in;
        }
        if (C == 0 && B == 0 && A == 0) {
            if (in == Pin) { b = (b + 1) % m; ++ba; }
            else            { a = (a + 1) % m; ++aa; }
        } else if (C >= 0) {
            if (A > 0) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
            else        { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
        } else {
            if (B > 0) { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
            else        { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
        }
    } while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );
    if (in == Unknown) {
        if (in_convex(Q, P[0])) return P;
        if (in_convex(P, Q[0])) return Q;
    }
    return R;
}

// Find the diameter of polygon.
// Rotating callipers
double convex_diameter(Polygon pt) {
    const int n = pt.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; ++i) {
        if (pt[i].y > pt[is].y) is = i;
        if (pt[i].y < pt[js].y) js = i;
    }
    double maxd = (pt[is]-pt[js]).norm();
    int i, maxi, j, maxj;
    i = maxi = is;
    j = maxj = js;
    do {
        int jj = j+1; if (jj == n) jj = 0;
        if ((pt[i] - pt[jj]).norm() > (pt[i] - pt[j]).norm()) j = (j+1) % n;
        else i = (i+1) % n;
        if ((pt[i]-pt[j]).norm() > maxd) {
            maxd = (pt[i]-pt[j]).norm();
            maxi = i; maxj = j;
        }
    } while (i != is || j != js);
    return maxd; /* farthest pair is (maxi, maxj). */
}

pair<Point,Point> closestPair(vector<Point> p) {
    // Source: e-maxx.ru
    return make_pair(Point(0, 0), Point(0, 0));
}
