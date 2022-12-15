// O(N) 2 pointers
// Find *smallest* substring that satisfy a predicate while minimizing a cost function
// (when not satisfy -> expand -> assume expand is always valid)
//
// - pred() = whether current segment satisfy condition
// - cost(l, r) = cost of [l, r]
// - add(i) = add i to current segment
// - rem(i) = remove i from current segment
// - indices from 0 to n-1
//
// Returns: <best cost, left, right> where [left, right] is substring with
//   mincost or [-1, -1] if no solution
//
// Tested:
// - https://www.spoj.com/problems/KOIREP/
//
// Two pointers (smallest substring) {{{
template<typename Pred, typename Cost, typename Add, typename Rem>
tuple<long long, int, int> two_pointers(int n, Pred pred, Cost cost, Add add, Rem rem) {
    tuple<long long, int, int> res {LLONG_MAX, -1, -1};

    // current window is [l, r]
    for (int l = 0, r = -1; l < n; ++l) {
        while (r+1 < n && !pred()) {
            ++r;
            add(r);
        }
        if (pred()) {
            res = min(res, {cost(l, r), l, r});
        }
        rem(l);
    }
    return res;
}
// }}}
