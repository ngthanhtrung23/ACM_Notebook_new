---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/optimizations/convex_hull.h\"\n// Original Recurrence:\n\
    //   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i\n// Condition:\n//   b[j] >=\
    \ b[j+1]\n//   a[i] <= a[i+1]\n// To solve:\n// Hull hull;\n// FOR(i,1,n) {\n\
    //   dp[i] = hull.get(a[i]);\n//   hull.add(b[i], dp[i]);\n// }\n\nconst int MAXN\
    \ = 100100;\n\nstruct Hull {\n    long long a[MAXN], b[MAXN];\n    double x[MAXN];\n\
    \    int head, tail;\n\n    Hull(): head(1), tail(0) {}\n\n    long long get(long\
    \ long xQuery) {\n        if (head > tail) return 0;\n        while (head < tail\
    \ && x[head + 1] <= xQuery) head++;\n        x[head] = xQuery;\n        return\
    \ a[head] * xQuery + b[head];\n    }\n\n    void add(long long aNew, long long\
    \ bNew) {\n        double xNew = -1e18;\n        while (head <= tail) {\n    \
    \        if (aNew == a[tail]) return;\n            xNew = 1.0 * (b[tail] - bNew)\
    \ / (aNew - a[tail]);\n            if (head == tail || xNew >= x[tail]) break;\n\
    \            tail--;\n        }\n        a[++tail] = aNew;\n        b[tail] =\
    \ bNew;\n        x[tail] = xNew;\n    }\n};\n"
  code: "// Original Recurrence:\n//   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i\n\
    // Condition:\n//   b[j] >= b[j+1]\n//   a[i] <= a[i+1]\n// To solve:\n// Hull\
    \ hull;\n// FOR(i,1,n) {\n//   dp[i] = hull.get(a[i]);\n//   hull.add(b[i], dp[i]);\n\
    // }\n\nconst int MAXN = 100100;\n\nstruct Hull {\n    long long a[MAXN], b[MAXN];\n\
    \    double x[MAXN];\n    int head, tail;\n\n    Hull(): head(1), tail(0) {}\n\
    \n    long long get(long long xQuery) {\n        if (head > tail) return 0;\n\
    \        while (head < tail && x[head + 1] <= xQuery) head++;\n        x[head]\
    \ = xQuery;\n        return a[head] * xQuery + b[head];\n    }\n\n    void add(long\
    \ long aNew, long long bNew) {\n        double xNew = -1e18;\n        while (head\
    \ <= tail) {\n            if (aNew == a[tail]) return;\n            xNew = 1.0\
    \ * (b[tail] - bNew) / (aNew - a[tail]);\n            if (head == tail || xNew\
    \ >= x[tail]) break;\n            tail--;\n        }\n        a[++tail] = aNew;\n\
    \        b[tail] = bNew;\n        x[tail] = xNew;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/optimizations/convex_hull.h
  requiredBy: []
  timestamp: '2022-12-26 18:06:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/optimizations/convex_hull.h
layout: document
redirect_from:
- /library/DP/optimizations/convex_hull.h
- /library/DP/optimizations/convex_hull.h.html
title: DP/optimizations/convex_hull.h
---
