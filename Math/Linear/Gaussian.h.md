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
    - https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
    - https://oj.vnoi.info/problem/icpc21_mb_c
    - https://open.kattis.com/problems/equationsolver
    - https://open.kattis.com/problems/equationsolverplus
  bundledCode: "#line 1 \"Math/Linear/Gaussian.h\"\n// Gauss-Jordan elimination.\n\
    // Returns: number of solution (0, 1 or INF)\n//   When the system has at least\
    \ one solution, ans will contains\n//   one possible solution\n// Possible improvement\
    \ when having precision errors:\n//   - Divide i-th row by a(i, i)\n//   - Choosing\
    \ pivoting row with min absolute value (sometimes this is better that maximum,\
    \ as implemented here)\n// Tested:\n// - https://open.kattis.com/problems/equationsolver\n\
    // - https://open.kattis.com/problems/equationsolverplus\n// - https://oj.vnoi.info/problem/icpc21_mb_c\n\
    \n// From https://cp-algorithms.com/linear_algebra/linear-system-gauss.html\n\
    // Solve:\n//   sum(aij * xj) = bi\n// last column of a is vector b\nint gauss\
    \ (vector < vector<double> > a, vector<double> & ans) {\n    int n = (int) a.size();\n\
    \    int m = (int) a[0].size() - 1;\n \n    vector<int> where (m, -1);\n    for\
    \ (int col=0, row=0; col<m && row<n; ++col) {\n        int sel = row;\n      \
    \  for (int i=row; i<n; ++i)\n            if (abs (a[i][col]) > abs (a[sel][col]))\n\
    \                sel = i;\n        if (abs (a[sel][col]) < EPS)\n            continue;\n\
    \        for (int i=col; i<=m; ++i)\n            swap (a[sel][i], a[row][i]);\n\
    \        where[col] = row;\n \n        for (int i=0; i<n; ++i)\n            if\
    \ (i != row) {\n                double c = a[i][col] / a[row][col];\n        \
    \        for (int j=col; j<=m; ++j)\n                    a[i][j] -= a[row][j]\
    \ * c;\n            }\n        ++row;\n    }\n \n    ans.assign (m, 0);\n    for\
    \ (int i=0; i<m; ++i)\n        if (where[i] != -1)\n            ans[i] = a[where[i]][m]\
    \ / a[where[i]][i];\n    for (int i=0; i<n; ++i) {\n        double sum = 0;\n\
    \        for (int j=0; j<m; ++j)\n            sum += ans[j] * a[i][j];\n     \
    \   if (abs (sum - a[i][m]) > EPS)\n            return 0;\n    }\n\n    // If\
    \ we need any solution (in case INF solutions), we should be\n    // ok at this\
    \ point.\n    // If need to solve partially (get which values are fixed/INF value):\n\
    //    for (int i=0; i<m; ++i)\n//        if (where[i] != -1) {\n//           \
    \ REP(j,n) if (j != i && fabs(a[where[i]][j]) > EPS) {\n//                where[i]\
    \ = -1;\n//                break;\n//            }\n//        }\n    // Then the\
    \ variables which has where[i] == -1 --> INF values\n \n    for (int i=0; i<m;\
    \ ++i)\n        if (where[i] == -1)\n            return INF;\n    return 1;\n\
    }\n"
  code: "// Gauss-Jordan elimination.\n// Returns: number of solution (0, 1 or INF)\n\
    //   When the system has at least one solution, ans will contains\n//   one possible\
    \ solution\n// Possible improvement when having precision errors:\n//   - Divide\
    \ i-th row by a(i, i)\n//   - Choosing pivoting row with min absolute value (sometimes\
    \ this is better that maximum, as implemented here)\n// Tested:\n// - https://open.kattis.com/problems/equationsolver\n\
    // - https://open.kattis.com/problems/equationsolverplus\n// - https://oj.vnoi.info/problem/icpc21_mb_c\n\
    \n// From https://cp-algorithms.com/linear_algebra/linear-system-gauss.html\n\
    // Solve:\n//   sum(aij * xj) = bi\n// last column of a is vector b\nint gauss\
    \ (vector < vector<double> > a, vector<double> & ans) {\n    int n = (int) a.size();\n\
    \    int m = (int) a[0].size() - 1;\n \n    vector<int> where (m, -1);\n    for\
    \ (int col=0, row=0; col<m && row<n; ++col) {\n        int sel = row;\n      \
    \  for (int i=row; i<n; ++i)\n            if (abs (a[i][col]) > abs (a[sel][col]))\n\
    \                sel = i;\n        if (abs (a[sel][col]) < EPS)\n            continue;\n\
    \        for (int i=col; i<=m; ++i)\n            swap (a[sel][i], a[row][i]);\n\
    \        where[col] = row;\n \n        for (int i=0; i<n; ++i)\n            if\
    \ (i != row) {\n                double c = a[i][col] / a[row][col];\n        \
    \        for (int j=col; j<=m; ++j)\n                    a[i][j] -= a[row][j]\
    \ * c;\n            }\n        ++row;\n    }\n \n    ans.assign (m, 0);\n    for\
    \ (int i=0; i<m; ++i)\n        if (where[i] != -1)\n            ans[i] = a[where[i]][m]\
    \ / a[where[i]][i];\n    for (int i=0; i<n; ++i) {\n        double sum = 0;\n\
    \        for (int j=0; j<m; ++j)\n            sum += ans[j] * a[i][j];\n     \
    \   if (abs (sum - a[i][m]) > EPS)\n            return 0;\n    }\n\n    // If\
    \ we need any solution (in case INF solutions), we should be\n    // ok at this\
    \ point.\n    // If need to solve partially (get which values are fixed/INF value):\n\
    //    for (int i=0; i<m; ++i)\n//        if (where[i] != -1) {\n//           \
    \ REP(j,n) if (j != i && fabs(a[where[i]][j]) > EPS) {\n//                where[i]\
    \ = -1;\n//                break;\n//            }\n//        }\n    // Then the\
    \ variables which has where[i] == -1 --> INF values\n \n    for (int i=0; i<m;\
    \ ++i)\n        if (where[i] == -1)\n            return INF;\n    return 1;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Linear/Gaussian.h
  requiredBy: []
  timestamp: '2021-12-21 14:25:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Linear/Gaussian.h
layout: document
redirect_from:
- /library/Math/Linear/Gaussian.h
- /library/Math/Linear/Gaussian.h.html
title: Math/Linear/Gaussian.h
---
