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
  bundledCode: "#line 1 \"String/kmp.h\"\n// prefix function: *length* of longest\
    \ prefix which is also suffix:\n//   pi[i] = max(k: s[0..k-1] == s[i-(k-1)..i]\n\
    //\n// KMP {{{\ntemplate<typename Container>\nstd::vector<int> prefix_function(const\
    \ Container& s) {\n    int n = s.size();\n    std::vector<int> pi(n);\n    for\
    \ (int i = 1; i < n; ++i) {\n        int j = pi[i-1];\n        while (j > 0 &&\
    \ s[i] != s[j]) j = pi[j-1];\n        if (s[i] == s[j]) ++j;\n        pi[i] =\
    \ j;\n    }\n    return pi;\n}\n\n// Return all positions (0-based) that pattern\
    \ `pat` appears in `text`\nstd::vector<int> kmp(const std::string& pat, const\
    \ std::string& text) {\n    auto pi = prefix_function(pat + '\\0' + text);\n \
    \   std::vector<int> res;\n    for (size_t i = pi.size() - text.size(); i < pi.size();\
    \ ++i) {\n        if (pi[i] == (int) pat.size()) {\n            res.push_back(i\
    \ - 2 * pat.size());\n        }\n    }\n    return res;\n}\n\n// NOT TESTED\n\
    // Returns cnt[i] = # occurrences of prefix of length-i\n// NOTE: cnt[0] = n+1\
    \ (0-length prefix appears n+1 times)\nstd::vector<int> prefix_occurrences(const\
    \ string& s) {\n    int n = s.size();\n    auto pi = prefix_function(s);\n   \
    \ std::vector<int> res(n + 1);\n    for (int i = 0; i < n; ++i) res[pi[i]]++;\n\
    \    for (int i = n-1; i > 0; --i) res[pi[i-1]] += res[i];\n    for (int i = 0;\
    \ i <= n; ++i) res[i]++;\n    return res;\n}\n// }}}\n"
  code: "// prefix function: *length* of longest prefix which is also suffix:\n//\
    \   pi[i] = max(k: s[0..k-1] == s[i-(k-1)..i]\n//\n// KMP {{{\ntemplate<typename\
    \ Container>\nstd::vector<int> prefix_function(const Container& s) {\n    int\
    \ n = s.size();\n    std::vector<int> pi(n);\n    for (int i = 1; i < n; ++i)\
    \ {\n        int j = pi[i-1];\n        while (j > 0 && s[i] != s[j]) j = pi[j-1];\n\
    \        if (s[i] == s[j]) ++j;\n        pi[i] = j;\n    }\n    return pi;\n}\n\
    \n// Return all positions (0-based) that pattern `pat` appears in `text`\nstd::vector<int>\
    \ kmp(const std::string& pat, const std::string& text) {\n    auto pi = prefix_function(pat\
    \ + '\\0' + text);\n    std::vector<int> res;\n    for (size_t i = pi.size() -\
    \ text.size(); i < pi.size(); ++i) {\n        if (pi[i] == (int) pat.size()) {\n\
    \            res.push_back(i - 2 * pat.size());\n        }\n    }\n    return\
    \ res;\n}\n\n// NOT TESTED\n// Returns cnt[i] = # occurrences of prefix of length-i\n\
    // NOTE: cnt[0] = n+1 (0-length prefix appears n+1 times)\nstd::vector<int> prefix_occurrences(const\
    \ string& s) {\n    int n = s.size();\n    auto pi = prefix_function(s);\n   \
    \ std::vector<int> res(n + 1);\n    for (int i = 0; i < n; ++i) res[pi[i]]++;\n\
    \    for (int i = n-1; i > 0; --i) res[pi[i-1]] += res[i];\n    for (int i = 0;\
    \ i <= n; ++i) res[i]++;\n    return res;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/kmp.h
  requiredBy: []
  timestamp: '2022-12-24 21:01:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/kmp.h
layout: document
redirect_from:
- /library/String/kmp.h
- /library/String/kmp.h.html
title: String/kmp.h
---
