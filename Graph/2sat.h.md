---
data:
  _extendedDependsOn: []
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
    // #include \"DfsTree/StronglyConnected.h\"\nstruct TwoSatSolver {\n    TwoSatSolver(int\
    \ _n_vars) : n_vars(_n_vars), g(2*n_vars) {}\n\n    void x_or_y_constraint(bool\
    \ is_x_true, int x, bool is_y_true, int y) {\n        assert(x >= 0 && x < n_vars);\n\
    \        assert(y >= 0 && y < n_vars);\n        if (!is_x_true) x += n_vars;\n\
    \        if (!is_y_true) y += n_vars;\n        // x || y\n        // !x -> y\n\
    \        // !y -> x\n        g[(x + n_vars) % (2*n_vars)].push_back(y);\n    \
    \    g[(y + n_vars) % (2*n_vars)].push_back(x);\n    }\n\n    // Returns:\n  \
    \  // If no solution -> returns {false, {}}\n    // If has solution -> returns\
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
    // #include \"DfsTree/StronglyConnected.h\"\nstruct TwoSatSolver {\n    TwoSatSolver(int\
    \ _n_vars) : n_vars(_n_vars), g(2*n_vars) {}\n\n    void x_or_y_constraint(bool\
    \ is_x_true, int x, bool is_y_true, int y) {\n        assert(x >= 0 && x < n_vars);\n\
    \        assert(y >= 0 && y < n_vars);\n        if (!is_x_true) x += n_vars;\n\
    \        if (!is_y_true) y += n_vars;\n        // x || y\n        // !x -> y\n\
    \        // !y -> x\n        g[(x + n_vars) % (2*n_vars)].push_back(y);\n    \
    \    g[(y + n_vars) % (2*n_vars)].push_back(x);\n    }\n\n    // Returns:\n  \
    \  // If no solution -> returns {false, {}}\n    // If has solution -> returns\
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
  dependsOn: []
  isVerificationFile: false
  path: Graph/2sat.h
  requiredBy: []
  timestamp: '2022-01-09 22:41:11+08:00'
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
