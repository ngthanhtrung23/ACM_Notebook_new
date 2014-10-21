#include "template.h"
#include "String/SuffixArray.h"

const int MN = 100111;
string s;
int l[MN], r[MN], st[MN], top;
int n;

inline long long f(long long x) { return x * (x + 1) / 2; }

int main() {
    while (cin >> s) {
        n = s.length();
        SuffixArray sa(s, 256);
        // PR0(sa.SA, n);
        // PR0(sa.LCP, n);
        sa.LCP.push_back(0);

        top = 0; st[0] = -1;
        REP(i,n) {
            while (top && sa.LCP[st[top]] >= sa.LCP[i]) --top;
            l[i] = st[top] + 1;
            st[++top] = i;
        }
        top = 0; st[0] = n;
        FORD(i,n-1,0) {
            while (top && sa.LCP[st[top]] >= sa.LCP[i]) --top;
            r[i] = st[top] - 1;
            st[++top] = i;
        }

        set< pair<int,int> > all;
        long long res = 0;
        REP(i,n) {
            pair<int,int> cur = make_pair(l[i] - 1, r[i]);
            if (all.count(cur)) continue;

            all.insert(cur);
            if (sa.LCP[i] == 0) continue;
            
            int bound = max(sa.LCP[l[i] - 1], sa.LCP[r[i] + 1]);
            res += f(r[i] - l[i] + 2) * (sa.LCP[i] - bound);

            // cout << l[i] << ' ' << r[i] << ' ' << sa.LCP[i] << ' ' << res << endl;
        }

        REP(i,n) {
            int len = n - sa.SA[i];
            int done = max(sa.LCP[i], sa.LCP[i+1]);

            res += len - done;
        }
        cout << res << endl;
    }
}

