// Palindrome Tree {{{
// Notes:
// - number of *distinct* palindrome substring <= N
// Tested:
// - https://oj.vnoi.info/problem/icpc22_mn_d
template<int MAXC = 26>
struct PalindromicTree {
    PalindromicTree(const string& str)
            : _sz(str.size() + 5),
              next(_sz, vector<int> (MAXC, 0)),
              link(_sz, 0), qlink(_sz, 0),
              cnt(_sz, 0), right_id(_sz, 0),
              len(_sz, 0), s(_sz, 0) {
        init();
        for (int i = 0; i < (int) str.size(); ++i) {
            add(str[i], i);
        }
        count();
    }
    int _sz;

    // returns vector of (left, right, frequency)
    vector<tuple<int,int,int>> get_palindromes() {
        vector<tuple<int,int,int>> res;
        dfs(0, res);
        dfs(1, res);
        return res;
    }

    void dfs(int u, vector<tuple<int,int,int>>& res) {
        if (u > 1) {  // u = 0 and u = 1 are two empty nodes
            res.emplace_back(right_id[u] - len[u] + 1, right_id[u], cnt[u]);
        }
        for (int i = 0; i < MAXC; ++i) {
            if (next[u][i]) dfs(next[u][i], res);
        }
    }

    int last, n, p;
    vector<vector<int>> next, dlink;
    vector<int> link, qlink, cnt, right_id, len, s;

    int newnode(int l, int right) {
        len[p] = l;
        right_id[p] = right;
        return p++;
    }
    void init() {
        p = 0;
        newnode(0, -1), newnode(-1, -1);
        n = last = 0;
        s[n] = -1, link[0] = 1;
    }
    int getlink(int x) {
        while (s[n - len[x] - 1] != s[n]) {
            if (s[n - len[link[x]] - 1] == s[n]) x = link[x];
            else x = qlink[x];
        }
        return x;
    }
    void add(char c, int right) {
        c -= 'a';
        s[++n] = c;
        int cur = getlink(last);
        if (!next[cur][(int) c]) {
            int now = newnode(len[cur] + 2, right);
            link[now] = next[getlink(link[cur])][(int) c];
            next[cur][(int) c] = now;
            if (s[n - len[link[now]]] == s[n - len[link[link[now]]]]) {
                qlink[now] = qlink[link[now]];
            }
            else {
                qlink[now] = link[link[now]];
            }
        }
        last = next[cur][(int) c];
        cnt[last]++;
    }
    void count() {
        for (int i = p - 1; i >= 0; i--) {
            cnt[link[i]] += cnt[i];
        }
    }
};
// }}}
