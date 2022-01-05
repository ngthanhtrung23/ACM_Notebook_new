---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Misc/Die.h
    title: Misc/Die.h
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
    \n#line 1 \"Misc/Die.h\"\nconst int rotations[6][4] = {\n    {1, 4, 0, 5}, //\
    \ left\n    {1, 5, 0, 4}, // right\n    {4, 3, 5, 2}, // up\n    {4, 2, 5, 3},\
    \ // down\n};\nstruct Die;\nmap<int, Die> dieMap;\nstruct Die {\n    int arr[6];\
    \ /* 0 right, 1 left, 2 forward, 3 backward, 4 top, 5 bottom */\n    Die(){ REP(i,6)\
    \ arr[i] = i; }\n    Die(int cipher) { // 0 -> 23\n        if (dieMap.empty())\
    \ puts(\"Call openDie(die());\"); else (*this) = dieMap[cipher];\n    }\n    Die\
    \ move(int dir) {\n        Die res = (*this);\n        int t = res.arr[rotations[dir][0]];\n\
    \        REP(i,3) res.arr[rotations[dir][i]] = res.arr[rotations[dir][i+1]];\n\
    \        res.arr[rotations[dir][3]] = t;\n        return res;\n    }\n    int\
    \ encrypt() { // 0 -> 23\n        int res = arr[0] * 4;\n        FOR(i,3,5) if\
    \ (arr[i] < arr[2]) res++;\n        return res;\n    }\n};\nvoid openDie(Die t)\
    \ {\n    dieMap[t.encrypt()] = t;\n    REP(dir,4) if (!dieMap.count(t.move(dir).encrypt()))\
    \ openDie(t.move(dir));\n}\n\n#line 3 \"Misc/Die.cpp\"\nint main() {\n}\n"
  code: '#include "../template.h"

    #include "Die.h"

    int main() {

    }

    '
  dependsOn:
  - template.h
  - Misc/Die.h
  isVerificationFile: false
  path: Misc/Die.cpp
  requiredBy: []
  timestamp: '2015-02-19 17:45:08+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Die.cpp
layout: document
redirect_from:
- /library/Misc/Die.cpp
- /library/Misc/Die.cpp.html
title: Misc/Die.cpp
---
