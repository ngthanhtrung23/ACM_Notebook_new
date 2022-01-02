// LiChao SegTree
// Copied from https://judge.yosupo.jp/submission/60250
//
// Tested:
// - https://judge.yosupo.jp/problem/segment_add_get_min
// - https://judge.yosupo.jp/problem/line_add_get_min
// - (convex hull trick) https://oj.vnoi.info/problem/vmpizza
// - https://oj.vnoi.info/problem/vomario
template<
  typename T,  // for segment & coordinates data types, e.g. long long
  typename TM  // for intermediate computations, e.g. __int128_t
> struct LiChao {
    LiChao(const vector<T>& _xs) : xs(_xs) {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        n = xs.size();
        head = 1;
        while (head < n) head <<= 1;

        lines.assign(head * 2, {0, 0, -1, false});
        xyz.resize(head * 2);
        for (int i = 0; i < n; i++) {
            xyz[head + i] = {xs[i], xs[i], xs[i]};
        }
        for (int i = head - 1; i; i--) {
            int l = i*2, r = i*2 + 1;
            xyz[i] = {
                std::get<0>(xyz[l]),
                std::get<0>(xyz[r]),
                std::get<2>(xyz[r]),
            };
        }
    }

    void add_line(T a, T b, int idx = -1) {
        ql = 0, qr = n;
        if (ql >= qr) return;
        rec(1, 0, head, Line{a, b, idx, true});
    }

    void add_segment(T left, T right, T a, T b, int idx = -1) {
        ql = std::lower_bound(xs.begin(), xs.end(), left) - xs.begin();
        qr = std::lower_bound(xs.begin(), xs.end(), right) - xs.begin();
        if (ql >= qr) return;
        rec(1, 0, head, Line{a, b, idx, true});
    }

    struct Result {
        T line_a, line_b;
        int line_id;
        bool is_valid;  // if false -> result is INFINITY
        TM minval;
    };

    Result get(T x) {
        int i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        assert(i < n && xs[i] == x);
        return get(i, x);
    }

// private:
    int n, head;
    vector<T> xs;  // coordinates of all get queries

    struct Line {
        T a, b;  // a*x + b
        int id;
        bool is_valid;
        TM f(T x) const { return TM(a) * x + b; }
    };
    vector<Line> lines;

    vector<tuple<T, T, T>> xyz;  // <left, mid, right>

    int ql, qr;
    void rec(int i, int l, int r, Line new_line) {
        const int mid = (l + r) / 2;

        if (l >= qr || r <= ql) {
            return;
        } else if (ql <= l && r <= qr) {
            if (!lines[i].is_valid) {
                lines[i] = new_line;
                return;
            }

            auto [x, y, z] = xyz[i];
            bool upd_x = lines[i].f(x) > new_line.f(x);
            bool upd_y = lines[i].f(y) > new_line.f(y);
            bool upd_z = lines[i].f(z) > new_line.f(z);

            if (upd_x && upd_y && upd_z) {
                lines[i] = new_line;
                return;
            }
            if (upd_y && upd_z) {
                std::swap(lines[i], new_line);
                rec(i*2, l, mid, new_line);
            } else if (upd_x && upd_y) {
                std::swap(lines[i], new_line);
                rec(i*2 + 1, mid, r, new_line);
            } else if (upd_x) {
                rec(i*2, l, mid, new_line);
            } else if (upd_z) {
                rec(i*2+1, mid, r, new_line);
            } else {
                return;
            }
        } else {
            if (ql < mid) rec(i*2, l, mid, new_line);
            if (qr > mid) rec(i*2+1, mid, r, new_line);
        }
    }

    Result get(int i, T x) {
        i += head;
        Line res = lines[i];
        TM val = res.is_valid ? res.f(x) : 0;
        for (i /= 2; i; i /= 2) {
            if (!lines[i].is_valid) continue;
            TM tmp = lines[i].f(x);
            if (!res.is_valid || tmp < val) res = lines[i], val = tmp;
        }
        return {res.a, res.b, res.id, res.is_valid, val};
    }
};
