// Smallest enclosing circle:
// Given N points. Find the smallest circle enclosing these points.
// Complexity: O(N)
// 0 points --> NULL
// 1 points --> circle with radius 0

struct SmallestClosingCircle {
    Circle *makeCircle(vector<Point> points) {
        random_shuffle(points.begin(),points.end());
        Circle *c = NULL;
        for (int i = 0; i < points.size(); i++) {
            Point p = points[i];
            if (c == NULL || !c->contains(p))
                c = makeCircleOnePoint(points,0,i, p);
        }
        return c;
    }

    Circle *makeCircleOnePoint(vector<Point> &points, int fromIdx, int toIdx, Point p) {
        Circle *c = new Circle(p.x, p.y, 0);
        for (int i = fromIdx; i < toIdx; i++) {
            Point q = points[i];
            if (!c->contains(q)) {
                if (fabs(c->r) < EPS) c = makeDiameter(p, q);
                else c = makeCircleTwoPoints(points,0,i, p, q);
            }
        }
        return c;
    }

    // Two boundary points known
    Circle *makeCircleTwoPoints(vector<Point> &points, int fromIdx, int toIdx, Point p, Point q) {
        Circle *temp = makeDiameter(p, q);
        bool ContainsAll=1;
        for(int i = fromIdx; i < toIdx; ++i) if(!temp->contains(points[i])){
            ContainsAll = 0;
            break;
        }
        if (ContainsAll) return temp;

        Circle *left = NULL;
        Circle *right = NULL;
        for (int i = fromIdx; i < toIdx; ++i) {
            Point r = points[i];
            Point pq = q - p;
            double cross = pq % (r - p);
            Circle *c = makeCircumcircle(p, q, r);
            if (c == NULL)
                continue;
            else if (cross > 0 && (left == NULL || pq % (*c - p) > pq % (*left - p)))
                left = c;
            else if (cross < 0 && (right == NULL || pq % (*c - p) < pq % (*right - p)))
                right = c;
        }
        return (right == NULL || left != NULL) && left->r <= right->r ? left : right;
    }

    Circle *makeDiameter(Point a, Point b) {
        return new Circle((a + b) * 0.5, (a - b).len());
    }

    Circle *makeCircumcircle(Point a, Point b, Point c) {
        double d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2;
        if (d == 0)    return NULL;
        double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
        double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
        Point p = Point(x, y);
        return new Circle(p, (p - a).len());
    }

} smallestClosingCircle;
