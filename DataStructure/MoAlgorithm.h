// Notes:
// - queries are [l, r]
// - add(int array_id) -> void 
// - remove(int array_id) -> void
// - get(QueryT query) -> ResultT
//
// Tested:
// - https://www.spoj.com/problems/KDOMINO/ (submission ID: 30602374)
// - https://www.spoj.com/problems/FREQ2 (submission ID: 30602401)
//
// Mo algorithm {{{
template<typename QueryT, typename ResultT, typename Add, typename Rem, typename Get>
vector<ResultT> mo(int n, std::vector<QueryT> queries, Add add, Rem rem, Get get) {
    int q = queries.size();
    std::vector<ResultT> res(q);
 
    // Sort queries in increasing order of (left / SQRT, right)
    int S = sqrt(n);
    if (S < 1) S = 1;
 
    std::vector<int> query_ids(q);
    std::iota(query_ids.begin(), query_ids.end(), 0);
    std::sort(query_ids.begin(), query_ids.end(), [&] (int q1, int q2) {
            int bucket1 = queries[q1].l / S;
            int bucket2 = queries[q2].l / S;
            if (bucket1 != bucket2) return bucket1 < bucket2;
            else {
                return bucket1 % 2
                        ? (queries[q1].r > queries[q2].r)
                        : (queries[q1].r < queries[q2].r);
            }
        });
 
    // Answer queries
    int cur_l = -1, cur_r = -1;
    for (int qid : query_ids) {
        // move to this range
        if (cur_l < 0) {
            for (int i = queries[qid].l; i <= queries[qid].r; ++i) {
                add(i);
            }
            cur_l = queries[qid].l, cur_r = queries[qid].r;
        } else {
            while (cur_l > queries[qid].l) add(--cur_l);
            while (cur_r < queries[qid].r) add(++cur_r);
            while (cur_r > queries[qid].r) rem(cur_r--);
            while (cur_l < queries[qid].l) rem(cur_l++);
        }
 
        res[qid] = get(queries[qid]);
    }
    return res;
}
 
// Example
struct Query {
    int l, r;  // QueryT must have l, r
};
ostream& operator << (ostream& cout, const Query& q) {
    cout << "Query: [" << q.l << ", " << q.r << "]";
    return cout;
}
// Usage
// auto res = mo<Query, int, decltype(add), decltype(rem), decltype(get)>
//        (n, queries, add, rem, get);
// }}}
