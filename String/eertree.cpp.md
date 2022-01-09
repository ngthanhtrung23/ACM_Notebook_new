---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b;\
    \ i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a)\
    \ for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin()) it\
    \ = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \" = \"\
    ; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
    \ cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n) { cout << #a << \" =\
    \ \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\
    \n// For printing pair, container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n#line 2 \"String/eertree.cpp\"\n\nconst int MAXN = 105000;\n\nstruct\
    \ node {\n\tint next[26];\n\tint len;\n\tint sufflink;\n};\n\nint len;\nchar s[MAXN];\n\
    node tree[MAXN]; \nint num; \t\t\t// node 1 - root with len -1, node 2 - root\
    \ with len 0\nint suff; \t\t\t// max suffix palindrome\n\nbool addLetter(int pos)\
    \ {\n\tint cur = suff, curlen = 0;\n\tint let = s[pos] - 'a';\n\n\twhile (true)\
    \ {\n\t\tcurlen = tree[cur].len;\n\t\tif (pos - 1 - curlen >= 0 && s[pos - 1 -\
    \ curlen] == s[pos])    \t\n\t\t\tbreak;\t\n\t\tcur = tree[cur].sufflink;\n\t\
    }\t\t\n\tif (tree[cur].next[let]) {\t\n\t\tsuff = tree[cur].next[let];\n\t\treturn\
    \ false;\n\t}\n\n\tnum++;\n\tsuff = num;\n\ttree[num].len = tree[cur].len + 2;\n\
    \ttree[cur].next[let] = num;\n\n\tif (tree[num].len == 1) {\n\t\ttree[num].sufflink\
    \ = 2;\n\t\treturn true;\n\t}\n\n\twhile (true) {\n\t\tcur = tree[cur].sufflink;\n\
    \t\tcurlen = tree[cur].len;\n\t\tif (pos - 1 - curlen >= 0 && s[pos - 1 - curlen]\
    \ == s[pos]) {\n\t\t\ttree[num].sufflink = tree[cur].next[let];\n\t\t\tbreak;\n\
    \t\t}    \t\n\t}           \n\n\treturn true;\n}\n\nvoid initTree() {\n\tnum =\
    \ 2; suff = 2;\n\ttree[1].len = -1; tree[1].sufflink = 1;\n\ttree[2].len = 0;\
    \ tree[2].sufflink = 1;\n}\n\nint solve() {\n\tscanf(\"%s\\n\", &s[0]);\n\tlen\
    \ = strlen(s);\n\tinitTree();\n\tfor (int i = 0; i < len; i++) {\n\t\taddLetter(i);\n\
    \t}\n\treturn 0;\n} \n"
  code: "#include \"template.h\"\n\nconst int MAXN = 105000;\n\nstruct node {\n\t\
    int next[26];\n\tint len;\n\tint sufflink;\n};\n\nint len;\nchar s[MAXN];\nnode\
    \ tree[MAXN]; \nint num; \t\t\t// node 1 - root with len -1, node 2 - root with\
    \ len 0\nint suff; \t\t\t// max suffix palindrome\n\nbool addLetter(int pos) {\n\
    \tint cur = suff, curlen = 0;\n\tint let = s[pos] - 'a';\n\n\twhile (true) {\n\
    \t\tcurlen = tree[cur].len;\n\t\tif (pos - 1 - curlen >= 0 && s[pos - 1 - curlen]\
    \ == s[pos])    \t\n\t\t\tbreak;\t\n\t\tcur = tree[cur].sufflink;\n\t}\t\t\n\t\
    if (tree[cur].next[let]) {\t\n\t\tsuff = tree[cur].next[let];\n\t\treturn false;\n\
    \t}\n\n\tnum++;\n\tsuff = num;\n\ttree[num].len = tree[cur].len + 2;\n\ttree[cur].next[let]\
    \ = num;\n\n\tif (tree[num].len == 1) {\n\t\ttree[num].sufflink = 2;\n\t\treturn\
    \ true;\n\t}\n\n\twhile (true) {\n\t\tcur = tree[cur].sufflink;\n\t\tcurlen =\
    \ tree[cur].len;\n\t\tif (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])\
    \ {\n\t\t\ttree[num].sufflink = tree[cur].next[let];\n\t\t\tbreak;\n\t\t}    \t\
    \n\t}           \n\n\treturn true;\n}\n\nvoid initTree() {\n\tnum = 2; suff =\
    \ 2;\n\ttree[1].len = -1; tree[1].sufflink = 1;\n\ttree[2].len = 0; tree[2].sufflink\
    \ = 1;\n}\n\nint solve() {\n\tscanf(\"%s\\n\", &s[0]);\n\tlen = strlen(s);\n\t\
    initTree();\n\tfor (int i = 0; i < len; i++) {\n\t\taddLetter(i);\n\t}\n\treturn\
    \ 0;\n} \n"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/eertree.cpp
  requiredBy: []
  timestamp: '2022-01-09 21:09:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/eertree.cpp
layout: document
redirect_from:
- /library/String/eertree.cpp
- /library/String/eertree.cpp.html
title: String/eertree.cpp
---
