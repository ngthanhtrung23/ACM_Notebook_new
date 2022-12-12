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
  bundledCode: "#line 1 \"Misc/board_utils.h\"\n#include <algorithm>\n#include <vector>\n\
    \nint n_row, n_col;\n\ninline int get_id(int r, int c) {\n    return r * n_col\
    \ + c;\n}\ninline std::pair<int,int> get_rc(int id) {\n    return std::make_pair(id\
    \ / n_col, id % n_col);\n}\ninline bool is_inside(int r, int c) {\n    return\
    \ 0 <= r && r < n_row\n        && 0 <= c && c < n_col;\n}\n\nconst std::vector<std::pair<int,int>>\
    \ DIRECTIONS = {\n    {-1, 0}, {1, 0}, {0, -1}, {0, 1},\n    // 8 directions:\n\
    \    // {-1, -1}, {-1, 1}, {1, -1}, {1, 1},\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\nint n_row, n_col;\n\ninline int\
    \ get_id(int r, int c) {\n    return r * n_col + c;\n}\ninline std::pair<int,int>\
    \ get_rc(int id) {\n    return std::make_pair(id / n_col, id % n_col);\n}\ninline\
    \ bool is_inside(int r, int c) {\n    return 0 <= r && r < n_row\n        && 0\
    \ <= c && c < n_col;\n}\n\nconst std::vector<std::pair<int,int>> DIRECTIONS =\
    \ {\n    {-1, 0}, {1, 0}, {0, -1}, {0, 1},\n    // 8 directions:\n    // {-1,\
    \ -1}, {-1, 1}, {1, -1}, {1, 1},\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/board_utils.h
  requiredBy: []
  timestamp: '2022-12-12 13:43:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/board_utils.h
layout: document
redirect_from:
- /library/Misc/board_utils.h
- /library/Misc/board_utils.h.html
title: Misc/board_utils.h
---
