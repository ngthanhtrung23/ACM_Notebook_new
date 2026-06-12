---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Misc/Die.cpp
    title: Misc/Die.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/Die.h\"\nconst int rotations[6][4] = {\n    {1, 4,\
    \ 0, 5}, // left\n    {1, 5, 0, 4}, // right\n    {4, 3, 5, 2}, // up\n    {4,\
    \ 2, 5, 3}, // down\n};\nstruct Die;\nmap<int, Die> dieMap;\nstruct Die {\n  \
    \  int arr[6]; /* 0 right, 1 left, 2 forward, 3 backward, 4 top, 5 bottom */\n\
    \    Die(){ REP(i,6) arr[i] = i; }\n    Die(int cipher) { // 0 -> 23\n       \
    \ if (dieMap.empty()) puts(\"Call openDie(die());\"); else (*this) = dieMap[cipher];\n\
    \    }\n    Die move(int dir) {\n        Die res = (*this);\n        int t = res.arr[rotations[dir][0]];\n\
    \        REP(i,3) res.arr[rotations[dir][i]] = res.arr[rotations[dir][i+1]];\n\
    \        res.arr[rotations[dir][3]] = t;\n        return res;\n    }\n    int\
    \ encrypt() { // 0 -> 23\n        int res = arr[0] * 4;\n        FOR(i,3,5) if\
    \ (arr[i] < arr[2]) res++;\n        return res;\n    }\n};\nvoid openDie(Die t)\
    \ {\n    dieMap[t.encrypt()] = t;\n    REP(dir,4) if (!dieMap.count(t.move(dir).encrypt()))\
    \ openDie(t.move(dir));\n}\n\n"
  code: "const int rotations[6][4] = {\n    {1, 4, 0, 5}, // left\n    {1, 5, 0, 4},\
    \ // right\n    {4, 3, 5, 2}, // up\n    {4, 2, 5, 3}, // down\n};\nstruct Die;\n\
    map<int, Die> dieMap;\nstruct Die {\n    int arr[6]; /* 0 right, 1 left, 2 forward,\
    \ 3 backward, 4 top, 5 bottom */\n    Die(){ REP(i,6) arr[i] = i; }\n    Die(int\
    \ cipher) { // 0 -> 23\n        if (dieMap.empty()) puts(\"Call openDie(die());\"\
    ); else (*this) = dieMap[cipher];\n    }\n    Die move(int dir) {\n        Die\
    \ res = (*this);\n        int t = res.arr[rotations[dir][0]];\n        REP(i,3)\
    \ res.arr[rotations[dir][i]] = res.arr[rotations[dir][i+1]];\n        res.arr[rotations[dir][3]]\
    \ = t;\n        return res;\n    }\n    int encrypt() { // 0 -> 23\n        int\
    \ res = arr[0] * 4;\n        FOR(i,3,5) if (arr[i] < arr[2]) res++;\n        return\
    \ res;\n    }\n};\nvoid openDie(Die t) {\n    dieMap[t.encrypt()] = t;\n    REP(dir,4)\
    \ if (!dieMap.count(t.move(dir).encrypt())) openDie(t.move(dir));\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Die.h
  requiredBy:
  - Misc/Die.cpp
  timestamp: '2014-10-15 21:19:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Die.h
layout: document
redirect_from:
- /library/Misc/Die.h
- /library/Misc/Die.h.html
title: Misc/Die.h
---
