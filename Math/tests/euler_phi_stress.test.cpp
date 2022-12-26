#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template.h"
#include "../Prime/EulerPhi.h"
#include "../multiplicative_functions_linear.h"

void solve() {
    linear_sieve::linear_sieve_phi(N);
    for (int i = 1; i < N; ++i) {
        assert(linear_sieve::phi[i] == eulerPhi(i));
        assert(linear_sieve::phi[i] == eulerPhi_lookup(i));
    }
    cout << "Hello World\n";
}
