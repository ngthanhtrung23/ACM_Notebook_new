// Container operations, from https://codeforces.com/submissions/Yuu {{{
enum ReduceOperator { MIN, MAX };
template<typename Container>
auto operator | (const Container& a, ReduceOperator op) {
	switch (op) {
		case MIN:
			return *min_element(a.begin(), a.end());
		case MAX:
			return *max_element(a.begin(), a.end());
		default:
			cerr << "OP NOT DEFINED" << endl;
            assert(false);
	}
}
enum TransformOperator { PREFIX_SUM };
template<typename Container>
auto operator | (Container& a, TransformOperator op) {
    switch (op) {
        case PREFIX_SUM:
            std::partial_sum(a.begin(), a.end(), a.begin());
            break;
        default:
			cerr << "OP NOT DEFINED" << endl;
            assert(false);
    }
    return a;
}
enum IOOperator { IN, OUT_ONE_PER_LINE };
template<typename Container>
auto operator | (Container& a, IOOperator op) {
    switch (op) {
        case IN:
            for (auto& elem : a) cin >> elem;
            break;
        case OUT_ONE_PER_LINE:
            for (const auto& elem : a) cout << elem << '\n';
            break;
        default:
			cerr << "OP NOT DEFINED" << endl;
            assert(false);
    }
    return a;
}
// }}}
