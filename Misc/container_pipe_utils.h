// Container operations, idea from https://codeforces.com/submissions/Yuu {{{
template<typename T> struct accumulator_type { using type = T; };
template<> struct accumulator_type<int32_t> { using type = int64_t; };
template<> struct accumulator_type<uint32_t> { using type = uint64_t; };
template<> struct accumulator_type<int64_t> { using type = __int128_t; };
template<> struct accumulator_type<uint64_t> { using type = __uint128_t; };

enum ReduceOperator { MIN, MAX };
template<typename Container>
auto operator | (const Container& a, ReduceOperator op) {
    switch (op) {
        case MIN:
            return *min_element(a.begin(), a.end());
        case MAX:
            return *max_element(a.begin(), a.end());
    }
    assert(false);
}
enum SumOperator { SUM };
template<typename Container>
auto operator | (const Container& a, SumOperator op) {
    typename accumulator_type<typename Container::value_type>::type sum{};
    switch (op) {
        case SUM:
            for (const auto& elem : a) sum += elem;
            return sum;
    }
    assert(false);
}
enum TransformOperator { ADD_1, COMPRESS, PREFIX_SUM, REVERSE, SORT, SUB_1 };
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
        case REVERSE:
            std::reverse(a.begin(), a.end());
            break;
        case SORT:
            std::sort(a.begin(), a.end());
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
            for (const auto& elem : a) cout << elem << ' ';
            break;
        case OUT_ONE_PER_LINE:
            for (const auto& elem : a) cout << elem << '\n';
            break;
    }
    return a;
}
// }}}
