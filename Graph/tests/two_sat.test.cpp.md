---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/2sat.h
    title: Graph/2sat.h
  - icon: ':heavy_check_mark:'
    path: Graph/DfsTree/StronglyConnected.h
    title: Graph/DfsTree/StronglyConnected.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"Graph/tests/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/DfsTree/StronglyConnected.h\"\
    \n// Index from 0\n// Usage:\n// DirectedDfs tree;\n// Now you can use tree.scc\n\
    //\n// Note: reverse(tree.scc) is topo sorted\n//\n// Tested:\n// - (requires\
    \ scc to be topo sorted) https://judge.yosupo.jp/problem/scc\nstruct DirectedDfs\
    \ {\n    vector<vector<int>> g;\n    int n;\n    vector<int> num, low, current,\
    \ S;\n    int counter;\n    vector<int> comp_ids;\n    vector< vector<int> > scc;\n\
    \n    DirectedDfs(const vector<vector<int>>& _g) : g(_g), n(g.size()),\n     \
    \       num(n, -1), low(n, 0), current(n, 0), counter(0), comp_ids(n, -1) {\n\
    \        for (int i = 0; i < n; i++) {\n            if (num[i] == -1) dfs(i);\n\
    \        }\n    }\n\n    void dfs(int u) {\n        low[u] = num[u] = counter++;\n\
    \        S.push_back(u);\n        current[u] = 1;\n        for (auto v : g[u])\
    \ {\n            if (num[v] == -1) dfs(v);\n            if (current[v]) low[u]\
    \ = min(low[u], low[v]);\n        }\n        if (low[u] == num[u]) {\n       \
    \     scc.push_back(vector<int>());\n            while (1) {\n               \
    \ int v = S.back(); S.pop_back(); current[v] = 0;\n                scc.back().push_back(v);\n\
    \                comp_ids[v] = ((int) scc.size()) - 1;\n                if (u\
    \ == v) break;\n            }\n        }\n    }\n};\n#line 1 \"Graph/2sat.h\"\n\
    // For lexicographical min result:\n// - For each variable: check if it can be\
    \ set to False\n//   (by adding constraint i -> !i)\n// - If solver.solve() ->\
    \ keep constraint i -> !i\n// - Otherwise, remove constraint i -> !i, and add\
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
    };\n#line 8 \"Graph/tests/two_sat.test.cpp\"\n\n#define REP(i, a) for (int i =\
    \ 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    string wtf; cin >> wtf >> wtf;\n    int n, m; cin >> n >> m;\n\
    \    TwoSatSolver solver(n);\n    while (m--) {\n        int x, y; cin >> x >>\
    \ y >> wtf;\n        solver.x_or_y_constraint(x > 0, std::abs(x) - 1, y > 0, std::abs(y)\
    \ - 1);\n    }\n    auto [has_solution, sol] = solver.solve();\n    if (has_solution)\
    \ {\n        cout << \"s SATISFIABLE\" << endl;\n        cout << \"v \";\n   \
    \     REP(i,n) {\n            if (sol[i]) cout << i+1;\n            else cout\
    \ << \"-\" << (i+1);\n            cout << ' ';\n        }\n        cout << 0 <<\
    \ endl;\n    } else {\n        cout << \"s UNSATISFIABLE\" << endl;\n    }\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../DfsTree/StronglyConnected.h\"\n#include\
    \ \"../2sat.h\"\n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    string wtf;\
    \ cin >> wtf >> wtf;\n    int n, m; cin >> n >> m;\n    TwoSatSolver solver(n);\n\
    \    while (m--) {\n        int x, y; cin >> x >> y >> wtf;\n        solver.x_or_y_constraint(x\
    \ > 0, std::abs(x) - 1, y > 0, std::abs(y) - 1);\n    }\n    auto [has_solution,\
    \ sol] = solver.solve();\n    if (has_solution) {\n        cout << \"s SATISFIABLE\"\
    \ << endl;\n        cout << \"v \";\n        REP(i,n) {\n            if (sol[i])\
    \ cout << i+1;\n            else cout << \"-\" << (i+1);\n            cout <<\
    \ ' ';\n        }\n        cout << 0 << endl;\n    } else {\n        cout << \"\
    s UNSATISFIABLE\" << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/DfsTree/StronglyConnected.h
  - Graph/2sat.h
  isVerificationFile: true
  path: Graph/tests/two_sat.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 22:41:11+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/two_sat.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/two_sat.test.cpp
- /verify/Graph/tests/two_sat.test.cpp.html
title: Graph/tests/two_sat.test.cpp
---
