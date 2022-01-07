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
    - https://cses.fi/problemset/task/1668
  bundledCode: "#line 1 \"Graph/bipartite_coloring.h\"\n// Bipartite coloring (color\
    \ graph with 2 colors)\n// Graph is 0-based\n// Returns:\n// - can color?\n//\
    \ - color, 1-based\n//\n// Tested:\n// - https://cses.fi/problemset/task/1668\n\
    pair<bool, vector<int>> bipartite_coloring(const vector<vector<int>>& g) {\n \
    \   int n = g.size();\n    vector<int> color(n, -1);\n\n    std::function<void(int)>\
    \ dfs = [&] (int u) {\n        for (int v : g[u]) {\n            if (color[v]\
    \ < 0) {\n                color[v] = 3 - color[u];\n                dfs(v);\n\
    \            } else if (color[u] == color[v]) {\n                throw 1;\n  \
    \          }\n        }\n    };\n\n    try {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (color[i] < 0) {\n                color[i] = 1;\n        \
    \        dfs(i);\n            }\n        }\n    } catch (...) {\n        return\
    \ {false, {}};\n    }\n\n    return {true, color};\n}\n\n"
  code: "// Bipartite coloring (color graph with 2 colors)\n// Graph is 0-based\n\
    // Returns:\n// - can color?\n// - color, 1-based\n//\n// Tested:\n// - https://cses.fi/problemset/task/1668\n\
    pair<bool, vector<int>> bipartite_coloring(const vector<vector<int>>& g) {\n \
    \   int n = g.size();\n    vector<int> color(n, -1);\n\n    std::function<void(int)>\
    \ dfs = [&] (int u) {\n        for (int v : g[u]) {\n            if (color[v]\
    \ < 0) {\n                color[v] = 3 - color[u];\n                dfs(v);\n\
    \            } else if (color[u] == color[v]) {\n                throw 1;\n  \
    \          }\n        }\n    };\n\n    try {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (color[i] < 0) {\n                color[i] = 1;\n        \
    \        dfs(i);\n            }\n        }\n    } catch (...) {\n        return\
    \ {false, {}};\n    }\n\n    return {true, color};\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bipartite_coloring.h
  requiredBy: []
  timestamp: '2022-01-07 14:06:07+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bipartite_coloring.h
layout: document
redirect_from:
- /library/Graph/bipartite_coloring.h
- /library/Graph/bipartite_coloring.h.html
title: Graph/bipartite_coloring.h
---
