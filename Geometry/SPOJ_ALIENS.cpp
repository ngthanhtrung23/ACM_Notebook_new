#include "../template.h"
#include "basic.h"
#include "circle.h"
#include "smallestEnclosingCircle.h"

int main()
{
    int test, n;
    double x, y;

    cin >> test;
    while (test--) {
        cin >> n;
        vector<Point> points;
        while (n--) {
            scanf("%lf%lf", &x, &y);
            points.push_back(Point(x, y));
        }

        SmallestEnclosingCircle scc;
        Circle c = scc.getCircle(points);
        printf("%.2lf\n%.2lf %.2lf\n", c.r, c.x, c.y);
    }
}

