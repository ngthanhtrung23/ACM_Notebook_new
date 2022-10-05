// Vec utils {{{
// Given vector `a`, commpute next[i] = position of next occurrence of a[i]
// Returns -1 if no next occurrence
template<typename Container>
std::vector<int> getNext(const Container& a) {
    std::map<int, int> cur;
    std::vector<int> res(a.size());
    int n = a.size();

    for (int i = n - 1; i >= 0; --i) {
        res[i] = cur.count(a[i]) ? cur[a[i]] : -1;
        cur[a[i]] = i;
    }

    return res;
}
// Given vector `a`, commpute prev[i] = position of previous occurrence of a[i]
// Returns -1 if no previous occurrence
template<typename Container>
std::vector<int> getPrev(const Container& a) {
    std::map<int, int> cur;
    std::vector<int> res(a.size());
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        res[i] = cur.count(a[i]) ? cur[a[i]] : -1;
        cur[a[i]] = i;
    }

    return res;
}
// }}}
