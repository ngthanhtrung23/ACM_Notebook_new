---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/gym/100341
    - https://open.kattis.com/problems/polymul2
  bundledCode: "#line 1 \"Math/Polynomial/Karatsuba.h\"\n// Copied from team TwT514\
    \ (Shik + takaramono + coquelicot)\n// Tested:\n// - https://open.kattis.com/problems/polymul2\n\
    // - http://codeforces.com/gym/100341 - C\n// Notes:\n// - n must be power of\
    \ 2. Remember to memset a, b, c to 0\nll buf[10000000],*ptr=buf;\nvoid mul( int\
    \ n, ll *a, ll *b, ll *c ) {\n    if ( n<=32 ) {\n        REP(i,2*n) c[i]=0;\n\
    \        REP(i,n) REP(j,n) c[i+j]+=a[i]*b[j];\n        REP(i,2*n) c[i]%=MOD;\n\
    \        return;\n    }\n    int m=n/2;\n    ll *s1=ptr; ptr+=n;\n    ll *s2=ptr;\
    \ ptr+=n;\n    ll *s3=ptr; ptr+=n;\n    ll *aa=ptr; ptr+=m;\n    ll *bb=ptr; ptr+=m;\n\
    \    REP(i,m) {\n        aa[i]=a[i]+a[i+m];\n        bb[i]=b[i]+b[i+m];\n    \
    \    if ( aa[i]>=MOD ) aa[i]-=MOD;\n        if ( bb[i]>=MOD ) bb[i]-=MOD;\n  \
    \  }\n    mul(m,a,b,s1);\n    mul(m,a+m,b+m,s2);\n    mul(m,aa,bb,s3);\n    memcpy(c,s1,n*sizeof(ll));\n\
    \    memcpy(c+n,s2,n*sizeof(ll));\n    REP(i,n) c[i+m]+=s3[i]-s1[i]-s2[i];\n \
    \   REP(i,2*n) c[i]%=MOD;\n    ptr-=4*n;\n}\n// mul(2^x, a, b, c); REP(i,2*n)\
    \ c[i] = (c[i] % MOD + MOD) % MOD\n"
  code: "// Copied from team TwT514 (Shik + takaramono + coquelicot)\n// Tested:\n\
    // - https://open.kattis.com/problems/polymul2\n// - http://codeforces.com/gym/100341\
    \ - C\n// Notes:\n// - n must be power of 2. Remember to memset a, b, c to 0\n\
    ll buf[10000000],*ptr=buf;\nvoid mul( int n, ll *a, ll *b, ll *c ) {\n    if (\
    \ n<=32 ) {\n        REP(i,2*n) c[i]=0;\n        REP(i,n) REP(j,n) c[i+j]+=a[i]*b[j];\n\
    \        REP(i,2*n) c[i]%=MOD;\n        return;\n    }\n    int m=n/2;\n    ll\
    \ *s1=ptr; ptr+=n;\n    ll *s2=ptr; ptr+=n;\n    ll *s3=ptr; ptr+=n;\n    ll *aa=ptr;\
    \ ptr+=m;\n    ll *bb=ptr; ptr+=m;\n    REP(i,m) {\n        aa[i]=a[i]+a[i+m];\n\
    \        bb[i]=b[i]+b[i+m];\n        if ( aa[i]>=MOD ) aa[i]-=MOD;\n        if\
    \ ( bb[i]>=MOD ) bb[i]-=MOD;\n    }\n    mul(m,a,b,s1);\n    mul(m,a+m,b+m,s2);\n\
    \    mul(m,aa,bb,s3);\n    memcpy(c,s1,n*sizeof(ll));\n    memcpy(c+n,s2,n*sizeof(ll));\n\
    \    REP(i,n) c[i+m]+=s3[i]-s1[i]-s2[i];\n    REP(i,2*n) c[i]%=MOD;\n    ptr-=4*n;\n\
    }\n// mul(2^x, a, b, c); REP(i,2*n) c[i] = (c[i] % MOD + MOD) % MOD\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Polynomial/Karatsuba.h
  requiredBy: []
  timestamp: '2016-02-02 03:37:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Polynomial/Karatsuba.h
layout: document
redirect_from:
- /library/Math/Polynomial/Karatsuba.h
- /library/Math/Polynomial/Karatsuba.h.html
title: Math/Polynomial/Karatsuba.h
---
