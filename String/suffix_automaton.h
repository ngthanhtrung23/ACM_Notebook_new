struct Node {
    int len, link; // len = max length of suffix in this class
    int next[33];
};
Node s[MN * 2];
set< pair<int,int> > order; // in most application we'll need to sort by len
struct Automaton {
    int sz, last;
    Automaton() {
		order.clear();
        sz = last = 0;
        s[0].len = 0;
        s[0].link = -1;
        ++sz;
        // need to reset next if necessary
    }
    void extend(char c) {
        c = c - 'A';
        int cur = sz++, p;
        s[cur].len = s[last].len + 1;
        order.insert(make_pair(s[cur].len, cur));

        for(p = last; p != -1 && !s[p].next[c]; p = s[p].link)
            s[p].next[c] = cur;
        if (p == -1) s[cur].link = 0;
        else {
            int q = s[p].next[c];
            if (s[p].len + 1 == s[q].len) s[cur].link = q;
            else {
                int clone = sz++;
                s[clone].len = s[p].len + 1;
                memcpy(s[clone].next, s[q].next, sizeof(s[q].next));
                s[clone].link = s[q].link;
                order.insert(make_pair(s[clone].len, clone));

                for(; p != -1 && s[p].next[c] == q; p = s[p].link)
                    s[p].next[c] = clone;
                s[q].link = s[cur].link = clone;
            }
        }
        last = cur;
    }
};
// Construct:
// Automaton sa; for(char c : s) sa.extend(c);
// 1. Number of distinct substr:
//    - Find number of different paths --> DFS on SA
//    - f[u] = 1 + sum( f[v] for v in s[u].next
// 2. Number of occurrences of a substr:
//    - Initially, in extend: s[cur].cnt = 1; s[clone].cnt = 0;
//    - for(it : reverse order)
//        p = nodes[it->second].link;
//        nodes[p].cnt += nodes[it->second].cnt
// 3. Find total length of different substrings:
//    - We have f[u] = number of strings starting from node u
//    - ans[u] = sum(ans[v] + d[v] for v in next[u])
// 4. Lexicographically k-th substring
//    - Based on number of different substring
// 5. Smallest cyclic shift
//    - Build SA of S+S, then just follow smallest link
// 6. Find first occurrence
//    - firstpos[cur] = len[cur] - 1, firstpos[clone] = firstpos[q]
