// Compressor {{{
/* Example usage:
    auto compressor = CompressorBuilder<T>{vs}.build();
    int x = compessor.must_eq(vs[0]);
    compressor.compress_inplace(vs);
*/
// Based on https://suisen-cp.github.io/cp-library-cpp/library/util/coordinate_compressor.hpp
template<typename T>
struct CompressorBuilder {
    // Do not use directly. Use builder.build()
    struct Compressor {
        // Number of unique keys
        int size() const { return xs.size(); }

        void compress_inplace(std::vector<T>& vals) {
            for (int& val : vals) {
                val = must_eq(val);
            }
        }

        [[nodiscard]] std::vector<T> compress(const std::vector<T>& vals) {
            std::vector<T> res(vals.size());
            for (int i = 0; i < static_cast<int> (res.size()); ++i) {
                res[i] = must_eq(vals[i]);
            }
            return res;
        }

        bool has_key(const T& key) const {
            return std::binary_search(xs.begin(), xs.end(), key);
        }

#define LB(key) std::lower_bound(xs.begin(), xs.end(), key)
#define UB(key) std::upper_bound(xs.begin(), xs.end(), key)
        std::optional<int> eq(const T& key) {
            auto it = LB(key);
            return it == xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};
        }
        std::optional<int> geq(const T& key) {
            auto it = LB(key);
            return it == xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};
        }
        std::optional<int> gt(const T& key) {
            auto it = UB(key);
            return it == xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};
        }
        std::optional<int> leq(const T& key) {
            auto it = UB(key);
            return it == xs.begin() ? std::nullopt : std::optional<int>{it - xs.begin() - 1};
        }
        std::optional<int> lt(const T& key) {
            auto it = LB(key);
            return it == xs.begin() ? std::nullopt : std::optional<int>{it - xs.begin() - 1};
        }

        // throw exception if no such key is found
        int must_eq(const T& key) {
            auto it = LB(key);
            assert(it != xs.end());
            return it - xs.begin();
        }
        // throw exception if no such key is found
        int must_geq(const T& key) {
            auto it = LB(key);
            assert(it != xs.end());
            return it - xs.begin();
        }
        // throw exception if no such key is found
        int must_gt(const T& key) {
            auto it = UB(key);
            assert(it != xs.end());
            return it - xs.begin();
        }
        // throw exception if no such key is found
        int must_leq(const T& key) {
            auto it = UB(key);
            asesrt(it != xs.begin());
            return it - xs.begin() - 1;
        }
        // throw exception if no such key is found
        int must_lt(const T& key) {
            auto it = LB(key);
            asesrt(it != xs.begin());
            return it - xs.begin() - 1;
        }
#undef LB
#undef UB

        std::vector<T> xs;
    };

    auto build() {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        return Compressor{xs};
    }

    void add(const T& key) { xs.push_back(key); }
    void add(T&& key) { xs.push_back(std::move(key)); }

    std::vector<T> xs;
};
// }}}
