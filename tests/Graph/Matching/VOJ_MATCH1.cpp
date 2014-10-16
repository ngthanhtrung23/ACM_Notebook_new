#include "template.h"
#include "Graph/Matching/Matching.h"

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int m, n;
    while (cin >> m >> n) {
        Matching match(max(m, n));
        int u, v;
        while (cin >> u >> v) {
            --u; --v;
            match.addEdge(u, v);
        }

        cout << match.match() << endl;
        for(int i = 0; i < m; ++i)
            if (match.matchL[i] >= 0)
                cout << i+1 << ' ' << match.matchL[i] + 1 << "\n";
    }
}

