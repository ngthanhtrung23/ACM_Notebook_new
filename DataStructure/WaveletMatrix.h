// WaveletMatrix {{{
// Copied from https://github.com/dacin21/dacin21_codebook/blob/master/trees/wavelet_matrix.cpp
//
// Notes:
// - Index from 0
// - k (for k-th query) from 0
// - Need to remove #define int long long
//
// Tested:
// - (kth query) https://judge.yosupo.jp/problem/range_kth_smallest
// - (range_count) https://judge.yosupo.jp/problem/static_range_frequency

// Bit Presum {{{
class Bit_Presum {
public:
    static constexpr uint32_t omega = CHAR_BIT * sizeof(uint64_t);
    static constexpr uint32_t lg_omega = __lg(omega);
    static_assert(omega == 64u);

    Bit_Presum(vector<uint64_t> mask_)
            : n(mask_.size()), mask(move(mask_)), presum(n+1) {
        build();
    }
    Bit_Presum(uint32_t bits, bool init_val = 0)
            : n((bits>>lg_omega) + 1),
              mask(n, init_val ? ~uint64_t{0} : uint64_t{0}),
              presum(n+1) {
        if (init_val) mask.back()<<=((n<<lg_omega) - bits);
        build();
    }
    // popcount l <= i < r
    uint32_t query(uint32_t l, uint32_t r) const {
        if (__builtin_expect(r < l, false)) return 0;
        return query(r) - query(l);
    }
    // popcount 0 <= i < x
    uint32_t query(uint32_t x) const {
        uint32_t high = x>>lg_omega, low = x & ((uint64_t{1}<<lg_omega) - 1);
        uint32_t ret = presum_query(high);
        ret += __builtin_popcountll(mask[high]& ((uint64_t{1} << low)-1));
        return ret;
    }

    void update_pre_build(uint32_t x, bool val) {
        uint32_t high = x>>lg_omega, low = x & ((1u<<lg_omega) - 1);
        mask[high] = (mask[high] & ~(uint64_t{1} << low)) | (uint64_t{val}<<low);
    }
    void do_build() {
        build();
    }

    friend ostream& operator<<(ostream&o, Bit_Presum const&b) {
        for (auto const& e : b.mask) {
            stringstream ss;
            ss << bitset<omega>(e);
            auto s = ss.str();
            reverse(s.begin(), s.end());
            o << s << "|";
        }
        o << " : ";
        for (auto const&e:b.presum) o << e << " ";
        o << "\n";
        return o;
    }

private:
    void presum_build() {
        for (uint32_t x = 1; x <= n; ++x) {
            presum[x] += presum[x-1];
        }
    }
    // sum 0 <= i < x
    uint32_t presum_query(uint32_t x) const {
        return presum[x];
    }
    void build() {
        for (uint32_t x = 0; x < n; ++x) {
            presum[x+1] = __builtin_popcountll(mask[x]);
        }
        presum_build();
    }

    const uint32_t n;
    vector<uint64_t> mask;
    vector<uint32_t> presum;
};
// }}}

template<typename T, typename Bit_Ds = Bit_Presum>
class WaveletMatrix {
public:
    static_assert(is_integral<T>::value);
    static constexpr uint32_t height = CHAR_BIT * sizeof(T);

    WaveletMatrix(vector<T> v): n(v.size()), data(height, n) {
        build(move(v));
    }
    // count l <= i < r  s.t.  A <= val[i] < B
    uint32_t range_count(int l, int r, T A, T B) const {
        assert(0 <= l && r <= n);
        return count_lower(l, r, B) - count_lower(l, r, A);
    }
    // count l <= i < r  s.t.  A <= val[i]
    uint32_t range_count_up(int l, int r, T A) const {
        assert(0 <= l && r <= n);
        if (__builtin_expect(l>r, false)) return uint32_t{0};
        return (r-l) - count_lower(l, r, A);
    }
    // k from 0
    // range: [l, r-1]
    T k_th(int l, int r, int k) const {
        assert(0 <= k && k < n);
        return get_kth(l, r, k);
    }

    // internal functions {{{
private:
    void build(vector<T> v) {
        m_index.resize(height);
        T const a = numeric_limits<T>::min();
        for (int h = height-1; h>=0;--h) {
            T const b = a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0, h-1)));
            for (int i=0;i<n;++i) {
                data[h].update_pre_build(i, v[i]<b);
            }
            data[h].do_build();
            const int m = stable_partition(v.begin(), v.end(), [&b](T const&x) {return x < b;}) - v.begin();
            for (int i=m;i<n;++i) {
                v[i] = v[i] - (T{1}<<(max(0, h-1))) + !h - (T{1}<<(max(0, h-1)));
            }
            m_index[h] = m;
        }
    }
    /// count l <= i < r  s.t.  val[i] < B
    uint32_t count_lower(int l, int r, T const&B) const {
        assert(0 <= l && r <= n);
        if (__builtin_expect(r<l, false)) return 0;
        uint32_t ret = 0;
        int h = height;
        T a = numeric_limits<T>::min();
        while(h > 0) {
            --h;
			bool go_left = B < a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0, h-1)));
            const int low_l = data[h].query(l), low_r = data[h].query(r);
            if (go_left) {
                l = low_l;
                r = low_r;
            } else {
                a = a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0, h-1)));
                ret+= low_r-low_l;
                l = m_index[h] + l-low_l;
                r = m_index[h] + r-low_r;
            }
        }
        return ret;
    }
    T get_kth(int l, int r, int k) const {
        assert(0 <= l && r <= n);
        assert(0 <= k && k < r-l);
        int h = height;
        T a = numeric_limits<T>::min();
        while (h > 0) {
            --h;
            const int low_l = data[h].query(l), low_r = data[h].query(r), low_lr = low_r-low_l;
            bool go_left = k < low_lr;
            if (go_left) {
                l = low_l;
                r = low_r;
            } else {
                a+= T{1}<<h;
                k-= low_lr;
                l = m_index[h] + l-low_l;
                r = m_index[h] + r-low_r;
            }
        }
        return a;
    }

    const int n;
    vector<int> m_index;
    vector<Bit_Ds> data;
    // }}}
};
// }}}
