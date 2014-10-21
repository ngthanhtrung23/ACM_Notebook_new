#include "template.h"
#include "String/SuffixArray.h"

const int MN = 100111;

string s;
int k, n;
long long sumLen[MN];
SuffixArray SA("", 256);

inline int suffixLen(int i) {
    return n - i;
}

int findPos(int l, int r, char c, int len, bool first) {
    int res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        char cmid = (SA.SA[mid] + len - 1 < n) ? s[SA.SA[mid] + len - 1] : 'a' - 1;
        if (cmid < c) {
            l = mid + 1;
        }
        else if (cmid > c) {
            r = mid - 1;
        }
        else {
            res = mid;
            if (first) r = mid - 1;
            else l = mid + 1;
        }
    }
    return res;
}

int main() {
    while (cin >> s >> k) {
        n = s.length();
        SA = SuffixArray(s, 256);
        if (k > (n * (n+1LL)) / 2) {
            cout << "No such line." << endl;
            continue;
        }

//        PR0(SA.SA, n);
//        PR0(SA.LCP, n);

        sumLen[0] = suffixLen(SA.SA[0]);
        FOR(i,1,n-1) sumLen[i] = sumLen[i-1] + suffixLen(SA.SA[i]);

        int l = 0, r = n-1, len = 1;
        while (k > 0) {
//            cout << "Search " << k << ": " << l << " --> " << r << "  " << len << endl;
            int from, to;
            FOR(c,'a','z') {
                from = findPos(l, r, c, len, true);
                to = findPos(l, r, c, len, false);

                if (from < 0) continue;

                long long cnt = sumLen[to] - ((from == 0) ? 0 : sumLen[from - 1]);
                cnt -= (to - from + 1) * (len - 1);

//                cout << "   " << (char) c << ' ' << from << ' ' << to << ' ' << cnt << endl;

                if (cnt >= k) {
                    l = from;
                    r = to;
                    break;
                }
                else k -= cnt;
            }
            ++len;
            k -= to - from + 1;
        }

        cout << s.substr(SA.SA[l], len-1) << endl;
    }
}
