// Given a polygon a[i]. Check if it is simple (does not self-intersect)
// - If a vertex appear >= 2 times --> not simple
// - l[i] = Line(a[i], a[i+1])
double get (int i, double cx) { // get y-coordinate of segment a[i] - a[i+1]
    if (a[i].x == a[i + 1].x) return (a[i].y + a[i + 1].y) / 2.0;
    return a[i].y + (a[i + 1].y - a[i].y) / (a[i + 1].x - a[i].x + 0.0) * (cx - a[i].x);
}
struct comp { // compare 2 points
    bool operator() (const int& i, const int& j) const {
        double x1 = max (min (a[i].x, a[i + 1].x), min (a[j].x, a[j + 1].x));
        double x2 = min (max (a[i].x, a[i + 1].x), max (a[j].x, a[j + 1].x));
        double cx = (x1 + x2) / 2;
        double a = get (i, cx);
        double b = get (j, cx);
        return a < b - 1e-6 || (abs (a - b) < 1e-6 && i < j);
    }   
};
bool is_simple() {
	vector< pair< pair<ll,int>, int > > events;
	FOR(i,1,n) {
		ll l = min(a[i].x, a[i+1].x);
		ll r = max(a[i].x, a[i+1].x);
		events.push_back(make_pair(make_pair(l, 0), i));
		events.push_back(make_pair(make_pair(r, 1), i));
	}
	sort(events.begin(), events.end());

	memset(mark, 0, sizeof mark);
	set<int, comp> all;
	for(auto p : events) {
		int id = p.second;
		if (!mark[id]) all.insert(id);

		auto it = all.find(id);
		auto prev = it;
		if (prev != all.begin()) {
			prev--;
			if (areIntersect(l[id], l[*prev]))  // l[i] = segment a[i] - a[i+1]
				return false; // not simple polygon
		}
		auto next = it; ++next;
		if (next != all.end()) {
			if (areIntersect(l[id], l[*next]))
				return false;
			if (cntIntersect(l[*prev], l[*next]))
				return false;
		}
		if (mark[id]) all.erase(id);
		mark[id] = !mark[id];
	}
	return true;
}
