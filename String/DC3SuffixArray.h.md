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
  bundledCode: "#line 1 \"String/DC3SuffixArray.h\"\n// Linear Suffix Array O(N)\r\
    \n\r\n// String index from 0\r\n// Usage:\r\n//  string s;\r\n//  DC3Algorithm\
    \ dc3;\r\n//  dc3.Construct(s);\r\n//  Now we can use dc3.GetSA() and dc3.GetLCP()\r\
    \n\r\n#define MAXN 1000010 // >= 256\r\nclass DC3Algorithm {\r\nprivate: \r\n\
    \    int AN;\r\n    int A[3 * MAXN + 100];\r\n    int cnt[MAXN + 1]; \r\n    int\
    \ SA[MAXN + 1];\r\n\r\n    void radix_pass(int* A, int AN, int* R, int RN, int*\
    \ D) {\r\n        memset(cnt, 0, sizeof(int) * (AN + 1));\r\n        int* C =\
    \ cnt + 1;\r\n        for (int i = 0; i < RN; i++) ++C[A[R[i]]];\r\n        for\
    \ (int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);\r\n     \
    \   for (int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];\r\n    }\r\n\r\n    void\
    \ suffix_array(int* A, int AN) {\r\n        if (!AN) \r\n            SA[0] = 0;\r\
    \n        else if (AN == 1) {\r\n            SA[0] = 1;\r\n            SA[1] =\
    \ 0;\r\n            return;\r\n        }\r\n        \r\n        int RN = 0;\r\n\
    \        int* SUBA = A + AN + 2;\r\n        int* R = SUBA + AN + 2;\r\n      \
    \  for (int i = 1; i < AN; i += 3) SUBA[RN++] = i;\r\n        for (int i = 2;\
    \ i < AN; i += 3) SUBA[RN++] = i;\r\n        A[AN + 1] = A[AN] = -1;\r\n     \
    \   radix_pass(A + 2, AN - 2, SUBA, RN, R);\r\n        radix_pass(A + 1, AN -\
    \ 1, R, RN, SUBA);\r\n        radix_pass(A + 0, AN - 0, SUBA, RN, R);\r\n\r\n\
    \        int resfix, resmul, v;\r\n        if (AN % 3 == 1) {\r\n            resfix\
    \ = 1;\r\n            resmul = RN >> 1;\r\n        }\r\n        else {\r\n   \
    \         resfix = 2;\r\n            resmul = RN + 1 >> 1;\r\n        }\r\n  \
    \      for (int i = v = 0; i < RN; i++) {\r\n            v += i && (A[R[i - 1]\
    \ + 0] != A[R[i] + 0] || A[R[i - 1] + 1] != A[R[i] + 1] || A[R[i - 1] + 2] !=\
    \ A[R[i] + 2]);\r\n            SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul]\
    \ = v;\r\n        }\r\n\r\n        if (v + 1 != RN) {\r\n            suffix_array(SUBA,\
    \ RN);\r\n            SA[0] = AN;\r\n            for (int i = 1; i <= RN; i++)\
    \ \r\n                SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) : 3\
    \ * (SA[i] - resmul) + resfix;\r\n        }\r\n        else {\r\n            SA[0]\
    \ = AN;\r\n            memcpy(SA + 1, R, sizeof(int) * RN);\r\n        }\r\n\r\
    \n        int NMN = RN; \r\n        for (int i = RN = 0; i <= NMN; i++) \r\n \
    \           if (SA[i] % 3 == 1) \r\n                SUBA[RN++] = SA[i] - 1;\r\n\
    \        \r\n        radix_pass(A, AN, SUBA, RN, R);\r\n\r\n        for (int i\
    \ = 0; i <= NMN; i++) \r\n            SUBA[SA[i]] = i;\r\n\r\n        int ii =\
    \ RN - 1;\r\n        int jj = NMN;\r\n        int pos;\r\n        for (pos = AN;\
    \ ii >= 0; pos--) {\r\n            int i = R[ii];\r\n            int j = SA[jj];\r\
    \n            int v = A[i] - A[j];\r\n            if (!v) \r\n               \
    \ if (j % 3 == 1) \r\n                    v = SUBA[i + 1] - SUBA[j + 1];\r\n \
    \               else {\r\n                    v = A[i + 1] - A[j + 1];\r\n   \
    \                 if (!v) v = SUBA[i + 2] - SUBA[j + 2];\r\n                }\
    \            \r\n            SA[pos] = v < 0 ? SA[jj--] : R[ii--];\r\n       \
    \ }\r\n    }\r\n\r\n    void prep_string(string s) {\r\n        int v = 0;\r\n\
    \        AN = s.length();\r\n        memset(cnt, 0, 256 * sizeof(int));\r\n  \
    \      for (int i = 0; i < AN; i++) cnt[s[i]]++;\r\n        for (int i = 0; i\
    \ < 256; i++) cnt[i] = cnt[i] ? v++ : -1;\r\n        for (int i = 0; i < AN; i++)\
    \ A[i] = cnt[s[i]];\r\n    }\r\n\r\n    int REVSA[MAXN + 1];\r\n    void compute_reverse_sa()\
    \ {\r\n        for (int i = 0; i <= AN; i++) REVSA[SA[i]] = i;\r\n    }\r\n\r\n\
    \    int LCP[MAXN + 1];\r\n    void compute_lcp() {\r\n        int len = 0;\r\n\
    \        for (int i = 0; i < AN; i++, len = max(0, len - 1)) {\r\n           \
    \ int s = REVSA[i];\r\n            int j = SA[s - 1];\r\n            for (; i\
    \ + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);\r\n        \
    \    LCP[s] = len;\r\n        }\r\n    }\r\n    \r\npublic:\r\n    \r\n    void\
    \ Construct(string s) {\r\n        prep_string(s.c_str());\r\n        suffix_array(A,\
    \ AN);\r\n        compute_reverse_sa();\r\n        compute_lcp();\r\n    }\r\n\
    \    \r\n    vector<int> GetSA() {\r\n        vector<int> ret; ret.clear();\r\n\
    \        for (int i = 1; i <= AN; i++)\r\n            ret.push_back(SA[i]);\r\n\
    \        return ret;\r\n    }\r\n    \r\n    vector<int> GetLCP() {\r\n      \
    \  vector<int> ret; ret.clear();\r\n        for (int i = 1; i <= AN; i++)\r\n\
    \            ret.push_back(LCP[i]);\r\n        return ret;\r\n    }\r\n};\r\n"
  code: "// Linear Suffix Array O(N)\r\n\r\n// String index from 0\r\n// Usage:\r\n\
    //  string s;\r\n//  DC3Algorithm dc3;\r\n//  dc3.Construct(s);\r\n//  Now we\
    \ can use dc3.GetSA() and dc3.GetLCP()\r\n\r\n#define MAXN 1000010 // >= 256\r\
    \nclass DC3Algorithm {\r\nprivate: \r\n    int AN;\r\n    int A[3 * MAXN + 100];\r\
    \n    int cnt[MAXN + 1]; \r\n    int SA[MAXN + 1];\r\n\r\n    void radix_pass(int*\
    \ A, int AN, int* R, int RN, int* D) {\r\n        memset(cnt, 0, sizeof(int) *\
    \ (AN + 1));\r\n        int* C = cnt + 1;\r\n        for (int i = 0; i < RN; i++)\
    \ ++C[A[R[i]]];\r\n        for (int i = -1, v = 0; i <= AN && v < RN; v += C[i++])\
    \ swap(v, C[i]);\r\n        for (int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];\r\
    \n    }\r\n\r\n    void suffix_array(int* A, int AN) {\r\n        if (!AN) \r\n\
    \            SA[0] = 0;\r\n        else if (AN == 1) {\r\n            SA[0] =\
    \ 1;\r\n            SA[1] = 0;\r\n            return;\r\n        }\r\n       \
    \ \r\n        int RN = 0;\r\n        int* SUBA = A + AN + 2;\r\n        int* R\
    \ = SUBA + AN + 2;\r\n        for (int i = 1; i < AN; i += 3) SUBA[RN++] = i;\r\
    \n        for (int i = 2; i < AN; i += 3) SUBA[RN++] = i;\r\n        A[AN + 1]\
    \ = A[AN] = -1;\r\n        radix_pass(A + 2, AN - 2, SUBA, RN, R);\r\n       \
    \ radix_pass(A + 1, AN - 1, R, RN, SUBA);\r\n        radix_pass(A + 0, AN - 0,\
    \ SUBA, RN, R);\r\n\r\n        int resfix, resmul, v;\r\n        if (AN % 3 ==\
    \ 1) {\r\n            resfix = 1;\r\n            resmul = RN >> 1;\r\n       \
    \ }\r\n        else {\r\n            resfix = 2;\r\n            resmul = RN +\
    \ 1 >> 1;\r\n        }\r\n        for (int i = v = 0; i < RN; i++) {\r\n     \
    \       v += i && (A[R[i - 1] + 0] != A[R[i] + 0] || A[R[i - 1] + 1] != A[R[i]\
    \ + 1] || A[R[i - 1] + 2] != A[R[i] + 2]);\r\n            SUBA[R[i] / 3 + (R[i]\
    \ % 3 == resfix) * resmul] = v;\r\n        }\r\n\r\n        if (v + 1 != RN) {\r\
    \n            suffix_array(SUBA, RN);\r\n            SA[0] = AN;\r\n         \
    \   for (int i = 1; i <= RN; i++) \r\n                SA[i] = SA[i] < resmul ?\
    \ 3 * SA[i] + (resfix==1?2:1) : 3 * (SA[i] - resmul) + resfix;\r\n        }\r\n\
    \        else {\r\n            SA[0] = AN;\r\n            memcpy(SA + 1, R, sizeof(int)\
    \ * RN);\r\n        }\r\n\r\n        int NMN = RN; \r\n        for (int i = RN\
    \ = 0; i <= NMN; i++) \r\n            if (SA[i] % 3 == 1) \r\n               \
    \ SUBA[RN++] = SA[i] - 1;\r\n        \r\n        radix_pass(A, AN, SUBA, RN, R);\r\
    \n\r\n        for (int i = 0; i <= NMN; i++) \r\n            SUBA[SA[i]] = i;\r\
    \n\r\n        int ii = RN - 1;\r\n        int jj = NMN;\r\n        int pos;\r\n\
    \        for (pos = AN; ii >= 0; pos--) {\r\n            int i = R[ii];\r\n  \
    \          int j = SA[jj];\r\n            int v = A[i] - A[j];\r\n           \
    \ if (!v) \r\n                if (j % 3 == 1) \r\n                    v = SUBA[i\
    \ + 1] - SUBA[j + 1];\r\n                else {\r\n                    v = A[i\
    \ + 1] - A[j + 1];\r\n                    if (!v) v = SUBA[i + 2] - SUBA[j + 2];\r\
    \n                }            \r\n            SA[pos] = v < 0 ? SA[jj--] : R[ii--];\r\
    \n        }\r\n    }\r\n\r\n    void prep_string(string s) {\r\n        int v\
    \ = 0;\r\n        AN = s.length();\r\n        memset(cnt, 0, 256 * sizeof(int));\r\
    \n        for (int i = 0; i < AN; i++) cnt[s[i]]++;\r\n        for (int i = 0;\
    \ i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;\r\n        for (int i = 0; i < AN;\
    \ i++) A[i] = cnt[s[i]];\r\n    }\r\n\r\n    int REVSA[MAXN + 1];\r\n    void\
    \ compute_reverse_sa() {\r\n        for (int i = 0; i <= AN; i++) REVSA[SA[i]]\
    \ = i;\r\n    }\r\n\r\n    int LCP[MAXN + 1];\r\n    void compute_lcp() {\r\n\
    \        int len = 0;\r\n        for (int i = 0; i < AN; i++, len = max(0, len\
    \ - 1)) {\r\n            int s = REVSA[i];\r\n            int j = SA[s - 1];\r\
    \n            for (; i + len < AN && j + len < AN && A[i + len] == A[j + len];\
    \ len++);\r\n            LCP[s] = len;\r\n        }\r\n    }\r\n    \r\npublic:\r\
    \n    \r\n    void Construct(string s) {\r\n        prep_string(s.c_str());\r\n\
    \        suffix_array(A, AN);\r\n        compute_reverse_sa();\r\n        compute_lcp();\r\
    \n    }\r\n    \r\n    vector<int> GetSA() {\r\n        vector<int> ret; ret.clear();\r\
    \n        for (int i = 1; i <= AN; i++)\r\n            ret.push_back(SA[i]);\r\
    \n        return ret;\r\n    }\r\n    \r\n    vector<int> GetLCP() {\r\n     \
    \   vector<int> ret; ret.clear();\r\n        for (int i = 1; i <= AN; i++)\r\n\
    \            ret.push_back(LCP[i]);\r\n        return ret;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: String/DC3SuffixArray.h
  requiredBy: []
  timestamp: '2014-10-14 00:47:40+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/DC3SuffixArray.h
layout: document
redirect_from:
- /library/String/DC3SuffixArray.h
- /library/String/DC3SuffixArray.h.html
title: String/DC3SuffixArray.h
---
