#include "template.h"
#include "Graph/Matching/FastMatching.h"

int main() {
    int m, n, p;
    while (cin >> m >> n >> p) {
        Matching match(max(m, n));
        while (p--) {
            int u, v; cin >> u >> v;
            match.addEdge(u, v);
        }
        cout << match.match() << endl;
    }
}

