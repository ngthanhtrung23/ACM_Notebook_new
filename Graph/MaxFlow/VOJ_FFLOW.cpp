// Fastest flow
// Index from 0

#include "../../template.h"
#include "../../buffered_reader.h"
#include "MaxFlow.h"

int main() {
    int n; GN(n);
    MaxFlow flow(n);
    int x; GN(x);
    while (x--) {
        int u, v, c;
        GN(u); GN(v); GN(c);
        --u; --v;
        flow.addEdge(u, v, c);
        flow.addEdge(v, u, c);
    }
    cout << flow.getFlow(0, n-1) << endl;
    return 0;
}
