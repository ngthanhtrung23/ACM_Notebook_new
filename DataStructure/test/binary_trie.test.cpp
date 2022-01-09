#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../template.h"
#include "../BinaryTrie.h"

void solve() {
    BinaryTrie<int, int, 30> trie;
    int q; cin >> q;
    while (q--) {
        int typ, x; cin >> typ >> x;
        if (typ == 0) {
            int has = trie.count(x);
            if (has == 0) trie.insert(x);
        } else if (typ == 1) {
            int has = trie.count(x);
            if (has == 1) trie.remove(x);
        }
        else cout << trie.min_element(x).first << '\n';
    }
}
