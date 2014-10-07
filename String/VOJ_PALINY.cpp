// http://vn.spoj.com/problems/PALINY/

#include <bits/stdc++.h>
using namespace std;
const char DUMMY = '.';

int manacher(string s) {
    int n = s.size() * 2 - 1;
    vector <int> f = vector <int>(n, 0);
    string a = string(n, DUMMY);
    for (int i = 0; i < n; i += 2) a[i] = s[i / 2];

    int l = 0, r = -1, center, res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        j = (i > r ? 0 : min(f[l + r - i], r - i)) + 1;
        while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
        f[i] = --j;
        if (i + j > r) {
            r = i + j;
            l = i - j;
        }

        int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
        if (len > res) {
            res = len;
            center = i;
        }
    }

    return res;
}


int main() {
    int n;
    char s[100100];
    scanf("%d%s", &n, s);
    cout << manacher(string(s, n)) << endl;
}
