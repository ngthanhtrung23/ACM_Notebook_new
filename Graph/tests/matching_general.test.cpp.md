---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Matching/GeneralMatching.h
    title: Graph/Matching/GeneralMatching.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"Graph/tests/matching_general.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/general_matching\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Graph/Matching/GeneralMatching.h\"\n// Max matching\
    \ on general graph\n// Copied from https://judge.yosupo.jp/submission/61234\n\
    //\n// Notes:\n// - Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/general_matching\n\
    // - https://oj.vnoi.info/problem/qbflower\n// - https://uoj.ac/problem/79\n//\
    \ - https://acm.timus.ru/problem.aspx?space=1&num=1099\n\nstruct GeneralMatching\
    \ {\n    GeneralMatching(int _n) : n(_n), match(_n, -1), g(_n),\n            timer(-1),\
    \ label(_n), parent(_n), orig(_n), aux(_n, -1) {}\n\n    void add_edge(int u,\
    \ int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n\
    \    int get_match() {\n        for (int i = 0; i < n; i++) {\n            if\
    \ (match[i] == -1) bfs(i);\n        }\n        int res = 0;\n        for (int\
    \ i = 0; i < n; i++) {\n            if (match[i] >= 0) ++res;\n        }\n   \
    \     return res / 2;\n    }\n\n    int n;\n    vector<int> match;\n\nprivate:\n\
    \    int lca(int x, int y) {\n        for (timer++; ; swap(x, y)) {\n        \
    \    if (x == -1) continue;\n            if (aux[x] == timer) return x;\n    \
    \        aux[x] = timer;\n            x = (match[x] == -1 ? -1 : orig[parent[match[x]]]);\n\
    \        }\n    }\n\n    void blossom(int v, int w, int a) {\n        while (orig[v]\
    \ != a) {\n            parent[v] = w;\n            w = match[v];\n           \
    \ if (label[w] == 1) {\n                label[w] = 0;\n                q.push_back(w);\n\
    \            }\n            orig[v] = orig[w] = a;\n            v = parent[w];\n\
    \        }\n    }\n\n    void augment(int v) {\n        while (v != -1) {\n  \
    \          int pv = parent[v], nv = match[pv];\n            match[v] = pv; match[pv]\
    \ = v; v = nv;\n        }\n    }\n\n    int bfs(int root) {\n        fill(label.begin(),\
    \ label.end(), -1);\n        iota(orig.begin(), orig.end(), 0);\n        q.clear();\n\
    \        label[root] = 0;\n        q.push_back(root);\n        for (int i = 0;\
    \ i < (int) q.size(); ++i) {\n            int v = q[i];\n            for (auto\
    \ x : g[v]) {\n                if (label[x] == -1) {\n                    label[x]\
    \ = 1;\n                    parent[x] = v;\n                    if (match[x] ==\
    \ -1) {\n                        augment(x);\n                        return 1;\n\
    \                    }\n                    label[match[x]] = 0;\n           \
    \         q.push_back(match[x]);\n                } else if (label[x] == 0 &&\
    \ orig[v] != orig[x]) {\n                    int a = lca(orig[v], orig[x]);\n\
    \                    blossom(x, v, a);\n                    blossom(v, x, a);\n\
    \                }\n            }\n        }\n        return 0;\n    }\n\nprivate:\n\
    \    vector<vector<int>> g;\n    int timer;\n    vector<int> label, parent, orig,\
    \ aux, q;\n};\n#line 7 \"Graph/tests/matching_general.test.cpp\"\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin >> n >> m;\n\
    \    GeneralMatching match(n);\n    while (m--) {\n        int a, b; cin >> a\
    \ >> b;\n        match.add_edge(a, b);\n    }\n    cout << match.get_match() <<\
    \ '\\n';\n    for (int i = 0; i < n; i++) {\n        if (match.match[i] != -1\
    \ && match.match[i] > i) {\n            cout << i << ' ' << match.match[i] <<\
    \ '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Matching/GeneralMatching.h\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m;\
    \ cin >> n >> m;\n    GeneralMatching match(n);\n    while (m--) {\n        int\
    \ a, b; cin >> a >> b;\n        match.add_edge(a, b);\n    }\n    cout << match.get_match()\
    \ << '\\n';\n    for (int i = 0; i < n; i++) {\n        if (match.match[i] !=\
    \ -1 && match.match[i] > i) {\n            cout << i << ' ' << match.match[i]\
    \ << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/Matching/GeneralMatching.h
  isVerificationFile: true
  path: Graph/tests/matching_general.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 00:30:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/matching_general.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/matching_general.test.cpp
- /verify/Graph/tests/matching_general.test.cpp.html
title: Graph/tests/matching_general.test.cpp
---
