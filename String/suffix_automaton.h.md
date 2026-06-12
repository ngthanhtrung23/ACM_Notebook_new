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
  bundledCode: "#line 1 \"String/suffix_automaton.h\"\nstruct Node {\n    int len,\
    \ link; // len = max length of suffix in this class\n    int next[33];\n};\nNode\
    \ s[MN * 2];\nset< pair<int,int> > order; // in most application we'll need to\
    \ sort by len\nstruct Automaton {\n    int sz, last;\n    Automaton() {\n\t\t\
    order.clear();\n        sz = last = 0;\n        s[0].len = 0;\n        s[0].link\
    \ = -1;\n        ++sz;\n        // need to reset next if necessary\n    }\n  \
    \  void extend(char c) {\n        c = c - 'A';\n        int cur = sz++, p;\n \
    \       s[cur].len = s[last].len + 1;\n        order.insert(make_pair(s[cur].len,\
    \ cur));\n\n        for(p = last; p != -1 && !s[p].next[c]; p = s[p].link)\n \
    \           s[p].next[c] = cur;\n        if (p == -1) s[cur].link = 0;\n     \
    \   else {\n            int q = s[p].next[c];\n            if (s[p].len + 1 ==\
    \ s[q].len) s[cur].link = q;\n            else {\n                int clone =\
    \ sz++;\n                s[clone].len = s[p].len + 1;\n                memcpy(s[clone].next,\
    \ s[q].next, sizeof(s[q].next));\n                s[clone].link = s[q].link;\n\
    \                order.insert(make_pair(s[clone].len, clone));\n\n           \
    \     for(; p != -1 && s[p].next[c] == q; p = s[p].link)\n                   \
    \ s[p].next[c] = clone;\n                s[q].link = s[cur].link = clone;\n  \
    \          }\n        }\n        last = cur;\n    }\n};\n// Construct:\n// Automaton\
    \ sa; for(char c : s) sa.extend(c);\n// 1. Number of distinct substr:\n//    -\
    \ Find number of different paths --> DFS on SA\n//    - f[u] = 1 + sum( f[v] for\
    \ v in s[u].next\n// 2. Number of occurrences of a substr:\n//    - Initially,\
    \ in extend: s[cur].cnt = 1; s[clone].cnt = 0;\n//    - for(it : reverse order)\n\
    //        p = nodes[it->second].link;\n//        nodes[p].cnt += nodes[it->second].cnt\n\
    // 3. Find total length of different substrings:\n//    - We have f[u] = number\
    \ of strings starting from node u\n//    - ans[u] = sum(ans[v] + d[v] for v in\
    \ next[u])\n// 4. Lexicographically k-th substring\n//    - Based on number of\
    \ different substring\n// 5. Smallest cyclic shift\n//    - Build SA of S+S, then\
    \ just follow smallest link\n// 6. Find first occurrence\n//    - firstpos[cur]\
    \ = len[cur] - 1, firstpos[clone] = firstpos[q]\n"
  code: "struct Node {\n    int len, link; // len = max length of suffix in this class\n\
    \    int next[33];\n};\nNode s[MN * 2];\nset< pair<int,int> > order; // in most\
    \ application we'll need to sort by len\nstruct Automaton {\n    int sz, last;\n\
    \    Automaton() {\n\t\torder.clear();\n        sz = last = 0;\n        s[0].len\
    \ = 0;\n        s[0].link = -1;\n        ++sz;\n        // need to reset next\
    \ if necessary\n    }\n    void extend(char c) {\n        c = c - 'A';\n     \
    \   int cur = sz++, p;\n        s[cur].len = s[last].len + 1;\n        order.insert(make_pair(s[cur].len,\
    \ cur));\n\n        for(p = last; p != -1 && !s[p].next[c]; p = s[p].link)\n \
    \           s[p].next[c] = cur;\n        if (p == -1) s[cur].link = 0;\n     \
    \   else {\n            int q = s[p].next[c];\n            if (s[p].len + 1 ==\
    \ s[q].len) s[cur].link = q;\n            else {\n                int clone =\
    \ sz++;\n                s[clone].len = s[p].len + 1;\n                memcpy(s[clone].next,\
    \ s[q].next, sizeof(s[q].next));\n                s[clone].link = s[q].link;\n\
    \                order.insert(make_pair(s[clone].len, clone));\n\n           \
    \     for(; p != -1 && s[p].next[c] == q; p = s[p].link)\n                   \
    \ s[p].next[c] = clone;\n                s[q].link = s[cur].link = clone;\n  \
    \          }\n        }\n        last = cur;\n    }\n};\n// Construct:\n// Automaton\
    \ sa; for(char c : s) sa.extend(c);\n// 1. Number of distinct substr:\n//    -\
    \ Find number of different paths --> DFS on SA\n//    - f[u] = 1 + sum( f[v] for\
    \ v in s[u].next\n// 2. Number of occurrences of a substr:\n//    - Initially,\
    \ in extend: s[cur].cnt = 1; s[clone].cnt = 0;\n//    - for(it : reverse order)\n\
    //        p = nodes[it->second].link;\n//        nodes[p].cnt += nodes[it->second].cnt\n\
    // 3. Find total length of different substrings:\n//    - We have f[u] = number\
    \ of strings starting from node u\n//    - ans[u] = sum(ans[v] + d[v] for v in\
    \ next[u])\n// 4. Lexicographically k-th substring\n//    - Based on number of\
    \ different substring\n// 5. Smallest cyclic shift\n//    - Build SA of S+S, then\
    \ just follow smallest link\n// 6. Find first occurrence\n//    - firstpos[cur]\
    \ = len[cur] - 1, firstpos[clone] = firstpos[q]\n"
  dependsOn: []
  isVerificationFile: false
  path: String/suffix_automaton.h
  requiredBy: []
  timestamp: '2016-03-23 04:08:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/suffix_automaton.h
layout: document
redirect_from:
- /library/String/suffix_automaton.h
- /library/String/suffix_automaton.h.html
title: String/suffix_automaton.h
---
