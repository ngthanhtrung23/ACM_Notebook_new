---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegTree.h
    title: DataStructure/LazySegTree.h
  - icon: ':heavy_check_mark:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
  - icon: ':heavy_check_mark:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../LazySegTree.h\"\
    \n#include \"../../Math/modulo_anta.h\"\n#include \"../../buffered_reader.h\"\n\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\nstruct Node {\n    modular sum, sz;\n};\nstruct Lazy {\n    modular a, b;\n\
    };\n\nNode op(Node l, Node r) {\n    return Node {\n        l.sum + r.sum,\n \
    \       l.sz + r.sz\n    };\n}\nNode e() {\n    return Node{0, 0};\n}\n\nNode\
    \ apply(Lazy f, Node node) {\n    return Node{\n        f.a * node.sum + f.b *\
    \ node.sz,\n        node.sz\n    };\n}\nLazy combine(Lazy g, Lazy f) {\n    return\
    \ Lazy {\n        f.a * g.a,\n        g.a * f.b + g.b\n    };\n}\nLazy id() {\n\
    \    return Lazy{1, 0};\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<Node> nodes(n);\n    for (auto& node\
    \ : nodes) {\n        cin >> node.sum;\n        node.sz = 1;\n    }\n    LazySegTree<Node,\
    \ op, e, Lazy, apply, combine, id> st(nodes);\n\n    while (q--) {\n        int\
    \ typ; cin >> typ;\n        if (typ == 0) {\n            int l, r;\n         \
    \   Lazy f;\n            cin >> l >> r >> f.a >> f.b;\n            st.apply(l,\
    \ r, f);\n        } else {\n            int l, r; cin >> l >> r;\n           \
    \ cout << st.prod(l, r).sum << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/LazySegTree.h
  - Math/modulo_anta.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
- /verify/DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp.html
title: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
---
