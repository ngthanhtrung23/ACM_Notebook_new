// Efficient O(N + alphabet_size) time and space suffix array
// For ICPC notebook, it's better to copy a shorter code such as
// https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/SuffixArray.h

// Usage:
// - sa = suffix_array(s, 'a', 'z')
// - lcp = LCP(s, sa)
//   lcp[i] = LCP(sa[i], sa[i+1])
//
// Tested:
// - SA https://judge.yosupo.jp/problem/suffixarray
// - SA https://www.spoj.com/problems/SARRAY/
// - LCP https://judge.yosupo.jp/problem/number_of_substrings
// Suffix Array {{{
// Copied from https://judge.yosupo.jp/submission/52300
// Helper functions {{{
void induced_sort(const std::vector<int>& vec, int val_range,
                  std::vector<int>& SA, const std::vector<bool>& sl,
                  const std::vector<int>& lms_idx) {
    std::vector<int> l(val_range, 0), r(val_range, 0);
    for (int c : vec) {
        if (c + 1 < val_range) ++l[c + 1];
        ++r[c];
    }
    std::partial_sum(l.begin(), l.end(), l.begin());
    std::partial_sum(r.begin(), r.end(), r.begin());
    std::fill(SA.begin(), SA.end(), -1);
    for (int i = (int)lms_idx.size() - 1; i >= 0; --i)
        SA[--r[vec[lms_idx[i]]]] = lms_idx[i];
    for (int i : SA)
        if (i >= 1 && sl[i - 1]) SA[l[vec[i - 1]]++] = i - 1;
    std::fill(r.begin(), r.end(), 0);
    for (int c : vec) ++r[c];
    std::partial_sum(r.begin(), r.end(), r.begin());
    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
        if (i >= 1 && !sl[i - 1]) {
            SA[--r[vec[i - 1]]] = i - 1;
        }
}

std::vector<int> SA_IS(const std::vector<int>& vec, int val_range) {
    const int n = vec.size();
    std::vector<int> SA(n), lms_idx;
    std::vector<bool> sl(n);
    sl[n - 1] = false;
    for (int i = n - 2; i >= 0; --i) {
        sl[i] = (vec[i] > vec[i + 1] || (vec[i] == vec[i + 1] && sl[i + 1]));
        if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);
    }
    std::reverse(lms_idx.begin(), lms_idx.end());
    induced_sort(vec, val_range, SA, sl, lms_idx);
    std::vector<int> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
    for (int i = 0, k = 0; i < n; ++i)
        if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {
            new_lms_idx[k++] = SA[i];
        }
    int cur = 0;
    SA[n - 1] = cur;
    for (size_t k = 1; k < new_lms_idx.size(); ++k) {
        int i = new_lms_idx[k - 1], j = new_lms_idx[k];
        if (vec[i] != vec[j]) {
            SA[j] = ++cur;
            continue;
        }
        bool flag = false;
        for (int a = i + 1, b = j + 1;; ++a, ++b) {
            if (vec[a] != vec[b]) {
                flag = true;
                break;
            }
            if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {
                flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));
                break;
            }
        }
        SA[j] = (flag ? ++cur : cur);
    }
    for (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];
    if (cur + 1 < (int)lms_idx.size()) {
        auto lms_SA = SA_IS(lms_vec, cur + 1);
        for (size_t i = 0; i < lms_idx.size(); ++i) {
            new_lms_idx[i] = lms_idx[lms_SA[i]];
        }
    }
    induced_sort(vec, val_range, SA, sl, new_lms_idx);
    return SA;
}
// }}}

