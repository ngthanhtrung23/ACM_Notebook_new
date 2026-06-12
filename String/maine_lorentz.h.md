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
  bundledCode: "#line 1 \"String/maine_lorentz.h\"\n// T\xECm c\xE1c x\xE2u con l\u1EB7\
    p li\xEAn ti\u1EBFp 2 l\u1EA7n\nvector<int> z_function(const string & s) {\n\t\
    int n = (int) s.length();\n\tvector<int> z(n);\n\tfor (int i = 1, l = 0, r = 0;\
    \ i < n; ++i) {\n\t\tif (i <= r)\n\t\t\tz[i] = min(r - i + 1, z[i - l]);\n\t\t\
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])\n\t\t\t++z[i];\n\t\tif (i + z[i]\
    \ - 1 > r)\n\t\t\tl = i, r = i + z[i] - 1;\n\t}\n\treturn z;\n}\n\nvoid output_tandem(const\
    \ string & s, int shift, bool left, int cntr, int l,\n\t\tint l1, int l2) {\n\t\
    int pos;\n\tif (left) pos = cntr - l1;\n\telse pos = cntr - l1 - l2 - l1 + 1;\n\
    \tcout << \"[\" << shift + pos << \"..\" << shift + pos + 2 * l - 1 << \"] = \"\
    \n\t\t\t<< s.substr(pos, 2 * l) << endl;\n}\n\nvoid output_tandems(const string\
    \ & s, int shift, bool left, int cntr, int l,\n\t\tint k1, int k2) {\n\tfor (int\
    \ l1 = 1; l1 <= l; ++l1) {\n\t\tif (left && l1 == l)\n\t\t\tbreak;\n\t\tif (l1\
    \ <= k1 && l - l1 <= k2)\n\t\t\toutput_tandem(s, shift, left, cntr, l, l1, l -\
    \ l1);\n\t}\n}\n\ninline int get_z(const vector<int> & z, int i) {\n\treturn 0\
    \ <= i && i < (int) z.size() ? z[i] : 0;\n}\n\nvoid find_tandems(string s, int\
    \ shift = 0) {\n\tint n = (int) s.length();\n\tif (n == 1)\n\t\treturn;\n\n\t\
    int nu = n / 2, nv = n - nu;\n\tstring u = s.substr(0, nu), v = s.substr(nu);\n\
    \tstring ru = string(u.rbegin(), u.rend()), rv = string(v.rbegin(), v.rend());\n\
    \n\tfind_tandems(u, shift);\n\tfind_tandems(v, shift + nu);\n\n\tvector<int> z1\
    \ = z_function(ru), z2 = z_function(v + '#' + u), z3 =\n\t\t\tz_function(ru +\
    \ '#' + rv), z4 = z_function(v);\n\tfor (int cntr = 0; cntr < n; ++cntr) {\n\t\
    \tint l, k1, k2;\n\t\tif (cntr < nu) {\n\t\t\tl = nu - cntr;\n\t\t\tk1 = get_z(z1,\
    \ nu - cntr);\n\t\t\tk2 = get_z(z2, nv + 1 + cntr);\n\t\t} else {\n\t\t\tl = cntr\
    \ - nu + 1;\n\t\t\tk1 = get_z(z3, nu + 1 + nv - 1 - (cntr - nu));\n\t\t\tk2 =\
    \ get_z(z4, (cntr - nu) + 1);\n\t\t}\n\t\tif (k1 + k2 >= l) output_tandems(s,\
    \ shift, cntr < nu, cntr, l, k1, k2);\n\t}\n}\n"
  code: "// T\xECm c\xE1c x\xE2u con l\u1EB7p li\xEAn ti\u1EBFp 2 l\u1EA7n\nvector<int>\
    \ z_function(const string & s) {\n\tint n = (int) s.length();\n\tvector<int> z(n);\n\
    \tfor (int i = 1, l = 0, r = 0; i < n; ++i) {\n\t\tif (i <= r)\n\t\t\tz[i] = min(r\
    \ - i + 1, z[i - l]);\n\t\twhile (i + z[i] < n && s[z[i]] == s[i + z[i]])\n\t\t\
    \t++z[i];\n\t\tif (i + z[i] - 1 > r)\n\t\t\tl = i, r = i + z[i] - 1;\n\t}\n\t\
    return z;\n}\n\nvoid output_tandem(const string & s, int shift, bool left, int\
    \ cntr, int l,\n\t\tint l1, int l2) {\n\tint pos;\n\tif (left) pos = cntr - l1;\n\
    \telse pos = cntr - l1 - l2 - l1 + 1;\n\tcout << \"[\" << shift + pos << \"..\"\
    \ << shift + pos + 2 * l - 1 << \"] = \"\n\t\t\t<< s.substr(pos, 2 * l) << endl;\n\
    }\n\nvoid output_tandems(const string & s, int shift, bool left, int cntr, int\
    \ l,\n\t\tint k1, int k2) {\n\tfor (int l1 = 1; l1 <= l; ++l1) {\n\t\tif (left\
    \ && l1 == l)\n\t\t\tbreak;\n\t\tif (l1 <= k1 && l - l1 <= k2)\n\t\t\toutput_tandem(s,\
    \ shift, left, cntr, l, l1, l - l1);\n\t}\n}\n\ninline int get_z(const vector<int>\
    \ & z, int i) {\n\treturn 0 <= i && i < (int) z.size() ? z[i] : 0;\n}\n\nvoid\
    \ find_tandems(string s, int shift = 0) {\n\tint n = (int) s.length();\n\tif (n\
    \ == 1)\n\t\treturn;\n\n\tint nu = n / 2, nv = n - nu;\n\tstring u = s.substr(0,\
    \ nu), v = s.substr(nu);\n\tstring ru = string(u.rbegin(), u.rend()), rv = string(v.rbegin(),\
    \ v.rend());\n\n\tfind_tandems(u, shift);\n\tfind_tandems(v, shift + nu);\n\n\t\
    vector<int> z1 = z_function(ru), z2 = z_function(v + '#' + u), z3 =\n\t\t\tz_function(ru\
    \ + '#' + rv), z4 = z_function(v);\n\tfor (int cntr = 0; cntr < n; ++cntr) {\n\
    \t\tint l, k1, k2;\n\t\tif (cntr < nu) {\n\t\t\tl = nu - cntr;\n\t\t\tk1 = get_z(z1,\
    \ nu - cntr);\n\t\t\tk2 = get_z(z2, nv + 1 + cntr);\n\t\t} else {\n\t\t\tl = cntr\
    \ - nu + 1;\n\t\t\tk1 = get_z(z3, nu + 1 + nv - 1 - (cntr - nu));\n\t\t\tk2 =\
    \ get_z(z4, (cntr - nu) + 1);\n\t\t}\n\t\tif (k1 + k2 >= l) output_tandems(s,\
    \ shift, cntr < nu, cntr, l, k1, k2);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/maine_lorentz.h
  requiredBy: []
  timestamp: '2017-12-04 02:04:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/maine_lorentz.h
layout: document
redirect_from:
- /library/String/maine_lorentz.h
- /library/String/maine_lorentz.h.html
title: String/maine_lorentz.h
---
