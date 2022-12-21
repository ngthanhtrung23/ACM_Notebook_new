---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':x:'
    path: DataStructure/SegTree2D.h
    title: DataStructure/SegTree2D.h
  - icon: ':question:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"buffered_reader.h\"\
    \n// Buffered reader {{{\nnamespace IO {\n    const int BUFSIZE = 1<<14;\n   \
    \ char buf[BUFSIZE + 1], *inp = buf;\n\n    bool reacheof;\n    char get_char()\
    \ {\n        if (!*inp && !reacheof) {\n            memset(buf, 0, sizeof buf);\n\
    \            int tmp = fread(buf, 1, BUFSIZE, stdin);\n            if (tmp !=\
    \ BUFSIZE) reacheof = true;\n            inp = buf;\n        }\n        return\
    \ *inp++;\n    }\n    template<typename T>\n    T get() {\n        int neg = 0;\n\
    \        T res = 0;\n        char c = get_char();\n        while (!std::isdigit(c)\
    \ && c != '-' && c != '+') c = get_char();\n        if (c == '+') { neg = 0; }\n\
    \        else if (c == '-') { neg = 1; }\n        else res = c - '0';\n\n    \
    \    c = get_char();\n        while (std::isdigit(c)) {\n            res = res\
    \ * 10 + (c - '0');\n            c = get_char();\n        }\n        return neg\
    \ ? -res : res;\n    }\n};\n// Helper methods\nint ri() {\n    return IO::get<int>();\n\
    }\n// }}}\n#line 1 \"DataStructure/SegTree2D.h\"\n// 2D segment tree\n#line 1\
    \ \"DataStructure/SegTree.h\"\n// SegTree, copied from AtCoder library {{{\n//\
    \ AtCoder doc: https://atcoder.github.io/ac-library/master/document_en/segtree.html\n\
    //\n// Notes:\n// - Index of elements from 0 -> n-1\n// - Range queries are [l,\
    \ r-1]\n//\n// Tested:\n// - (binary search) https://atcoder.jp/contests/practice2/tasks/practice2_j\n\
    // - https://oj.vnoi.info/problem/gss\n// - https://oj.vnoi.info/problem/nklineup\n\
    // - (max_right & min_left for delete position queries) https://oj.vnoi.info/problem/segtree_itstr\n\
    // - https://judge.yosupo.jp/problem/point_add_range_sum\n// - https://judge.yosupo.jp/problem/point_set_range_composite\n\
    int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\ntemplate<\n    class T,  // data type for nodes\n\
    \    T (*op) (T, T),  // operator to combine 2 nodes\n    T (*e)() // identity\
    \ element\n>\nstruct SegTree {\n    SegTree() : SegTree(0) {}\n    explicit SegTree(int\
    \ n) : SegTree(vector<T> (n, e())) {}\n    explicit SegTree(const vector<T>& v)\
    \ : _n((int) v.size()) {\n        log = ceil_pow2(_n);\n        size = 1<<log;\n\
    \        d = vector<T> (2*size, e());\n\n        for (int i = 0; i < _n; i++)\
    \ d[size+i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n         \
    \   update(i);\n        }\n    }\n\n    // 0 <= p < n\n    void set(int p, T x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    // 0 <=\
    \ p < n\n    T get(int p) const {\n        assert(0 <= p && p < _n);\n       \
    \ return d[p + size];\n    }\n\n    // Get product in range [l, r-1]\n    // 0\
    \ <= l <= r <= n\n    // For empty segment (l == r) -> return e()\n    T prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n        T sml\
    \ = e(), smr = e();\n        l += size;\n        r += size;\n        while (l\
    \ < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1)\
    \ smr = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n       \
    \ }\n        return op(sml, smr);\n    }\n\n    T all_prod() const {\n       \
    \ return d[1];\n    }\n\n    // Binary search on SegTree to find largest r:\n\
    \    //    f(op(a[l] .. a[r-1])) = true   (assuming empty array is always true)\n\
    \    //    f(op(a[l] .. a[r])) = false    (assuming op(..., a[n]), which is out\
    \ of bound, is always false)\n    template <bool (*f)(T)> int max_right(int l)\
    \ const {\n        return max_right(l, [](T x) { return f(x); });\n    }\n   \
    \ template <class F> int max_right(int l, F f) const {\n        assert(0 <= l\
    \ && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n   \
    \     l += size;\n        T sm = e();\n        do {\n            while (l % 2\
    \ == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while (l\
    \ < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    // Binary search\
    \ on SegTree to find smallest l:\n    //    f(op(a[l] .. a[r-1])) = true     \
    \ (assuming empty array is always true)\n    //    f(op(a[l-1] .. a[r-1])) = false\
    \   (assuming op(a[-1], ..), which is out of bound, is always false)\n    template\
    \ <bool (*f)(T)> int min_left(int r) const {\n        return min_left(r, [](T\
    \ x) { return f(x); });\n    }\n    template <class F> int min_left(int r, F f)\
    \ const {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n     \
    \   if (r == 0) return 0;\n        r += size;\n        T sm = e();\n        do\
    \ {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n       \
    \     if (!f(op(d[r], sm))) {\n                while (r < size) {\n          \
    \          r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n    \
    \                    sm = op(d[r], sm);\n                        r--;\n      \
    \              }\n                }\n                return r + 1 - size;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    vector<T> d;\n\
    \n    void update(int k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n};\n\
    // }}}\n\n// SegTree examples {{{\n// Examples: Commonly used SegTree ops: max\
    \ / min / sum\nstruct MaxSegTreeOp {\n    static int op(int x, int y) {\n    \
    \    return max(x, y);\n    }\n    static int e() {\n        return INT_MIN;\n\
    \    }\n};\n\nstruct MinSegTreeOp {\n    static int op(int x, int y) {\n     \
    \   return min(x, y);\n    }\n    static int e() {\n        return INT_MAX;\n\
    \    }\n};\n\nstruct SumSegTreeOp {\n    static long long op(long long x, long\
    \ long y) {\n        return x + y;\n    }\n    static long long e() {\n      \
    \  return 0;\n    }\n};\n\nusing STMax = SegTree<int, MaxSegTreeOp::op, MaxSegTreeOp::e>;\n\
    using STMin = SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e>;\nusing STSum =\
    \ SegTree<int, SumSegTreeOp::op, SumSegTreeOp::e>;\n// }}}\n#line 3 \"DataStructure/SegTree2D.h\"\
    \ntemplate<\n    class S,        // aggregate data type\n    S (*op) (S, S), //\
    \ combine aggregate data\n    S (*e) (),      // empty element\n    class Coord\
    \     // for x and y coordinates\n> struct SegTree2D {\n    using P = pair<Coord,\
    \ Coord>;\n\n    // _points must contains all add queries\n    SegTree2D(const\
    \ vector<P>& _points) : points(_points) {\n        sort(points.begin(), points.end());\n\
    \        points.erase(unique(points.begin(), points.end()), points.end());\n \
    \       n = points.size();\n\n        // init segtrees\n        coords.resize(n\
    \ * 2);\n        for (int i = 0; i < n; i++) {\n            coords[n + i] = {{points[i].second,\
    \ points[i].first}};\n        }\n        for (int i = n-1; i > 0; i--) {\n   \
    \         std::merge(coords[i*2].begin(), coords[i*2].end(),\n               \
    \        coords[i*2+1].begin(), coords[i*2+1].end(),\n                       std::back_inserter(coords[i]));\n\
    \            coords[i].erase(unique(coords[i].begin(), coords[i].end()), coords[i].end());\n\
    \        }\n        for (const auto& c : coords) {\n            segs.emplace_back(SegTree<S,\
    \ op, e>(c.size()));\n        }\n    }\n\n    // Set value(p) = val\n    void\
    \ set(P p, S val) {\n        int i = lower_bound(points.begin(), points.end(),\
    \ p) - points.begin();\n        assert(i < n && points[i] == p);\n        for\
    \ (i += n; i; i >>= 1) {\n            int j = lower_bound(coords[i].begin(), coords[i].end(),\
    \ P{p.second, p.first}) - coords[i].begin();\n            segs[i].set(j, val);\n\
    \        }\n    }\n\n    // Get value at p\n    S get(P p) const {\n        return\
    \ prod(p, P{p.first + 1, p.second + 1});\n    }\n\n    // Get sum of points in\
    \ rectangles, given bottom-left and top-right\n    // [low.x, high.x - 1] * [low.y,\
    \ high.y - 1]\n    S prod(P low, P high) const {\n        assert(low.first <=\
    \ high.first);\n        assert(low.second <= high.second);\n        if (low.first\
    \ == high.first) return e();\n        if (low.second == high.second) return e();\n\
    \n        int l = n + (lower_bound(points.begin(), points.end(), low, cmpFirst)\
    \ - points.begin());\n        int r = n + (lower_bound(points.begin(), points.end(),\
    \ high, cmpFirst) - points.begin());\n        S res = e();\n        while (l <\
    \ r) {\n            if (l & 1) res = op(res, prod_1d(l++, low.second, high.second));\n\
    \            if (r & 1) res = op(res, prod_1d(--r, low.second, high.second));\n\
    \            l >>= 1; r >>= 1;\n        }\n        return res;\n    }\n\n// private:\n\
    \    S prod_1d(int x, Coord l, Coord r) const {\n        auto il = lower_bound(coords[x].begin(),\
    \ coords[x].end(), P{l, l}, cmpFirst) - coords[x].begin();\n        auto ir =\
    \ lower_bound(coords[x].begin(), coords[x].end(), P{r, r}, cmpFirst) - coords[x].begin();\n\
    \        return segs[x].prod(il, ir);\n    }\n\n    static bool cmpFirst(const\
    \ P& u, const P& v) {\n        return u.first < v.first;\n    }\n\n    int n;\n\
    \    vector<P> points;\n\n    // segtrees, outer layer by x-coordinate\n    vector<vector<P>>\
    \ coords;  // coords[i] stores all points maintained by i-th node in ST\n    vector<SegTree<S,\
    \ op, e>> segs;\n};\n#line 8 \"DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\ntemplate<typename\
    \ T>\nstruct Query {\n    static const int ADD = 0;\n    static const int QUERY\
    \ = 1;\n\n    int typ;  // ADD or QUERY\n    int x, y;\n    int x2, y2;  // for\
    \ QUERY: [x1, x2-1] * [y1, y2-1]\n\n    T weight;\n};\n\nint32_t main() {\n  \
    \  ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n    int\
    \ q = IO::get<int>();\n\n    using ll = long long;\n    vector<Query<ll>> queries;\n\
    \    REP(i,n) {\n        int x = IO::get<int>();\n        int y = IO::get<int>();\n\
    \        ll val = IO::get<ll>();\n        queries.push_back({Query<ll>::ADD, x,\
    \ y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int typ = IO::get<int>();\n\
    \        if (typ == 0) {\n            int x = IO::get<int>();\n            int\
    \ y = IO::get<int>();\n            ll val = IO::get<ll>();\n            queries.push_back({Query<ll>::ADD,\
    \ x, y, -1, -1, val});\n        } else {\n            int x = IO::get<int>();\n\
    \            int y = IO::get<int>();\n            int x2 = IO::get<int>();\n \
    \           int y2 = IO::get<int>();\n            queries.push_back({Query<ll>::QUERY,\
    \ x, y, x2, y2, 0});\n        }\n    }\n\n    using P = pair<int,int>;\n    vector<P>\
    \ points;\n    for (auto query : queries) {\n        if (query.typ == Query<ll>::ADD)\
    \ {\n            points.push_back({query.x, query.y});\n        }\n    }\n\n \
    \   SegTree2D<ll, SumSegTreeOp::op, SumSegTreeOp::e, int> st(points);\n    for\
    \ (auto query : queries) {\n        if (query.typ == Query<ll>::ADD) {\n     \
    \       P p{query.x, query.y};\n            st.set(p, st.get(p) + query.weight);\n\
    \        } else {\n            cout << st.prod(P{query.x, query.y}, P{query.x2,\
    \ query.y2}) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../buffered_reader.h\"\
    \n#include \"../SegTree2D.h\"\n\n#define REP(i, a) for (int i = 0, _##i = (a);\
    \ i < _##i; ++i)\n\ntemplate<typename T>\nstruct Query {\n    static const int\
    \ ADD = 0;\n    static const int QUERY = 1;\n\n    int typ;  // ADD or QUERY\n\
    \    int x, y;\n    int x2, y2;  // for QUERY: [x1, x2-1] * [y1, y2-1]\n\n   \
    \ T weight;\n};\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get<int>();\n    int q = IO::get<int>();\n\n    using ll = long\
    \ long;\n    vector<Query<ll>> queries;\n    REP(i,n) {\n        int x = IO::get<int>();\n\
    \        int y = IO::get<int>();\n        ll val = IO::get<ll>();\n        queries.push_back({Query<ll>::ADD,\
    \ x, y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int typ = IO::get<int>();\n\
    \        if (typ == 0) {\n            int x = IO::get<int>();\n            int\
    \ y = IO::get<int>();\n            ll val = IO::get<ll>();\n            queries.push_back({Query<ll>::ADD,\
    \ x, y, -1, -1, val});\n        } else {\n            int x = IO::get<int>();\n\
    \            int y = IO::get<int>();\n            int x2 = IO::get<int>();\n \
    \           int y2 = IO::get<int>();\n            queries.push_back({Query<ll>::QUERY,\
    \ x, y, x2, y2, 0});\n        }\n    }\n\n    using P = pair<int,int>;\n    vector<P>\
    \ points;\n    for (auto query : queries) {\n        if (query.typ == Query<ll>::ADD)\
    \ {\n            points.push_back({query.x, query.y});\n        }\n    }\n\n \
    \   SegTree2D<ll, SumSegTreeOp::op, SumSegTreeOp::e, int> st(points);\n    for\
    \ (auto query : queries) {\n        if (query.typ == Query<ll>::ADD) {\n     \
    \       P p{query.x, query.y};\n            st.set(p, st.get(p) + query.weight);\n\
    \        } else {\n            cout << st.prod(P{query.x, query.y}, P{query.x2,\
    \ query.y2}) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - buffered_reader.h
  - DataStructure/SegTree2D.h
  - DataStructure/SegTree.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 12:35:38+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
- /verify/DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp.html
title: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
---
