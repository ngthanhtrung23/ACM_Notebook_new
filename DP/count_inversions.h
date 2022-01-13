#include "../Misc/compress.h"
#include "../DataStructure/Fenwick.h"

// Given vector vs, return number of inversions
template<typename T>
long long count_inversions(vector<T> vs) {
    int n = vs.size();
    vs = compress(vs);
    Fenwick<int> bit(n);

    long long res = 0;
    for (auto v : vs) {
        res += bit.get(v+1, n);
        bit.update(v, +1);
    }
    return res;
}
