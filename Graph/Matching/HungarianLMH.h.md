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
    - https://codeforces.com/contest/1437/problem/C
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"Graph/Matching/HungarianLMH.h\"\n// Index from 1\n// Min\
    \ cost matching\n// Usage: init(); for[i,j,cost] addEdge(i, j, cost)\n//\n// Tested:\n\
    // - SGU 210\n// - SGU 206\n// - https://codeforces.com/contest/1437/problem/C\n\
    // - https://judge.yosupo.jp/problem/assignment\n\n#define arg __arg\nlong long\
    \ c[MN][MN];\nlong long fx[MN], fy[MN];\nint mx[MN], my[MN];\nint trace[MN], qu[MN],\
    \ arg[MN];\nlong long d[MN];\nint front, rear, start, finish;\n\nvoid init() {\n\
    \    FOR(i,1,N) {\n        fy[i] = mx[i] = my[i] = 0;\n        FOR(j,1,N) c[i][j]\
    \ = inf;\n    }\n}\n\nvoid addEdge(int i, int j, long long cost) {\n    c[i][j]\
    \ = min(c[i][j], cost);\n}\n\ninline long long getC(int i, int j) {\n    return\
    \ c[i][j] - fx[i] - fy[j];\n}\n\nvoid initBFS() {\n    front = rear = 1;\n   \
    \ qu[1] = start;\n    memset(trace, 0, sizeof trace);\n    FOR(j,1,N) {\n    \
    \    d[j] = getC(start, j);\n        arg[j] = start;\n    }\n    finish = 0;\n\
    }\n\nvoid findAugPath() {\n    while (front <= rear) {\n        int i = qu[front++];\n\
    \        FOR(j,1,N) if (!trace[j]) {\n            long long w = getC(i, j);\n\
    \            if (!w) {\n                trace[j] = i;\n                if (!my[j])\
    \ {\n                    finish = j;\n                    return ;\n         \
    \       }\n                qu[++rear] = my[j];\n            }\n            if\
    \ (d[j] > w) {\n                d[j] = w;\n                arg[j] = i;\n     \
    \       }\n        }\n    }\n}\n\nvoid subx_addy() {\n    long long delta = inf;\n\
    \    FOR(j,1,N)\n        if (trace[j] == 0 && d[j] < delta) delta = d[j];\n\n\
    \    // xoay\n    fx[start] += delta;\n    FOR(j,1,N)\n        if (trace[j]) {\n\
    \            int i = my[j];\n            fy[j] -= delta;\n            fx[i] +=\
    \ delta;\n        }\n        else d[j] -= delta;\n\n    FOR(j,1,N)\n        if\
    \ (!trace[j] && !d[j]) {\n            trace[j] = arg[j];\n            if (!my[j])\
    \ { finish = j; return ; }\n            qu[++rear] = my[j];\n        }\n}\n\n\
    void enlarge() {\n    do {\n        int i = trace[finish];\n        int next =\
    \ mx[i];\n        mx[i] = finish;\n        my[finish] = i;\n        finish = next;\n\
    \    } while (finish);\n}\n\nint mincost() {\n    FOR(i,1,N) fx[i] = *min_element(c[i]+1,\
    \ c[i]+N+1);\n    FOR(j,1,N) {\n        fy[j] = c[1][j] - fx[1];\n        FOR(i,1,N)\
    \ {\n            fy[j] = min(fy[j], c[i][j] - fx[i]);\n        }\n    }\n    FOR(i,1,N)\
    \ {\n        start = i;\n        initBFS();\n        while (finish == 0) {\n \
    \           findAugPath();\n            if (!finish) subx_addy();\n        }\n\
    \        enlarge();\n    }\n    int res = 0;\n    FOR(i,1,N) res += c[i][mx[i]];\n\
    \    return res;\n}\n"
  code: "// Index from 1\n// Min cost matching\n// Usage: init(); for[i,j,cost] addEdge(i,\
    \ j, cost)\n//\n// Tested:\n// - SGU 210\n// - SGU 206\n// - https://codeforces.com/contest/1437/problem/C\n\
    // - https://judge.yosupo.jp/problem/assignment\n\n#define arg __arg\nlong long\
    \ c[MN][MN];\nlong long fx[MN], fy[MN];\nint mx[MN], my[MN];\nint trace[MN], qu[MN],\
    \ arg[MN];\nlong long d[MN];\nint front, rear, start, finish;\n\nvoid init() {\n\
    \    FOR(i,1,N) {\n        fy[i] = mx[i] = my[i] = 0;\n        FOR(j,1,N) c[i][j]\
    \ = inf;\n    }\n}\n\nvoid addEdge(int i, int j, long long cost) {\n    c[i][j]\
    \ = min(c[i][j], cost);\n}\n\ninline long long getC(int i, int j) {\n    return\
    \ c[i][j] - fx[i] - fy[j];\n}\n\nvoid initBFS() {\n    front = rear = 1;\n   \
    \ qu[1] = start;\n    memset(trace, 0, sizeof trace);\n    FOR(j,1,N) {\n    \
    \    d[j] = getC(start, j);\n        arg[j] = start;\n    }\n    finish = 0;\n\
    }\n\nvoid findAugPath() {\n    while (front <= rear) {\n        int i = qu[front++];\n\
    \        FOR(j,1,N) if (!trace[j]) {\n            long long w = getC(i, j);\n\
    \            if (!w) {\n                trace[j] = i;\n                if (!my[j])\
    \ {\n                    finish = j;\n                    return ;\n         \
    \       }\n                qu[++rear] = my[j];\n            }\n            if\
    \ (d[j] > w) {\n                d[j] = w;\n                arg[j] = i;\n     \
    \       }\n        }\n    }\n}\n\nvoid subx_addy() {\n    long long delta = inf;\n\
    \    FOR(j,1,N)\n        if (trace[j] == 0 && d[j] < delta) delta = d[j];\n\n\
    \    // xoay\n    fx[start] += delta;\n    FOR(j,1,N)\n        if (trace[j]) {\n\
    \            int i = my[j];\n            fy[j] -= delta;\n            fx[i] +=\
    \ delta;\n        }\n        else d[j] -= delta;\n\n    FOR(j,1,N)\n        if\
    \ (!trace[j] && !d[j]) {\n            trace[j] = arg[j];\n            if (!my[j])\
    \ { finish = j; return ; }\n            qu[++rear] = my[j];\n        }\n}\n\n\
    void enlarge() {\n    do {\n        int i = trace[finish];\n        int next =\
    \ mx[i];\n        mx[i] = finish;\n        my[finish] = i;\n        finish = next;\n\
    \    } while (finish);\n}\n\nint mincost() {\n    FOR(i,1,N) fx[i] = *min_element(c[i]+1,\
    \ c[i]+N+1);\n    FOR(j,1,N) {\n        fy[j] = c[1][j] - fx[1];\n        FOR(i,1,N)\
    \ {\n            fy[j] = min(fy[j], c[i][j] - fx[i]);\n        }\n    }\n    FOR(i,1,N)\
    \ {\n        start = i;\n        initBFS();\n        while (finish == 0) {\n \
    \           findAugPath();\n            if (!finish) subx_addy();\n        }\n\
    \        enlarge();\n    }\n    int res = 0;\n    FOR(i,1,N) res += c[i][mx[i]];\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Matching/HungarianLMH.h
  requiredBy: []
  timestamp: '2021-12-19 00:28:43+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Matching/HungarianLMH.h
layout: document
redirect_from:
- /library/Graph/Matching/HungarianLMH.h
- /library/Graph/Matching/HungarianLMH.h.html
title: Graph/Matching/HungarianLMH.h
---
