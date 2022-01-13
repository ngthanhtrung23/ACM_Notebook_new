// Compress vector vs, and return the compressed vector
// Returned values in [0, k-1] where k = number of different values
template<typename V>
V compress(V vs) {
    auto vals = vs;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (auto& v : vs) {
        v = lower_bound(vals.begin(), vals.end(), v) - vals.begin();
    }
    return vs;
}
