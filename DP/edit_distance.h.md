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
  bundledCode: "#line 1 \"DP/edit_distance.h\"\n// Minimum number of operations to\
    \ transform string a => string b\n// In one operation, we can either modify 1\
    \ character, delete 1 character or\n// insert 1 character (insert is not needed\
    \ in this case)\n//\n// Edit distance {{{\nint edit_distance(std::string a, std::string\
    \ b) {\n    int la = a.size();\n    int lb = b.size();\n    a = \" \" + a + \"\
    \ \";\n    b = \" \" + b + \" \";\n\n    std::vector<std::vector<int>> f(la +\
    \ 1, std::vector<int> (lb + 1, la + lb));\n\n    // corner cases\n    for (int\
    \ j = 0; j <= lb; ++j) f[0][j] = j;\n    for (int i = 0; i <= la; ++i) f[i][0]\
    \ = i;\n\n    // DP\n    for (int i = 1; i <= la; ++i) {\n        for (int j =\
    \ 1; j <= lb; ++j) {\n            if (a[i] == b[j]) f[i][j] = f[i-1][j-1];\n \
    \           else f[i][j] = 1 + std::min({\n                    f[i-1][j-1],  //\
    \ modify\n                    f[i][j-1],    // remove b[j]\n                 \
    \   f[i-1][j],    // remove a[i]\n                    });\n        }\n    }\n\n\
    \    return f.back().back();\n}\n// }}}\n"
  code: "// Minimum number of operations to transform string a => string b\n// In\
    \ one operation, we can either modify 1 character, delete 1 character or\n// insert\
    \ 1 character (insert is not needed in this case)\n//\n// Edit distance {{{\n\
    int edit_distance(std::string a, std::string b) {\n    int la = a.size();\n  \
    \  int lb = b.size();\n    a = \" \" + a + \" \";\n    b = \" \" + b + \" \";\n\
    \n    std::vector<std::vector<int>> f(la + 1, std::vector<int> (lb + 1, la + lb));\n\
    \n    // corner cases\n    for (int j = 0; j <= lb; ++j) f[0][j] = j;\n    for\
    \ (int i = 0; i <= la; ++i) f[i][0] = i;\n\n    // DP\n    for (int i = 1; i <=\
    \ la; ++i) {\n        for (int j = 1; j <= lb; ++j) {\n            if (a[i] ==\
    \ b[j]) f[i][j] = f[i-1][j-1];\n            else f[i][j] = 1 + std::min({\n  \
    \                  f[i-1][j-1],  // modify\n                    f[i][j-1],   \
    \ // remove b[j]\n                    f[i-1][j],    // remove a[i]\n         \
    \           });\n        }\n    }\n\n    return f.back().back();\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/edit_distance.h
  requiredBy: []
  timestamp: '2022-12-26 15:37:34+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/edit_distance.h
layout: document
redirect_from:
- /library/DP/edit_distance.h
- /library/DP/edit_distance.h.html
title: DP/edit_distance.h
---
