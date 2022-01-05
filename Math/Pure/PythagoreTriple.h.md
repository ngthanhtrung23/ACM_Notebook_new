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
  bundledCode: "#line 1 \"Math/Pure/PythagoreTriple.h\"\n// sinh bo 3 pytago nguyen\
    \ thuy voi x, y, z <= n\nvector< vector<int> > genPrimitivePytTriples(int n) {\n\
    \    vector< vector<int> > ret;\n    for (int r=1; r*r<=n; ++r) for (int s=(r%2==0)?1:2;\
    \ s<r; s+=2) if (__gcd(r,s)==1) {\n        vector<int> t;\n        t.push_back(r*r+s*s);\
    \ //z \n        t.push_back(2*r*s); // y\n        t.push_back(r*r-s*s); // x\n\
    \        if (t[0]<=n) ret.push_back(t);        \n    }\n    sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n// a^2 + b^2 == c^2\n// To generate all primitive\
    \ triples:\n// a = m^2 - n^2, b = 2mn, c = m^2 + n^2 (m > n)\n// Primitive triples\
    \ iff gcd(m, n) == 1 && (m - n) % 2 == 1\n"
  code: "// sinh bo 3 pytago nguyen thuy voi x, y, z <= n\nvector< vector<int> > genPrimitivePytTriples(int\
    \ n) {\n    vector< vector<int> > ret;\n    for (int r=1; r*r<=n; ++r) for (int\
    \ s=(r%2==0)?1:2; s<r; s+=2) if (__gcd(r,s)==1) {\n        vector<int> t;\n  \
    \      t.push_back(r*r+s*s); //z \n        t.push_back(2*r*s); // y\n        t.push_back(r*r-s*s);\
    \ // x\n        if (t[0]<=n) ret.push_back(t);        \n    }\n    sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n// a^2 + b^2 == c^2\n// To generate all primitive\
    \ triples:\n// a = m^2 - n^2, b = 2mn, c = m^2 + n^2 (m > n)\n// Primitive triples\
    \ iff gcd(m, n) == 1 && (m - n) % 2 == 1\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Pure/PythagoreTriple.h
  requiredBy: []
  timestamp: '2015-02-02 18:15:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Pure/PythagoreTriple.h
layout: document
redirect_from:
- /library/Math/Pure/PythagoreTriple.h
- /library/Math/Pure/PythagoreTriple.h.html
title: Math/Pure/PythagoreTriple.h
---
