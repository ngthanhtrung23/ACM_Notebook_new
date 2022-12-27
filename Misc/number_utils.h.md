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
  bundledCode: "#line 1 \"Misc/number_utils.h\"\n// return digits of an integer (reversed\
    \ order) {{{\nvector<int> get_digits(int n) {\n    if (n == 0) return {0};\n \
    \   vector<int> res;\n    while (n > 0) {\n        res.push_back(n % 10);\n  \
    \      n /= 10;\n    }\n    return res;\n}\n// }}}\n"
  code: "// return digits of an integer (reversed order) {{{\nvector<int> get_digits(int\
    \ n) {\n    if (n == 0) return {0};\n    vector<int> res;\n    while (n > 0) {\n\
    \        res.push_back(n % 10);\n        n /= 10;\n    }\n    return res;\n}\n\
    // }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/number_utils.h
  requiredBy: []
  timestamp: '2022-12-27 15:34:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/number_utils.h
layout: document
redirect_from:
- /library/Misc/number_utils.h
- /library/Misc/number_utils.h.html
title: Misc/number_utils.h
---
