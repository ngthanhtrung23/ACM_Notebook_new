// Quay điểm P quanh trục vector đơn vị (x,y,z) 1 góc a
// [ txx + c  | txy – sz | txz + sy ]
// [ txy + sz | tyy + c  | tyz – sx ]
// [ txz - sy | tyz + sx | tzz + c  ]
// Với: c = cos(a)      s = sin(a)      t = 1 – cos(a)

const double EPS = 1e-6;

inline double det(double a, double b, double c, double d) {
    return a * d - b * c;
}
struct Point {
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    double length() {
        return sqrt(x * x + y * y + z * z);
    }
    double operator * (Point a) const { return x*a.x + y*a.y + z*a.z; }
    Point operator + (Point a) { return Point(x+a.x, y+a.y, z+a.z); }
    Point operator - (Point a) { return Point(x-a.x, y-a.y, z-a.z); }
    Point operator %(const Point &op) const {
        return Point(det(y, z, op.y, op.z), -det(x, z, op.x, op.z), det(x, y,
                op.x, op.y));
    }
};
struct Space {
    double a, b, c, d;
    Space(Point p0, Point p1, Point p2) {
        a = p0.y * (p1.z - p2.z) + p1.y * (p2.z - p0.z) + p2.y * (p0.z - p1.z);
        b = p0.z * (p1.x - p2.x) + p1.z * (p2.x - p0.x) + p2.z * (p0.x - p1.x);
        c = p0.x * (p1.y - p2.y) + p1.x * (p2.y - p0.y) + p2.x * (p0.y - p1.y);
        d = -p0.x * (p1.y * p2.z - p2.y * p1.z) - p1.x * (p2.y * p0.z - p0.y * p2.z) 
- p2.x * (p0.y * p1.z - p1.y * p0.z);
    }
};
Point projection(Point v, Point u) { // Chiếu vector v lên vector u
    double scalar = (v * u) / (u * u);
    return u * scalar;
}
Point projection(Point p, Point a, Point b, Point c) { // Chiếu điểm p lên mặt phẳng ABC
    Point u = (b - a) % (c - a), v = p - a;
    double scalar = (v * u) / (u * u);
    return p - (u * scalar);
}
double dist(Point p, Point a, Point b) { // Khoảng cách từ p tới đường thẳng AB
    p = p - a;
    Point proj = projection(p, b - a);
    return sqrt(p * p - proj * proj);
}
double area(Point a, Point b, Point c) { // Diện tích tam giác ABC
    double h = dist(a, b, c);
    return (h * (b - c).length()) / 2;
}
double volume(Point x, Point y, Point z) { // Thể tích của 3 vector 
    Point base = Point(y.y * z.z - y.z * z.y, y.z * z.x - y.x * z.z, y.x * z.y
            - y.y * z.x);
    return fabs(x.x * base.x + x.y * base.y + x.z * base.z) / 3;
}

// V - E + F = 2  |  E <= 3V – 6  |  F <= 2V - 4


