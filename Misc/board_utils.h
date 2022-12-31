#include <algorithm>
#include <vector>

int n_row, n_col;

// board utils {{{
inline int get_id(int r, int c) {
    return r * n_col + c;
}
inline std::pair<int,int> get_rc(int id) {
    return std::make_pair(id / n_col, id % n_col);
}
inline bool is_inside(int r, int c) {
    return 0 <= r && r < n_row
        && 0 <= c && c < n_col;
}

const std::vector<std::pair<int,int>> DIRECTIONS = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    // 8 directions:
    // {-1, -1}, {-1, 1}, {1, -1}, {1, 1},
};
// }}}
