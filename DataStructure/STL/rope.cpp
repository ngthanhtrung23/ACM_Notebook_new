#include <bits/stdc++.h>
#include <ext/rope> // Slow (balanced BST)!!! do not abuse
using namespace std;
using namespace __gnu_cxx;
int main() {
    rope <int> v; //use as usual STL container
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        v.push_back(i); //initialization
    int l, r;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        --l, --r;
        rope <int> cur = v.substr(l, r - l + 1);
        v.erase(l, r - l + 1);
        // Note: if erase a single element, must use v.erase(i, 1).
        // There is another function v.erase(i) but it's wrong
        // https://codeforces.com/blog/entry/94213
        v.insert(v.mutable_begin(), cur);
    }
    for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it)
        cout << *it << " ";
}
