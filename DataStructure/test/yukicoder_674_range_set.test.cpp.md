---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RangeSet.h
    title: DataStructure/RangeSet.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/674
    links:
    - https://yukicoder.me/problems/no/674
  bundledCode: "#line 1 \"DataStructure/test/yukicoder_674_range_set.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/674\"\n\n#line 1 \"template.h\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define FOR(i,a,b) for(int\
    \ i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b;\
    \ i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin())\
    \ it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \"\
    \ = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
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
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/RangeSet.h\"\n// RangeSet\
    \ - for maintaining set of segments {{{\n//\n// merge_adjacent_segment = true\
    \ -> merge 2 consecutive segments,\n// e.g. [1, 10] and [11, 20] --> [1, 20]\n\
    //\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp\n\
    template<typename T, bool merge_adjacent_segment = true>\nstruct RangeSet {\n\
    \    T n_elements() const { return sz; }\n    T n_ranges() const { return ranges.size();\
    \ }\n\n    bool contains(T x) const {\n        auto it = ranges.upper_bound(x);\n\
    \        return it != ranges.begin() && x <= std::prev(it)->second;\n    }\n\n\
    \    // Find range containing x, i.e. l <= x <= r\n    std::optional<std::pair<T,\
    \ T>> find_range(T x) const {\n        auto it = ranges.upper_bound(x);\n    \
    \    if (it == ranges.begin()) return std::nullopt;\n        --it;\n        return\
    \ (x <= it->second) ? std::optional<std::pair<T, T>>{*it} : std::nullopt;\n  \
    \  }\n\n    // Insert [l, r]\n    // Returns number of new integers added.\n \
    \   // AMORTIZED O(logN)\n    T insert(T l, T r) {\n        assert(l <= r);\n\
    \        auto it = ranges.upper_bound(l);\n        if (it != ranges.begin() &&\
    \ is_mergeable(std::prev(it)->second, l)) {\n            it = std::prev(it);\n\
    \            l = std::min(l, it->first);\n        }\n        T inserted = 0;\n\
    \        for (; it != ranges.end() && is_mergeable(r, it->first); it = ranges.erase(it))\
    \ {\n            auto [cl, cr] = *it;\n            r = std::max(r, cr);\n    \
    \        inserted -= cr - cl + 1;\n        }\n\n        inserted += r - l + 1;\n\
    \        ranges[l] = r;\n        sz += inserted;\n        return inserted;\n \
    \   }\n\n    // Erase [l, r]\n    // Returns number of integers removed\n    //\
    \ AMORTIZED O(logN)\n    T erase(T l, T r) {\n        assert(l <= r);\n      \
    \  T tl = l, tr = r;\n        auto it = ranges.upper_bound(l);\n        if (it\
    \ != ranges.begin() && l <= std::prev(it)->second) {\n            it = std::prev(it);\n\
    \            tl = it->first;\n        }\n\n        T erased = 0;\n        for\
    \ (; it != ranges.end() && it->first <= r; it = ranges.erase(it)) {\n        \
    \    auto [cl, cr] = *it;\n            tr = cr;\n            erased += cr - cl\
    \ + 1;\n        }\n        if (tl < l) {\n            ranges[tl] = l-1;\n    \
    \        erased -= l - tl;\n        }\n        if (r < tr) {\n            ranges[r\
    \ + 1] = tr;\n            erased -= tr - r;\n        }\n        sz -= erased;\n\
    \        return erased;\n    }\n\n    // Find min x: x >= lower && x NOT in this\
    \ set\n    T minimum_excluded(T lower) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(lower);\n        return it == ranges.end() ? lower\
    \ : it->second + 1;\n    }\n\n    // Find max x: x <= upper && x NOT in this set\n\
    \    T maximum_excluded(T upper) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(upper);\n        return it == ranges.end() ? upper\
    \ : it->first - 1;\n    }\n\n    T sz = 0;\n    std::map<T, T> ranges;\n\n   \
    \ bool is_mergeable(T cur_r, T next_l) {\n        return next_l <= cur_r + merge_adjacent_segment;\n\
    \    }\n};\n// }}}\n#line 5 \"DataStructure/test/yukicoder_674_range_set.test.cpp\"\
    \n\nvoid solve() {\n    long long d;\n    int q;\n    std::cin >> d >> q;\n\n\
    \    long long ans = 0;\n    RangeSet<long long> set;\n    while (q --> 0) {\n\
    \        long long l, r;\n        std::cin >> l >> r;\n        set.insert(l, r);\n\
    \        auto lr_opt = set.find_range(l);\n        if (lr_opt.has_value()) {\n\
    \            auto [nl, nr] = lr_opt.value();\n            ans = std::max(ans,\
    \ nr - nl + 1LL);\n        }\n        std::cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/674\"\n\n#include \"../../template.h\"\
    \n#include \"../RangeSet.h\"\n\nvoid solve() {\n    long long d;\n    int q;\n\
    \    std::cin >> d >> q;\n\n    long long ans = 0;\n    RangeSet<long long> set;\n\
    \    while (q --> 0) {\n        long long l, r;\n        std::cin >> l >> r;\n\
    \        set.insert(l, r);\n        auto lr_opt = set.find_range(l);\n       \
    \ if (lr_opt.has_value()) {\n            auto [nl, nr] = lr_opt.value();\n   \
    \         ans = std::max(ans, nr - nl + 1LL);\n        }\n        std::cout <<\
    \ ans << '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/RangeSet.h
  isVerificationFile: true
  path: DataStructure/test/yukicoder_674_range_set.test.cpp
  requiredBy: []
  timestamp: '2022-08-15 00:18:10+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/yukicoder_674_range_set.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/yukicoder_674_range_set.test.cpp
- /verify/DataStructure/test/yukicoder_674_range_set.test.cpp.html
title: DataStructure/test/yukicoder_674_range_set.test.cpp
---
