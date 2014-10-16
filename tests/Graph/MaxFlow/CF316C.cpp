#include "template.h"
#include "Graph/Matching/HungarianAssignment.h"

int m, n, a[111][111], id[111][111];
const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

Hungary match;

int main() {
    int m, n;
    while (cin >> m >> n) {
        int even = 0, odd = 0;
        int now = 0;
        FOR(i,1,m) FOR(j,1,n) {
            cin >> a[i][j];
            if ((i + j) % 2 == 0) id[i][j] = ++even;
            else id[i][j] = ++odd;
        }
        match.init(m*n/2, m*n/2);

        FOR(i,1,m) FOR(j,1,n) {
            if ((i + j) % 2 == 0) {
                REP(dir,4) {
                    int ii = i + di[dir], jj = j + dj[dir];
                    if (ii < 1 || ii > m || jj < 1 || jj > n) continue;

                    if (a[i][j] == a[ii][jj]) match.add(id[i][j], id[ii][jj], 0);
                    else match.add(id[i][j], id[ii][jj], 1);
                }
            }
        }
        cout << match.mincost()<< endl;
    }
    return 0;
}

