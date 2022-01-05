---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/minmove.h
    title: String/minmove.h
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
    \n#line 1 \"String/minmove.h\"\n// T\xEDnh v\u1ECB tr\xED c\u1EE7a x\xE2u xoay\
    \ v\xF2ng c\xF3 th\u1EE9 t\u1EF1 t\u1EEB \u0111i\u1EC3n nh\u1ECF nh\u1EA5t c\u1EE7\
    a x\xE2u s[]\nint minmove(string s) {\n    int n = s.length();\n    int x, y,\
    \ i, j, u, v; // x is the smallest string before string y\n    for (x = 0, y =\
    \ 1; y < n; ++ y) {\n        i = u = x;\n        j = v = y;\n        while (s[i]\
    \ == s[j]) {\n            ++ u; ++ v;\n            if (++ i == n) i = 0;\n   \
    \         if (++ j == n) j = 0;\n            if (i == x) break; // All strings\
    \ are equal\n        }\n        if (s[i] <= s[j]) y = v;\n        else {\n   \
    \         x = y;\n            if (u > y) y = u;\n        }\n    }\n    return\
    \ x;\n}\n#line 3 \"String/minmove.cpp\"\n\nint main() {\n    cout << minmove(\"\
    mississippi\") << endl; // 10\n    cout << minmove(\"cdefab\") << endl; // 4\n\
    \    cout << minmove(\"zzzzzz\") << endl; // 0\n}\n"
  code: "#include \"../template.h\"\n#include \"minmove.h\"\n\nint main() {\n    cout\
    \ << minmove(\"mississippi\") << endl; // 10\n    cout << minmove(\"cdefab\")\
    \ << endl; // 4\n    cout << minmove(\"zzzzzz\") << endl; // 0\n}\n"
  dependsOn:
  - template.h
  - String/minmove.h
  isVerificationFile: false
  path: String/minmove.cpp
  requiredBy: []
  timestamp: '2015-02-19 17:45:08+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/minmove.cpp
layout: document
redirect_from:
- /library/String/minmove.cpp
- /library/String/minmove.cpp.html
title: String/minmove.cpp
---
