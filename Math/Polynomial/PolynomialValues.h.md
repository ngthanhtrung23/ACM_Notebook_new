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
  bundledCode: "#line 1 \"Math/Polynomial/PolynomialValues.h\"\n// m = number of known\
    \ points\n// o = number of unknown points\n// d[0] = values of known points\n\
    /* calculate differences */\nfor(i=0;i<m-1;i++) {\n    for(j=1;j<m;j++) d[i+1][j]=d[i][j]-d[i][j-1];\n\
    }\nfor (j=0;j<o;j++) { /* generate j numbers */\n    for (i=m-2;i>=0;i--)\n  \
    \      d[i][m-1]+=d[i+1][m-1] ;\n    printf(\"%d%c\",d[0][m-1], (j==o-1)?'\\n':'\
    \ ');\n}\n"
  code: "// m = number of known points\n// o = number of unknown points\n// d[0] =\
    \ values of known points\n/* calculate differences */\nfor(i=0;i<m-1;i++) {\n\
    \    for(j=1;j<m;j++) d[i+1][j]=d[i][j]-d[i][j-1];\n}\nfor (j=0;j<o;j++) { /*\
    \ generate j numbers */\n    for (i=m-2;i>=0;i--)\n        d[i][m-1]+=d[i+1][m-1]\
    \ ;\n    printf(\"%d%c\",d[0][m-1], (j==o-1)?'\\n':' ');\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Polynomial/PolynomialValues.h
  requiredBy: []
  timestamp: '2015-11-01 14:30:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Polynomial/PolynomialValues.h
layout: document
redirect_from:
- /library/Math/Polynomial/PolynomialValues.h
- /library/Math/Polynomial/PolynomialValues.h.html
title: Math/Polynomial/PolynomialValues.h
---
