---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/fenwick.test.cpp
    title: DataStructure/test/fenwick.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/fenwick_pointaddrangesum.test.cpp
    title: DataStructure/test/fenwick_pointaddrangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/lca.test.cpp
    title: DataStructure/test/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/rmq.test.cpp
    title: DataStructure/test/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
    title: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
  - icon: ':x:'
    path: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
    title: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"buffered_reader.h\"\nnamespace IO {\n    const int BUFSIZE\
    \ = 1<<14;\n    char buf[BUFSIZE + 1], *inp = buf;\n\n    bool reacheof;\n   \
    \ char get_char() {\n        if (!*inp && !reacheof) {\n            memset(buf,\
    \ 0, sizeof buf);\n            int tmp = fread(buf, 1, BUFSIZE, stdin);\n    \
    \        if (tmp != BUFSIZE) reacheof = true;\n            inp = buf;\n      \
    \  }\n        return *inp++;\n    }\n    template<typename T>\n    T get_int()\
    \ {\n        int neg = 0;\n        T res = 0;\n        char c = get_char();\n\
    \        while (!std::isdigit(c) && c != '-' && c != '+') c = get_char();\n  \
    \      if (c == '+') { neg = 0; }\n        else if (c == '-') { neg = 1; }\n \
    \       else res = c - '0';\n\n        c = get_char();\n        while (std::isdigit(c))\
    \ {\n            res = res * 10 + (c - '0');\n            c = get_char();\n  \
    \      }\n        return neg ? -res : res;\n    }\n};\n"
  code: "namespace IO {\n    const int BUFSIZE = 1<<14;\n    char buf[BUFSIZE + 1],\
    \ *inp = buf;\n\n    bool reacheof;\n    char get_char() {\n        if (!*inp\
    \ && !reacheof) {\n            memset(buf, 0, sizeof buf);\n            int tmp\
    \ = fread(buf, 1, BUFSIZE, stdin);\n            if (tmp != BUFSIZE) reacheof =\
    \ true;\n            inp = buf;\n        }\n        return *inp++;\n    }\n  \
    \  template<typename T>\n    T get_int() {\n        int neg = 0;\n        T res\
    \ = 0;\n        char c = get_char();\n        while (!std::isdigit(c) && c !=\
    \ '-' && c != '+') c = get_char();\n        if (c == '+') { neg = 0; }\n     \
    \   else if (c == '-') { neg = 1; }\n        else res = c - '0';\n\n        c\
    \ = get_char();\n        while (std::isdigit(c)) {\n            res = res * 10\
    \ + (c - '0');\n            c = get_char();\n        }\n        return neg ? -res\
    \ : res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: buffered_reader.h
  requiredBy: []
  timestamp: '2021-12-30 01:16:19+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - DataStructure/test/fenwick.test.cpp
  - DataStructure/test/lca.test.cpp
  - DataStructure/test/segment_tree_pointaddrangesum.test.cpp
  - DataStructure/test/rmq.test.cpp
  - DataStructure/test/fenwick_pointaddrangesum.test.cpp
documentation_of: buffered_reader.h
layout: document
redirect_from:
- /library/buffered_reader.h
- /library/buffered_reader.h.html
title: buffered_reader.h
---
