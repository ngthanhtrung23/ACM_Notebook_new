#include "../template.h"

void zfunc(int n, int v[], int z[]) {
    int l = 0, r = -1;
    z[0] = 0;
    FOR(i, 1, n - 1) {
        int k = (i > r) ? 0 : min(z[i - l], r - i + 1);
        while (i + k < n && v[k] == v[i + k]) ++k;
        z[i] = k;
        if (i + k - 1 > r) {
            l = i;
            r = i + k - 1;
        }
    }
    z[0] = n;
}

int main() {
}
