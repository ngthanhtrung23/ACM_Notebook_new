#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_C"

#include "../../template.h"
#include "../bigint.h"

void solve() {
    BigInt a, b; cin >> a >> b;
    cout << a.mul_karatsuba(b) << endl;
}
