// Copied from https://github.com/nilehmann/wavelet-tree/blob/master/wavelet-matrix.cpp
// Notes:
// - Does not work with negative numbers
// - Indices from 0
// - K from 1 (for K-th smallest queries)
//
// Tested:
// - https://www.spoj.com/problems/ILKQUERY/
// - https://open.kattis.com/problems/easyquery
#define log2(x) (sizeof(unsigned)*8 - __builtin_clz(x))

#define popcnt(x) __builtin_popcount(x)

#define set_bit(v, i, b) v |= ((b) << (i))
#define get_bit(v, i) ((v) & (1 << (i)))
// Indices start from 0
struct BitmapRank {
    const int bits = sizeof(int)*8;
    vector<int> vec;
    vector<int> count;

    BitmapRank() {}

    void resize(int n) {
        vec.resize((n+bits-1)/bits);
        count.resize(vec.size());
    }

    void set(int i, bool b) {
        set_bit(vec[i/bits], i %bits, b);
    }

    void build_rank() {
        for (int i = 1; i < (int)vec.size(); ++i)
            count[i] = count[i-1] + popcnt(vec[i-1]);
    }

    int rank1(int i) const {
        return i < 0 ? 0 : count[i/bits] + popcnt(vec[i/bits] << (bits - i%bits - 1));
    }

    int rank1(int i, int j) const {
        return rank1(j) - rank1(i-1);
    }

    int rank0(int i) const {
        return i < 0 ? 0 : i - rank1(i) + 1;
    }

    int rank0(int i, int j) const {
        return rank0(j) - rank0(i-1);
    }
};

// Wavelet Matrix with succinct representation of bitmaps
struct WaveletMatrix {
    unsigned height;
    vector<BitmapRank> B;
    vector<int> z;

    WaveletMatrix(const vector<int> &A) :
        WaveletMatrix(A, *max_element(A.begin(), A.end()) + 1) {}

    // sigma = size of the alphabet, ie., one more than the maximum element
    // in A.
    WaveletMatrix(const vector<int> &orig, int sigma)
        : height(log2(sigma - 1)),
            B(height), z(height) {
        auto A = orig;
        for (unsigned l = 0; l < height; ++l) {
            B[l].resize(A.size());
            for (unsigned i = 0; i < A.size(); ++i)
                B[l].set(i, get_bit(A[i], height - l - 1));
            B[l].build_rank();

            auto it = stable_partition(A.begin(), A.end(), [=] (int c) {
                    return not get_bit(c, height - l - 1);
                });
            z[l] = distance(A.begin(), it);
        }
    }

    // Count occurrences of number c until position i.
    // ie, occurrences of c in positions [0,i]
    int rank(int c, int i) const {
        int p = -1;
        for (unsigned l = 0; l < height; ++l) {
            if (get_bit(c, height - l - 1)) {
                p = z[l] + B[l].rank1(p) - 1;
                i = z[l] + B[l].rank1(i) - 1;
            } else {
                p = B[l].rank0(p) - 1;
                i = B[l].rank0(i) - 1;
            }
        }
        return i - p;
    }

    // Find the k-th smallest element in positions [i,j].
    // The smallest element is k=1
    // Indices from 0
    int quantile(int k, int i, int j) const {
        int element = 0;
        for (unsigned l = 0; l < height; ++l) {
            int r = B[l].rank0(i, j);
            if (r >= k) {
                i = B[l].rank0(i-1);
                j = B[l].rank0(j) - 1;
            } else {
                i = z[l] + B[l].rank1(i-1);
                j = z[l] + B[l].rank1(j) - 1;
                k -= r;
                set_bit(element, height - l - 1, 1);
            }
        }
        return element;
    }

    // Count number of occurrences of numbers in the range [a, b]
    // present in the sequence in positions [i, j], ie, if representing a grid it
    // counts number of points in the specified rectangle.
    int range(int i, int j, int a, int b) const {
        return range(i, j, a, b, 0, (1 << height)-1, 0);
    }

    int range(int i, int j, int a, int b, int L, int U, int l) const {
        if (b < L || U < a)
            return 0;

        int M = L + (U-L)/2;
        if (a <= L && U <= b)
            return j - i + 1;
        else {
            int left = range(B[l].rank0(i-1), B[l].rank0(j) - 1,
                                             a, b, L, M, l + 1);
            int right = range(z[l] + B[l].rank1(i-1), z[l] + B[l].rank1(j) - 1,
                                                a, b, M+1, U, l+1);
            return left + right;
        }
    }
};
