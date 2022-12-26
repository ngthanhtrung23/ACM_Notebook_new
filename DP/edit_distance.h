// Minimum number of operations to transform string a => string b
// In one operation, we can either modify 1 character, delete 1 character or
// insert 1 character (insert is not needed in this case)
//
// Edit distance {{{
int edit_distance(std::string a, std::string b) {
    int la = a.size();
    int lb = b.size();
    a = " " + a + " ";
    b = " " + b + " ";

    std::vector<std::vector<int>> f(la + 1, std::vector<int> (lb + 1, la + lb));

    // corner cases
    for (int j = 0; j <= lb; ++j) f[0][j] = j;
    for (int i = 0; i <= la; ++i) f[i][0] = i;

    // DP
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1];
            else f[i][j] = 1 + std::min({
                    f[i-1][j-1],  // modify
                    f[i][j-1],    // remove b[j]
                    f[i-1][j],    // remove a[i]
                    });
        }
    }

    return f.back().back();
}
// }}}
