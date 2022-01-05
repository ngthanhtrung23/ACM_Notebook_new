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
    - https://codeforces.com/blog/entry/94213
  bundledCode: "#line 1 \"DataStructure/STL/rope.cpp\"\n#include <bits/stdc++.h>\n\
    #include <ext/rope> // Slow (balanced BST)!!! do not abuse\nusing namespace std;\n\
    using namespace __gnu_cxx;\nint main() {\n    rope <int> v; //use as usual STL\
    \ container\n    int n, m;\n    cin >> n >> m;\n    for(int i = 1; i <= n; ++i)\n\
    \        v.push_back(i); //initialization\n    int l, r;\n    for(int i = 0; i\
    \ < m; ++i)\n    {\n        cin >> l >> r;\n        --l, --r;\n        rope <int>\
    \ cur = v.substr(l, r - l + 1);\n        v.erase(l, r - l + 1);\n        // Note:\
    \ if erase a single element, must use v.erase(i, 1).\n        // There is another\
    \ function v.erase(i) but it's wrong\n        // https://codeforces.com/blog/entry/94213\n\
    \        v.insert(v.mutable_begin(), cur);\n    }\n    for(rope <int>::iterator\
    \ it = v.mutable_begin(); it != v.mutable_end(); ++it)\n        cout << *it <<\
    \ \" \";\n}\n"
  code: "#include <bits/stdc++.h>\n#include <ext/rope> // Slow (balanced BST)!!! do\
    \ not abuse\nusing namespace std;\nusing namespace __gnu_cxx;\nint main() {\n\
    \    rope <int> v; //use as usual STL container\n    int n, m;\n    cin >> n >>\
    \ m;\n    for(int i = 1; i <= n; ++i)\n        v.push_back(i); //initialization\n\
    \    int l, r;\n    for(int i = 0; i < m; ++i)\n    {\n        cin >> l >> r;\n\
    \        --l, --r;\n        rope <int> cur = v.substr(l, r - l + 1);\n       \
    \ v.erase(l, r - l + 1);\n        // Note: if erase a single element, must use\
    \ v.erase(i, 1).\n        // There is another function v.erase(i) but it's wrong\n\
    \        // https://codeforces.com/blog/entry/94213\n        v.insert(v.mutable_begin(),\
    \ cur);\n    }\n    for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end();\
    \ ++it)\n        cout << *it << \" \";\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/STL/rope.cpp
  requiredBy: []
  timestamp: '2021-08-25 10:01:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/STL/rope.cpp
layout: document
redirect_from:
- /library/DataStructure/STL/rope.cpp
- /library/DataStructure/STL/rope.cpp.html
title: DataStructure/STL/rope.cpp
---
