---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Polynomial/NTT.h
    title: Math/Polynomial/NTT.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"Math/tests/ntt.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/Polynomial/NTT.h\"\
    \n// Copied from chemthan\n// 2x slower than atcoder library\n// Tested:\n// -\
    \ https://oj.vnoi.info/problem/icpc21_mt_d\n// - https://judge.yosupo.jp/problem/convolution_mod\n\
    // - https://judge.yosupo.jp/problem/convolution_mod_1000000007\n//\n// Sample\
    \ usage: Multiply big-int polynomials using NTT + CRT\n//   NTT<MOD0, 1 << 21>\
    \ ntt0;\n//   NTT<MOD1, 1 << 21> ntt1;\n//   auto r0 = ntt0.multiply(v1, v2);\n\
    //   auto r1 = ntt1.multiply(v1, v2);\n//\n//   // Using CRT to combine r0 and\
    \ r1\n//   CRT<int> crt;\n//   crt.add(MOD0, r0[idx]);\n//   crt.add(MOD1, r1[idx]);\n\
    //   cout << crt.res << endl;\n\n// mod must be NTT mod\n// maxf = max degree\
    \ of c. Should be 2^k?\ntemplate<const int mod, const int maxf>\nstruct NTT {\n\
    \    NTT() {\n        int k = 0; while ((1 << k) < maxf) k++;\n        bitrev[0]\
    \ = 0;\n        for (int i = 1; i < maxf; i++) {\n            bitrev[i] = bitrev[i\
    \ >> 1] >> 1 | ((i & 1) << (k - 1));\n        }\n        int pw = fpow(prt(),\
    \ (mod - 1) / maxf);\n        rts[0] = 1;\n        for (int i = 1; i <= maxf;\
    \ i++) {\n            rts[i] = (long long) rts[i - 1] * pw % mod;\n        }\n\
    \        for (int i = 1; i <= maxf; i <<= 1) {\n            iv[i] = fpow(i, mod\
    \ - 2);\n        }\n    }\n\n    vector<int> multiply(vector<int> a, vector<int>\
    \ b) {\n        static int fa[maxf], fb[maxf], fc[maxf];\n        int na = a.size(),\
    \ nb = b.size();\n        for (int i = 0; i < na; i++) fa[i] = a[i];\n       \
    \ for (int i = 0; i < nb; i++) fb[i] = b[i];\n        multiply(fa, fb, na, nb,\
    \ fc);\n        int k = na + nb - 1;\n        vector<int> res(k);\n        for\
    \ (int i = 0; i < k; i++) res[i] = fc[i];\n        return res;\n    }\n\nprivate:\n\
    \    int rts[maxf + 1];\n    int bitrev[maxf];\n    int iv[maxf + 1];\n\n    int\
    \ fpow(int a, int k) {\n        if (!k) return 1;\n        int res = a, tmp =\
    \ a;\n        k--;\n        while (k) {\n            if (k & 1) {\n          \
    \      res = (long long) res * tmp % mod;\n            }\n            tmp = (long\
    \ long) tmp * tmp % mod;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n    int prt() {\n        vector<int> dvs;\n        for (int i = 2; i *\
    \ i < mod; i++) {\n            if ((mod - 1) % i) continue;\n            dvs.push_back(i);\n\
    \            if (i * i != mod - 1) dvs.push_back((mod - 1) / i);\n        }\n\
    \        for (int i = 2; i < mod; i++) {\n            int flag = 1;\n        \
    \    for (int j = 0; j < (int) dvs.size(); j++) {\n                if (fpow(i,\
    \ dvs[j]) == 1) {\n                    flag = 0;\n                    break;\n\
    \                }\n            }\n            if (flag) return i;\n        }\n\
    \        assert(0);\n        return -1;\n    }\n    void dft(int a[], int n, int\
    \ sign) {\n        int d = 0; while ((1 << d) * n != maxf) d++;\n        for (int\
    \ i = 0; i < n; i++) {\n            if (i < (bitrev[i] >> d)) {\n            \
    \    swap(a[i], a[bitrev[i] >> d]);\n            }\n        }\n        for (int\
    \ len = 2; len <= n; len <<= 1) {\n            int delta = maxf / len * sign;\n\
    \            for (int i = 0; i < n; i += len) {\n                int *w = sign\
    \ > 0 ? rts : rts + maxf;\n                for (int k = 0; k + k < len; k++) {\n\
    \                    int &a1 = a[i + k + (len >> 1)], &a2 = a[i + k];\n      \
    \              int t = (long long) *w * a1 % mod;\n                    a1 = a2\
    \ - t;\n                    a2 = a2 + t;\n                    a1 += a1 < 0 ? mod\
    \ : 0;\n                    a2 -= a2 >= mod ? mod : 0;\n                    w\
    \ += delta;\n                }\n            }\n        }\n        if (sign < 0)\
    \ {\n            int in = iv[n];\n            for (int i = 0; i < n; i++) {\n\
    \                a[i] = (long long) a[i] * in % mod;\n            }\n        }\n\
    \    }\n    void multiply(int a[], int b[], int na, int nb, int c[]) {\n     \
    \   static int fa[maxf], fb[maxf];\n        int n = na + nb - 1; while (n != (n\
    \ & -n)) n += n & -n;\n        for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;\n\
    \        for (int i = 0; i < na; i++) fa[i] = a[i];\n        for (int i = 0; i\
    \ < nb; i++) fb[i] = b[i];\n        dft(fa, n, 1), dft(fb, n, 1);\n        for\
    \ (int i = 0; i < n; i++) fa[i] = (long long) fa[i] * fb[i] % mod;\n        dft(fa,\
    \ n, -1);\n        for (int i = 0; i < n; i++) c[i] = fa[i];\n    }\n};\n\n/*\
    \ Examples\nconst int MOD0 = 1004535809; //2^21 * 479 + 1\nconst int MOD1 = 1012924417;\
    \ //2^21 * 483 + 1\nconst int MOD2 = 998244353;  //2^20 * 476 + 1\nNTT<MOD0, 1\
    \ << 21> ntt0;\nNTT<MOD1, 1 << 21> ntt1;\n*/\n#line 7 \"Math/tests/ntt.test.cpp\"\
    \n\nNTT<998244353, 1<<20> ntt;\n\n#define REP(i, a) for (int i = 0, _##i = (a);\
    \ i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, m; cin >> n >> m;\n    vector<int> a(n); REP(i,n) cin >> a[i];\n \
    \   vector<int> b(m); REP(i,m) cin >> b[i];\n\n    auto c = ntt.multiply(a, b);\n\
    \    for (int x : c) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Polynomial/NTT.h\"\n\n\
    NTT<998244353, 1<<20> ntt;\n\n#define REP(i, a) for (int i = 0, _##i = (a); i\
    \ < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, m; cin >> n >> m;\n    vector<int> a(n); REP(i,n) cin >> a[i];\n \
    \   vector<int> b(m); REP(i,m) cin >> b[i];\n\n    auto c = ntt.multiply(a, b);\n\
    \    for (int x : c) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - Math/Polynomial/NTT.h
  isVerificationFile: true
  path: Math/tests/ntt.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 18:30:35+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/ntt.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/ntt.test.cpp
- /verify/Math/tests/ntt.test.cpp.html
title: Math/tests/ntt.test.cpp
---
