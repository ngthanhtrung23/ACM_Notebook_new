// Farey sequence (denominator <= N) enumeration:
// Properties
// 1. Two fractions: 0 <= a/b < c/d <= 1 are neighbors in some Farey sequence iff b*c - a*d == 1
// 2. If b*c - a*d == 1, the (unique) fraction between a/b and c/d with smallest denominator is (a+c) / (b+d)
// 3. If a/b < c/d < e/f are 3 consecutives fraction in some Farey sequence, then c/d = (a+e) / (b+f)

int N = 12000;
pair<int,int> next(int a, int b, int c, int d) {
    int k = (N + b) / d;
    return make_pair(k*c - a, k*d - b);
}
// To find c/d using only a/b:
// Using extended euclid, we can find c0, d0 such that b*c0 - a*d0 == 1
// c = c0 + (N - d0)/b * a
// d = d0 + (N - d0)/b * b

// To count number of fractions in range (x, y):
// F(N) = count(k/n : x < k/n < y and n <= N)
// R(N) = count(k/n : x < k/n < y and n <= N and gcd(k,n) == 1)
// F(N) can be easily calculated in O(N)
// F(N) = sum( R(N div m) for m = 1..N )
// Thus R(N) can be calculated using generalized inversed Moebius formula
