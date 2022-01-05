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
  bundledCode: "#line 1 \"Math/NumberTheory/x_k_a.h\"\n//Find all x such that x^k=a(mod\
    \ n) n is pime\nint generator (int p) { //Return primirity root of prime p\n \
    \   vector<int> fact; int phi = p-1,  n = phi;\n    for (int i=2; i*i<=n; ++i)\n\
    \        if (n % i == 0) {\n            fact.push_back (i); \n            while\
    \ (n % i == 0)    n /= i;\n        }\n    if (n > 1)\n        fact.push_back (n);\
    \ \n    for (int res=2; res<=p; ++res) {\n        bool ok = true;\n        for\
    \ (size_t i=0; i<fact.size() && ok; ++i)\n            ok &= powMod (res, phi /\
    \ fact[i], p) != 1;\n        if (ok)  return res;\n    }\n    return -1;\n} \n\
    int main() { \n    int n, k, a; cin >> n >> k >> a;\n    if (a == 0) { puts (\"\
    1\\n0\");  return 0; } \n    int g = generator (n); \n    int sq = (int) sqrt\
    \ (n + .0) + 1;\n    vector < pair<int,int> > dec (sq);\n    for (int i=1; i<=sq;\
    \ ++i)\n    dec[i-1] = make_pair (powMod (g, int (i * sq * 1ll * k % (n - 1)),\
    \ n), i);\n    sort (dec.begin(), dec.end());\n    int any_ans = -1;\n    for\
    \ (int i=0; i<sq; ++i) {\n        int my = int (powMod (g, int (i * 1ll * k %\
    \ (n - 1)), n) * 1ll * a % n);\n        vector < pair<int,int> >::iterator it\
    \ =\n                  lower_bound (dec.begin(), dec.end(), make_pair (my, 0));\n\
    \        if (it != dec.end() && it->first == my) { \n            any_ans = it->second\
    \ * sq - i;\n            break;\n        }\n    }\n    if (any_ans == -1) { puts\
    \ (\"0\");  return 0; }\n    int delta = (n-1) / gcd (k, n-1);  vector<int> ans;\n\
    \    for (int cur=any_ans%delta; cur<n-1; cur+=delta) \n        ans.push_back\
    \ (powMod (g, cur, n));\n    sort (ans.begin(), ans.end());\n    for (size_t i=0;\
    \ i<ans.size(); ++i) printf (\"%d \", ans[i]);  \n}\n\n"
  code: "//Find all x such that x^k=a(mod n) n is pime\nint generator (int p) { //Return\
    \ primirity root of prime p\n    vector<int> fact; int phi = p-1,  n = phi;\n\
    \    for (int i=2; i*i<=n; ++i)\n        if (n % i == 0) {\n            fact.push_back\
    \ (i); \n            while (n % i == 0)    n /= i;\n        }\n    if (n > 1)\n\
    \        fact.push_back (n); \n    for (int res=2; res<=p; ++res) {\n        bool\
    \ ok = true;\n        for (size_t i=0; i<fact.size() && ok; ++i)\n           \
    \ ok &= powMod (res, phi / fact[i], p) != 1;\n        if (ok)  return res;\n \
    \   }\n    return -1;\n} \nint main() { \n    int n, k, a; cin >> n >> k >> a;\n\
    \    if (a == 0) { puts (\"1\\n0\");  return 0; } \n    int g = generator (n);\
    \ \n    int sq = (int) sqrt (n + .0) + 1;\n    vector < pair<int,int> > dec (sq);\n\
    \    for (int i=1; i<=sq; ++i)\n    dec[i-1] = make_pair (powMod (g, int (i *\
    \ sq * 1ll * k % (n - 1)), n), i);\n    sort (dec.begin(), dec.end());\n    int\
    \ any_ans = -1;\n    for (int i=0; i<sq; ++i) {\n        int my = int (powMod\
    \ (g, int (i * 1ll * k % (n - 1)), n) * 1ll * a % n);\n        vector < pair<int,int>\
    \ >::iterator it =\n                  lower_bound (dec.begin(), dec.end(), make_pair\
    \ (my, 0));\n        if (it != dec.end() && it->first == my) { \n            any_ans\
    \ = it->second * sq - i;\n            break;\n        }\n    }\n    if (any_ans\
    \ == -1) { puts (\"0\");  return 0; }\n    int delta = (n-1) / gcd (k, n-1); \
    \ vector<int> ans;\n    for (int cur=any_ans%delta; cur<n-1; cur+=delta) \n  \
    \      ans.push_back (powMod (g, cur, n));\n    sort (ans.begin(), ans.end());\n\
    \    for (size_t i=0; i<ans.size(); ++i) printf (\"%d \", ans[i]);  \n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/x_k_a.h
  requiredBy: []
  timestamp: '2015-02-02 18:15:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/x_k_a.h
layout: document
redirect_from:
- /library/Math/NumberTheory/x_k_a.h
- /library/Math/NumberTheory/x_k_a.h.html
title: Math/NumberTheory/x_k_a.h
---
