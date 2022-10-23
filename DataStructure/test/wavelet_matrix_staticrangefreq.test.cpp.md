---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix.h
    title: DataStructure/WaveletMatrix.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/WaveletMatrix.h\"\
    \n// WaveletMatrix {{{\n// Copied from https://github.com/dacin21/dacin21_codebook/blob/master/trees/wavelet_matrix.cpp\n\
    //\n// Notes:\n// - Index from 0\n// - k (for k-th query) from 0\n// - Need to\
    \ remove #define int long long\n//\n// Tested:\n// - (kth query) https://judge.yosupo.jp/problem/range_kth_smallest\n\
    // - (range_count) https://judge.yosupo.jp/problem/static_range_frequency\n\n\
    // Bit Presum {{{\nclass Bit_Presum {\npublic:\n    static constexpr uint32_t\
    \ omega = CHAR_BIT * sizeof(uint64_t);\n    static constexpr uint32_t lg_omega\
    \ = __lg(omega);\n    static_assert(omega == 64u);\n\n    Bit_Presum(vector<uint64_t>\
    \ mask_)\n            : n(mask_.size()), mask(move(mask_)), presum(n+1) {\n  \
    \      build();\n    }\n    Bit_Presum(uint32_t bits, bool init_val = 0)\n   \
    \         : n((bits>>lg_omega) + 1),\n              mask(n, init_val ? ~uint64_t{0}\
    \ : uint64_t{0}),\n              presum(n+1) {\n        if (init_val) mask.back()<<=((n<<lg_omega)\
    \ - bits);\n        build();\n    }\n    // popcount l <= i < r\n    uint32_t\
    \ query(uint32_t l, uint32_t r) const {\n        if (__builtin_expect(r < l, false))\
    \ return 0;\n        return query(r) - query(l);\n    }\n    // popcount 0 <=\
    \ i < x\n    uint32_t query(uint32_t x) const {\n        uint32_t high = x>>lg_omega,\
    \ low = x & ((uint64_t{1}<<lg_omega) - 1);\n        uint32_t ret = presum_query(high);\n\
    \        ret += __builtin_popcountll(mask[high]& ((uint64_t{1} << low)-1));\n\
    \        return ret;\n    }\n\n    void update_pre_build(uint32_t x, bool val)\
    \ {\n        uint32_t high = x>>lg_omega, low = x & ((1u<<lg_omega) - 1);\n  \
    \      mask[high] = (mask[high] & ~(uint64_t{1} << low)) | (uint64_t{val}<<low);\n\
    \    }\n    void do_build() {\n        build();\n    }\n\n    friend ostream&\
    \ operator<<(ostream&o, Bit_Presum const&b) {\n        for (auto const& e : b.mask)\
    \ {\n            stringstream ss;\n            ss << bitset<omega>(e);\n     \
    \       auto s = ss.str();\n            reverse(s.begin(), s.end());\n       \
    \     o << s << \"|\";\n        }\n        o << \" : \";\n        for (auto const&e:b.presum)\
    \ o << e << \" \";\n        o << \"\\n\";\n        return o;\n    }\n\nprivate:\n\
    \    void presum_build() {\n        for (uint32_t x = 1; x <= n; ++x) {\n    \
    \        presum[x] += presum[x-1];\n        }\n    }\n    // sum 0 <= i < x\n\
    \    uint32_t presum_query(uint32_t x) const {\n        return presum[x];\n  \
    \  }\n    void build() {\n        for (uint32_t x = 0; x < n; ++x) {\n       \
    \     presum[x+1] = __builtin_popcountll(mask[x]);\n        }\n        presum_build();\n\
    \    }\n\n    const uint32_t n;\n    vector<uint64_t> mask;\n    vector<uint32_t>\
    \ presum;\n};\n// }}}\n\ntemplate<typename T, typename Bit_Ds = Bit_Presum>\n\
    class WaveletMatrix {\npublic:\n    static_assert(is_integral<T>::value);\n  \
    \  static constexpr uint32_t height = CHAR_BIT * sizeof(T);\n\n    WaveletMatrix(vector<T>\
    \ v): n(v.size()), data(height, n) {\n        build(move(v));\n    }\n    // count\
    \ l <= i < r  s.t.  A <= val[i] < B\n    uint32_t range_count(int l, int r, T\
    \ A, T B) const {\n        assert(0 <= l && r <= n);\n        return count_lower(l,\
    \ r, B) - count_lower(l, r, A);\n    }\n    // count l <= i < r  s.t.  A <= val[i]\n\
    \    uint32_t range_count_up(int l, int r, T A) const {\n        assert(0 <= l\
    \ && r <= n);\n        if (__builtin_expect(l>r, false)) return uint32_t{0};\n\
    \        return (r-l) - count_lower(l, r, A);\n    }\n    // k from 0\n    //\
    \ range: [l, r-1]\n    T k_th(int l, int r, int k) const {\n        assert(0 <=\
    \ k && k < n);\n        return get_kth(l, r, k);\n    }\n\n    // internal functions\
    \ {{{\nprivate:\n    void build(vector<T> v) {\n        m_index.resize(height);\n\
    \        T const a = numeric_limits<T>::min();\n        for (int h = height-1;\
    \ h>=0;--h) {\n            T const b = a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0,\
    \ h-1)));\n            for (int i=0;i<n;++i) {\n                data[h].update_pre_build(i,\
    \ v[i]<b);\n            }\n            data[h].do_build();\n            const\
    \ int m = stable_partition(v.begin(), v.end(), [&b](T const&x) {return x < b;})\
    \ - v.begin();\n            for (int i=m;i<n;++i) {\n                v[i] = v[i]\
    \ - (T{1}<<(max(0, h-1))) + !h - (T{1}<<(max(0, h-1)));\n            }\n     \
    \       m_index[h] = m;\n        }\n    }\n    /// count l <= i < r  s.t.  val[i]\
    \ < B\n    uint32_t count_lower(int l, int r, T const&B) const {\n        assert(0\
    \ <= l && r <= n);\n        if (__builtin_expect(r<l, false)) return 0;\n    \
    \    uint32_t ret = 0;\n        int h = height;\n        T a = numeric_limits<T>::min();\n\
    \        while(h > 0) {\n            --h;\n\t\t\tbool go_left = B < a + (T{1}<<(max(0,\
    \ h-1))) - !h + (T{1}<<(max(0, h-1)));\n            const int low_l = data[h].query(l),\
    \ low_r = data[h].query(r);\n            if (go_left) {\n                l = low_l;\n\
    \                r = low_r;\n            } else {\n                a = a + (T{1}<<(max(0,\
    \ h-1))) - !h + (T{1}<<(max(0, h-1)));\n                ret+= low_r-low_l;\n \
    \               l = m_index[h] + l-low_l;\n                r = m_index[h] + r-low_r;\n\
    \            }\n        }\n        return ret;\n    }\n    T get_kth(int l, int\
    \ r, int k) const {\n        assert(0 <= l && r <= n);\n        assert(0 <= k\
    \ && k < r-l);\n        int h = height;\n        T a = numeric_limits<T>::min();\n\
    \        while (h > 0) {\n            --h;\n            const int low_l = data[h].query(l),\
    \ low_r = data[h].query(r), low_lr = low_r-low_l;\n            bool go_left =\
    \ k < low_lr;\n            if (go_left) {\n                l = low_l;\n      \
    \          r = low_r;\n            } else {\n                a+= T{1}<<h;\n  \
    \              k-= low_lr;\n                l = m_index[h] + l-low_l;\n      \
    \          r = m_index[h] + r-low_r;\n            }\n        }\n        return\
    \ a;\n    }\n\n    const int n;\n    vector<int> m_index;\n    vector<Bit_Ds>\
    \ data;\n    // }}}\n};\n// }}}\n#line 7 \"DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q;\
    \ cin >> n >> q;\n    vector<int> a(n);\n    for (int& x : a) cin >> x;\n\n  \
    \  WaveletMatrix<int> wm(a);\n    while (q--) {\n        int l, r, x; cin >> l\
    \ >> r >> x;\n        cout << wm.range_count(l, r, x, x+1) << '\\n';\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../WaveletMatrix.h\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q;\
    \ cin >> n >> q;\n    vector<int> a(n);\n    for (int& x : a) cin >> x;\n\n  \
    \  WaveletMatrix<int> wm(a);\n    while (q--) {\n        int l, r, x; cin >> l\
    \ >> r >> x;\n        cout << wm.range_count(l, r, x, x+1) << '\\n';\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - DataStructure/WaveletMatrix.h
  isVerificationFile: true
  path: DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp
  requiredBy: []
  timestamp: '2022-10-24 01:33:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp
- /verify/DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp.html
title: DataStructure/test/wavelet_matrix_staticrangefreq.test.cpp
---
