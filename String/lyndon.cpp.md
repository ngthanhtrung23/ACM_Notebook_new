---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/lyndon.h
    title: String/lyndon.h
  - icon: ':warning:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#include <bits/stdc++.h>\n\n#define FOR(i,a,b)\
    \ for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\nusing namespace std;\n\nint main() {\n    return 0;\n}\n\
    \n#line 1 \"String/lyndon.h\"\n// Decompose s = w1w2..wk : k max and w1 >= w2\
    \ >= ...\n// each wi is strictly smaller than all its rotation\nvoid lyndon(string\
    \ s) {\n    int n = (int) s.length();\n    int i = 0;\n    while (i < n) {\n \
    \       int j = i + 1, k = i;\n        while (j < n && s[k] <= s[j]) {\n     \
    \       if (s[k] < s[j]) k = i;\n            else ++k;\n            ++j;\n   \
    \     }\n        while (i <= k) {\n            cout << s.substr(i, j - k) << '\
    \ ';\n            i += j - k;\n        }\n    }\n    cout << endl;\n}\n#line 3\
    \ \"String/lyndon.cpp\"\n\nint main() {\n    lyndon(\"abcdef\"); // abcdef\n \
    \   lyndon(\"fedcba\"); // f e d c b a\n    lyndon(\"aaaaaa\"); // a a a a a a\n\
    \    lyndon(\"ababab\"); // ab ab ab\n}\n"
  code: "#include \"../template.h\"\n#include \"lyndon.h\"\n\nint main() {\n    lyndon(\"\
    abcdef\"); // abcdef\n    lyndon(\"fedcba\"); // f e d c b a\n    lyndon(\"aaaaaa\"\
    ); // a a a a a a\n    lyndon(\"ababab\"); // ab ab ab\n}\n"
  dependsOn:
  - template.h
  - String/lyndon.h
  isVerificationFile: false
  path: String/lyndon.cpp
  requiredBy: []
  timestamp: '2015-09-28 02:35:16+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/lyndon.cpp
layout: document
redirect_from:
- /library/String/lyndon.cpp
- /library/String/lyndon.cpp.html
title: String/lyndon.cpp
---
