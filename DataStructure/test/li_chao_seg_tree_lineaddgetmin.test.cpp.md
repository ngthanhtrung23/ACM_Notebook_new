---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LiChaoSegTree.h
    title: DataStructure/LiChaoSegTree.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/LiChaoSegTree.h\"\
    \n// LiChao SegTree\n// Copied from https://judge.yosupo.jp/submission/60250\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/segment_add_get_min\n// -\
    \ https://judge.yosupo.jp/problem/line_add_get_min\n// - (convex hull trick) https://oj.vnoi.info/problem/vmpizza\n\
    // - https://oj.vnoi.info/problem/vomario\ntemplate<\n  typename T,  // for segment\
    \ & coordinates data types, e.g. long long\n  typename TM  // for intermediate\
    \ computations, e.g. __int128_t\n> struct LiChao {\n    LiChao(const vector<T>&\
    \ _xs) : xs(_xs) {\n        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        n = xs.size();\n        head = 1;\n       \
    \ while (head < n) head <<= 1;\n\n        lines.assign(head * 2, {0, 0, -1, false});\n\
    \        xyz.resize(head * 2);\n        for (int i = 0; i < n; i++) {\n      \
    \      xyz[head + i] = {xs[i], xs[i], xs[i]};\n        }\n        for (int i =\
    \ head - 1; i; i--) {\n            int l = i*2, r = i*2 + 1;\n            xyz[i]\
    \ = {\n                std::get<0>(xyz[l]),\n                std::get<0>(xyz[r]),\n\
    \                std::get<2>(xyz[r]),\n            };\n        }\n    }\n\n  \
    \  void add_line(T a, T b, int idx = -1) {\n        ql = 0, qr = n;\n        if\
    \ (ql >= qr) return;\n        rec(1, 0, head, Line{a, b, idx, true});\n    }\n\
    \n    void add_segment(T left, T right, T a, T b, int idx = -1) {\n        ql\
    \ = std::lower_bound(xs.begin(), xs.end(), left) - xs.begin();\n        qr = std::lower_bound(xs.begin(),\
    \ xs.end(), right) - xs.begin();\n        if (ql >= qr) return;\n        rec(1,\
    \ 0, head, Line{a, b, idx, true});\n    }\n\n    struct Result {\n        T line_a,\
    \ line_b;\n        int line_id;\n        bool is_valid;  // if false -> result\
    \ is INFINITY\n        TM minval;\n    };\n\n    Result get(T x) {\n        int\
    \ i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n        assert(i\
    \ < n && xs[i] == x);\n        return get(i, x);\n    }\n\n// private:\n    int\
    \ n, head;\n    vector<T> xs;  // coordinates of all get queries\n\n    struct\
    \ Line {\n        T a, b;  // a*x + b\n        int id;\n        bool is_valid;\n\
    \        TM f(T x) const { return TM(a) * x + b; }\n    };\n    vector<Line> lines;\n\
    \n    vector<tuple<T, T, T>> xyz;  // <left, mid, right>\n\n    int ql, qr;\n\
    \    void rec(int i, int l, int r, Line new_line) {\n        const int mid = (l\
    \ + r) / 2;\n\n        if (l >= qr || r <= ql) {\n            return;\n      \
    \  } else if (ql <= l && r <= qr) {\n            if (!lines[i].is_valid) {\n \
    \               lines[i] = new_line;\n                return;\n            }\n\
    \n            auto [x, y, z] = xyz[i];\n            bool upd_x = lines[i].f(x)\
    \ > new_line.f(x);\n            bool upd_y = lines[i].f(y) > new_line.f(y);\n\
    \            bool upd_z = lines[i].f(z) > new_line.f(z);\n\n            if (upd_x\
    \ && upd_y && upd_z) {\n                lines[i] = new_line;\n               \
    \ return;\n            }\n            if (upd_y && upd_z) {\n                std::swap(lines[i],\
    \ new_line);\n                rec(i*2, l, mid, new_line);\n            } else\
    \ if (upd_x && upd_y) {\n                std::swap(lines[i], new_line);\n    \
    \            rec(i*2 + 1, mid, r, new_line);\n            } else if (upd_x) {\n\
    \                rec(i*2, l, mid, new_line);\n            } else if (upd_z) {\n\
    \                rec(i*2+1, mid, r, new_line);\n            } else {\n       \
    \         return;\n            }\n        } else {\n            if (ql < mid)\
    \ rec(i*2, l, mid, new_line);\n            if (qr > mid) rec(i*2+1, mid, r, new_line);\n\
    \        }\n    }\n\n    Result get(int i, T x) {\n        i += head;\n      \
    \  Line res = lines[i];\n        TM val = res.is_valid ? res.f(x) : 0;\n     \
    \   for (i /= 2; i; i /= 2) {\n            if (!lines[i].is_valid) continue;\n\
    \            TM tmp = lines[i].f(x);\n            if (!res.is_valid || tmp < val)\
    \ res = lines[i], val = tmp;\n        }\n        return {res.a, res.b, res.id,\
    \ res.is_valid, val};\n    }\n};\n#line 7 \"DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp\"\
    \n\nusing ll = long long;\nstruct Query {\n    int typ;\n    ll a, b;\n};\n\n\
    int32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin\
    \ >> n >> q;\n\n    vector<Query> queries;\n    vector<ll> xs;\n\n    while (n--)\
    \ {\n        ll a, b; cin >> a >> b;\n        queries.push_back({0, a, b});\n\
    \    }\n\n    while (q--) {\n        int typ; cin >> typ;\n        if (typ ==\
    \ 0) {\n            ll a, b; cin >> a >> b;\n            queries.push_back({0,\
    \ a, b});\n        } else {\n            ll x; cin >> x;\n            queries.push_back({1,\
    \ x, 0});\n            xs.push_back(x);\n        }\n    }\n    LiChao<ll, __int128_t>\
    \ tree(xs);\n\n    for (auto [typ, a, b] : queries) {\n        if (typ == 0) {\n\
    \            tree.add_line(a, b, 0);\n        } else {\n            auto res =\
    \ tree.get(a);\n            assert(res.is_valid);\n            cout << (long long)\
    \ res.minval << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../LiChaoSegTree.h\"\
    \n\nusing ll = long long;\nstruct Query {\n    int typ;\n    ll a, b;\n};\n\n\
    int32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin\
    \ >> n >> q;\n\n    vector<Query> queries;\n    vector<ll> xs;\n\n    while (n--)\
    \ {\n        ll a, b; cin >> a >> b;\n        queries.push_back({0, a, b});\n\
    \    }\n\n    while (q--) {\n        int typ; cin >> typ;\n        if (typ ==\
    \ 0) {\n            ll a, b; cin >> a >> b;\n            queries.push_back({0,\
    \ a, b});\n        } else {\n            ll x; cin >> x;\n            queries.push_back({1,\
    \ x, 0});\n            xs.push_back(x);\n        }\n    }\n    LiChao<ll, __int128_t>\
    \ tree(xs);\n\n    for (auto [typ, a, b] : queries) {\n        if (typ == 0) {\n\
    \            tree.add_line(a, b, 0);\n        } else {\n            auto res =\
    \ tree.get(a);\n            assert(res.is_valid);\n            cout << (long long)\
    \ res.minval << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/LiChaoSegTree.h
  isVerificationFile: true
  path: DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 02:20:31+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp
- /verify/DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp.html
title: DataStructure/test/li_chao_seg_tree_lineaddgetmin.test.cpp
---
