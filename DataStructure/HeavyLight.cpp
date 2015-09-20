#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for(int i=(a); i>=(b); --i)
using namespace std;

const int MN = 100111;
int n;                             // number of vertices
vector<int> a[MN];                 // adjacency list

struct SegmentTree {               // 0-based indices
    SegmentTree(int from, int to) {
    }

    void update(int from, int to) {
    }
};

const int MAX_LOG = 18;

int father[MAX_LOG + 1][MN];
struct LCA { // Index from 1
    int h[MN];

public:
    LCA(int root) {
        h[root] = 1;
        father[0][root] = -1;
        dfs(root, -1);

        FOR(i,1,MAX_LOG) {
            FOR(u,1,n) { // Change this if index from 0
                if (father[i-1][u] < 0) father[i][u] = -1;
                else father[i][u] = father[i-1][ father[i-1][u] ];
            }
        }
    }

    int get(int u, int v) {
        if (u == v) return u;
        if (h[u] > h[v]) swap(u, v);

        if (h[u] != h[v]) {
            FORD(i,MAX_LOG,0) {
                int x = father[i][v];
                if (x < 0) continue;
                if (h[x] >= h[u]) {
                    v = x;
                }
            }
        }
        if (u == v) return u;

        FORD(i,MAX_LOG,0) {
            if (father[i][u] != father[i][v]) {
                u = father[i][u];
                v = father[i][v];
            }
        }
        return father[0][u];
    }

private:
    void dfs(int u, int fu) {
        for(int v : a[u]) if (v != fu) {
            h[v] = h[u] + 1;
            father[0][v] = u;
            dfs(v, u);
        }
    }
};

int numNode[MN];               // size of T(u)
int par[MN];                   // u --> parent(u)
int depth[MN];                 // u --> depth(u)
int heavyUp[MN];               // = 0 if this is 1st in chain
int heavyDown[MN];             // next vertex in chain
int firstOnChain[MN];          // chain --> 1st vertex
int idChain[MN];               // vertex --> chain
int posChain[MN];              // vertex --> position in chain
int sizeChain[MN];             // chain --> its size

int numChain;
vector<SegmentTree> trees;

// Note:
// - The following implementation is for IT on nodes
// - If need to update / query on edges:
// - - Add 1 array to store values of edges going from firstOnChain[idChain[v]] --> its parent
// - - All trees.update call need to be (from, to] instead of [from, to]
struct HeavyLight { // 1-based index
public:
    HeavyLight(int root) {
        visit(root);
        initHeavyLight();
    }
    void udpateTree(int v, int u, int lca) {
        updateTreeAncestor(v, lca);
        updateTreeAncestor(u, lca);
    }
    void updateTreeAncestor(int v, int u) { // u is ancestor of v
        while (1) {
            if (idChain[u] == idChain[v]) {
                trees[idChain[u]].update(posChain[u], posChain[v]);
                return;
            }
            trees[idChain[v]].update(0, posChain[v]);
            v = par[firstOnChain[idChain[v]]];
        }
    }

private:
    void visit(int x) {
        numNode[x] = 1;
        for (auto y : a[x]) {
            if (y == par[x]) continue;
            par[y] = x;
            depth[y] = depth[x] + 1;
            visit(y);
            numNode[x] += numNode[y];
        }
        for (auto y : a[x])
            if (y != par[x] && numNode[y] * 2 >= numNode[x])
                heavyUp[y] = 1, heavyDown[x] = y;
    }
    void initHeavyLight() {
        for (int i = 1; i <= n; i++) {
            int x = i;
            if (heavyUp[x]) continue;
            firstOnChain[numChain] = x;
            while (x) {
                idChain[x] = numChain;
                posChain[x] = sizeChain[numChain]++;
                x = heavyDown[x];
            }
            trees.push_back(SegmentTree(0, sizeChain[numChain++] - 1));
        }
    }
};
