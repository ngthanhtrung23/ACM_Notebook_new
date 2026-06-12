---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/bipartite_coloring.test.cpp
    title: Graph/tests/bipartite_coloring.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/600/problem/F
    - https://judge.yosupo.jp/problem/bipartite_edge_coloring
    - https://judge.yosupo.jp/submission/11755
    - https://oj.vnoi.info/problem/nkdec
  bundledCode: "#line 1 \"Graph/bipartite_edge_coloring.h\"\n// Copied from https://judge.yosupo.jp/submission/11755\n\
    // Source: Benq\n//\n// Tested:\n// - https://codeforces.com/contest/600/problem/F\n\
    // - https://judge.yosupo.jp/problem/bipartite_edge_coloring\n// - https://oj.vnoi.info/problem/nkdec\n\
    \n// Credit: Benq\n// returns vector of {vertex, id of edge to vertex}\n// the\
    \ second element of the first pair is always -1\ntemplate<int N, bool directed>\
    \ struct Euler {\n    vector<pair<int, int>> adj[N];\n    vector<pair<int, int>>::iterator\
    \ iter[N];\n    bool in_vertex[N];\n    vector<int> nodes;\n    vector<bool> used;\n\
    \    Euler() { for (int i = 0; i < N; i++) in_vertex[i] = 0; }\n    vector<int>\
    \ ans;\n    void clear() {\n        for (auto &t: nodes) adj[t].clear(), in_vertex[t]\
    \ = 0;\n        nodes.clear(); used.clear(); ans.clear();\n    }\n    void add(int\
    \ x) {\n        if (in_vertex[x]) return;\n        in_vertex[x] = 1;\n       \
    \ nodes.push_back(x);\n    }\n    void add_edge(int a, int b) {\n        int m\
    \ = used.size();\n        used.push_back(0);\n        add(a); add(b);\n      \
    \  adj[a].emplace_back(b, m);\n        if (!directed) adj[b].emplace_back(a, m);\n\
    \    }\n    void go(int src) {\n        vector<pair<pair<int, int>,int>> ret,\
    \ s = {{{src, -1}, -1}};\n        // {{vertex, prev vertex}, edge label}\n   \
    \     while (s.size()) {\n            int x = s.back().first.first;\n        \
    \    auto& it = iter[x], en = end(adj[x]);\n            while (it != en && used[it->second])\
    \ it ++;\n            if (it == en) { // no more edges out of vertex\n       \
    \         if ((int)ret.size() && ret.back().first.second != x) exit(5);\n    \
    \            ret.push_back(s.back()), s.pop_back();\n            } else {\n  \
    \              s.push_back({{it->first,x},it->second});\n                used[it->second]\
    \ = 1;\n            }\n        }\n        for (int i = 0; i < (int)ret.size()\
    \ - 1; i++) ans.push_back(ret[i].second);\n        assert((int)ans.size() % 2\
    \ == 0);\n    }\n    array<vector<int>, 2> tour() {\n        for (auto &v: nodes)\
    \ {\n            assert(adj[v].size() % 2 == 0);\n            iter[v] = begin(adj[v]);\n\
    \        }\n        for (auto &v: nodes) for (auto &e: adj[v]) if (!used[e.second])\
    \ go(v);\n        array<vector<int>, 2> res;\n        for (int i = 0; i < (int)ans.size();\
    \ i++) res[i % 2].push_back(ans[i]);\n        return res;\n    }\n};\n\ntypedef\
    \ array<int, 2> T;\nstruct EdgeColoring {\n    int n; vector<T> ed;\n    Euler<N\
    \ * 2, 0> E; // at least 2 * n\n    array<vector<int>,2> split(vector<int> lab)\
    \ { // k is even, split into two parts\n        E.clear();\n        for (auto\
    \ &t: lab) E.add_edge(ed[t][0], ed[t][1]);\n        auto v = E.tour(); // get\
    \ half edges on each\n        for (int i = 0; i < 2; i++) for (auto &t: v[i])\
    \ t = lab[t];\n        return v;\n    }\n    vector<int> match(vector<int> lab)\
    \ { // find perfect matching in MlogM\n        assert((int)lab.size() && (int)lab.size()\
    \ % n == 0);\n        int k = (int)lab.size() / n;\n        int p = 0;\n     \
    \   while ((1 << p) < n * k) p ++;\n        int a = (1 << p) / k;\n        int\
    \ b = (1 << p) - k * a;\n        vector<int> cnt_good((int)lab.size(),a), cnt_bad(n,b);\
    \ // now each edge is adjacent to 2^t\n        for (; p; --p) { // divide by two!!\n\
    \            E.clear(); vector<int> tmp;\n            for (int i = 0; i < n *\
    \ k; i++) {\n                if (cnt_good[i] & 1) E.add_edge(ed[lab[i]][0], ed[lab[i]][1]),\
    \ tmp.push_back(i);\n                cnt_good[i] /= 2;\n            }\n      \
    \      int num_lab = tmp.size();\n            for (int i = 0; i < n; i++) {\n\
    \                if (cnt_bad[i] & 1) E.add_edge(i, n + i), tmp.push_back(i);\n\
    \                cnt_bad[i] /= 2;\n            }\n            array<vector<int>,\
    \ 2> x = E.tour();\n            T cnt = T();\n            for (int i = 0; i <\
    \ 2; i++) for (auto &t: x[i]) cnt[i] += t >= num_lab;\n            if (cnt[0]\
    \ > cnt[1]) swap(x[0], x[1]);\n            for (auto &t: x[0]) {\n           \
    \     if (t < num_lab) cnt_good[tmp[t]] ++;\n                else cnt_bad[tmp[t]]\
    \ ++;\n            }\n        }\n        vector<int> v;\n        for (int i =\
    \ 0; i < (int) lab.size(); i++) if (cnt_good[i]) v.push_back(lab[i]);\n      \
    \  assert((int)v.size() == n);\n        return v;\n    }\n    vector<bool> used;\n\
    \    vector<vector<int>> edge_color(vector<int> lab) { // regular bipartite graph!\n\
    \        assert((int)lab.size() % n == 0);\n        int k = (int)lab.size() /\
    \ n;\n        if (k == 0) return {};\n        if (k == 1) return {lab};\n    \
    \    if ( __builtin_popcount(k) == 1) {\n            array<vector<int>,2> p =\
    \ split(lab);\n            vector<vector<int>> a = edge_color(p[0]), b = edge_color(p[1]);\n\
    \            a.insert(end(a), b.begin(), b.end());\n            return a;\n  \
    \      }\n        if (k % 2 == 0) {\n            array<vector<int>, 2> p = split(lab);\n\
    \            auto a = edge_color(p[0]);\n            int cur = k/2;\n        \
    \    while ( __builtin_popcount(cur) > 1) {\n                cur ++;\n       \
    \         p[1].insert(end(p[1]),a.back().begin(), a.back().end());\n         \
    \       a.pop_back();\n            }\n            auto b = edge_color(p[1]);\n\
    \            a.insert(end(a),b.begin(), b.end());\n            return a;\n   \
    \     } else {\n            vector<int> v = match(lab);\n            for (auto\
    \ &t: v) used[t] = 1;\n            vector<int> LAB;\n            for (auto &t:\
    \ lab) if (!used[t]) LAB.push_back(t);\n            for (auto &t: v) used[t] =\
    \ 0;\n            auto a = edge_color(LAB);\n            a.push_back(v);\n   \
    \         return a;\n        }\n    }\n    // returns edge chromatic number, ans\
    \ contains the edge coloring(colors are 1 indexed)\n    // supports multiple edges\n\
    \    // 0 indexed, O(M log M)\n    int solve(vector<T> _ed, vector<int> &ans)\
    \ {\n        if (_ed.empty()) {\n            return 0;\n        }\n        T side\
    \ = T();\n        for (auto &t: _ed) for (int i = 0; i < 2; i++) side[i] = max(side[i],\
    \ t[i]+1);\n        vector<int> deg[2], cmp[2], sz[2];\n        for (int i = 0;\
    \ i < 2; i++) deg[i].resize(side[i]), cmp[i].resize(side[i]);\n        for (auto\
    \ &t: _ed) for (int i = 0; i < 2; i++) deg[i][t[i]] ++;\n        int k = 0;\n\
    \        for (int i = 0; i < 2; i++) for (auto &t: deg[i]) k = max(k, t);\n  \
    \      for (int s = 0; s < 2; s++) {\n            for (int i = 0; i < side[s];\
    \ ) {\n                sz[s].push_back(0);\n                while (i < side[s]\
    \ && sz[s].back() + deg[s][i] <= k) {\n                    cmp[s][i] = (int)sz[s].size()\
    \ - 1;\n                    sz[s].back() += deg[s][i++];\n                }\n\
    \            }\n        }\n        for (int i = 0; i < 2; i++) while (sz[i].size()\
    \ < sz[i ^ 1].size()) sz[i].push_back(0);\n        n = sz[0].size();\n       \
    \ for (auto &t: _ed) ed.push_back({cmp[0][t[0]], n + cmp[1][t[1]]});\n       \
    \ int ind = 0;\n        for (int i = 0; i < n; i++) {\n            while (sz[0][i]\
    \ < k) {\n                while (sz[1][ind] == k) ind ++;\n                sz[0][i]\
    \ ++, sz[1][ind] ++;\n                ed.push_back({i, n + ind});\n          \
    \  }\n        }\n        used.resize(n * k);\n        vector<int> lab(n * k);\n\
    \        iota(lab.begin(), lab.end(),0);\n        auto tmp = edge_color(lab);\n\
    \        ans.resize(_ed.size());\n        for (int i = 0; i < (int) tmp.size();\
    \ i++) {\n            for (auto x: tmp[i]) if (x < (int) _ed.size()) ans[x] =\
    \ i + 1;\n        }\n        return tmp.size();\n    }\n};\n"
  code: "// Copied from https://judge.yosupo.jp/submission/11755\n// Source: Benq\n\
    //\n// Tested:\n// - https://codeforces.com/contest/600/problem/F\n// - https://judge.yosupo.jp/problem/bipartite_edge_coloring\n\
    // - https://oj.vnoi.info/problem/nkdec\n\n// Credit: Benq\n// returns vector\
    \ of {vertex, id of edge to vertex}\n// the second element of the first pair is\
    \ always -1\ntemplate<int N, bool directed> struct Euler {\n    vector<pair<int,\
    \ int>> adj[N];\n    vector<pair<int, int>>::iterator iter[N];\n    bool in_vertex[N];\n\
    \    vector<int> nodes;\n    vector<bool> used;\n    Euler() { for (int i = 0;\
    \ i < N; i++) in_vertex[i] = 0; }\n    vector<int> ans;\n    void clear() {\n\
    \        for (auto &t: nodes) adj[t].clear(), in_vertex[t] = 0;\n        nodes.clear();\
    \ used.clear(); ans.clear();\n    }\n    void add(int x) {\n        if (in_vertex[x])\
    \ return;\n        in_vertex[x] = 1;\n        nodes.push_back(x);\n    }\n   \
    \ void add_edge(int a, int b) {\n        int m = used.size();\n        used.push_back(0);\n\
    \        add(a); add(b);\n        adj[a].emplace_back(b, m);\n        if (!directed)\
    \ adj[b].emplace_back(a, m);\n    }\n    void go(int src) {\n        vector<pair<pair<int,\
    \ int>,int>> ret, s = {{{src, -1}, -1}};\n        // {{vertex, prev vertex}, edge\
    \ label}\n        while (s.size()) {\n            int x = s.back().first.first;\n\
    \            auto& it = iter[x], en = end(adj[x]);\n            while (it != en\
    \ && used[it->second]) it ++;\n            if (it == en) { // no more edges out\
    \ of vertex\n                if ((int)ret.size() && ret.back().first.second !=\
    \ x) exit(5);\n                ret.push_back(s.back()), s.pop_back();\n      \
    \      } else {\n                s.push_back({{it->first,x},it->second});\n  \
    \              used[it->second] = 1;\n            }\n        }\n        for (int\
    \ i = 0; i < (int)ret.size() - 1; i++) ans.push_back(ret[i].second);\n       \
    \ assert((int)ans.size() % 2 == 0);\n    }\n    array<vector<int>, 2> tour() {\n\
    \        for (auto &v: nodes) {\n            assert(adj[v].size() % 2 == 0);\n\
    \            iter[v] = begin(adj[v]);\n        }\n        for (auto &v: nodes)\
    \ for (auto &e: adj[v]) if (!used[e.second]) go(v);\n        array<vector<int>,\
    \ 2> res;\n        for (int i = 0; i < (int)ans.size(); i++) res[i % 2].push_back(ans[i]);\n\
    \        return res;\n    }\n};\n\ntypedef array<int, 2> T;\nstruct EdgeColoring\
    \ {\n    int n; vector<T> ed;\n    Euler<N * 2, 0> E; // at least 2 * n\n    array<vector<int>,2>\
    \ split(vector<int> lab) { // k is even, split into two parts\n        E.clear();\n\
    \        for (auto &t: lab) E.add_edge(ed[t][0], ed[t][1]);\n        auto v =\
    \ E.tour(); // get half edges on each\n        for (int i = 0; i < 2; i++) for\
    \ (auto &t: v[i]) t = lab[t];\n        return v;\n    }\n    vector<int> match(vector<int>\
    \ lab) { // find perfect matching in MlogM\n        assert((int)lab.size() &&\
    \ (int)lab.size() % n == 0);\n        int k = (int)lab.size() / n;\n        int\
    \ p = 0;\n        while ((1 << p) < n * k) p ++;\n        int a = (1 << p) / k;\n\
    \        int b = (1 << p) - k * a;\n        vector<int> cnt_good((int)lab.size(),a),\
    \ cnt_bad(n,b); // now each edge is adjacent to 2^t\n        for (; p; --p) {\
    \ // divide by two!!\n            E.clear(); vector<int> tmp;\n            for\
    \ (int i = 0; i < n * k; i++) {\n                if (cnt_good[i] & 1) E.add_edge(ed[lab[i]][0],\
    \ ed[lab[i]][1]), tmp.push_back(i);\n                cnt_good[i] /= 2;\n     \
    \       }\n            int num_lab = tmp.size();\n            for (int i = 0;\
    \ i < n; i++) {\n                if (cnt_bad[i] & 1) E.add_edge(i, n + i), tmp.push_back(i);\n\
    \                cnt_bad[i] /= 2;\n            }\n            array<vector<int>,\
    \ 2> x = E.tour();\n            T cnt = T();\n            for (int i = 0; i <\
    \ 2; i++) for (auto &t: x[i]) cnt[i] += t >= num_lab;\n            if (cnt[0]\
    \ > cnt[1]) swap(x[0], x[1]);\n            for (auto &t: x[0]) {\n           \
    \     if (t < num_lab) cnt_good[tmp[t]] ++;\n                else cnt_bad[tmp[t]]\
    \ ++;\n            }\n        }\n        vector<int> v;\n        for (int i =\
    \ 0; i < (int) lab.size(); i++) if (cnt_good[i]) v.push_back(lab[i]);\n      \
    \  assert((int)v.size() == n);\n        return v;\n    }\n    vector<bool> used;\n\
    \    vector<vector<int>> edge_color(vector<int> lab) { // regular bipartite graph!\n\
    \        assert((int)lab.size() % n == 0);\n        int k = (int)lab.size() /\
    \ n;\n        if (k == 0) return {};\n        if (k == 1) return {lab};\n    \
    \    if ( __builtin_popcount(k) == 1) {\n            array<vector<int>,2> p =\
    \ split(lab);\n            vector<vector<int>> a = edge_color(p[0]), b = edge_color(p[1]);\n\
    \            a.insert(end(a), b.begin(), b.end());\n            return a;\n  \
    \      }\n        if (k % 2 == 0) {\n            array<vector<int>, 2> p = split(lab);\n\
    \            auto a = edge_color(p[0]);\n            int cur = k/2;\n        \
    \    while ( __builtin_popcount(cur) > 1) {\n                cur ++;\n       \
    \         p[1].insert(end(p[1]),a.back().begin(), a.back().end());\n         \
    \       a.pop_back();\n            }\n            auto b = edge_color(p[1]);\n\
    \            a.insert(end(a),b.begin(), b.end());\n            return a;\n   \
    \     } else {\n            vector<int> v = match(lab);\n            for (auto\
    \ &t: v) used[t] = 1;\n            vector<int> LAB;\n            for (auto &t:\
    \ lab) if (!used[t]) LAB.push_back(t);\n            for (auto &t: v) used[t] =\
    \ 0;\n            auto a = edge_color(LAB);\n            a.push_back(v);\n   \
    \         return a;\n        }\n    }\n    // returns edge chromatic number, ans\
    \ contains the edge coloring(colors are 1 indexed)\n    // supports multiple edges\n\
    \    // 0 indexed, O(M log M)\n    int solve(vector<T> _ed, vector<int> &ans)\
    \ {\n        if (_ed.empty()) {\n            return 0;\n        }\n        T side\
    \ = T();\n        for (auto &t: _ed) for (int i = 0; i < 2; i++) side[i] = max(side[i],\
    \ t[i]+1);\n        vector<int> deg[2], cmp[2], sz[2];\n        for (int i = 0;\
    \ i < 2; i++) deg[i].resize(side[i]), cmp[i].resize(side[i]);\n        for (auto\
    \ &t: _ed) for (int i = 0; i < 2; i++) deg[i][t[i]] ++;\n        int k = 0;\n\
    \        for (int i = 0; i < 2; i++) for (auto &t: deg[i]) k = max(k, t);\n  \
    \      for (int s = 0; s < 2; s++) {\n            for (int i = 0; i < side[s];\
    \ ) {\n                sz[s].push_back(0);\n                while (i < side[s]\
    \ && sz[s].back() + deg[s][i] <= k) {\n                    cmp[s][i] = (int)sz[s].size()\
    \ - 1;\n                    sz[s].back() += deg[s][i++];\n                }\n\
    \            }\n        }\n        for (int i = 0; i < 2; i++) while (sz[i].size()\
    \ < sz[i ^ 1].size()) sz[i].push_back(0);\n        n = sz[0].size();\n       \
    \ for (auto &t: _ed) ed.push_back({cmp[0][t[0]], n + cmp[1][t[1]]});\n       \
    \ int ind = 0;\n        for (int i = 0; i < n; i++) {\n            while (sz[0][i]\
    \ < k) {\n                while (sz[1][ind] == k) ind ++;\n                sz[0][i]\
    \ ++, sz[1][ind] ++;\n                ed.push_back({i, n + ind});\n          \
    \  }\n        }\n        used.resize(n * k);\n        vector<int> lab(n * k);\n\
    \        iota(lab.begin(), lab.end(),0);\n        auto tmp = edge_color(lab);\n\
    \        ans.resize(_ed.size());\n        for (int i = 0; i < (int) tmp.size();\
    \ i++) {\n            for (auto x: tmp[i]) if (x < (int) _ed.size()) ans[x] =\
    \ i + 1;\n        }\n        return tmp.size();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bipartite_edge_coloring.h
  requiredBy: []
  timestamp: '2022-01-06 03:56:46+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/bipartite_coloring.test.cpp
documentation_of: Graph/bipartite_edge_coloring.h
layout: document
redirect_from:
- /library/Graph/bipartite_edge_coloring.h
- /library/Graph/bipartite_edge_coloring.h.html
title: Graph/bipartite_edge_coloring.h
---
