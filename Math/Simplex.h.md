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
    - http://codeforces.com/gym/100216
  bundledCode: "#line 1 \"Math/Simplex.h\"\n// Tested:\n// - http://codeforces.com/gym/100216\
    \ - C\n// - SRM 676 - 1000\n// - SRM 694 - 900\n// m = # inequalities, n = #variables\n\
    // variables numbered from 0\n// C[0] = objective function (max)\n// C[1..m] =\
    \ leq equations:\n//    sum( C[i][j] * X[j] ) <= C[i][n]\n// Return: -INF if infeasible,\
    \ INF if unbounded, max otherwise\n#define MAXM 400 // leave one extra \n#define\
    \ MAXN 400 // leave one extra \n#define EPS 1e-9 \n#define INF 1.0/0.0 \ndouble\
    \ A[MAXM][MAXN]; \nint basis[MAXM], out[MAXN]; \nvoid pivot(int m, int n, int\
    \ a, int b) { \n    int i,j; \n    for (i=0;i<=m;i++) \n        if (i!=a) \n \
    \           for (j=0;j<=n;j++)\n                if (j!=b) \n                 \
    \   A[i][j] -= A[a][j] * A[i][b] / A[a][b]; \n    for (j=0;j<=n;j++) \n      \
    \  if (j!=b) A[a][j] /= A[a][b]; \n    for (i=0;i<=m;i++) \n        if (i!=a)\
    \ A[i][b] = -A[i][b]/A[a][b]; \n            A[a][b] = 1/A[a][b]; \n    swap(basis[a],\
    \ out[b]);\n} \ndouble simplex(int m, int n, double C[][MAXN], double X[]) { \n\
    \    int i,j,ii,jj; // i,ii are row indexes; j,jj are column indexes \n    for\
    \ (i=1;i<=m;i++) \n        for (j=0;j<=n;j++) \n            A[i][j] = C[i][j];\
    \ \n    for (j=0;j<=n;j++) A[0][j] = -C[0][j]; \n    for (i=0;i<=m;i++) basis[i]\
    \ = -i; \n    for (j=0;j<=n;j++) out[j] = j; \n    for(;;) { \n        for (i=ii=1;i<=m;i++)\
    \ \n            if (A[i][n]<A[ii][n] || (A[i][n]==A[ii][n] && basis[i]<basis[ii]))\
    \ \n                ii=i; \n        if (A[ii][n] >= -EPS) break; \n        for\
    \ (j=jj=0;j<n;j++) \n            if (A[ii][j]<A[ii][jj]-EPS || (A[ii][j]<A[ii][jj]-EPS\
    \ && out[i]<out[j])) \n                jj=j;\n        if (A[ii][jj] >= -EPS) return\
    \ -INF; \n        pivot(m,n,ii,jj); \n    } \n    for(;;) { \n        for (j=jj=0;j<n;j++)\
    \ \n            if (A[0][j]<A[0][jj] || (A[0][j]==A[0][jj] && out[j]<out[jj]))\
    \ \n                jj=j; \n        if (A[0][jj] > -EPS) break; \n        for\
    \ (i=1,ii=0;i<=m;i++) \n            if ((A[i][jj]>EPS) && \n                 \
    \   (!ii || (A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]-EPS) || \n                ((A[i][n]/A[i][jj]\
    \ < A[ii][n]/A[ii][jj]+EPS) && (basis[i] < basis[ii])))) \n            ii=i; \n\
    \        if (A[ii][jj] <= EPS) return INF; \n        pivot(m,n,ii,jj); \n    }\
    \ \n    for (j=0;j<n;j++)\n        X[j] = 0; \n    for (i=1;i<=m;i++) \n     \
    \   if (basis[i] >= 0) \n            X[basis[i]] = A[i][n]; \n    return A[0][n];\
    \ \n} \n"
  code: "// Tested:\n// - http://codeforces.com/gym/100216 - C\n// - SRM 676 - 1000\n\
    // - SRM 694 - 900\n// m = # inequalities, n = #variables\n// variables numbered\
    \ from 0\n// C[0] = objective function (max)\n// C[1..m] = leq equations:\n//\
    \    sum( C[i][j] * X[j] ) <= C[i][n]\n// Return: -INF if infeasible, INF if unbounded,\
    \ max otherwise\n#define MAXM 400 // leave one extra \n#define MAXN 400 // leave\
    \ one extra \n#define EPS 1e-9 \n#define INF 1.0/0.0 \ndouble A[MAXM][MAXN]; \n\
    int basis[MAXM], out[MAXN]; \nvoid pivot(int m, int n, int a, int b) { \n    int\
    \ i,j; \n    for (i=0;i<=m;i++) \n        if (i!=a) \n            for (j=0;j<=n;j++)\n\
    \                if (j!=b) \n                    A[i][j] -= A[a][j] * A[i][b]\
    \ / A[a][b]; \n    for (j=0;j<=n;j++) \n        if (j!=b) A[a][j] /= A[a][b];\
    \ \n    for (i=0;i<=m;i++) \n        if (i!=a) A[i][b] = -A[i][b]/A[a][b]; \n\
    \            A[a][b] = 1/A[a][b]; \n    swap(basis[a], out[b]);\n} \ndouble simplex(int\
    \ m, int n, double C[][MAXN], double X[]) { \n    int i,j,ii,jj; // i,ii are row\
    \ indexes; j,jj are column indexes \n    for (i=1;i<=m;i++) \n        for (j=0;j<=n;j++)\
    \ \n            A[i][j] = C[i][j]; \n    for (j=0;j<=n;j++) A[0][j] = -C[0][j];\
    \ \n    for (i=0;i<=m;i++) basis[i] = -i; \n    for (j=0;j<=n;j++) out[j] = j;\
    \ \n    for(;;) { \n        for (i=ii=1;i<=m;i++) \n            if (A[i][n]<A[ii][n]\
    \ || (A[i][n]==A[ii][n] && basis[i]<basis[ii])) \n                ii=i; \n   \
    \     if (A[ii][n] >= -EPS) break; \n        for (j=jj=0;j<n;j++) \n         \
    \   if (A[ii][j]<A[ii][jj]-EPS || (A[ii][j]<A[ii][jj]-EPS && out[i]<out[j])) \n\
    \                jj=j;\n        if (A[ii][jj] >= -EPS) return -INF; \n       \
    \ pivot(m,n,ii,jj); \n    } \n    for(;;) { \n        for (j=jj=0;j<n;j++) \n\
    \            if (A[0][j]<A[0][jj] || (A[0][j]==A[0][jj] && out[j]<out[jj])) \n\
    \                jj=j; \n        if (A[0][jj] > -EPS) break; \n        for (i=1,ii=0;i<=m;i++)\
    \ \n            if ((A[i][jj]>EPS) && \n                    (!ii || (A[i][n]/A[i][jj]\
    \ < A[ii][n]/A[ii][jj]-EPS) || \n                ((A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]+EPS)\
    \ && (basis[i] < basis[ii])))) \n            ii=i; \n        if (A[ii][jj] <=\
    \ EPS) return INF; \n        pivot(m,n,ii,jj); \n    } \n    for (j=0;j<n;j++)\n\
    \        X[j] = 0; \n    for (i=1;i<=m;i++) \n        if (basis[i] >= 0) \n  \
    \          X[basis[i]] = A[i][n]; \n    return A[0][n]; \n} \n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Simplex.h
  requiredBy: []
  timestamp: '2016-07-10 02:23:02+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Simplex.h
layout: document
redirect_from:
- /library/Math/Simplex.h
- /library/Math/Simplex.h.html
title: Math/Simplex.h
---
