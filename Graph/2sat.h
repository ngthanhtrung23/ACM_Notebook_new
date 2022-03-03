// For lexicographical min result:
// - For each variable: check if it can be set to False
//   (by adding constraint i -> !i)
// - If solver.solve() -> keep constraint i -> !i
// - Otherwise, remove constraint i -> !i, and add !i -> i to force it to True
// See https://oj.vnoi.info/problem/icpc21_mt_i

// Variables: 0 -> n-1
// Tested:
// - https://judge.yosupo.jp/problem/two_sat
// - https://oj.vnoi.info/problem/twosat
// - https://oj.vnoi.info/problem/elect
// - https://open.kattis.com/problems/cleaningpipes
// - https://oj.vnoi.info/problem/icpc21_mt_i
// - https://cses.fi/problemset/task/1684/
#include "DfsTree/StronglyConnected.h"
struct TwoSatSolver {
    TwoSatSolver(int _n_vars) : n_vars(_n_vars), g(2*n_vars) {}

    void x_or_y_constraint(bool is_x_true, int x, bool is_y_true, int y) {
        assert(x >= 0 && x < n_vars);
        assert(y >= 0 && y < n_vars);
        if (!is_x_true) x += n_vars;
        if (!is_y_true) y += n_vars;
        // x || y
        // !x -> y
        // !y -> x
        g[(x + n_vars) % (2*n_vars)].push_back(y);
        g[(y + n_vars) % (2*n_vars)].push_back(x);
    }

    // Returns:
    // If no solution -> returns {false, {}}
    // If has solution -> returns {true, solution}
    //    where |solution| = n_vars, solution = true / false
    pair<bool, vector<bool>> solve() {
        DirectedDfs tree(g);
        vector<bool> solution(n_vars);
        for (int i = 0; i < n_vars; i++) {
            if (tree.comp_ids[i] == tree.comp_ids[i + n_vars]) {
                return {false, {}};
            }
            // Note that reverse(tree.scc) is topo sorted
            solution[i] = tree.comp_ids[i] < tree.comp_ids[i + n_vars];
        }
        return {true, solution};
    }

    // number of variables
    int n_vars;
    // vertex 0 -> n_vars - 1: Ai is true
    // vertex n_vars -> 2*n_vars - 1: Ai is false
    vector<vector<int>> g;
};
