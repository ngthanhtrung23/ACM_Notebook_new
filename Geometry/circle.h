struct Circle : Point {
    long double r;
};
void tangents(Point c, long double r1, long double r2, vector<Line> & ans) {
    long double r = r2 - r1;
    long double z = sqr(c.x) + sqr(c.y);
    long double d = z - sqr(r);
    if (d < -EPS)  return;
    d = sqrt(fabs(d));
    Line l((c.x * r + c.y * d) / z,
            (c.y * r - c.x * d) / z,
            r1);
    ans.push_back(l);
}
vector<Line> tangents(Circle a, Circle b) {
    vector<Line> ans; ans.clear();
    for (int i=-1; i<=1; i+=2)
        for (int j=-1; j<=1; j+=2)
            tangents(b-a, a.r*i, b.r*j, ans);
    REP(i,ans.size())
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    return ans;
}
int intersection(Line l, Circle cir, Point &A, Point &B) {
    long double r, a, b, c;
    r = cir.r;
    a = l.a;
    b = l.b;
    c = l.c + l.a*cir.x + l.b*cir.y;

    long double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS) return 0;
    else if (fabs(c*c - r*r*(a*a+b*b)) < EPS) {
        A = Point(x0, y0) + Point(cir.x, cir.y);
        return 1;
    }
    else {
        long double d = r*r - c*c/(a*a+b*b);
        long double mult = sqrt (d / (a*a+b*b));
        long double ax,ay,bx,by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;

        A = Point(ax, ay) + Point(cir.x, cir.y);
        B = Point(bx, by) + Point(cir.x, cir.y);
        return 2;
    }
}
