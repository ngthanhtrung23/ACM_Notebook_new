// Segment tree beats
// Tutorial:
// - https://codeforces.com/blog/entry/57319
// - https://www.youtube.com/watch?v=wFqKgrW1IMQ
//
// AC: https://www.acmicpc.net/problem/17474

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

struct Node {
    int max1;  // max value
    int max2;  // 2nd max value (must be different from max1)
    int cnt_max;  // how many indices have value == max1
    int sum;
    int lazy;

    Node() {}
    Node(int val) {  // initialize with a single number.
        max1 = val;
        max2 = -1;  // Note that values are in [0, 2^31), so -1 works here.
        cnt_max = 1;
        sum = val;
        lazy = -1;  // Note that values are in [0, 2^31), so -1 works here.
    }

    void setMin(int val) {  // for each i, set a[i] = min(a[i], val)
        assert(val > max2);

        if (max1 <= val) return;

        // Sample: 1 3 5 8 8 --> 1 3 5 6 6
        sum -= (max1 - val) * cnt_max;
        lazy = val;
        max1 = val;
    }
} it[8000111];

Node operator + (const Node& a, const Node& b) {
    Node res;
    res.max1 = max(a.max1, b.max1);

    res.max2 = max(a.max2, b.max2);
    if (a.max1 != res.max1) res.max2 = max(res.max2, a.max1);
    if (b.max1 != res.max1) res.max2 = max(res.max2, b.max1);

    res.cnt_max = 0;
    if (a.max1 == res.max1) res.cnt_max += a.cnt_max;
    if (b.max1 == res.max1) res.cnt_max += b.cnt_max;

    res.sum = a.sum + b.sum;
    res.lazy = -1;
    return res;
}

void down(int i) {
    if (it[i].lazy < 0) return;

    it[i*2].setMin(it[i].lazy);
    it[i*2+1].setMin(it[i].lazy);

    it[i].lazy = -1;
}

int a[1000111];
void build(int i, int l, int r) {
    if (l == r) {
        it[i] = Node(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2 + 1, mid + 1, r);

    it[i] = it[i*2] + it[i*2 + 1];
}

void setMin(int i, int l, int r, int u, int v, int x) {
    if (v < l || r < u) return;
    if (it[i].max1 <= x) return;
    // now max1 > x

    if (u <= l && r <= v && it[i].max2 < x) {
        it[i].setMin(x);
        return;
    }

    down(i);
    int mid = (l + r) / 2;
    setMin(i*2, l, mid, u, v, x);
    setMin(i*2 + 1, mid+1, r, u, v, x);
    it[i] = it[i*2] + it[i*2 + 1];
}

int getMax(int i, int l, int r, int u, int v) {
    if (v < l || r < u) return -1;
    if (u <= l && r <= v) return it[i].max1;

    down(i);
    int mid = (l + r) / 2;
    return max(getMax(i*2, l, mid, u, v),
            getMax(i*2+1, mid+1, r, u, v));
}

int getSum(int i, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return it[i].sum;

    down(i);
    int mid = (l + r) / 2;
    return getSum(i*2, l, mid, u, v) + getSum(i*2+1, mid+1, r, u, v);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // read initial array
    int n; cin >> n;
    FOR(i,1,n) cin >> a[i];
    
    // initialize segment tree beats
    build(1, 1, n);
    
    // queries
    int q; cin >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) { // for each i in [l, r] set a[i] = min(a[i], x)
            int l, r, x; cin >> l >> r >> x;
            setMin(1, 1, n, l, r, x);
        } else if (typ == 2) { // find max(a[i]) for i in [l, r]
            int l, r; cin >> l >> r;
            cout << getMax(1, 1, n, l, r) << '\n';
        } else { // find sum(a[i]) for i in [l, r]
            int l, r; cin >> l >> r;
            cout << getSum(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
