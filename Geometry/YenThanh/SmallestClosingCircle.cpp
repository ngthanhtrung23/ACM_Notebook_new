//======================================================
//SMALLEST CLOSING CIRCLE - by T7
//======================================================

struct Point {
	double x,y;
	Point(){}
	Point(double a, double b) {
		x=a; y=b;
	}
	Point subtract(Point p) {
		return Point(x - p.x, y - p.y);
	}
	double distance(Point p) {
		return hypot(x - p.x, y - p.y);
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	double norm() {
		return x * x + y * y;
	}
};

struct Circle {
	Point c;
	double r;
    Circle(){}
	Circle(Point a, double b) {
		c=a; r=b;
	}
	bool contains(Point p) {
		return c.distance(p) <= r + 1e-9;
	}
};



struct SmallestClosingCircle{
	/*
	 * Returns the smallest circle that encloses all the given points. Runs in expected O(n) time, randomized.
	 * Note: If 0 points are given, null is returned. If 1 point is given, a circle of radius 0 is returned.
	 */
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
		Circle *c = new Circle(p, 0);
		for (int i = fromIdx; i < toIdx; i++) {
			Point q = points[i];
			if (!c->contains(q)) {
				if (c->r == 0)
					c = makeDiameter(p, q);
				else
					c = makeCircleTwoPoints(points,0,i, p, q);
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
			Point pq = q.subtract(p);
			double cross = pq.cross(r.subtract(p));
			Circle *c = makeCircumcircle(p, q, r);
			if (c == NULL)
				continue;
			else if (cross > 0 && (left == NULL || pq.cross(c->c.subtract(p)) > pq.cross(left->c.subtract(p))))
				left = c;
			else if (cross < 0 && (right == NULL || pq.cross(c->c.subtract(p)) < pq.cross(right->c.subtract(p))))
				right = c;
		}
		return right == NULL || (left != NULL && left->r) <= right->r ? left : right;
	}

	Circle *makeDiameter(Point a, Point b) {
		return new Circle(Point((a.x + b.x)/ 2, (a.y + b.y) / 2), a.distance(b) / 2);
	}

	Circle *makeCircumcircle(Point a, Point b, Point c) {
		double d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2;
		if (d == 0)	return NULL;
		double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
		double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
		Point p = Point(x, y);
		return new Circle(p, p.distance(a));
	}

} smallestClosingCircle;

//======================================================
