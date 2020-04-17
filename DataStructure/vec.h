// Copied from https://codeforces.com/blog/entry/76149

template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template<typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T> (args...)) {}
};

template<typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : vector<T> (n, val) {}
};

// Usage:
{
    Vec<2, int> a(10, 50); // int a[10][50] initialized with zero
    Vec<3, double> b(10, 10, 10, 3.14); // double b[10][10][10] initialized with 3.14

    Vec<3, long long> c(5, 5); // the third dimension has no value yet
    c[0][0].push_back(100); // now c[0][0][0] has a value (100) but others don't

    Vec<4, int> d(10, 10);
    d[2][3].push_back(Vec<1, int>(100, 12345)); // now d[2][3][0] is a vector with 100 values of 12345

    Vec<1, string> e; // just blank vector of strings
}
