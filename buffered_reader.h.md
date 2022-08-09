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
    path: DataStructure/test/hld_lca.test.cpp
    title: DataStructure/test/hld_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/lca.test.cpp
    title: DataStructure/test/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/rmq.test.cpp
    title: DataStructure/test/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
    title: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
    title: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
    title: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
    title: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
    title: DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/matrix_det.test.cpp
    title: Math/tests/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/matrix_inverse.test.cpp
    title: Math/tests/matrix_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/matrix_mult.test.cpp
    title: Math/tests/matrix_mult.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "// Buffered reader {{{\n#pragma once\nnamespace IO {\n    const int BUFSIZE\
    \ = 1<<14;\n    char buf[BUFSIZE + 1], *inp = buf;\n\n    bool reacheof;\n   \
    \ char get_char() {\n        if (!*inp && !reacheof) {\n            memset(buf,\
    \ 0, sizeof buf);\n            int tmp = fread(buf, 1, BUFSIZE, stdin);\n    \
    \        if (tmp != BUFSIZE) reacheof = true;\n            inp = buf;\n      \
    \  }\n        return *inp++;\n    }\n    template<typename T>\n    T get() {\n\
    \        int neg = 0;\n        T res = 0;\n        char c = get_char();\n    \
    \    while (!std::isdigit(c) && c != '-' && c != '+') c = get_char();\n      \
    \  if (c == '+') { neg = 0; }\n        else if (c == '-') { neg = 1; }\n     \
    \   else res = c - '0';\n\n        c = get_char();\n        while (std::isdigit(c))\
    \ {\n            res = res * 10 + (c - '0');\n            c = get_char();\n  \
    \      }\n        return neg ? -res : res;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: buffered_reader.h
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/segment_tree_pointaddrangesum.test.cpp
  - DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  - DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
  - DataStructure/test/hld_lca.test.cpp
  - DataStructure/test/rmq.test.cpp
  - DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
  - DataStructure/test/fenwick.test.cpp
  - DataStructure/test/fenwick_pointaddrangesum.test.cpp
  - DataStructure/test/lca.test.cpp
  - DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - Math/tests/matrix_inverse.test.cpp
  - Math/tests/matrix_mult.test.cpp
  - Math/tests/matrix_det.test.cpp
documentation_of: buffered_reader.h
layout: document
redirect_from:
- /library/buffered_reader.h
- /library/buffered_reader.h.html
title: buffered_reader.h
---
