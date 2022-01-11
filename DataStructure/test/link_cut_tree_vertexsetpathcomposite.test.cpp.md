---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LinkCutTree.h
    title: DataStructure/LinkCutTree.h
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../../Math/modulo_anta.h\"\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\n#define PATH_QUERIES_ONLY\nstruct T {\n    modular a, b;\n\n    T() : a(1),\
    \ b(0) {}\n    T(modular _a, modular _b) : a(_a), b(_b) {}\n\n    // return f(g())\n\
    \    T operator + (const T& g) const {\n        return T {\n            a * g.a,\n\
    \            a * g.b + b,\n        };\n    }\n\n    T operator += (const T& g)\
    \ {\n        b = a * g.b + b;\n        a = a * g.a;\n        return *this;\n \
    \   }\n};\n#include \"../LinkCutTree.h\"\n\n#define FOR(i, a, b) for (int i =\
    \ (a), _##i = (b); i <= _##i; ++i)\n#define REP(i, a) for (int i = 0, _##i = (a);\
    \ i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \n    int n, q; cin >> n >> q;\n    LinkCut tree(n);\n\n    FOR(i,1,n) {\n   \
    \     modular a, b; cin >> a >> b;\n        tree.set(i, T{a, b});\n    }\n\n \
    \   REP(i,n-1) {\n        int u, v; cin >> u >> v;\n        ++u; ++v;\n      \
    \  tree.link(u, v);\n    }\n\n    while (q--) {\n        int typ; cin >> typ;\n\
    \        if (typ == 0) {  // remove (u, v), add (w, x)\n            int u, v,\
    \ w, x; cin >> u >> v >> w >> x;\n            ++u; ++v;\n            ++w; ++x;\n\
    \            tree.cut(u, v);\n            tree.link(w, x);\n        } else if\
    \ (typ == 1) {  // set f(p) = cx + d\n            int p; cin >> p;\n         \
    \   ++p;\n            modular c, d; cin >> c >> d;\n            tree.set(p, T{c,\
    \ d});\n        } else if (typ == 2) {  // get path (u, v) and apply f(x)\n  \
    \          int u, v; cin >> u >> v;\n            ++u; ++v;\n            modular\
    \ x; cin >> x;\n\n            auto f = tree.getPath(u, v);\n            cout <<\
    \ f.a * x + f.b << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - Math/modulo_anta.h
  - DataStructure/LinkCutTree.h
  isVerificationFile: true
  path: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 20:18:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
- /verify/DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp.html
title: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
---
