#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <complex>
#include <iostream>
#include <algorithm>

#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

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
