// Problem: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1860

#include "template.h"

const int MN = 2011;
long long dp[MN][MN];
int a[MN], C[MN][MN], A[MN][MN];
int n;

int main() {
    int t;
    while (cin >> t >> n) {
        FOR(i,1,n) {
            cin >> a[i];
        }
        ++n; a[n] = t;
        FOR(i,1,n) FOR(j,i,n) C[i][j] = a[j] - a[i-1];

        FOR(i,1,n) dp[i][i] = 0, A[i][i] = i;

        FOR(len,1,n-1)
            FOR(i,1,n-len) {
                int j = i + len;
                dp[i][j] = 2000111000;
                FOR(k,A[i][j-1],A[i+1][j]) {
                    int cur = dp[i][k-1] + dp[k][j] + C[i][j];
                    if (cur < dp[i][j]) {
                        dp[i][j] = cur;
                        A[i][j] = k;
                    }
                }
            }
        cout << dp[1][n] << endl;
    }
}
