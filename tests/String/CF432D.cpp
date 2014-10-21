#define _GLIBCXX_DEBUG
#define _GLIBCXX_DEBUG_PEDANTIC
#include "template.h"
#include "String/SuffixArray.h"

#define TWO(X) (1<<(X))
#define next next_
const int MN = 1000111;

string s;
int n, indexOf[MN], next[MN];
int rmq[22][MN], lg[MN];

int getMin(int l, int r) {
    if (l > r) return 1000111000;
    int t = lg[r - l + 1];
    return min( rmq[t][l], rmq[t][1+r-TWO(t)] );
}

int getRight(int id, int x) {
    int left = id, right = n-1, res = id;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (getMin(id+1, mid) >= x) {
            res = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return res;
}

int getLeft(int id, int x) {
    int left = 0, right = id, res = id;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (getMin(mid+1, id) >= x) {
            res = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return res;
}

int count(int x) {
    int r = getRight(indexOf[x], n-x);
    int l = getLeft(indexOf[x], n-x);
    return r - l + 1;
}

int main() {
    s = "";
    FOR(i,1,100000) s += 'A';
        n = s.length();
        SuffixArray SA(s, 256);

        cout << "Done init SA" << endl;

        memset(lg, 0, sizeof lg);
        lg[0] = 0;
        for(int i = 1, x = 0; i < MN; i *= 2, ++x)
            lg[i] = x;
        FOR(i,2,MN-1)
            if (!lg[i]) lg[i] = lg[i-1];

        REP(i,n) rmq[0][i] = SA.LCP[i];
        FOR(t,1,20)
            FOR(i,0,n-TWO(t))
                rmq[t][i] = min(rmq[t-1][i], rmq[t-1][i+TWO(t-1)]);

        REP(i,n) indexOf[SA.SA[i]] = i;

        next[0] = -1;
        int j = -1;
        FOR(i,1,n-1) {
            while (j >= 0 && s[i] != s[j+1]) j = next[j];
            if (s[i] == s[j+1]) ++j;
            next[i] = j;
        }

        vector< pair<int,int> > res;
        int x = n-1;
        while (x >= 0) {
            res.push_back(make_pair(1+x, count(n-1-x)));
            x = next[x];
        }
}
