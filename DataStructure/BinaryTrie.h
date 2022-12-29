// Binary Trie
// Based on https://judge.yosupo.jp/submission/72657
// Supports:
// - get min / max / kth element
// - given K, find x: x^K is min / max / kth
//
// Notes:
// - high mem usage. If just need kth_element
//   -> use OrderedSet.h if MAX_VALUE is ~10^6
//   -> use STL/order_statistic.cpp if MAX_VALUE is big / custom type
//
// Tested:
// - (insert, remove, min xor) https://judge.yosupo.jp/problem/set_xor_min
// - (insert, max xor) https://cses.fi/problemset/task/1655/
// Binary trie {{{
template<
    class Val = long long,   // values stored in Trie
    class Count = long long, // frequency of values
    int B = (sizeof(Val) * 8 - 1)  // max number of bit
> struct BinaryTrie {
    struct Node {
        std::array<int, 2> child;
        Count count;
        Node() : child{-1, -1}, count(0) {}
    };

    BinaryTrie() : nodes{Node()} {} // create root node

    // Number of elements in the trie
    Count size() {
        return nodes[0].count;
    }

    void insert(Val x, Count cnt = 1) {
        update(x, cnt);
    }
    void remove(Val x, Count cnt = 1) {
        update(x, -cnt);
    }

    // return min(X ^ xor_val)
    pair<Val, Node> min_element(Val xor_val = 0) {
        assert(0 < size());
        return kth_element(0, xor_val);
    }

    // return max(X ^ xor_val)
    // Tested: https://www.spoj.com/problems/XORX/
    pair<Val, Node> max_element(Val xor_val = 0) {
        assert(0 < size());
        return kth_element(size() - 1, xor_val);
    }

    // return k-th smallest (X ^ xor_val)  (0 <= K < size())
    pair<Val, Node> kth_element(Count k, Val xor_val = 0) {
        assert(0 <= k && k < size());
        int u = 0;
        Val x = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = get_bit(xor_val, i);
            int v0 = get_child(u, b);
            if (nodes[v0].count <= k) {
                k -= nodes[v0].count;
                u = get_child(u, 1-b);
                x |= 1LL << i;
            } else {
                u = v0;
            }
        }
        return {x, nodes[u]};
    }

    // return frequency of x
    Count count(Val x) {
        int u = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = get_bit(x, i);
            if (nodes[u].child[b] == -1) {
                return 0;
            }
            u = get_child(u, b);
        }
        return nodes[u].count;
    }

    // return how many values a where a ^ xor_val < x
    // Tested: https://www.spoj.com/problems/SUBXOR/
    Count count_less_than(Val x, Val xor_val) {
        Count sum = 0;
        int u = 0;
        for (int i = B - 1; i >= 0; --i) {
            int bx = get_bit(x, i);
            int bxor = get_bit(xor_val, i);
            if (bx == 1) {
                // i = first bit where a^xor_val differ from x
                if (nodes[u].child[bxor] >= 0) {
                    sum += nodes[nodes[u].child[bxor]].count;
                }
            }
            if (nodes[u].child[bx ^ bxor] == -1) {
                return sum;
            }
            u = get_child(u, bx ^ bxor);
        }
        return sum;
    }

// private:
    vector<Node> nodes;

    int get_child(int p, int b) {
        assert(0 <= p && p < (int) nodes.size());
        assert(0 <= b && b < 2);
        if (nodes[p].child[b] == -1) {
            nodes[p].child[b] = nodes.size();
            nodes.push_back(Node{});
        }
        return nodes[p].child[b];
    }

    void update(Val x, Count cnt) {
        int u = 0;
        for (int i = B - 1; i >= 0; i--) {
            nodes[u].count += cnt;
            assert(nodes[u].count >= 0);  // prevent over delete
            int b = get_bit(x, i);
            u = get_child(u, b);
        }
        nodes[u].count += cnt;
        assert(nodes[u].count >= 0);  // prevent over delete
    }

    inline int get_bit(Val v, int bit) {
        return (v >> bit) & 1;
    }
};
// }}}
