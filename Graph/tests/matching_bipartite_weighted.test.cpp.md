---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Matching/HungarianLMH.h
    title: Graph/Matching/HungarianLMH.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"Graph/tests/matching_bipartite_weighted.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nconst int MN = 511;\nconst long long inf = 1000111000111LL;\n\
    int N;\n\n#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n\
    #line 1 \"Graph/Matching/HungarianLMH.h\"\n// Index from 1\n// Min cost matching\n\
    // Usage: init(); for[i,j,cost] addEdge(i, j, cost)\n//\n// Tested:\n// - SGU\
    \ 210\n// - SGU 206\n// - https://codeforces.com/contest/1437/problem/C\n// -\
    \ https://judge.yosupo.jp/problem/assignment\n\n#define arg __arg\nlong long c[MN][MN];\n\
    long long fx[MN], fy[MN];\nint mx[MN], my[MN];\nint trace[MN], qu[MN], arg[MN];\n\
    long long d[MN];\nint front, rear, start, finish;\n\nvoid init() {\n    FOR(i,1,N)\
    \ {\n        fy[i] = mx[i] = my[i] = 0;\n        FOR(j,1,N) c[i][j] = inf;\n \
    \   }\n}\n\nvoid addEdge(int i, int j, long long cost) {\n    c[i][j] = min(c[i][j],\
    \ cost);\n}\n\ninline long long getC(int i, int j) {\n    return c[i][j] - fx[i]\
    \ - fy[j];\n}\n\nvoid initBFS() {\n    front = rear = 1;\n    qu[1] = start;\n\
    \    memset(trace, 0, sizeof trace);\n    FOR(j,1,N) {\n        d[j] = getC(start,\
    \ j);\n        arg[j] = start;\n    }\n    finish = 0;\n}\n\nvoid findAugPath()\
    \ {\n    while (front <= rear) {\n        int i = qu[front++];\n        FOR(j,1,N)\
    \ if (!trace[j]) {\n            long long w = getC(i, j);\n            if (!w)\
    \ {\n                trace[j] = i;\n                if (!my[j]) {\n          \
    \          finish = j;\n                    return ;\n                }\n    \
    \            qu[++rear] = my[j];\n            }\n            if (d[j] > w) {\n\
    \                d[j] = w;\n                arg[j] = i;\n            }\n     \
    \   }\n    }\n}\n\nvoid subx_addy() {\n    long long delta = inf;\n    FOR(j,1,N)\n\
    \        if (trace[j] == 0 && d[j] < delta) delta = d[j];\n\n    // xoay\n   \
    \ fx[start] += delta;\n    FOR(j,1,N)\n        if (trace[j]) {\n            int\
    \ i = my[j];\n            fy[j] -= delta;\n            fx[i] += delta;\n     \
    \   }\n        else d[j] -= delta;\n\n    FOR(j,1,N)\n        if (!trace[j] &&\
    \ !d[j]) {\n            trace[j] = arg[j];\n            if (!my[j]) { finish =\
    \ j; return ; }\n            qu[++rear] = my[j];\n        }\n}\n\nvoid enlarge()\
    \ {\n    do {\n        int i = trace[finish];\n        int next = mx[i];\n   \
    \     mx[i] = finish;\n        my[finish] = i;\n        finish = next;\n    }\
    \ while (finish);\n}\n\nlong long mincost() {\n    FOR(i,1,N) fx[i] = *min_element(c[i]+1,\
    \ c[i]+N+1);\n    FOR(j,1,N) {\n        fy[j] = c[1][j] - fx[1];\n        FOR(i,1,N)\
    \ {\n            fy[j] = min(fy[j], c[i][j] - fx[i]);\n        }\n    }\n    FOR(i,1,N)\
    \ {\n        start = i;\n        initBFS();\n        while (finish == 0) {\n \
    \           findAugPath();\n            if (!finish) subx_addy();\n        }\n\
    \        enlarge();\n    }\n    long long res = 0;\n    FOR(i,1,N) res += c[i][mx[i]];\n\
    \    return res;\n}\n#line 12 \"Graph/tests/matching_bipartite_weighted.test.cpp\"\
    \n\nint32_t main() {\n    cin >> N;\n    FOR(i,1,N) FOR(j,1,N) cin >> c[i][j];\n\
    \    cout << mincost() << '\\n';\n    FOR(i,1,N) {\n        cout << mx[i] - 1\
    \ << ' ';\n    }\n    cout << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nconst int MN = 511;\nconst long long\
    \ inf = 1000111000111LL;\nint N;\n\n#define FOR(i, a, b) for (int i = (a), _##i\
    \ = (b); i <= _##i; ++i)\n#include \"../Matching/HungarianLMH.h\"\n\nint32_t main()\
    \ {\n    cin >> N;\n    FOR(i,1,N) FOR(j,1,N) cin >> c[i][j];\n    cout << mincost()\
    \ << '\\n';\n    FOR(i,1,N) {\n        cout << mx[i] - 1 << ' ';\n    }\n    cout\
    \ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - Graph/Matching/HungarianLMH.h
  isVerificationFile: true
  path: Graph/tests/matching_bipartite_weighted.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 04:03:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/matching_bipartite_weighted.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/matching_bipartite_weighted.test.cpp
- /verify/Graph/tests/matching_bipartite_weighted.test.cpp.html
title: Graph/tests/matching_bipartite_weighted.test.cpp
---
