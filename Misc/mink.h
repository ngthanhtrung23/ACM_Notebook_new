// Tested:
// - 1D: https://oj.vnoi.info/problem/mink
// - 2D (just do 1D twice, for row then for col): https://www.spoj.com/problems/ADASQR/
//
// NOTE: Must update MN
const int MN = 5000111;

// Return min of each length-K-subarray for range [left, right) {{{
template<typename T>
vector<T> mink(const std::vector<T>& a, int k) {
    // deque maintaining candidates in *increasing order*
    // Avoid using std::deque because of performance
    int head = 0, tail = -1;
    static pair<int, T> buf[MN];

    auto is_empty = [&] () { return head > tail; };
    auto add = [&] (int id, T val) {
        while (!is_empty() && buf[tail].second >= val) --tail;
        buf[++tail] = {id, val};
    };
    // remove all ids <= lower_bound
    auto rem = [&] (int lower_bound) {
        if (!is_empty() && buf[head].first <= lower_bound) ++head;
    };

    int n = a.size();
    vector<T> res(n - k + 1);
    for (int i = 0; i < n; ++i) {
        add(i, a[i]);
        if (i >= k-1) {
            rem(i - k);
            res[i-k+1] = buf[head].second;
        }
    }
    return res;
}
// }}}
