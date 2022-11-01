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
    - https://oj.vnoi.info/problem/icpc22_mn_d
  bundledCode: "#line 1 \"String/PalindromeTree_eertree.cpp\"\n// Palindrome Tree\
    \ {{{\n// Notes:\n// - number of *distinct* palindrome substring <= N\n// Tested:\n\
    // - https://oj.vnoi.info/problem/icpc22_mn_d\ntemplate<int MAXC = 26>\nstruct\
    \ PalindromicTree {\n    PalindromicTree(const string& str)\n            : _sz(str.size()\
    \ + 5),\n              next(_sz, vector<int> (MAXC, 0)),\n              link(_sz,\
    \ 0), qlink(_sz, 0),\n              cnt(_sz, 0), right_id(_sz, 0),\n         \
    \     len(_sz, 0), s(_sz, 0) {\n        init();\n        for (int i = 0; i < (int)\
    \ str.size(); ++i) {\n            add(str[i], i);\n        }\n        count();\n\
    \    }\n    int _sz;\n\n    // returns vector of (left, right, frequency)\n  \
    \  vector<tuple<int,int,int>> get_palindromes() {\n        vector<tuple<int,int,int>>\
    \ res;\n        dfs(0, res);\n        dfs(1, res);\n        return res;\n    }\n\
    \n    void dfs(int u, vector<tuple<int,int,int>>& res) {\n        if (u > 1) {\
    \  // u = 0 and u = 1 are two empty nodes\n            res.emplace_back(right_id[u]\
    \ - len[u] + 1, right_id[u], cnt[u]);\n        }\n        for (int i = 0; i <\
    \ MAXC; ++i) {\n            if (next[u][i]) dfs(next[u][i], res);\n        }\n\
    \    }\n\n    int last, n, p;\n    vector<vector<int>> next, dlink;\n    vector<int>\
    \ link, qlink, cnt, right_id, len, s;\n\n    int newnode(int l, int right) {\n\
    \        len[p] = l;\n        right_id[p] = right;\n        return p++;\n    }\n\
    \    void init() {\n        p = 0;\n        newnode(0, -1), newnode(-1, -1);\n\
    \        n = last = 0;\n        s[n] = -1, link[0] = 1;\n    }\n    int getlink(int\
    \ x) {\n        while (s[n - len[x] - 1] != s[n]) {\n            if (s[n - len[link[x]]\
    \ - 1] == s[n]) x = link[x];\n            else x = qlink[x];\n        }\n    \
    \    return x;\n    }\n    void add(char c, int right) {\n        c -= 'a';\n\
    \        s[++n] = c;\n        int cur = getlink(last);\n        if (!next[cur][(int)\
    \ c]) {\n            int now = newnode(len[cur] + 2, right);\n            link[now]\
    \ = next[getlink(link[cur])][(int) c];\n            next[cur][(int) c] = now;\n\
    \            if (s[n - len[link[now]]] == s[n - len[link[link[now]]]]) {\n   \
    \             qlink[now] = qlink[link[now]];\n            }\n            else\
    \ {\n                qlink[now] = link[link[now]];\n            }\n        }\n\
    \        last = next[cur][(int) c];\n        cnt[last]++;\n    }\n    void count()\
    \ {\n        for (int i = p - 1; i >= 0; i--) {\n            cnt[link[i]] += cnt[i];\n\
    \        }\n    }\n};\n// }}}\n"
  code: "// Palindrome Tree {{{\n// Notes:\n// - number of *distinct* palindrome substring\
    \ <= N\n// Tested:\n// - https://oj.vnoi.info/problem/icpc22_mn_d\ntemplate<int\
    \ MAXC = 26>\nstruct PalindromicTree {\n    PalindromicTree(const string& str)\n\
    \            : _sz(str.size() + 5),\n              next(_sz, vector<int> (MAXC,\
    \ 0)),\n              link(_sz, 0), qlink(_sz, 0),\n              cnt(_sz, 0),\
    \ right_id(_sz, 0),\n              len(_sz, 0), s(_sz, 0) {\n        init();\n\
    \        for (int i = 0; i < (int) str.size(); ++i) {\n            add(str[i],\
    \ i);\n        }\n        count();\n    }\n    int _sz;\n\n    // returns vector\
    \ of (left, right, frequency)\n    vector<tuple<int,int,int>> get_palindromes()\
    \ {\n        vector<tuple<int,int,int>> res;\n        dfs(0, res);\n        dfs(1,\
    \ res);\n        return res;\n    }\n\n    void dfs(int u, vector<tuple<int,int,int>>&\
    \ res) {\n        if (u > 1) {  // u = 0 and u = 1 are two empty nodes\n     \
    \       res.emplace_back(right_id[u] - len[u] + 1, right_id[u], cnt[u]);\n   \
    \     }\n        for (int i = 0; i < MAXC; ++i) {\n            if (next[u][i])\
    \ dfs(next[u][i], res);\n        }\n    }\n\n    int last, n, p;\n    vector<vector<int>>\
    \ next, dlink;\n    vector<int> link, qlink, cnt, right_id, len, s;\n\n    int\
    \ newnode(int l, int right) {\n        len[p] = l;\n        right_id[p] = right;\n\
    \        return p++;\n    }\n    void init() {\n        p = 0;\n        newnode(0,\
    \ -1), newnode(-1, -1);\n        n = last = 0;\n        s[n] = -1, link[0] = 1;\n\
    \    }\n    int getlink(int x) {\n        while (s[n - len[x] - 1] != s[n]) {\n\
    \            if (s[n - len[link[x]] - 1] == s[n]) x = link[x];\n            else\
    \ x = qlink[x];\n        }\n        return x;\n    }\n    void add(char c, int\
    \ right) {\n        c -= 'a';\n        s[++n] = c;\n        int cur = getlink(last);\n\
    \        if (!next[cur][(int) c]) {\n            int now = newnode(len[cur] +\
    \ 2, right);\n            link[now] = next[getlink(link[cur])][(int) c];\n   \
    \         next[cur][(int) c] = now;\n            if (s[n - len[link[now]]] ==\
    \ s[n - len[link[link[now]]]]) {\n                qlink[now] = qlink[link[now]];\n\
    \            }\n            else {\n                qlink[now] = link[link[now]];\n\
    \            }\n        }\n        last = next[cur][(int) c];\n        cnt[last]++;\n\
    \    }\n    void count() {\n        for (int i = p - 1; i >= 0; i--) {\n     \
    \       cnt[link[i]] += cnt[i];\n        }\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/PalindromeTree_eertree.cpp
  requiredBy: []
  timestamp: '2022-11-01 16:26:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/PalindromeTree_eertree.cpp
layout: document
redirect_from:
- /library/String/PalindromeTree_eertree.cpp
- /library/String/PalindromeTree_eertree.cpp.html
title: String/PalindromeTree_eertree.cpp
---