// 3d convex hull
inline int sign(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
vector<Point> arr;
vector<int> rnd;
set<int> used;

typedef vector<int> Side;
Side getFirstSide(vector<Point> &p) {
    int i1 = 0;
    REP(i,p.size()) {
        if (p[i].z < p[i1].z || (p[i].z == p[i1].z && p[i].x < p[i1].x)
                || (p[i].z == p[i1].z && p[i].x == p[i1].x && p[i].y < p[i1].y)) {
            i1 = i;
        }
    }
    int i2 = i1 == 0 ? 1 : 0;
    REP(i,p.size()) {
        if (i != i1) {
            Point zDir(0, 0, 1);
            double curCos = (p[i] - p[i1]) * zDir / (p[i] - p[i1]).length();
            double bestCos = (p[i2] - p[i1]) * zDir / (p[i2] - p[i1]).length();
            if (curCos < bestCos) {
                i2 = i;
            }
        }
    }
    int i3 = -1;
    int n = p.size();
    REP(ri,n) {
        int i = rnd[ri];
        if (i != i1 && i != i2) {
            Point norm = (p[i1] - p[i]) % (p[i2] - p[i]);
            bool sg[] = { 0, 0, 0 };
            REP(t,n) {
                int j = rnd[t];
                sg[1 + sign((p[j] - p[i]) * norm)] = true;
                if (sg[0] && sg[2]) {
                    break;
                }
            }
            if (sg[0] ^ sg[2]) {
                i3 = i;
                if (!sg[0]) {
                    swap(i3, i2);
                }
                break;
            }
        }
    }
    vector<int> res;
    res.push_back(i1);
    res.push_back(i2);
    res.push_back(i3);
    return res;
}

inline int getSideKey(int i, int j, int k) {
    int key = (i * 1000 + j) * 1000 + k;
    return key;
}
inline bool isUsed(int i, int j, int k) {
    return used.find(getSideKey(i, j, k)) != used.end();
}

inline double getAngle(const Point &n1, const Point &n2) {
    return atan2((n1 % n2).length(), n1 * n2);
}

inline double getNormsAngle(int i, int j, int k, int t, vector<Point> &p) {
    Point n1 = (p[j] - p[i]) % (p[k] - p[i]);
    Point n2 = (p[t] - p[i]) % (p[j] - p[i]);
    return getAngle(n1, n2);
}

void dfs(int i, int j, int k, vector<Point> &p, vector<Side> &sides) {
    if (i < j && i < k) {
        vector<int> side(3);
        side[0] = i;
        side[1] = j;
        side[2] = k;
        sides.push_back(side);
    }
    int key = getSideKey(i, j, k);
    used.insert(key);
    int n = p.size();
    if (!isUsed(j, k, i))
        dfs(j, k, i, p, sides);
    if (!isUsed(k, i, j))
        dfs(k, i, j, p, sides);

    int bestT = -1;
    double bestAngle = 1e20;
    Point curNorm = (p[j] - p[i]) % (p[k] - p[i]);
    Point dir = p[j] - p[i];
    REP(t,n) {
        if (t != i && t != j && t != k) {
            Point newNorm = (p[t] - p[i]) % dir;
            double curAng = curNorm * newNorm / newNorm.length();
            if (bestT == -1 || curAng > bestAngle) {
                bestT = t;
                bestAngle = curAng;
            }
        }
    }
    if (!isUsed(i, bestT, j)) {
        dfs(i, bestT, j, p, sides);
    }
}
vector<Side> convexHull3d(vector<Point> p) {
    used.clear();
    rnd.resize(p.size());
    REP(i,p.size())
        rnd[i] = i;
    random_shuffle(rnd.begin(), rnd.end());
    Side side0 = getFirstSide(p);
    vector<Side> sides;

    dfs(side0[0], side0[1], side0[2], p, sides);
    return sides;
}

/* eliminate conflict sides */
inline bool isEmpty(Point x, Point y, Point z) {
    return abs(x * Point(y.y * z.z - y.z * z.y, y.z * z.x - y.x * z.z, y.x
            * z.y - y.y * z.x)) <= EPS;
}
inline bool conflict(Side a, Side b) {
    Point x = arr[a[0]], y = arr[a[1]], z = arr[a[2]];
    REP(i,3) {
        Point t = arr[b[i]];
        if (!isEmpty(x - t, y - t, z - t))
            return false;
    }
    return true;
}
vector<Side> eliminate(vector<Side> p) {
    vector<Side> res;
    vector<bool> fre;
    fre.resize(p.size(), true);
    REP(i,p.size()) {
        if (!fre[i])
            continue;
        res.push_back(p[i]);
        FOR(j,i+1,p.size() - 1)
            if (fre[j]) {
                if (conflict(p[i], p[j])) {
                    fre[j] = false;
                    res.back().insert(res.back().end(), p[j].begin(),
                            p[j].end());
                }
            }
    }
    REP(i,res.size()) {
        sort(res[i].begin(), res[i].end());
        res[i].resize(unique(res[i].begin(), res[i].end()) - res[i].begin());
    }
    return res;
}
// End of 3d convex hull
