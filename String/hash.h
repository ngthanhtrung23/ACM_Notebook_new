#include "../Math/modint.h"

// Hash {{{
// Usage:
// HashGenerator g(MAX_LENGTH)
//
// auto h = g.hash(s)
// g.equals(s, h, l1, r1, s, h, l2, r2)
// g.cmp(s, h, l1, r1, s, h, l2, r2)
//
// Tested:
// - https://oj.vnoi.info/problem/substr
// - https://oj.vnoi.info/problem/paliny  - max palin / binary search
// - https://oj.vnoi.info/problem/dtksub  - hash<Hash> for unordered_map
// - https://oj.vnoi.info/problem/vostr   - cmp

const int MOD = 1e9 + 7;
using modular = ModInt<MOD>;

struct Hash {
    long long x;
    modular y;

    Hash operator + (const Hash& a) const { return Hash{x + a.x, y + a.y}; }
    Hash operator - (const Hash& a) const { return Hash{x - a.x, y - a.y}; }
    Hash operator * (const Hash& a) const { return Hash{x * a.x, y * a.y}; }
    Hash operator * (int k) const { return Hash{x*k, y*k}; }

    Hash& operator += (const Hash& a) { return *this = *this + a; }
    Hash& operator -= (const Hash& a) { return *this = *this - a; }
    Hash& operator *= (const Hash& a) { return *this = *this * a; }
};
bool operator == (const Hash& a, const Hash& b) {
    return a.x == b.x && a.y == b.y;
}
bool operator < (const Hash& a, const Hash& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y.x < b.y.x;
}
std::ostream& operator << (std::ostream& out, const Hash& h) {
    out << '(' << h.x << ", " << h.y << ')';
    return out;
}

// hash function for std::unordered_map
namespace std {
    template<>
    struct hash<Hash> {
        public:
            size_t operator() (const Hash& h) const {
                return h.x * 1000000009 + h.y.x;
            }
    };
}

struct HashGenerator {
    HashGenerator(int maxLen, int base = 311) {
        p.resize(maxLen + 1);
        p[0] = {1, 1};
        for (int i = 1; i <= maxLen; i++) {
            p[i] = p[i-1] * base;
        }
    }

    template<typename Container>
    std::vector<Hash> hash(const Container& s) const {
        std::vector<Hash> res(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            res[i] = p[i] * (int) s[i];
        }
        std::partial_sum(res.begin(), res.end(), res.begin());
        return res;
    }

    Hash getHash(const std::vector<Hash>& h, int l, int r) const {
        return __getHash(h, l, r) * p[p.size() - 1 - l];
    }

    // compare [l1, r1] vs [l2, r2]
    bool equals(
            const std::vector<Hash>& h1, int l1, int r1,
            const std::vector<Hash>& h2, int l2, int r2) const {
        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());
        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());
        if (r1 - l1 != r2 - l2) return false;

        return getHash(h1, l1, r1) == getHash(h2, l2, r2);
    }

    // Returns length of max common prefix of h1[l1, r1] and h2[l2, r2]
    // length = 0 -> first character of 2 substrings are different.
    int maxCommonPrefix(
            const std::vector<Hash>& h1, int l1, int r1,
            const std::vector<Hash>& h2, int l2, int r2) const {
        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());
        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());

        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;

        int res = -1, left = 0, right = std::min(len1, len2) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (equals(h1, l1, l1 + mid, h2, l2, l2 + mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res + 1;
        /* C++20
        auto r = std::views::iota(0, std::min(len1, len2));
        auto res = std::ranges::partition_point(
                r,
                [&] (int mid) {
                    return equals(h1, l1, l1+mid, h2, l2, l2+mid);
                });
        return *res;
         */
    }

    // compare s1[l1, r1] and s2[l2, r2]
    template<typename Container1, typename Container2>
    int cmp(
            const Container1& s1, const std::vector<Hash>& h1, int l1, int r1,
            const Container2& s2, const std::vector<Hash>& h2, int l2, int r2) const {
        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());
        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());

        int commonPrefixLen = maxCommonPrefix(h1, l1, r1, h2, l2, r2);
        char c1 = (l1 + commonPrefixLen <= r1) ? s1[l1 + commonPrefixLen] : 0;
        char c2 = (l2 + commonPrefixLen <= r2) ? s2[l2 + commonPrefixLen] : 0;

        return (c1 == c2) ? 0 : ((c1 < c2) ? -1 : 1);
    }

private:
    std::vector<Hash> p;

    // DO NOT USE, this doesn't divide by p[l]
    Hash __getHash(const std::vector<Hash>& h, int l, int r) const {
        assert(0 <= l && l <= r && r < (int) h.size());
        return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);
    }
};
// }}}
