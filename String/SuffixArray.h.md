---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.h
    title: Math/modint.h
  - icon: ':heavy_check_mark:'
    path: String/hash.h
    title: String/hash.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/tests/lcp.test.cpp
    title: String/tests/lcp.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/suffix_array.test.cpp
    title: String/tests/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/suffix_array_queries.test.cpp
    title: String/tests/suffix_array_queries.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/contest/452/submission/7269543
    - https://cses.fi/problemset/task/2102
    - https://cses.fi/problemset/task/2103
    - https://cses.fi/problemset/task/2104
    - https://cses.fi/problemset/task/2106/
    - https://cses.fi/problemset/task/2108
    - https://judge.yosupo.jp/problem/number_of_substrings
    - https://judge.yosupo.jp/problem/suffixarray
    - https://oj.vnoi.info/problem/icpc22_mt_b
  bundledCode: "#line 1 \"String/SuffixArray.h\"\n// Suffix Array {{{\n// Source:\
    \ http://codeforces.com/contest/452/submission/7269543\n// Efficient Suffix Array\
    \ O(N*logN)\n\n// String index from 0\n// Usage:\n// string s;  (s[i] > 0)\n//\
    \ SuffixArray sa(s);\n// Now we can use sa.SA and sa.LCP\n// sa.LCP[i] = max common\
    \ prefix suffix of sa.SA[i-1] and sa.SA[i]\n//\n// Notes:\n// - Number of distinct\
    \ substrings = |S| * (|S| + 1) / 2 - sum(LCP)\n//\n// Tested:\n// - (build SA)\
    \ https://judge.yosupo.jp/problem/suffixarray\n// - (LCP) https://judge.yosupo.jp/problem/number_of_substrings\n\
    // - (LCP - kth distinct substr) https://cses.fi/problemset/task/2108\n// - (LCP\
    \ - longest repeated substr) https://cses.fi/problemset/task/2106/\nstruct SuffixArray\
    \ {\n    string a;\n    int N, m;\n    vector<int> SA, LCP, x, y, w, c;\n\n  \
    \  SuffixArray(string _a, int _m = 256) : a(\" \" + _a), N(a.length()), m(_m),\n\
    \            SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {\n        a[0] = 0;\n\
    \        DA();\n        kasaiLCP();\n        #define REF(X) { rotate(X.begin(),\
    \ X.begin()+1, X.end()); X.pop_back(); }\n        REF(SA); REF(LCP);\n       \
    \ a = a.substr(1, a.size());\n        for(int i = 0; i < (int) SA.size(); ++i)\
    \ --SA[i];\n        #undef REF\n    }\n\n    inline bool cmp (const int u, const\
    \ int v, const int l) {\n        return (y[u] == y[v] && (u + l < N && v + l <\
    \ N ? y[u + l] == y[v + l] : false));\n    }\n\n    void Sort() {\n        for(int\
    \ i = 0; i < m; ++i) w[i] = 0;\n        for(int i = 0; i < N; ++i) ++w[x[y[i]]];\n\
    \        for(int i = 0; i < m - 1; ++i) w[i + 1] += w[i];\n        for(int i =\
    \ N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];\n    }\n\n    void DA() {\n   \
    \     for(int i = 0; i < N; ++i) x[i] = a[i], y[i] = i;\n        Sort();\n   \
    \     for(int i, j = 1, p = 1; p < N; j <<= 1, m = p) {\n            for(p = 0,\
    \ i = N - j; i < N; i++) y[p++] = i;\n            for (int k = 0; k < N; ++k)\
    \ if (SA[k] >= j) y[p++] = SA[k] - j;\n            Sort();\n            for(swap(x,\
    \ y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)\n                x[SA[i]] = cmp(SA[i\
    \ - 1], SA[i], j) ? p - 1 : p++;\n        }\n    }\n\n    void kasaiLCP() {\n\
    \        for (int i = 0; i < N; i++) c[SA[i]] = i;\n        for (int i = 0, j,\
    \ k = 0; i < N; LCP[c[i++]] = k)\n            if (c[i] > 0) for (k ? k-- : 0,\
    \ j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);\n            else k = 0;\n   \
    \ }\n};\n\n// Example:\n// given string S and Q queries pat_i, for each query,\
    \ count how many\n// times pat_i appears in S\n// O(min(|S|, |pat|) * log(|S|))\
    \ per query\n//\n// Tested:\n// - (yes / no) https://cses.fi/problemset/task/2102\n\
    // - (count) https://cses.fi/problemset/task/2103\n// - (position; need RMQ) https://cses.fi/problemset/task/2104\n\
    int count_occurrence(const string& s, const vector<int>& sa, const string& pat)\
    \ {\n    int n = s.size(), m = pat.size();\n    assert(n == (int) sa.size());\n\
    \    if (n < m) return 0;\n \n    auto f = [&] (int start) {  // compare S[start..]\
    \ and pat[0..]\n        for (int i = 0; start + i < n && i < m; ++i) {\n     \
    \       if (s[start + i] < pat[i]) return true;\n            if (s[start + i]\
    \ > pat[i]) return false;\n        }\n        return n - start < m;\n    };\n\
    \    auto g = [&] (int start) {\n        for (int i = 0; start + i < n && i <\
    \ m; ++i) {\n            if (s[start + i] > pat[i]) return false;\n        }\n\
    \        return true;\n    };\n    auto l = std::partition_point(sa.begin(), sa.end(),\
    \ f);\n    auto r = std::partition_point(l, sa.end(), g);\n    return std::distance(l,\
    \ r);\n}\n\n\n// If hash array can be pre-computed, can answer each query in\n\
    // O(log(|S|) * log(|S| + |pat|)\n// Tested\n// - https://oj.vnoi.info/problem/icpc22_mt_b\n\
    #line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct ModInt {\n \
    \   using ll = long long;\n    int x;\n\n    constexpr ModInt() : x(0) {}\n  \
    \  constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static int mod()\
    \ { return MD; }\n    constexpr explicit operator bool() const { return x != 0;\
    \ }\n\n    constexpr ModInt operator + (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt operator - (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x - a.x + MD);\n    }\n\
    \    constexpr ModInt operator * (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x * a.x % MD);\n    }\n    constexpr ModInt operator / (const ModInt& a) const\
    \ {\n        return ModInt()._set((ll) x * a.inv().x % MD);\n    }\n    constexpr\
    \ ModInt operator - () const {\n        return ModInt()._set(MD - x);\n    }\n\
    \n    constexpr ModInt& operator += (const ModInt& a) { return *this = *this +\
    \ a; }\n    constexpr ModInt& operator -= (const ModInt& a) { return *this = *this\
    \ - a; }\n    constexpr ModInt& operator *= (const ModInt& a) { return *this =\
    \ *this * a; }\n    constexpr ModInt& operator /= (const ModInt& a) { return *this\
    \ = *this / a; }\n\n    friend constexpr ModInt operator + (ll a, const ModInt&\
    \ b) {\n        return ModInt()._set(a % MD + b.x);\n    }\n    friend constexpr\
    \ ModInt operator - (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD - b.x + MD);\n    }\n    friend constexpr ModInt operator * (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.x % MD);\n    }\n    friend\
    \ constexpr ModInt operator / (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.inv().x % MD);\n    }\n\n    constexpr bool operator == (const ModInt&\
    \ a) const { return x == a.x; }\n    constexpr bool operator != (const ModInt&\
    \ a) const { return x != a.x; }\n\n    friend std::istream& operator >> (std::istream&\
    \ is, ModInt& x) {\n        ll val; is >> val;\n        x = ModInt(val);\n   \
    \     return is;\n    }\n    constexpr friend std::ostream& operator << (std::ostream&\
    \ os, const ModInt& x) {\n        return os << x.x;\n    }\n\n    constexpr ModInt\
    \ pow(ll k) const {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n \
    \           if (k & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>=\
    \ 1;\n        }\n        return ans;\n    }\n\n    constexpr ModInt inv() const\
    \ {\n        if (x < 1000111) {\n            _precalc(1000111);\n            return\
    \ invs[x];\n        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while\
    \ (b) {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n      \
    \      t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a\
    \ == 1);\n        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static\
    \ std::vector<ModInt> factorials, inv_factorials, invs;\n    constexpr static\
    \ void _precalc(int n) {\n        if (factorials.empty()) {\n            factorials\
    \ = {1};\n            inv_factorials = {1};\n            invs = {0};\n       \
    \ }\n        if (n > MD) n = MD;\n        int old_sz = factorials.size();\n  \
    \      if (n <= old_sz) return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n\n    static int get_primitive_root() {\n       \
    \ static int primitive_root = 0;\n        if (!primitive_root) {\n           \
    \ primitive_root = [&]() {\n                std::set<int> fac;\n             \
    \   int v = MD - 1;\n                for (ll i = 2; i * i <= v; i++)\n       \
    \             while (v % i == 0) fac.insert(i), v /= i;\n                if (v\
    \ > 1) fac.insert(v);\n                for (int g = 1; g < MD; g++) {\n      \
    \              bool ok = true;\n                    for (auto i : fac)\n     \
    \                   if (ModInt(g).pow((MD - 1) / i) == 1) {\n                \
    \            ok = false;\n                            break;\n               \
    \         }\n                    if (ok) return g;\n                }\n      \
    \          return -1;\n            }();\n        }\n        return primitive_root;\n\
    \    }\n    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0,\
    \ 2*MD)\n    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v)\
    \ {\n        x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate\
    \ <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n#line 2 \"String/hash.h\"\
    \n\n// Hash {{{\n// Usage:\n// HashGenerator g(MAX_LENGTH)\n//\n// auto h = g.hash(s)\n\
    // g.equals(s, h, l1, r1, s, h, l2, r2)\n// g.cmp(s, h, l1, r1, s, h, l2, r2)\n\
    //\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n// - https://oj.vnoi.info/problem/paliny\
    \  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub  - hash<Hash>\
    \ for unordered_map\n// - https://oj.vnoi.info/problem/vostr   - cmp\n\nconst\
    \ int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\nstruct Hash {\n    long\
    \ long x;\n    modular y;\n\n    Hash operator + (const Hash& a) const { return\
    \ Hash{x + a.x, y + a.y}; }\n    Hash operator - (const Hash& a) const { return\
    \ Hash{x - a.x, y - a.y}; }\n    Hash operator * (const Hash& a) const { return\
    \ Hash{x * a.x, y * a.y}; }\n    Hash operator * (int k) const { return Hash{x*k,\
    \ y*k}; }\n\n    Hash& operator += (const Hash& a) { return *this = *this + a;\
    \ }\n    Hash& operator -= (const Hash& a) { return *this = *this - a; }\n   \
    \ Hash& operator *= (const Hash& a) { return *this = *this * a; }\n};\nbool operator\
    \ == (const Hash& a, const Hash& b) {\n    return a.x == b.x && a.y == b.y;\n\
    }\nstd::ostream& operator << (std::ostream& out, const Hash& h) {\n    out <<\
    \ '(' << h.x << \", \" << h.y << ')';\n    return out;\n}\n\n// hash function\
    \ for std::unordered_map\nnamespace std {\n    template<>\n    struct hash<Hash>\
    \ {\n        public:\n            size_t operator() (const Hash& h) const {\n\
    \                return h.x * 1000000009 + h.y.x;\n            }\n    };\n}\n\n\
    struct HashGenerator {\n    HashGenerator(int maxLen, int base = 311) {\n    \
    \    p.resize(maxLen + 1);\n        p[0] = {1, 1};\n        for (int i = 1; i\
    \ <= maxLen; i++) {\n            p[i] = p[i-1] * base;\n        }\n    }\n\n \
    \   template<typename Container>\n    std::vector<Hash> hash(const Container&\
    \ s) const {\n        std::vector<Hash> res(s.size());\n        for (size_t i\
    \ = 0; i < s.size(); i++) {\n            res[i] = p[i] * (int) s[i];\n       \
    \ }\n        std::partial_sum(res.begin(), res.end(), res.begin());\n        return\
    \ res;\n    }\n\n    Hash getHash(const std::vector<Hash>& h, int l, int r) const\
    \ {\n        return __getHash(h, l, r) * p[p.size() - 1 - l];\n    }\n\n    //\
    \ compare [l1, r1] vs [l2, r2]\n    bool equals(\n            const std::vector<Hash>&\
    \ h1, int l1, int r1,\n            const std::vector<Hash>& h2, int l2, int r2)\
    \ const {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());\n    \
    \    assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n        if (r1 - l1\
    \ != r2 - l2) return false;\n\n        return getHash(h1, l1, r1) == getHash(h2,\
    \ l2, r2);\n    }\n\n    // Returns length of max common prefix of h1[l1, r1]\
    \ and h2[l2, r2]\n    // length = 0 -> first character of 2 substrings are different.\n\
    \    int maxCommonPrefix(\n            const std::vector<Hash>& h1, int l1, int\
    \ r1,\n            const std::vector<Hash>& h2, int l2, int r2) const {\n    \
    \    assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <=\
    \ l2 && l2 <= r2 && r2 < (int) h2.size());\n\n        int len1 = r1 - l1 + 1;\n\
    \        int len2 = r2 - l2 + 1;\n\n        int res = -1, left = 0, right = std::min(len1,\
    \ len2) - 1;\n        while (left <= right) {\n            int mid = (left + right)\
    \ / 2;\n            if (equals(h1, l1, l1 + mid, h2, l2, l2 + mid)) {\n      \
    \          res = mid;\n                left = mid + 1;\n            } else {\n\
    \                right = mid - 1;\n            }\n        }\n        return res\
    \ + 1;\n        /* C++20\n        auto r = std::views::iota(0, std::min(len1,\
    \ len2));\n        auto res = std::ranges::partition_point(\n                r,\n\
    \                [&] (int mid) {\n                    return equals(h1, l1, l1+mid,\
    \ h2, l2, l2+mid);\n                });\n        return *res;\n         */\n \
    \   }\n\n    // compare s1[l1, r1] and s2[l2, r2]\n    template<typename Container1,\
    \ typename Container2>\n    int cmp(\n            const Container1& s1, const\
    \ std::vector<Hash>& h1, int l1, int r1,\n            const Container2& s2, const\
    \ std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0 <= l1 && l1\
    \ <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <= r2 && r2 <\
    \ (int) h2.size());\n\n        int commonPrefixLen = maxCommonPrefix(h1, l1, r1,\
    \ h2, l2, r2);\n        char c1 = (l1 + commonPrefixLen <= r1) ? s1[l1 + commonPrefixLen]\
    \ : 0;\n        char c2 = (l2 + commonPrefixLen <= r2) ? s2[l2 + commonPrefixLen]\
    \ : 0;\n\n        return (c1 == c2) ? 0 : ((c1 < c2) ? -1 : 1);\n    }\n\nprivate:\n\
    \    std::vector<Hash> p;\n\n    // DO NOT USE, this doesn't divide by p[l]\n\
    \    Hash __getHash(const std::vector<Hash>& h, int l, int r) const {\n      \
    \  assert(0 <= l && l <= r && r < (int) h.size());\n        return h[r] - (l ==\
    \ 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n// }}}\n#line 106 \"String/SuffixArray.h\"\
    \nint count_occurrence_hash(\n        const vector<int>& sa,        // suffix\
    \ array\n        const HashGenerator& gen,\n        const string& s,\n       \
    \ const vector<Hash>& hash_s,   // hash of `s`, generated with `gen`\n       \
    \ const string_view& pat,\n        const vector<Hash>& hash_pat  // hash of `pat`,\
    \ generated with `gen`\n        ) {\n    int n = s.size(), len = pat.size();\n\
    \    assert(len == (int) hash_pat.size());\n    assert(n == (int) sa.size());\n\
    \    if (n < len) return 0;\n\n    // f(start) = compare string S[start..] and\
    \ pat[0..len-1]\n    auto f = [&] (int start) {\n        return gen.cmp(\n   \
    \             s, hash_s, start, n-1,\n                pat, hash_pat, 0, len-1)\
    \ < 0;\n    };\n    // g(start) = true if S[start..] == pat[0..]\n    auto g =\
    \ [&] (int start) {\n        int max_len = std::min(n - start, len);\n       \
    \ return gen.cmp(\n                s, hash_s, start, start + max_len - 1,\n  \
    \              pat, hash_pat, 0, max_len-1) == 0;\n    };\n    auto l = std::partition_point(sa.begin(),\
    \ sa.end(), f);\n    auto r = std::partition_point(l, sa.end(), g);\n    return\
    \ std::distance(l, r);\n}\n// }}}\n"
  code: "// Suffix Array {{{\n// Source: http://codeforces.com/contest/452/submission/7269543\n\
    // Efficient Suffix Array O(N*logN)\n\n// String index from 0\n// Usage:\n// string\
    \ s;  (s[i] > 0)\n// SuffixArray sa(s);\n// Now we can use sa.SA and sa.LCP\n\
    // sa.LCP[i] = max common prefix suffix of sa.SA[i-1] and sa.SA[i]\n//\n// Notes:\n\
    // - Number of distinct substrings = |S| * (|S| + 1) / 2 - sum(LCP)\n//\n// Tested:\n\
    // - (build SA) https://judge.yosupo.jp/problem/suffixarray\n// - (LCP) https://judge.yosupo.jp/problem/number_of_substrings\n\
    // - (LCP - kth distinct substr) https://cses.fi/problemset/task/2108\n// - (LCP\
    \ - longest repeated substr) https://cses.fi/problemset/task/2106/\nstruct SuffixArray\
    \ {\n    string a;\n    int N, m;\n    vector<int> SA, LCP, x, y, w, c;\n\n  \
    \  SuffixArray(string _a, int _m = 256) : a(\" \" + _a), N(a.length()), m(_m),\n\
    \            SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {\n        a[0] = 0;\n\
    \        DA();\n        kasaiLCP();\n        #define REF(X) { rotate(X.begin(),\
    \ X.begin()+1, X.end()); X.pop_back(); }\n        REF(SA); REF(LCP);\n       \
    \ a = a.substr(1, a.size());\n        for(int i = 0; i < (int) SA.size(); ++i)\
    \ --SA[i];\n        #undef REF\n    }\n\n    inline bool cmp (const int u, const\
    \ int v, const int l) {\n        return (y[u] == y[v] && (u + l < N && v + l <\
    \ N ? y[u + l] == y[v + l] : false));\n    }\n\n    void Sort() {\n        for(int\
    \ i = 0; i < m; ++i) w[i] = 0;\n        for(int i = 0; i < N; ++i) ++w[x[y[i]]];\n\
    \        for(int i = 0; i < m - 1; ++i) w[i + 1] += w[i];\n        for(int i =\
    \ N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];\n    }\n\n    void DA() {\n   \
    \     for(int i = 0; i < N; ++i) x[i] = a[i], y[i] = i;\n        Sort();\n   \
    \     for(int i, j = 1, p = 1; p < N; j <<= 1, m = p) {\n            for(p = 0,\
    \ i = N - j; i < N; i++) y[p++] = i;\n            for (int k = 0; k < N; ++k)\
    \ if (SA[k] >= j) y[p++] = SA[k] - j;\n            Sort();\n            for(swap(x,\
    \ y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)\n                x[SA[i]] = cmp(SA[i\
    \ - 1], SA[i], j) ? p - 1 : p++;\n        }\n    }\n\n    void kasaiLCP() {\n\
    \        for (int i = 0; i < N; i++) c[SA[i]] = i;\n        for (int i = 0, j,\
    \ k = 0; i < N; LCP[c[i++]] = k)\n            if (c[i] > 0) for (k ? k-- : 0,\
    \ j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);\n            else k = 0;\n   \
    \ }\n};\n\n// Example:\n// given string S and Q queries pat_i, for each query,\
    \ count how many\n// times pat_i appears in S\n// O(min(|S|, |pat|) * log(|S|))\
    \ per query\n//\n// Tested:\n// - (yes / no) https://cses.fi/problemset/task/2102\n\
    // - (count) https://cses.fi/problemset/task/2103\n// - (position; need RMQ) https://cses.fi/problemset/task/2104\n\
    int count_occurrence(const string& s, const vector<int>& sa, const string& pat)\
    \ {\n    int n = s.size(), m = pat.size();\n    assert(n == (int) sa.size());\n\
    \    if (n < m) return 0;\n \n    auto f = [&] (int start) {  // compare S[start..]\
    \ and pat[0..]\n        for (int i = 0; start + i < n && i < m; ++i) {\n     \
    \       if (s[start + i] < pat[i]) return true;\n            if (s[start + i]\
    \ > pat[i]) return false;\n        }\n        return n - start < m;\n    };\n\
    \    auto g = [&] (int start) {\n        for (int i = 0; start + i < n && i <\
    \ m; ++i) {\n            if (s[start + i] > pat[i]) return false;\n        }\n\
    \        return true;\n    };\n    auto l = std::partition_point(sa.begin(), sa.end(),\
    \ f);\n    auto r = std::partition_point(l, sa.end(), g);\n    return std::distance(l,\
    \ r);\n}\n\n\n// If hash array can be pre-computed, can answer each query in\n\
    // O(log(|S|) * log(|S| + |pat|)\n// Tested\n// - https://oj.vnoi.info/problem/icpc22_mt_b\n\
    #include \"./hash.h\"\nint count_occurrence_hash(\n        const vector<int>&\
    \ sa,        // suffix array\n        const HashGenerator& gen,\n        const\
    \ string& s,\n        const vector<Hash>& hash_s,   // hash of `s`, generated\
    \ with `gen`\n        const string_view& pat,\n        const vector<Hash>& hash_pat\
    \  // hash of `pat`, generated with `gen`\n        ) {\n    int n = s.size(),\
    \ len = pat.size();\n    assert(len == (int) hash_pat.size());\n    assert(n ==\
    \ (int) sa.size());\n    if (n < len) return 0;\n\n    // f(start) = compare string\
    \ S[start..] and pat[0..len-1]\n    auto f = [&] (int start) {\n        return\
    \ gen.cmp(\n                s, hash_s, start, n-1,\n                pat, hash_pat,\
    \ 0, len-1) < 0;\n    };\n    // g(start) = true if S[start..] == pat[0..]\n \
    \   auto g = [&] (int start) {\n        int max_len = std::min(n - start, len);\n\
    \        return gen.cmp(\n                s, hash_s, start, start + max_len -\
    \ 1,\n                pat, hash_pat, 0, max_len-1) == 0;\n    };\n    auto l =\
    \ std::partition_point(sa.begin(), sa.end(), f);\n    auto r = std::partition_point(l,\
    \ sa.end(), g);\n    return std::distance(l, r);\n}\n// }}}\n"
  dependsOn:
  - String/hash.h
  - Math/modint.h
  isVerificationFile: false
  path: String/SuffixArray.h
  requiredBy: []
  timestamp: '2022-10-23 21:56:10+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/tests/suffix_array.test.cpp
  - String/tests/suffix_array_queries.test.cpp
  - String/tests/lcp.test.cpp
documentation_of: String/SuffixArray.h
layout: document
redirect_from:
- /library/String/SuffixArray.h
- /library/String/SuffixArray.h.html
title: String/SuffixArray.h
---
