// Trie {{{
// Tested:
// - https://www.spoj.com/problems/ADAINDEX/
struct Trie {
    Trie(int _nChild, char _offset)
        : nChild(_nChild), offset(_offset),
        children(1, std::vector<int> (_nChild, -1)) {}

    // Add a new string s to Trie. Returns ID of new node
    int add(const string& s) {
        int p = 0;
        for (char c : s) {
            p = getChild(p, c, /* create= */ true);
        }
        return p;
    }

    // Follow string s on trie, and return ID of node.
    // Returns -1 if no such node.
    int get(const string& s) {
        int p = 0;
        for (char c : s) {
            p = getChild(p, c);
            if (p < 0) return -1;
        }
        return p;
    }

    // Create a new child of p, edge from p -> child = c
    // Returns ID of new node
    int addNode(int p, char c) {
        // create child node
        int child = children.size();
        children.push_back(std::vector<int> (nChild, -1));

        // link
        children[p][c - offset] = child;
        return child;
    }

    bool hasChild(int p, char c) {
        return children[p][c - offset] >= 0;
    }

    // Returns -1 if no such child, otherwise returns ID of child
    // If create = true (useful for adding strings to trie), a new
    // child is created if not exist
    int getChild(int p, char c, bool create=false) {
        assert(p < (int) children.size());

        if (!hasChild(p, c) && create) {
            return addNode(p, c);
        }

        return children[p][c - offset];
    }

    int nChild;
    char offset;
    std::vector<std::vector<int>> children;
};
// }}}
