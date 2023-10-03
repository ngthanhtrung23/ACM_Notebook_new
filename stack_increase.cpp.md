---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/120772
  bundledCode: "#line 1 \"stack_increase.cpp\"\n// Source: https://codeforces.com/blog/entry/120772\n\
    #include <bits/stdc++.h>\nusing namespace std;\nvoid main_() {\n    // implement\
    \ your solution here\n}\nstatic void run_with_stack_size(void (*func)(void), size_t\
    \ stsize) {\n    char *stack, *send;\n    stack = (char *)malloc(stsize);\n  \
    \  send = stack + stsize - 16;\n    send = (char *)((uintptr_t)send / 16 * 16);\n\
    \    asm volatile(\n        \"mov %%rsp, (%0)\\n\"\n        \"mov %0, %%rsp\\\
    n\"\n        :\n        : \"r\"(send));\n    func();\n    asm volatile(\"mov (%0),\
    \ %%rsp\\n\" : : \"r\"(send));\n    free(stack);\n}\nint main() {\n    run_with_stack_size(main_,\
    \ 1024 * 1024 * 1024); // run with a 1 GiB stack\n    return 0;\n}\n"
  code: "// Source: https://codeforces.com/blog/entry/120772\n#include <bits/stdc++.h>\n\
    using namespace std;\nvoid main_() {\n    // implement your solution here\n}\n\
    static void run_with_stack_size(void (*func)(void), size_t stsize) {\n    char\
    \ *stack, *send;\n    stack = (char *)malloc(stsize);\n    send = stack + stsize\
    \ - 16;\n    send = (char *)((uintptr_t)send / 16 * 16);\n    asm volatile(\n\
    \        \"mov %%rsp, (%0)\\n\"\n        \"mov %0, %%rsp\\n\"\n        :\n   \
    \     : \"r\"(send));\n    func();\n    asm volatile(\"mov (%0), %%rsp\\n\" :\
    \ : \"r\"(send));\n    free(stack);\n}\nint main() {\n    run_with_stack_size(main_,\
    \ 1024 * 1024 * 1024); // run with a 1 GiB stack\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: stack_increase.cpp
  requiredBy: []
  timestamp: '2023-10-03 14:50:28-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: stack_increase.cpp
layout: document
redirect_from:
- /library/stack_increase.cpp
- /library/stack_increase.cpp.html
title: stack_increase.cpp
---