template<typename ContainerT = std::string, typename ElemT = unsigned char>
std::vector<int> suffix_array(const ContainerT& s, const ElemT first = 'a',
                         const ElemT last = 'z') {
    std::vector<int> vec(s.size() + 1);
    std::copy(std::begin(s), std::end(s), std::begin(vec));
    for (auto& x : vec) x -= (int)first - 1;
    vec.back() = 0;
    auto ret = SA_IS(vec, (int)last - (int)first + 2);
    ret.erase(ret.begin());
    return ret;
}
// Author: https://codeforces.com/blog/entry/12796?#comment-175287
// Uses kasai's algorithm linear in time and space
std::vector<int> LCP(const std::string& s, const std::vector<int>& sa) {
    int n = s.size(), k = 0;
    std::vector<int> lcp(n), rank(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++, k ? k-- : 0) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
    }
    lcp[n - 1] = 0;
    return lcp;
}
// }}}
// Number of distinct substrings {{{
// Tested:
// - https://judge.yosupo.jp/problem/number_of_substrings
// - https://www.spoj.com/problems/SUBST1/
int64_t cnt_distinct_substrings(const std::string& s) {
    auto lcp = LCP(s, suffix_array(s, 0, 255));
    return s.size() * (int64_t) (s.size() + 1) / 2
        - std::accumulate(lcp.begin(), lcp.end(), 0LL);
}
// }}}
// K-th distinct substring {{{
// Tested:
// - https://cses.fi/problemset/task/2108
// - https://www.spoj.com/problems/SUBLEX/

