---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/57319
    - https://www.acmicpc.net/problem/17474
    - https://www.youtube.com/watch?v=wFqKgrW1IMQ
  bundledCode: "#line 1 \"DataStructure/SegmentTreeBeats.cpp\"\n// Segment tree beats\n\
    // Tutorial:\n// - https://codeforces.com/blog/entry/57319\n// - https://www.youtube.com/watch?v=wFqKgrW1IMQ\n\
    //\n// AC: https://www.acmicpc.net/problem/17474\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define int long long\n#define FOR(i, a, b) for (int i\
    \ = (a), _##i = (b); i <= _##i; ++i)\n#define REP(i, a) for (int i = 0, _##i =\
    \ (a); i < _##i; ++i)\n\nstruct Node {\n    int max1;  // max value\n    int max2;\
    \  // 2nd max value (must be different from max1)\n    int cnt_max;  // how many\
    \ indices have value == max1\n    int sum;\n    int lazy;\n\n    Node() {}\n \
    \   Node(int val) {  // initialize with a single number.\n        max1 = val;\n\
    \        max2 = -1;  // Note that values are in [0, 2^31), so -1 works here.\n\
    \        cnt_max = 1;\n        sum = val;\n        lazy = -1;  // Note that values\
    \ are in [0, 2^31), so -1 works here.\n    }\n\n    void setMin(int val) {  //\
    \ for each i, set a[i] = min(a[i], val)\n        assert(val > max2);\n\n     \
    \   if (max1 <= val) return;\n\n        // Sample: 1 3 5 8 8 --> 1 3 5 6 6\n \
    \       sum -= (max1 - val) * cnt_max;\n        lazy = val;\n        max1 = val;\n\
    \    }\n} it[8000111];\n\nNode operator + (const Node& a, const Node& b) {\n \
    \   Node res;\n    res.max1 = max(a.max1, b.max1);\n\n    res.max2 = max(a.max2,\
    \ b.max2);\n    if (a.max1 != res.max1) res.max2 = max(res.max2, a.max1);\n  \
    \  if (b.max1 != res.max1) res.max2 = max(res.max2, b.max1);\n\n    res.cnt_max\
    \ = 0;\n    if (a.max1 == res.max1) res.cnt_max += a.cnt_max;\n    if (b.max1\
    \ == res.max1) res.cnt_max += b.cnt_max;\n\n    res.sum = a.sum + b.sum;\n   \
    \ res.lazy = -1;\n    return res;\n}\n\nvoid down(int i) {\n    if (it[i].lazy\
    \ < 0) return;\n\n    it[i*2].setMin(it[i].lazy);\n    it[i*2+1].setMin(it[i].lazy);\n\
    \n    it[i].lazy = -1;\n}\n\nint a[1000111];\nvoid build(int i, int l, int r)\
    \ {\n    if (l == r) {\n        it[i] = Node(a[l]);\n        return;\n    }\n\
    \    int mid = (l + r) / 2;\n    build(i*2, l, mid);\n    build(i*2 + 1, mid +\
    \ 1, r);\n\n    it[i] = it[i*2] + it[i*2 + 1];\n}\n\nvoid setMin(int i, int l,\
    \ int r, int u, int v, int x) {\n    if (v < l || r < u) return;\n    if (it[i].max1\
    \ <= x) return;\n    // now max1 > x\n\n    if (u <= l && r <= v && it[i].max2\
    \ < x) {\n        it[i].setMin(x);\n        return;\n    }\n\n    down(i);\n \
    \   int mid = (l + r) / 2;\n    setMin(i*2, l, mid, u, v, x);\n    setMin(i*2\
    \ + 1, mid+1, r, u, v, x);\n    it[i] = it[i*2] + it[i*2 + 1];\n}\n\nint getMax(int\
    \ i, int l, int r, int u, int v) {\n    if (v < l || r < u) return -1;\n    if\
    \ (u <= l && r <= v) return it[i].max1;\n\n    down(i);\n    int mid = (l + r)\
    \ / 2;\n    return max(getMax(i*2, l, mid, u, v),\n            getMax(i*2+1, mid+1,\
    \ r, u, v));\n}\n\nint getSum(int i, int l, int r, int u, int v) {\n    if (v\
    \ < l || r < u) return 0;\n    if (u <= l && r <= v) return it[i].sum;\n\n   \
    \ down(i);\n    int mid = (l + r) / 2;\n    return getSum(i*2, l, mid, u, v) +\
    \ getSum(i*2+1, mid+1, r, u, v);\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0);\n\
    \    cin.tie(0);\n    // read initial array\n    int n; cin >> n;\n    FOR(i,1,n)\
    \ cin >> a[i];\n    \n    // initialize segment tree beats\n    build(1, 1, n);\n\
    \    \n    // queries\n    int q; cin >> q;\n    while (q--) {\n        int typ;\
    \ cin >> typ;\n        if (typ == 1) { // for each i in [l, r] set a[i] = min(a[i],\
    \ x)\n            int l, r, x; cin >> l >> r >> x;\n            setMin(1, 1, n,\
    \ l, r, x);\n        } else if (typ == 2) { // find max(a[i]) for i in [l, r]\n\
    \            int l, r; cin >> l >> r;\n            cout << getMax(1, 1, n, l,\
    \ r) << '\\n';\n        } else { // find sum(a[i]) for i in [l, r]\n         \
    \   int l, r; cin >> l >> r;\n            cout << getSum(1, 1, n, l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "// Segment tree beats\n// Tutorial:\n// - https://codeforces.com/blog/entry/57319\n\
    // - https://www.youtube.com/watch?v=wFqKgrW1IMQ\n//\n// AC: https://www.acmicpc.net/problem/17474\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define int long long\n#define\
    \ FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n#define REP(i, a)\
    \ for (int i = 0, _##i = (a); i < _##i; ++i)\n\nstruct Node {\n    int max1; \
    \ // max value\n    int max2;  // 2nd max value (must be different from max1)\n\
    \    int cnt_max;  // how many indices have value == max1\n    int sum;\n    int\
    \ lazy;\n\n    Node() {}\n    Node(int val) {  // initialize with a single number.\n\
    \        max1 = val;\n        max2 = -1;  // Note that values are in [0, 2^31),\
    \ so -1 works here.\n        cnt_max = 1;\n        sum = val;\n        lazy =\
    \ -1;  // Note that values are in [0, 2^31), so -1 works here.\n    }\n\n    void\
    \ setMin(int val) {  // for each i, set a[i] = min(a[i], val)\n        assert(val\
    \ > max2);\n\n        if (max1 <= val) return;\n\n        // Sample: 1 3 5 8 8\
    \ --> 1 3 5 6 6\n        sum -= (max1 - val) * cnt_max;\n        lazy = val;\n\
    \        max1 = val;\n    }\n} it[8000111];\n\nNode operator + (const Node& a,\
    \ const Node& b) {\n    Node res;\n    res.max1 = max(a.max1, b.max1);\n\n   \
    \ res.max2 = max(a.max2, b.max2);\n    if (a.max1 != res.max1) res.max2 = max(res.max2,\
    \ a.max1);\n    if (b.max1 != res.max1) res.max2 = max(res.max2, b.max1);\n\n\
    \    res.cnt_max = 0;\n    if (a.max1 == res.max1) res.cnt_max += a.cnt_max;\n\
    \    if (b.max1 == res.max1) res.cnt_max += b.cnt_max;\n\n    res.sum = a.sum\
    \ + b.sum;\n    res.lazy = -1;\n    return res;\n}\n\nvoid down(int i) {\n   \
    \ if (it[i].lazy < 0) return;\n\n    it[i*2].setMin(it[i].lazy);\n    it[i*2+1].setMin(it[i].lazy);\n\
    \n    it[i].lazy = -1;\n}\n\nint a[1000111];\nvoid build(int i, int l, int r)\
    \ {\n    if (l == r) {\n        it[i] = Node(a[l]);\n        return;\n    }\n\
    \    int mid = (l + r) / 2;\n    build(i*2, l, mid);\n    build(i*2 + 1, mid +\
    \ 1, r);\n\n    it[i] = it[i*2] + it[i*2 + 1];\n}\n\nvoid setMin(int i, int l,\
    \ int r, int u, int v, int x) {\n    if (v < l || r < u) return;\n    if (it[i].max1\
    \ <= x) return;\n    // now max1 > x\n\n    if (u <= l && r <= v && it[i].max2\
    \ < x) {\n        it[i].setMin(x);\n        return;\n    }\n\n    down(i);\n \
    \   int mid = (l + r) / 2;\n    setMin(i*2, l, mid, u, v, x);\n    setMin(i*2\
    \ + 1, mid+1, r, u, v, x);\n    it[i] = it[i*2] + it[i*2 + 1];\n}\n\nint getMax(int\
    \ i, int l, int r, int u, int v) {\n    if (v < l || r < u) return -1;\n    if\
    \ (u <= l && r <= v) return it[i].max1;\n\n    down(i);\n    int mid = (l + r)\
    \ / 2;\n    return max(getMax(i*2, l, mid, u, v),\n            getMax(i*2+1, mid+1,\
    \ r, u, v));\n}\n\nint getSum(int i, int l, int r, int u, int v) {\n    if (v\
    \ < l || r < u) return 0;\n    if (u <= l && r <= v) return it[i].sum;\n\n   \
    \ down(i);\n    int mid = (l + r) / 2;\n    return getSum(i*2, l, mid, u, v) +\
    \ getSum(i*2+1, mid+1, r, u, v);\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0);\n\
    \    cin.tie(0);\n    // read initial array\n    int n; cin >> n;\n    FOR(i,1,n)\
    \ cin >> a[i];\n    \n    // initialize segment tree beats\n    build(1, 1, n);\n\
    \    \n    // queries\n    int q; cin >> q;\n    while (q--) {\n        int typ;\
    \ cin >> typ;\n        if (typ == 1) { // for each i in [l, r] set a[i] = min(a[i],\
    \ x)\n            int l, r, x; cin >> l >> r >> x;\n            setMin(1, 1, n,\
    \ l, r, x);\n        } else if (typ == 2) { // find max(a[i]) for i in [l, r]\n\
    \            int l, r; cin >> l >> r;\n            cout << getMax(1, 1, n, l,\
    \ r) << '\\n';\n        } else { // find sum(a[i]) for i in [l, r]\n         \
    \   int l, r; cin >> l >> r;\n            cout << getSum(1, 1, n, l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTreeBeats.cpp
  requiredBy: []
  timestamp: '2022-01-12 13:12:33+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTreeBeats.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTreeBeats.cpp
- /library/DataStructure/SegmentTreeBeats.cpp.html
title: DataStructure/SegmentTreeBeats.cpp
---
