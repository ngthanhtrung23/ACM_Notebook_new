// Tested:
// - https://spoj.com/problems/DNAOFELF/
//
// Computes the rank of binary vectors over GF(2).
//
// Each row a[i] is a vector of m bits.
//
// Example:
//   vectors: 101, 011, 110
//   rank = 2 because 101 XOR 011 = 110
//
// Parameters:
//   a : binary vectors
//   n : number of vectors
//   m : number of bits / columns to use
//
// Returns:
//   number of linearly independent vectors among the given rows.
//
// Complexity:
//   O(n * m * bitset_cost)
int gauss(vector<bitset<B>> a, int n, int m) {
    int rank = 0;

    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = -1;
        for (int i = row; i < n; ++i) {
            if (a[i][col]) {
                sel = i;
                break;
            }
        }

        // No vector has bit col = 1, so this column cannot add rank.
        if (sel == -1) continue;

        swap(a[sel], a[row]);

        for (int i = 0; i < n; ++i) {
            if (i != row && a[i][col]) {
                a[i] ^= a[row];
            }
        }

        ++row;
        ++rank;
    }

    return rank;
}
