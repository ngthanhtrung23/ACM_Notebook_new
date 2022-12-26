---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.h
    title: DataStructure/RMQ.h
  - icon: ':heavy_check_mark:'
    path: Math/modint.h
    title: Math/modint.h
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.h
    title: String/SuffixArray.h
  - icon: ':heavy_check_mark:'
    path: String/hash.h
    title: String/hash.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
  bundledCode: "#line 1 \"String/tests/suffix_array_queries.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"String/SuffixArray.h\"\
    \n// Efficient O(N + alphabet_size) time and space suffix array\n// For ICPC notebook,\
    \ it's better to copy a shorter code such as\n// https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/SuffixArray.h\n\
    \n// Usage:\n// - sa = suffix_array(s, 'a', 'z')\n// - lcp = LCP(s, sa)\n//  \
    \ lcp[i] = LCP(sa[i], sa[i+1])\n//\n// Tested:\n// - SA https://judge.yosupo.jp/problem/suffixarray\n\
    // - SA https://www.spoj.com/problems/SARRAY/\n// - LCP https://judge.yosupo.jp/problem/number_of_substrings\n\
    // Suffix Array {{{\n// Copied from https://judge.yosupo.jp/submission/52300\n\
    // Helper functions {{{\nvoid induced_sort(const std::vector<int>& vec, int val_range,\n\
    \                  std::vector<int>& SA, const std::vector<bool>& sl,\n      \
    \            const std::vector<int>& lms_idx) {\n    std::vector<int> l(val_range,\
    \ 0), r(val_range, 0);\n    for (int c : vec) {\n        if (c + 1 < val_range)\
    \ ++l[c + 1];\n        ++r[c];\n    }\n    std::partial_sum(l.begin(), l.end(),\
    \ l.begin());\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    std::fill(SA.begin(),\
    \ SA.end(), -1);\n    for (int i = (int)lms_idx.size() - 1; i >= 0; --i)\n   \
    \     SA[--r[vec[lms_idx[i]]]] = lms_idx[i];\n    for (int i : SA)\n        if\
    \ (i >= 1 && sl[i - 1]) SA[l[vec[i - 1]]++] = i - 1;\n    std::fill(r.begin(),\
    \ r.end(), 0);\n    for (int c : vec) ++r[c];\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1;\
    \ --k, i = SA[k])\n        if (i >= 1 && !sl[i - 1]) {\n            SA[--r[vec[i\
    \ - 1]]] = i - 1;\n        }\n}\n\nstd::vector<int> SA_IS(const std::vector<int>&\
    \ vec, int val_range) {\n    const int n = vec.size();\n    std::vector<int> SA(n),\
    \ lms_idx;\n    std::vector<bool> sl(n);\n    sl[n - 1] = false;\n    for (int\
    \ i = n - 2; i >= 0; --i) {\n        sl[i] = (vec[i] > vec[i + 1] || (vec[i] ==\
    \ vec[i + 1] && sl[i + 1]));\n        if (sl[i] && !sl[i + 1]) lms_idx.push_back(i\
    \ + 1);\n    }\n    std::reverse(lms_idx.begin(), lms_idx.end());\n    induced_sort(vec,\
    \ val_range, SA, sl, lms_idx);\n    std::vector<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n        if\
    \ (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n            new_lms_idx[k++]\
    \ = SA[i];\n        }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t\
    \ k = 1; k < new_lms_idx.size(); ++k) {\n        int i = new_lms_idx[k - 1], j\
    \ = new_lms_idx[k];\n        if (vec[i] != vec[j]) {\n            SA[j] = ++cur;\n\
    \            continue;\n        }\n        bool flag = false;\n        for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n            if (vec[a] != vec[b]) {\n  \
    \              flag = true;\n                break;\n            }\n         \
    \   if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n                flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n                break;\n\
    \            }\n        }\n        SA[j] = (flag ? ++cur : cur);\n    }\n    for\
    \ (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if\
    \ (cur + 1 < (int)lms_idx.size()) {\n        auto lms_SA = SA_IS(lms_vec, cur\
    \ + 1);\n        for (size_t i = 0; i < lms_idx.size(); ++i) {\n            new_lms_idx[i]\
    \ = lms_idx[lms_SA[i]];\n        }\n    }\n    induced_sort(vec, val_range, SA,\
    \ sl, new_lms_idx);\n    return SA;\n}\n// }}}\n\ntemplate<typename ContainerT\
    \ = std::string, typename ElemT = unsigned char>\nstd::vector<int> suffix_array(const\
    \ ContainerT& s, const ElemT first = 'a',\n                         const ElemT\
    \ last = 'z') {\n    std::vector<int> vec(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vec));\n    for (auto& x : vec) x -= (int)first - 1;\n\
    \    vec.back() = 0;\n    auto ret = SA_IS(vec, (int)last - (int)first + 2);\n\
    \    ret.erase(ret.begin());\n    return ret;\n}\n// Author: https://codeforces.com/blog/entry/12796?#comment-175287\n\
    // Uses kasai's algorithm linear in time and space\nstd::vector<int> LCP(const\
    \ std::string& s, const std::vector<int>& sa) {\n    int n = s.size(), k = 0;\n\
    \    std::vector<int> lcp(n), rank(n);\n    for (int i = 0; i < n; i++) rank[sa[i]]\
    \ = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n        if (rank[i] ==\
    \ n - 1) {\n            k = 0;\n            continue;\n        }\n        int\
    \ j = sa[rank[i] + 1];\n        while (i + k < n && j + k < n && s[i + k] == s[j\
    \ + k]) k++;\n        lcp[rank[i]] = k;\n    }\n    lcp[n - 1] = 0;\n    return\
    \ lcp;\n}\n// }}}\n// Number of distinct substrings {{{\n// Tested:\n// - https://judge.yosupo.jp/problem/number_of_substrings\n\
    // - https://www.spoj.com/problems/SUBST1/\nint64_t cnt_distinct_substrings(const\
    \ std::string& s) {\n    auto lcp = LCP(s, suffix_array(s, 0, 255));\n    return\
    \ s.size() * (int64_t) (s.size() + 1) / 2\n        - std::accumulate(lcp.begin(),\
    \ lcp.end(), 0LL);\n}\n// }}}\n// K-th distinct substring {{{\n// Tested:\n//\
    \ - https://cses.fi/problemset/task/2108\n// - https://www.spoj.com/problems/SUBLEX/\n\
    \n// Consider all distinct substring of string `s` in lexicographically increasing\n\
    // order. Find k-th substring.\n//\n// Preprocessing: O(N)\n// Each query: O(log(N))\n\
    //\n// Returns {start index, length}. If not found -> {-1, -1}\nstd::vector<std::pair<int,int>>\
    \ kth_distinct_substring(\n        const std::string& s,\n        const std::vector<int64_t>&\
    \ ks) {\n    if (s.empty()) {\n        return {};\n    }\n    auto sa = suffix_array(s,\
    \ 0, 255);\n    auto lcp = LCP(s, sa);\n    int n = s.size();\n    \n    // for\
    \ each suffix (in increasing order), we count how many new distinct\n    // substrings\
    \ it create\n    std::vector<int64_t> n_new_substrs(n);\n    for (int i = 0; i\
    \ < n; ++i) {\n        int substr_len = n - sa[i];\n        int new_substr_start\
    \ = (i > 0 ? lcp[i-1] : 0);\n        n_new_substrs[i] = substr_len - new_substr_start;\n\
    \    }\n    std::partial_sum(n_new_substrs.begin(), n_new_substrs.end(), n_new_substrs.begin());\n\
    \n    std::vector<std::pair<int,int>> res;\n    for (int64_t k : ks) {\n     \
    \   if (k > *n_new_substrs.rbegin()) {\n            res.emplace_back(-1, -1);\n\
    \        } else {\n            int i = std::lower_bound(n_new_substrs.begin(),\
    \ n_new_substrs.end(), k) - n_new_substrs.begin();\n            int new_substr_start\
    \ = (i > 0 ? lcp[i-1] : 0);\n            if (i > 0) k -= n_new_substrs[i-1];\n\
    \            res.emplace_back(sa[i], new_substr_start + k);\n        }\n    }\n\
    \    return res;\n}\n// }}}\n// Count substring occurrences {{{\n// given string\
    \ S and Q queries pat_i, for each query, count how many\n// times pat_i appears\
    \ in S\n// O(min(|S|, |pat|) * log(|S|)) per query\n//\n// Tested:\n// - (yes\
    \ / no) https://cses.fi/problemset/task/2102\n// - (count) https://cses.fi/problemset/task/2103\n\
    // - (position; need RMQ) https://cses.fi/problemset/task/2104\nint cnt_occurrences(const\
    \ string& s, const vector<int>& sa, const string& pat) {\n    int n = s.size(),\
    \ m = pat.size();\n    assert(n == (int) sa.size());\n    if (n < m) return 0;\n\
    \ \n    auto f = [&] (int start) {  // compare S[start..] and pat[0..]\n     \
    \   for (int i = 0; start + i < n && i < m; ++i) {\n            if (s[start +\
    \ i] < pat[i]) return true;\n            if (s[start + i] > pat[i]) return false;\n\
    \        }\n        return n - start < m;\n    };\n    auto g = [&] (int start)\
    \ {\n        for (int i = 0; start + i < n && i < m; ++i) {\n            if (s[start\
    \ + i] > pat[i]) return false;\n        }\n        return true;\n    };\n    auto\
    \ l = std::partition_point(sa.begin(), sa.end(), f);\n    auto r = std::partition_point(l,\
    \ sa.end(), g);\n    // To find first occurrence, return min of sa in range [l,\
    \ r)\n    // See https://cses.fi/problemset/task/2104\n    return std::distance(l,\
    \ r);\n}\n// }}}\n// Count substring occurrences using hash {{{\n// If hash array\
    \ can be pre-computed, can answer each query in\n// O(log(|S|) * log(|S| + |pat|)\n\
    // Tested\n// - https://oj.vnoi.info/problem/icpc22_mt_b\n#line 1 \"Math/modint.h\"\
    \n// ModInt {{{\ntemplate<int MD> struct ModInt {\n    using ll = long long;\n\
    \    int x;\n\n    constexpr ModInt() : x(0) {}\n    constexpr ModInt(ll v) {\
    \ _set(v % MD + MD); }\n    constexpr static int mod() { return MD; }\n    constexpr\
    \ explicit operator bool() const { return x != 0; }\n\n    constexpr ModInt operator\
    \ + (const ModInt& a) const {\n        return ModInt()._set((ll) x + a.x);\n \
    \   }\n    constexpr ModInt operator - (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x - a.x + MD);\n    }\n    constexpr ModInt operator * (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x * a.x % MD);\n    }\n\
    \    constexpr ModInt operator / (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x * a.inv().x % MD);\n    }\n    constexpr ModInt operator - () const {\n  \
    \      return ModInt()._set(MD - x);\n    }\n\n    constexpr ModInt& operator\
    \ += (const ModInt& a) { return *this = *this + a; }\n    constexpr ModInt& operator\
    \ -= (const ModInt& a) { return *this = *this - a; }\n    constexpr ModInt& operator\
    \ *= (const ModInt& a) { return *this = *this * a; }\n    constexpr ModInt& operator\
    \ /= (const ModInt& a) { return *this = *this / a; }\n\n    friend constexpr ModInt\
    \ operator + (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD +\
    \ b.x);\n    }\n    friend constexpr ModInt operator - (ll a, const ModInt& b)\
    \ {\n        return ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr\
    \ ModInt operator * (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.x % MD);\n    }\n    friend constexpr ModInt operator / (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\
    \n    constexpr bool operator == (const ModInt& a) const { return x == a.x; }\n\
    \    constexpr bool operator != (const ModInt& a) const { return x != a.x; }\n\
    \n    friend std::istream& operator >> (std::istream& is, ModInt& x) {\n     \
    \   ll val; is >> val;\n        x = ModInt(val);\n        return is;\n    }\n\
    \    constexpr friend std::ostream& operator << (std::ostream& os, const ModInt&\
    \ x) {\n        return os << x.x;\n    }\n\n    constexpr ModInt pow(ll k) const\
    \ {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n            if (k\
    \ & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n        }\n\
    \        return ans;\n    }\n\n    constexpr ModInt inv() const {\n        if\
    \ (x < 1000111) {\n            _precalc(1000111);\n            return invs[x];\n\
    \        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while (b) {\n\
    \            int q = a/b, t = a%b;\n            a = b; b = t;\n            t =\
    \ ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a == 1);\n\
    \        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static std::vector<ModInt>\
    \ factorials, inv_factorials, invs;\n    constexpr static void _precalc(int n)\
    \ {\n        if (factorials.empty()) {\n            factorials = {1};\n      \
    \      inv_factorials = {1};\n            invs = {0};\n        }\n        if (n\
    \ > MD) n = MD;\n        int old_sz = factorials.size();\n        if (n <= old_sz)\
    \ return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
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
    }\nbool operator < (const Hash& a, const Hash& b) {\n    if (a.x != b.x) return\
    \ a.x < b.x;\n    return a.y.x < b.y.x;\n}\nstd::ostream& operator << (std::ostream&\
    \ out, const Hash& h) {\n    out << '(' << h.x << \", \" << h.y << ')';\n    return\
    \ out;\n}\n\n// hash function for std::unordered_map\nnamespace std {\n    template<>\n\
    \    struct hash<Hash> {\n        public:\n            size_t operator() (const\
    \ Hash& h) const {\n                return h.x * 1000000009 + h.y.x;\n       \
    \     }\n    };\n}\n\nstruct HashGenerator {\n    HashGenerator(int maxLen, int\
    \ base = 311) {\n        p.resize(maxLen + 1);\n        p[0] = {1, 1};\n     \
    \   for (int i = 1; i <= maxLen; i++) {\n            p[i] = p[i-1] * base;\n \
    \       }\n    }\n\n    template<typename Container>\n    std::vector<Hash> hash(const\
    \ Container& s) const {\n        std::vector<Hash> res(s.size());\n        for\
    \ (size_t i = 0; i < s.size(); i++) {\n            res[i] = p[i] * (int) s[i];\n\
    \        }\n        std::partial_sum(res.begin(), res.end(), res.begin());\n \
    \       return res;\n    }\n\n    Hash getHash(const std::vector<Hash>& h, int\
    \ l, int r) const {\n        return __getHash(h, l, r) * p[p.size() - 1 - l];\n\
    \    }\n\n    // compare [l1, r1] vs [l2, r2]\n    bool equals(\n            const\
    \ std::vector<Hash>& h1, int l1, int r1,\n            const std::vector<Hash>&\
    \ h2, int l2, int r2) const {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int)\
    \ h1.size());\n        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\
    \        if (r1 - l1 != r2 - l2) return false;\n\n        return getHash(h1, l1,\
    \ r1) == getHash(h2, l2, r2);\n    }\n\n    // Returns length of max common prefix\
    \ of h1[l1, r1] and h2[l2, r2]\n    // length = 0 -> first character of 2 substrings\
    \ are different.\n    int maxCommonPrefix(\n            const std::vector<Hash>&\
    \ h1, int l1, int r1,\n            const std::vector<Hash>& h2, int l2, int r2)\
    \ const {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());\n    \
    \    assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n        int len1\
    \ = r1 - l1 + 1;\n        int len2 = r2 - l2 + 1;\n\n        int res = -1, left\
    \ = 0, right = std::min(len1, len2) - 1;\n        while (left <= right) {\n  \
    \          int mid = (left + right) / 2;\n            if (equals(h1, l1, l1 +\
    \ mid, h2, l2, l2 + mid)) {\n                res = mid;\n                left\
    \ = mid + 1;\n            } else {\n                right = mid - 1;\n       \
    \     }\n        }\n        return res + 1;\n        /* C++20\n        auto r\
    \ = std::views::iota(0, std::min(len1, len2));\n        auto res = std::ranges::partition_point(\n\
    \                r,\n                [&] (int mid) {\n                    return\
    \ equals(h1, l1, l1+mid, h2, l2, l2+mid);\n                });\n        return\
    \ *res;\n         */\n    }\n\n    // compare s1[l1, r1] and s2[l2, r2]\n    template<typename\
    \ Container1, typename Container2>\n    int cmp(\n            const Container1&\
    \ s1, const std::vector<Hash>& h1, int l1, int r1,\n            const Container2&\
    \ s2, const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0 <=\
    \ l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <= r2\
    \ && r2 < (int) h2.size());\n\n        int commonPrefixLen = maxCommonPrefix(h1,\
    \ l1, r1, h2, l2, r2);\n        char c1 = (l1 + commonPrefixLen <= r1) ? s1[l1\
    \ + commonPrefixLen] : 0;\n        char c2 = (l2 + commonPrefixLen <= r2) ? s2[l2\
    \ + commonPrefixLen] : 0;\n\n        return (c1 == c2) ? 0 : ((c1 < c2) ? -1 :\
    \ 1);\n    }\n\nprivate:\n    std::vector<Hash> p;\n\n    // DO NOT USE, this\
    \ doesn't divide by p[l]\n    Hash __getHash(const std::vector<Hash>& h, int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r < (int) h.size());\n  \
    \      return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n// }}}\n#line\
    \ 216 \"String/SuffixArray.h\"\nint cnt_occurrences_hash(\n        const vector<int>&\
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
    \ sa.end(), g);\n    return std::distance(l, r);\n}\n// }}}\n// Returns length\
    \ of LCS of strings s & t {{{\n// O(N)\n// Tested:\n// - https://www.spoj.com/problems/LCS/\n\
    // - https://www.spoj.com/problems/ADAPHOTO/\nint longestCommonSubstring(const\
    \ string& s, const string& t) {\n    char c = 127;\n    string combined = s +\
    \ c + t;\n    auto sa = suffix_array(combined, 0, 127);\n    auto lcp = LCP(combined,\
    \ sa);\n \n    // s -> 0 .. |s|-1\n    // 255 -> |s|\n    // t -> |s|+1 ..\n \
    \   int ls = s.size(), lcombined = combined.size();\n    auto is_s = [&] (int\
    \ id) { return sa[id] < ls; };\n    auto is_t = [&] (int id) { return sa[id] >\
    \ ls; };\n \n    assert(sa[lcombined - 1] == ls);\n \n    int res = 0;\n    for\
    \ (int i = 0; i < lcombined - 2; ++i) {\n        if ((is_s(i) && is_t(i+1)) ||\
    \ (is_s(i+1) && is_t(i))) {\n            res = max(res, lcp[i]);\n        }\n\
    \    }\n    return res;\n}\n// }}}\n// Returns length of LCS of n strings {{{\n\
    // Tested:\n// - https://www.spoj.com/problems/LCS2/\n// - https://www.spoj.com/problems/LONGCS\n\
    #line 1 \"DataStructure/RMQ.h\"\n// RMQ {{{\n//\n// Sparse table\n// Usage:\n\
    // RMQ<int, _min> st(v);\n//\n// Note:\n// - doesn't work for empty range\n//\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\ntemplate<class T,\
    \ T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const vector<T>&\
    \ v) : t{v}, n{(int) v.size()} {\n        for (int k = 1; (1<<k) <= n; ++k) {\n\
    \            t.emplace_back(n - (1<<k) + 1);\n            for (int i = 0; i +\
    \ (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i + (1<<(k-1))]);\n\
    \            }\n        }\n    }\n\n    // get range [l, r-1]\n    // doesn't\
    \ work for empty range\n    T get(int l, int r) const {\n        assert(0 <= l\
    \ && l < r && r <= n);\n        int k = __lg(r - l);\n        return op(t[k][l],\
    \ t[k][r - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n    int n;\n\
    };\ntemplate<class T> T _min(T a, T b) { return b < a ? b : a; }\ntemplate<class\
    \ T> T _max(T a, T b) { return a < b ? b : a; }\n// }}}\n#line 281 \"String/SuffixArray.h\"\
    \nint longestCommonSubstring(const std::vector<std::string> strs) {\n    char\
    \ c = 127;\n    string combined = \"\";\n    vector<int> ids;\n    for (size_t\
    \ i = 0; i < strs.size(); ++i) {\n        const auto& s = strs[i];\n        combined\
    \ += s;\n        while (ids.size() < combined.size()) ids.push_back(i);\n\n  \
    \      combined += c;\n        ids.push_back(-1);\n\n        --c;\n    }\n   \
    \ auto sa = suffix_array(combined, 0, 127);\n    auto lcp = LCP(combined, sa);\n\
    \    RMQ<int, _min> rmq(lcp);\n\n    // count frequency of i-th string in current\
    \ window\n    std::vector<int> cnt(strs.size(), 0);\n    int strs_in_window =\
    \ 0;\n    auto add = [&] (int i) {\n        if (i < 0) return;\n        ++cnt[i];\n\
    \        if (cnt[i] == 1) ++strs_in_window;\n    };\n    auto rem = [&] (int i)\
    \ {\n        if (i < 0) return;\n        --cnt[i];\n        if (cnt[i] == 0) --strs_in_window;\n\
    \    };\n\n    int i = 0, j = -1;\n    int lcombined = combined.size();\n    int\
    \ n = strs.size();\n    int res = 0;\n    while (i < lcombined - 1) {\n      \
    \  while (j + 1 < lcombined - 1 && strs_in_window < n) {\n            ++j;\n \
    \           add(ids[sa[j]]);\n        }\n        if (strs_in_window == n) {\n\
    \            res = max(res, rmq.get(i, j));\n        }\n\n        rem(ids[sa[i]]);\
    \ ++i;\n    }\n    return res;\n}\n// }}}\n#line 7 \"String/tests/suffix_array_queries.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    string s, pat;\n\
    \    int q;\n    cin >> s >> q;\n    auto sa = suffix_array(s, 0, 255);\n    while\
    \ (q--) {\n        cin >> pat;\n        int cnt = cnt_occurrences(s, sa, pat);\n\
    \        cout << (cnt ? 1 : 0) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../SuffixArray.h\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    string s, pat;\n\
    \    int q;\n    cin >> s >> q;\n    auto sa = suffix_array(s, 0, 255);\n    while\
    \ (q--) {\n        cin >> pat;\n        int cnt = cnt_occurrences(s, sa, pat);\n\
    \        cout << (cnt ? 1 : 0) << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - String/SuffixArray.h
  - String/hash.h
  - Math/modint.h
  - DataStructure/RMQ.h
  isVerificationFile: true
  path: String/tests/suffix_array_queries.test.cpp
  requiredBy: []
  timestamp: '2022-11-19 23:37:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/tests/suffix_array_queries.test.cpp
layout: document
redirect_from:
- /verify/String/tests/suffix_array_queries.test.cpp
- /verify/String/tests/suffix_array_queries.test.cpp.html
title: String/tests/suffix_array_queries.test.cpp
---
