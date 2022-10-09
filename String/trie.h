// Trie {{{
// Tested: https://www.fb.com/codingcompetitions/hacker-cup/2022/round-3/problems/B
struct Trie {
    Trie(int _nChild, char _offset)
        : nChild(_nChild), offset(_offset),
        children(1, std::vector<int> (_nChild, -1)) {}

    int addNode(int p, char c) {
        // create child node
        int child = children.size();
        children.push_back(std::vector<int> (nChild, -1));

        // link
        children[p][c - offset] = child;
        return child;
    }

    int nChild;
    char offset;
    std::vector<std::vector<int>> children;
};
// }}}
