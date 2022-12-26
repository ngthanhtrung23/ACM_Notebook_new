#include "../Misc/compress.h"

// Returns number of distinct, non-empty subsequences {{{
// T = type of input elements
// OutT = type of output (e.g. ModInt)
template<typename T, typename OutT>
OutT cnt_distinct_subsequences(std::vector<T> a) {
    auto compressor = CompressorBuilder<T>{a}.build();
    compressor.compress_inplace(a);

    std::vector<OutT> f(a.size() + 1);
    std::vector<int> last(a.size() + 1, -1);
    f[0] = 1;
    for (size_t i = 0; i < a.size(); ++i) {
        f[i+1] = f[i] * 2;
        if (last[a[i]] >= 0) f[i+1] -= f[last[a[i]]];
        last[a[i]] = i;
    }
    return f.back() - 1;
}
// }}}
