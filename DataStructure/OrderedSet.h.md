---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1076
    - https://open.kattis.com/problems/lazylearner
  bundledCode: "#line 1 \"DataStructure/OrderedSet.h\"\n// Copied from chemthan\n\
    // \n// Usage:\n// \n// OrderedTree<int> set;\n// set.init(MAX_VALUE);  // Init\
    \ set to store 0..n-1\n// set.upd(x, x, +1);    // normally can just upd x = val\
    \ (val is just for mapping of values)\n// set.find_by_order(k)  // k from 1\n\
    //\n// Tested:\n// - https://open.kattis.com/problems/lazylearner\n// - https://cses.fi/problemset/task/1076\n\
    \ntemplate<class num_t>\nstruct OrderedTree {\n    int n;\n    vector<num_t> a;\n\
    \    num_t tot;\n    vector<num_t> x;\n\n    void init(int _n) {\n        n =\
    \ _n;\n        a.resize(n);\n        for (int i = 0; i < n; i++) a[i] = 0;\n \
    \       tot = 0;\n        x.resize(n + 1);\n        for (int i = 0; i <= n; i++)\
    \ x[i] = 0;\n    }\n\n    void upd(int p, num_t val, num_t cnt) {\n        assert(0\
    \ <= p && p < n);\n        a[p] = val, tot += cnt;\n        for (p++; p <= n;\
    \ p += p & -p) {\n            x[p] += cnt;\n        }\n    }\n\n    // 1 <= k\
    \ <= tot  (tot = number of elements)\n    num_t find_by_order(num_t k) {\n   \
    \     assert(0 <= k && k <= tot);\n        if (!k) return -1;\n        int p =\
    \ 0;\n        for (int i = __lg(n); i >= 0; i--) {\n            if (p + (1 <<\
    \ i) <= n && x[p + (1 << i)] < k) {\n                k -= x[p + (1 << i)];\n \
    \               p += 1 << i;\n            }\n        }\n        return a[p];\n\
    \    }\n};\n"
  code: "// Copied from chemthan\n// \n// Usage:\n// \n// OrderedTree<int> set;\n\
    // set.init(MAX_VALUE);  // Init set to store 0..n-1\n// set.upd(x, x, +1);  \
    \  // normally can just upd x = val (val is just for mapping of values)\n// set.find_by_order(k)\
    \  // k from 1\n//\n// Tested:\n// - https://open.kattis.com/problems/lazylearner\n\
    // - https://cses.fi/problemset/task/1076\n\ntemplate<class num_t>\nstruct OrderedTree\
    \ {\n    int n;\n    vector<num_t> a;\n    num_t tot;\n    vector<num_t> x;\n\n\
    \    void init(int _n) {\n        n = _n;\n        a.resize(n);\n        for (int\
    \ i = 0; i < n; i++) a[i] = 0;\n        tot = 0;\n        x.resize(n + 1);\n \
    \       for (int i = 0; i <= n; i++) x[i] = 0;\n    }\n\n    void upd(int p, num_t\
    \ val, num_t cnt) {\n        assert(0 <= p && p < n);\n        a[p] = val, tot\
    \ += cnt;\n        for (p++; p <= n; p += p & -p) {\n            x[p] += cnt;\n\
    \        }\n    }\n\n    // 1 <= k <= tot  (tot = number of elements)\n    num_t\
    \ find_by_order(num_t k) {\n        assert(0 <= k && k <= tot);\n        if (!k)\
    \ return -1;\n        int p = 0;\n        for (int i = __lg(n); i >= 0; i--) {\n\
    \            if (p + (1 << i) <= n && x[p + (1 << i)] < k) {\n               \
    \ k -= x[p + (1 << i)];\n                p += 1 << i;\n            }\n       \
    \ }\n        return a[p];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/OrderedSet.h
  requiredBy: []
  timestamp: '2022-01-17 03:27:26+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/OrderedSet.h
layout: document
redirect_from:
- /library/DataStructure/OrderedSet.h
- /library/DataStructure/OrderedSet.h.html
title: DataStructure/OrderedSet.h
---
