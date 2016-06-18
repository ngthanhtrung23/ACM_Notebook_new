// Tested: http://codeforces.com/contest/678/standings/friends/true
// Add lines a*x + b, must be in increasing order of a
// Get y = max(a*x + b)
struct Hull {
    vector<double> x;
    vector<int> a;
    vector<int> b;

    void init() {
        x.clear();
        a.clear();
        b.clear();
    }

    void remove() {
        a.pop_back();
        b.pop_back();
        x.pop_back();
    }

    void insert(Line l) {
        if (a.empty()) {
            x.push_back(-INF);
            a.push_back(l.a);
            b.push_back(l.b);
        }
        else {
            double xNew = -INF;
            while (!a.empty()) {
                if (a.back() == l.a) {
                    b.back() = max(b.back(), l.b);
                    return;
                }
                assert(l.a > a.back());

                xNew = 1.0 * (b.back() - l.b) / (l.a - a.back());
                if (xNew < x.back()) {
                    remove();
                }
                else break;
            }

            a.push_back(l.a);
            b.push_back(l.b);
            x.push_back(xNew);
        }
    }

    int get(int x0) {
        if (a.empty()) {
            return -INF;
        }
        int i = upper_bound(x.begin(), x.end(), x0) - x.begin() - 1;
        return a[i] * x0 + b[i];
    }
};
