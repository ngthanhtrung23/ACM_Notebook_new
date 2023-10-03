// Tested:
// - https://www.spoj.com/problems/ADAUNIQ/
//
// Notes:
// - Updates must be set: A(u) = val
// - When implementing Update(id, new_value, cur_l, cur_r) -> void:
//   [cur_l, cur_r] = current segment
//   we need to handle the case where we update an index that is inside
//   [cur_l, cur_r]
//
// Mo algorithm with updates {{{
enum QueryType { GET = 0, UPDATE = 1 };

struct Query {
    int l, r;             // For get
    int u, val, old_val;  // For update
    int id;
    QueryType typ;
};

template<typename Add, typename Rem, typename Update, typename Get>
void mo_with_updates(
        int n, const vector<Query>& queries,
        Add add, Rem rem, Update update, Get get) {
    // Separate update and get queries
    vector<Query> updates, gets;
    for (const auto& query : queries) {
        if (query.typ == QueryType::UPDATE) updates.push_back(query);
        else gets.push_back(query);
    }

    // Sort queries
    int S = std::max<int>(1, cbrtl(n + 0.5));
    S = S * S;

    sort(gets.begin(), gets.end(), [&] (const Query& q1, const Query& q2) {
            int l1 = q1.l / S;
            int l2 = q2.l / S;
            if (l1 != l2) return l1 < l2;

            int r1 = q1.r / S;
            int r2 = q2.r / S;
            if (r1 != r2) return (l1 % 2 == 0) ? r1 < r2 : r1 > r2;

            return (r1 % 2 == 0)
                    ? q1.id < q2.id
                    : q1.id > q2.id;
            });

    // Process queries
    int cur_l = -1, cur_r = -1, cur_update = -1;
    for (const auto& query : gets) {
        // move to [l, r]
        if (cur_l < 0) {
            for (int i = query.l; i <= query.r; ++i) add(i);
            cur_l = query.l;
            cur_r = query.r;
        } else {
            while (cur_l > query.l) add(--cur_l);
            while (cur_r < query.r) add(++cur_r);
            while (cur_r > query.r) rem(cur_r--);
            while (cur_l < query.l) rem(cur_l++);
        }

        // process updates
        // should we update more?
        while (cur_update + 1 < (int) updates.size()
                && updates[cur_update + 1].id < query.id) {
            ++cur_update;
            update(updates[cur_update].u, updates[cur_update].val, cur_l, cur_r);
        }
        // should we update less?
        while (cur_update >= 0 && updates[cur_update].id > query.id) {
            update(updates[cur_update].u, updates[cur_update].old_val, cur_l, cur_r);
            --cur_update;
        }

        get(query);
    }
}
// }}}
