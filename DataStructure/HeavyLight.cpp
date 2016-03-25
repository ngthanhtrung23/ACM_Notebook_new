// Tested:
// - http://codeforces.com/gym/100739/problem/G
// Notes:
// - Index from 1
// - dfn: vertex id --> position
// --> for point query, only need to visit(dfn[u])
// --> for range query, use query(u, v)
// Author: zimpha
#include <bits/stdc++.h>
using namespace std;
const int MN = 100111;
vector<int> G[MN];
int sz[MN], dep[MN], fa[MN];
int dfn[MN], top[MN];
int n, id;

// Operations on segment tree
int querySeg(int i, int l, int r, int u, int v) {return 0;}

void dfs1(int u, int f = 0) {
    sz[u] = 1; fa[u] = f;
    for (auto &v: G[u]) if (v != f) {
        dep[v] = dep[u] + 1;
        dfs1(v, u); sz[u] += sz[v];
    }
}

void dfs2(int u, int chain, int f = 0) {
    int son(-1); dfn[u] = ++id; top[u] = chain;
    for (auto &v: G[u]) if (v != f) {
        if (son == -1 || sz[son] < sz[v]) son = v;
    }
    if (~son) dfs2(son, chain, u);
    for (auto &v: G[u]) if (v != f && v != son) {
        dfs2(v, v, u);
    }
}

int query(int u, int v) {
    int res = 0;
    int fu = top[u], fv = top[v];
    while (fu != fv) {
        if (dep[fu] < dep[fv]) swap(u, v), swap(fu, fv);
        res += querySeg(1, 1, n, dfn[fu], dfn[u]);
        u = fa[fu], fu = top[u];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res += querySeg(1, 1, n, dfn[u], dfn[v]);
    return res;
}

int main() {
    dfs1(1);
    id = 0;
    dfs2(1, 1);
}

