// Source: https://github.com/ADJA/algos/tree/master/DataStructures/SparseTable.cpp
// index from 1
int table[MAXLOG][MAXN];
int numlog[MAXN];

void buildTable() {
    numlog[1] = 0;
    for (int i = 2; i <= N; i++)
        numlog[i] = numlog[i / 2] + 1;

    for (int i = 0; i <= numlog[N]; i++) {
        int curlen = 1 << i;
        for (int j = 1; j <= N; j++) {
            if (i == 0) {
                table[i][j] = a[j];
                continue;
            }
            table[i][j] = max(table[i - 1][j], table[i - 1][j + curlen / 2]);
        }
    }
}

int getMax(int l, int r) {
    int curlog = numlog[r - l + 1];
    return max(table[curlog][l], table[curlog][r - (1 << curlog) + 1]); 
}
