// Notes:
// - queries are [l, r]
// - add(int array_id) -> void 
// - undo() -> void
// - get(QueryT query) -> ResultT
//
// Tested:
// - https://www.spoj.com/problems/FREQ2/ (submission ID: 30602190)
// - https://www.spoj.com/problems/KDOMINO/ (submission ID: 30602247)
// - https://www.spoj.com/problems/ZQUERY/
//
// Mo algorithm with undo DS {{{
template<typename QueryT, typename ResultT, typename Add, typename Undo, typename Get>
vector<ResultT> mo_with_undo(int n, std::vector<QueryT> queries, Add add, Undo undo, Get get) {
    int s = max((int) 1, (int) sqrt(n + 0.5));
    int q = queries.size();
    vector<ResultT> res(q);

    // For each block, stores vector of (query, id)
    std::vector<std::vector<int>> blocks(n / s + 1);
    for (int i = 0; i < q; ++i) {
        blocks[queries[i].l / s].push_back(i);
    }

    // Process each block
    int block_start = 0, block_end = s - 1;
    for (auto& block : blocks) {
        sort(block.begin(), block.end(), [&] (int q1, int q2) {
                return queries[q1].r < queries[q2].r;
                });
        int cur_r = block_end;
        for (int qid : block) {
            const auto& query = queries[qid];
            assert(block_start <= query.l && query.l <= block_end);

            // For query that is entirely inside this block, we just process it
            // and then undo immediately
            if (query.r <= block_end) {
                for (int i = query.l; i <= query.r; ++i) add(i);
                res[qid] = get(query);
                for (int i = query.l; i <= query.r; ++i) undo();
                continue;
            }

            // Order:
            // 1. add(i) for i in block_end + 1 .. query.r
            // 2. add(i) for i in query.l .. block_end
            // 3. get()
            // 4. undo() for i in query.l .. block_end => all of (2) is undo
            for (int i = cur_r + 1; i <= query.r; ++i) add(i);
            for (int i = query.l; i <= block_end; ++i) add(i);
            res[qid] = get(query);
            for (int i = query.l; i <= block_end; ++i) undo();
            cur_r = query.r;
        }

        for (int i = cur_r; i > block_end; --i) undo();

        block_start += s;
        block_end += s;
    }
    return res;
}

// Example
struct Query {
    int l, r;  // QueryT must have l, r
};
// Usage
// auto res = mo_with_undo<Query, int, decltype(add), decltype(undo), decltype(get)>
//        (n, queries, add, undo, get);
// }}}

