// Container operations, idea from https://codeforces.com/submissions/Yuu {{{
template<typename T> struct accumulator_type { using type = T; };
template<> struct accumulator_type<int32_t> { using type = int64_t; };
template<> struct accumulator_type<uint32_t> { using type = uint64_t; };
template<> struct accumulator_type<int64_t> { using type = __int128_t; };
template<> struct accumulator_type<uint64_t> { using type = __uint128_t; };

enum ReduceOperator { MIN, MAX, CNT_MAX };
template<typename Container>
auto operator | (const Container& a, ReduceOperator op) {
    switch (op) {
        case MIN:
            return *min_element(a.begin(), a.end());
        case MAX:
            return *max_element(a.begin(), a.end());
        case CNT_MAX:
            auto ma = *max_element(a.begin(), a.end());
            int cnt = 0;
            for (const auto& elem : a) cnt += elem == ma;
            return cnt;
    }
    assert(false);
}
enum SumOperator { SUM, SUM_XOR };
template<typename Container>
auto operator | (const Container& a, SumOperator op) {
    typename accumulator_type<typename Container::value_type>::type sum{};
    switch (op) {
        case SUM:
            for (const auto& elem : a) sum += elem;
            return sum;
        case SUM_XOR:
            for (const auto& elem : a) sum ^= elem;
            return sum;
    }
    assert(false);
}
enum ComparableOperator { SORT };
template<typename Container>
Container& operator | (Container& a, ComparableOperator op) {
    __typeof(a) values;
    switch (op) {
        case SORT:
            std::sort(a.begin(), a.end());
            break;
    }
    return a;
}
enum TransformOperator { ADD_1, PREFIX_SUM, PREFIX_SUM_XOR, REVERSE, SUB_1, COMPRESS };
template<typename Container>
Container& operator | (Container& a, TransformOperator op) {
    __typeof(a) values;
    switch (op) {
        case ADD_1:
            for (auto& elem : a) elem += 1;
            break;
        case COMPRESS:
            values = a;
            std::sort(values.begin(), values.end());
            values.erase(std::unique(values.begin(), values.end()), values.end());
            for (auto& value : a) value = std::lower_bound(values.begin(), values.end(), value) - values.begin();
            break;
        case PREFIX_SUM:
            std::partial_sum(a.begin(), a.end(), a.begin());
            break;
        case PREFIX_SUM_XOR:
            std::partial_sum(a.begin(), a.end(), a.begin(), [] (int x, int y) { return x ^ y; });
            break;
        case REVERSE:
            std::reverse(a.begin(), a.end());
            break;
        case SUB_1:
            for (auto& elem : a) elem -= 1;
            break;
    }
    return a;
}
enum IOOperator { IN, OUT_ONE_PER_LINE, OUT_1_LINE };
template<typename Container>
Container& operator | (Container& a, IOOperator op) {
    switch (op) {
        case IN:
            for (auto& elem : a) cin >> elem;
            break;
        case OUT_1_LINE:
            for (size_t i = 0; i < a.size(); ++i) {
                if (i > 0) cout << ' ';
                cout << a[i];
            }
            break;
        case OUT_ONE_PER_LINE:
            for (const auto& elem : a) cout << elem << '\n';
            break;
    }
    return a;
}
// }}}
