// 2D segment tree
#include "SegTree.h"
template<
    class S,        // aggregate data type
    S (*op) (S, S), // combine aggregate data
    S (*e) (),      // empty element
    class Coord     // for x and y coordinates
> struct SegTree2D {
    using P = pair<Coord, Coord>;

    // _points must contains all add queries
    SegTree2D(const vector<P>& _points) : points(_points) {
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        n = points.size();

        // init segtrees
        coords.resize(n * 2);
        for (int i = 0; i < n; i++) {
            coords[n + i] = {{points[i].second, points[i].first}};
        }
        for (int i = n-1; i > 0; i--) {
            std::merge(coords[i*2].begin(), coords[i*2].end(),
                       coords[i*2+1].begin(), coords[i*2+1].end(),
                       std::back_inserter(coords[i]));
            coords[i].erase(unique(coords[i].begin(), coords[i].end()), coords[i].end());
        }
        for (const auto& c : coords) {
            segs.emplace_back(SegTree<S, op, e>(c.size()));
        }
    }

    // Set value(p) = val
    void set(P p, S val) {
        int i = lower_bound(points.begin(), points.end(), p) - points.begin();
        assert(i < n && points[i] == p);
        for (i += n; i; i >>= 1) {
            int j = lower_bound(coords[i].begin(), coords[i].end(), P{p.second, p.first}) - coords[i].begin();
            segs[i].set(j, val);
        }
    }

    // Get value at p
    S get(P p) const {
        return prod(p, P{p.first + 1, p.second + 1});
    }

    // Get sum of points in rectangles, given bottom-left and top-right
    // [low.x, high.x - 1] * [low.y, high.y - 1]
    S prod(P low, P high) const {
        assert(low.first <= high.first);
        assert(low.second <= high.second);
        if (low.first == high.first) return e();
        if (low.second == high.second) return e();

        int l = n + (lower_bound(points.begin(), points.end(), low, cmpFirst) - points.begin());
        int r = n + (lower_bound(points.begin(), points.end(), high, cmpFirst) - points.begin());
        S res = e();
        while (l < r) {
            if (l & 1) res = op(res, prod_1d(l++, low.second, high.second));
            if (r & 1) res = op(res, prod_1d(--r, low.second, high.second));
            l >>= 1; r >>= 1;
        }
        return res;
    }

// private:
    S prod_1d(int x, Coord l, Coord r) const {
        auto il = lower_bound(coords[x].begin(), coords[x].end(), P{l, l}, cmpFirst) - coords[x].begin();
        auto ir = lower_bound(coords[x].begin(), coords[x].end(), P{r, r}, cmpFirst) - coords[x].begin();
        return segs[x].prod(il, ir);
    }

    static bool cmpFirst(const P& u, const P& v) {
        return u.first < v.first;
    }

    int n;
    vector<P> points;

    // segtrees, outer layer by x-coordinate
    vector<vector<P>> coords;  // coords[i] stores all points maintained by i-th node in ST
    vector<SegTree<S, op, e>> segs;
};
