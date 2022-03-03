---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DfsTree/StronglyConnected.h
    title: Graph/DfsTree/StronglyConnected.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/two_sat.test.cpp
    title: Graph/tests/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1684/
    - https://judge.yosupo.jp/problem/two_sat
    - https://oj.vnoi.info/problem/elect
    - https://oj.vnoi.info/problem/icpc21_mt_i
    - https://oj.vnoi.info/problem/twosat
    - https://open.kattis.com/problems/cleaningpipes
  bundledCode: "#line 1 \"Graph/2sat.h\"\n// For lexicographical min result:\n// -\
    \ For each variable: check if it can be set to False\n//   (by adding constraint\
    \ i -> !i)\n// - If solver.solve() -> keep constraint i -> !i\n// - Otherwise,\
    \ remove constraint i -> !i, and add !i -> i to force it to True\n// See https://oj.vnoi.info/problem/icpc21_mt_i\n\
    \n// Variables: 0 -> n-1\n// Tested:\n// - https://judge.yosupo.jp/problem/two_sat\n\
    // - https://oj.vnoi.info/problem/twosat\n// - https://oj.vnoi.info/problem/elect\n\
    // - https://open.kattis.com/problems/cleaningpipes\n// - https://oj.vnoi.info/problem/icpc21_mt_i\n\
    // - https://cses.fi/problemset/task/1684/\n#line 1 \"Graph/DfsTree/StronglyConnected.h\"\
    \n// Index from 0\n// Usage:\n// DirectedDfs tree;\n// Now you can use tree.scc\n\
    //\n// Note: reverse(tree.scc) is topo sorted\n//\n// Tested:\n// - (requires\
    \ scc to be topo sorted) https://judge.yosupo.jp/problem/scc\n// - https://cses.fi/problemset/task/1686/\n\
    struct DirectedDfs {\n    vector<vector<int>> g;\n    int n;\n    vector<int>\
    \ num, low, current, S;\n    int counter;\n    vector<int> comp_ids;\n    vector<\
    \ vector<int> > scc;\n\n    DirectedDfs(const vector<vector<int>>& _g) : g(_g),\
    \ n(g.size()),\n            num(n, -1), low(n, 0), current(n, 0), counter(0),\
    \ comp_ids(n, -1) {\n        for (int i = 0; i < n; i++) {\n            if (num[i]\
    \ == -1) dfs(i);\n        }\n    }\n\n    void dfs(int u) {\n        low[u] =\
    \ num[u] = counter++;\n        S.push_back(u);\n        current[u] = 1;\n    \
    \    for (auto v : g[u]) {\n            if (num[v] == -1) dfs(v);\n          \
    \  if (current[v]) low[u] = min(low[u], low[v]);\n        }\n        if (low[u]\
    \ == num[u]) {\n            scc.push_back(vector<int>());\n            while (1)\
    \ {\n                int v = S.back(); S.pop_back(); current[v] = 0;\n       \
    \         scc.back().push_back(v);\n                comp_ids[v] = ((int) scc.size())\
    \ - 1;\n                if (u == v) break;\n            }\n        }\n    }\n\n\
    \    // build DAG of strongly connected components\n    // Returns: adjacency\
    \ list of DAG\n    std::vector<std::vector<int>> build_scc_dag() {\n        std::vector<std::vector<int>>\
    \ dag(scc.size());\n        for (int u = 0; u < n; u++) {\n            int x =\
    \ comp_ids[u];\n            for (int v : g[u]) {\n                int y = comp_ids[v];\n\
    \                if (x != y) {\n                    dag[x].push_back(y);\n   \
    \             }\n            }\n        }\n        return dag;\n    }\n};\n#line\
    \ 17 \"Graph/2sat.h\"\nstruct TwoSatSolver {\n    TwoSatSolver(int _n_vars) :\
    \ n_vars(_n_vars), g(2*n_vars) {}\n\n    void x_or_y_constraint(bool is_x_true,\
    \ int x, bool is_y_true, int y) {\n        assert(x >= 0 && x < n_vars);\n   \
    \     assert(y >= 0 && y < n_vars);\n        if (!is_x_true) x += n_vars;\n  \
    \      if (!is_y_true) y += n_vars;\n        // x || y\n        // !x -> y\n \
    \       // !y -> x\n        g[(x + n_vars) % (2*n_vars)].push_back(y);\n     \
    \   g[(y + n_vars) % (2*n_vars)].push_back(x);\n    }\n\n    // Returns:\n   \
    \ // If no solution -> returns {false, {}}\n    // If has solution -> returns\
    \ {true, solution}\n    //    where |solution| = n_vars, solution = true / false\n\
    \    pair<bool, vector<bool>> solve() {\n        DirectedDfs tree(g);\n      \
    \  vector<bool> solution(n_vars);\n        for (int i = 0; i < n_vars; i++) {\n\
    \            if (tree.comp_ids[i] == tree.comp_ids[i + n_vars]) {\n          \
    \      return {false, {}};\n            }\n            // Note that reverse(tree.scc)\
    \ is topo sorted\n            solution[i] = tree.comp_ids[i] < tree.comp_ids[i\
    \ + n_vars];\n        }\n        return {true, solution};\n    }\n\n    // number\
    \ of variables\n    int n_vars;\n    // vertex 0 -> n_vars - 1: Ai is true\n \
    \   // vertex n_vars -> 2*n_vars - 1: Ai is false\n    vector<vector<int>> g;\n\
    };\n"
  code: "// For lexicographical min result:\n// - For each variable: check if it can\
    \ be set to False\n//   (by adding constraint i -> !i)\n// - If solver.solve()\
    \ -> keep constraint i -> !i\n// - Otherwise, remove constraint i -> !i, and add\
    \ !i -> i to force it to True\n// See https://oj.vnoi.info/problem/icpc21_mt_i\n\
    \n// Variables: 0 -> n-1\n// Tested:\n// - https://judge.yosupo.jp/problem/two_sat\n\
    // - https://oj.vnoi.info/problem/twosat\n// - https://oj.vnoi.info/problem/elect\n\
    // - https://open.kattis.com/problems/cleaningpipes\n// - https://oj.vnoi.info/problem/icpc21_mt_i\n\
    // - https://cses.fi/problemset/task/1684/\n#include \"DfsTree/StronglyConnected.h\"\
    \nstruct TwoSatSolver {\n    TwoSatSolver(int _n_vars) : n_vars(_n_vars), g(2*n_vars)\
    \ {}\n\n    void x_or_y_constraint(bool is_x_true, int x, bool is_y_true, int\
    \ y) {\n        assert(x >= 0 && x < n_vars);\n        assert(y >= 0 && y < n_vars);\n\
    \        if (!is_x_true) x += n_vars;\n        if (!is_y_true) y += n_vars;\n\
    \        // x || y\n        // !x -> y\n        // !y -> x\n        g[(x + n_vars)\
    \ % (2*n_vars)].push_back(y);\n        g[(y + n_vars) % (2*n_vars)].push_back(x);\n\
    \    }\n\n    // Returns:\n    // If no solution -> returns {false, {}}\n    //\
    \ If has solution -> returns {true, solution}\n    //    where |solution| = n_vars,\
    \ solution = true / false\n    pair<bool, vector<bool>> solve() {\n        DirectedDfs\
    \ tree(g);\n        vector<bool> solution(n_vars);\n        for (int i = 0; i\
    \ < n_vars; i++) {\n            if (tree.comp_ids[i] == tree.comp_ids[i + n_vars])\
    \ {\n                return {false, {}};\n            }\n            // Note that\
    \ reverse(tree.scc) is topo sorted\n            solution[i] = tree.comp_ids[i]\
    \ < tree.comp_ids[i + n_vars];\n        }\n        return {true, solution};\n\
    \    }\n\n    // number of variables\n    int n_vars;\n    // vertex 0 -> n_vars\
    \ - 1: Ai is true\n    // vertex n_vars -> 2*n_vars - 1: Ai is false\n    vector<vector<int>>\
    \ g;\n};\n"
  dependsOn:
  - Graph/DfsTree/StronglyConnected.h
  isVerificationFile: false
  path: Graph/2sat.h
  requiredBy: []
  timestamp: '2022-03-04 04:16:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/two_sat.test.cpp
documentation_of: Graph/2sat.h
layout: document
redirect_from:
- /library/Graph/2sat.h
- /library/Graph/2sat.h.html
title: Graph/2sat.h
---
