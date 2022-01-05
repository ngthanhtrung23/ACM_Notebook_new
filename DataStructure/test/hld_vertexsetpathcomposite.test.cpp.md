---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/HeavyLight_adamant.h
    title: DataStructure/HeavyLight_adamant.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':heavy_check_mark:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../SegTree.h\"\
    \n#include \"../../Math/modulo_anta.h\"\n#include \"../HeavyLight_adamant.h\"\n\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\n// SegTree ops\nstruct F {\n    modular a, b;\n};\nF op(const F& l, const\
    \ F& r) {\n    return F{\n        l.a*r.a,\n        r.a*l.b + r.b\n    };\n}\n\
    \nstruct Node {\n    F forward, backward;\n};\n\nNode op(Node l, Node r) {\n \
    \   return Node {\n        op(l.forward, r.forward),\n        op(r.backward, l.backward)\n\
    \    };\n}\n\nNode e() {\n    return Node {\n        F{1, 0},\n        F{1, 0}\n\
    \    };\n}\n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\n\
    int32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin\
    \ >> n >> q;\n    vector<F> fs(n);\n    REP(i,n) {\n        int a, b; cin >> a\
    \ >> b;\n        fs[i] = {a, b};\n    }\n\n    vector<vector<int>> g(n);\n   \
    \ REP(i,n-1) {\n        int u, v; cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    HLD hld(g, 0);\n\n    vector<Node> nodes;\n\
    \    REP(i,n) {\n        auto f = fs[hld.order[i]];\n        nodes.push_back({f,\
    \ f});\n    }\n    SegTree<Node, op, e> tree(nodes);\n\n    while (q--) {\n  \
    \      int typ; cin >> typ;\n        if (typ == 0) {\n            int p, a, b;\
    \ cin >> p >> a >> b;\n            tree.set(hld.in[p], {{a, b}, {a, b}});\n  \
    \      } else {\n            int start, end, x; cin >> start >> end >> x;\n\n\
    \            auto segments = hld.getSegments(start, end);\n            F res {1,\
    \ 0};\n            for (auto [u, v] : segments) {\n                if (hld.in[u]\
    \ <= hld.in[v]) {\n                    res = op(res, tree.prod(hld.in[u], hld.in[v]\
    \ + 1).forward);\n                } else {\n                    res = op(res,\
    \ tree.prod(hld.in[v], hld.in[u] + 1).backward);\n                }\n        \
    \    }\n            cout << (res.a * modular(x) + res.b) << '\\n';\n        }\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/SegTree.h
  - Math/modulo_anta.h
  - DataStructure/HeavyLight_adamant.h
  isVerificationFile: true
  path: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 04:56:25+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/hld_vertexsetpathcomposite.test.cpp
- /verify/DataStructure/test/hld_vertexsetpathcomposite.test.cpp.html
title: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
---