// Consider all distinct substring of string `s` in lexicographically increasing
// order. Find k-th substring.
//
// Preprocessing: O(N)
// Each query: O(log(N))
//
// Returns {start index, length}. If not found -> {-1, -1}
std::vector<std::pair<int,int>> kth_distinct_substring(
        const std::string& s,
        const std::vector<int64_t>& ks) {
    if (s.empty()) {
        return {};
    }
    auto sa = suffix_array(s, 0, 255);
    auto lcp = LCP(s, sa);
    int n = s.size();
    
    // for each suffix (in increasing order), we count how many new distinct
    // substrings it create
    std::vector<int64_t> n_new_substrs(n);
    for (int i = 0; i < n; ++i) {
        int substr_len = n - sa[i];
        int new_substr_start = (i > 0 ? lcp[i-1] : 0);
        n_new_substrs[i] = substr_len - new_substr_start;
    }
    std::partial_sum(n_new_substrs.begin(), n_new_substrs.end(), n_new_substrs.begin());

    std::vector<std::pair<int,int>> res;
    for (int64_t k : ks) {
        if (k > *n_new_substrs.rbegin()) {
            res.emplace_back(-1, -1);
        } else {
            int i = std::lower_bound(n_new_substrs.begin(), n_new_substrs.end(), k) - n_new_substrs.begin();
            int new_substr_start = (i > 0 ? lcp[i-1] : 0);
            if (i > 0) k -= n_new_substrs[i-1];
            res.emplace_back(sa[i], new_substr_start + k);
        }
    }
    return res;
}
// }}}
// Count substring occurrences {{{
// given string S and Q queries pat_i, for each query, count how many
// times pat_i appears in S
// O(min(|S|, |pat|) * log(|S|)) per query
//
// Tested:
// - (yes / no) https://cses.fi/problemset/task/2102
// - (count) https://cses.fi/problemset/task/2103
// - (position; need RMQ) https://cses.fi/problemset/task/2104
int cnt_occurrences(const string& s, const vector<int>& sa, const string& pat) {
    int n = s.size(), m = pat.size();
    assert(n == (int) sa.size());
    if (n < m) return 0;
 
    auto f = [&] (int start) {  // compare S[start..] and pat[0..]
        for (int i = 0; start + i < n && i < m; ++i) {
            if (s[start + i] < pat[i]) return true;
            if (s[start + i] > pat[i]) return false;
        }
        return n - start < m;
    };
    auto g = [&] (int start) {
        for (int i = 0; start + i < n && i < m; ++i) {
            if (s[start + i] > pat[i]) return false;
        }
        return true;
    };
    auto l = std::partition_point(sa.begin(), sa.end(), f);
    auto r = std::partition_point(l, sa.end(), g);
    // To find first occurrence, return min of sa in range [l, r)
    // See https://cses.fi/problemset/task/2104
    return std::distance(l, r);
}
// }}}
// Count substring occurrences using hash {{{
// If hash array can be pre-computed, can answer each query in
// O(log(|S|) * log(|S| + |pat|)
// Tested
// - https://oj.vnoi.info/problem/icpc22_mt_b
#include "./hash.h"
int cnt_occurrences_hash(
        const vector<int>& sa,        // suffix array
        const HashGenerator& gen,
        const string& s,
        const vector<Hash>& hash_s,   // hash of `s`, generated with `gen`
        const string_view& pat,
        const vector<Hash>& hash_pat  // hash of `pat`, generated with `gen`
        ) {
    int n = s.size(), len = pat.size();
    assert(len == (int) hash_pat.size());
    assert(n == (int) sa.size());
    if (n < len) return 0;

    // f(start) = compare string S[start..] and pat[0..len-1]
    auto f = [&] (int start) {
        return gen.cmp(
                s, hash_s, start, n-1,
                pat, hash_pat, 0, len-1) < 0;
    };
    // g(start) = true if S[start..] == pat[0..]
    auto g = [&] (int start) {
        int max_len = std::min(n - start, len);
        return gen.cmp(
                s, hash_s, start, start + max_len - 1,
                pat, hash_pat, 0, max_len-1) == 0;
    };
    auto l = std::partition_point(sa.begin(), sa.end(), f);
    auto r = std::partition_point(l, sa.end(), g);
    return std::distance(l, r);
}
// }}}
// Returns length of LCS of strings s & t {{{
// O(N)
// Tested:
// - https://www.spoj.com/problems/LCS/
// - https://www.spoj.com/problems/ADAPHOTO/
int longestCommonSubstring(const string& s, const string& t) {
    char c = 127;
    string combined = s + c + t;
    auto sa = suffix_array(combined, 0, 127);
    auto lcp = LCP(combined, sa);
 
    // s -> 0 .. |s|-1
    // 255 -> |s|
    // t -> |s|+1 ..
    int ls = s.size(), lcombined = combined.size();
    auto is_s = [&] (int id) { return sa[id] < ls; };
    auto is_t = [&] (int id) { return sa[id] > ls; };
 
    assert(sa[lcombined - 1] == ls);
 
    int res = 0;
    for (int i = 0; i < lcombined - 2; ++i) {
        if ((is_s(i) && is_t(i+1)) || (is_s(i+1) && is_t(i))) {
            res = max(res, lcp[i]);
        }
    }
    return res;
}
// }}}
// Returns length of LCS of n strings {{{
// Tested:
// - https://www.spoj.com/problems/LCS2/
// - https://www.spoj.com/problems/LONGCS
#include "../DataStructure/RMQ.h"
int longestCommonSubstring(const std::vector<std::string> strs) {
    char c = 127;
    string combined = "";
    vector<int> ids;
    for (size_t i = 0; i < strs.size(); ++i) {
        const auto& s = strs[i];
        combined += s;
        while (ids.size() < combined.size()) ids.push_back(i);

        combined += c;
        ids.push_back(-1);

        --c;
    }
    auto sa = suffix_array(combined, 0, 127);
    auto lcp = LCP(combined, sa);
    RMQ<int, _min> rmq(lcp);

    // count frequency of i-th string in current window
    std::vector<int> cnt(strs.size(), 0);
    int strs_in_window = 0;
    auto add = [&] (int i) {
        if (i < 0) return;
        ++cnt[i];
        if (cnt[i] == 1) ++strs_in_window;
    };
    auto rem = [&] (int i) {
        if (i < 0) return;
        --cnt[i];
        if (cnt[i] == 0) --strs_in_window;
    };

    int i = 0, j = -1;
    int lcombined = combined.size();
    int n = strs.size();
    int res = 0;
    while (i < lcombined - 1) {
        while (j + 1 < lcombined - 1 && strs_in_window < n) {
            ++j;
            add(ids[sa[j]]);
        }
        if (strs_in_window == n) {
            res = max(res, rmq.get(i, j));
        }

        rem(ids[sa[i]]); ++i;
    }
    return res;
}
// }}}
