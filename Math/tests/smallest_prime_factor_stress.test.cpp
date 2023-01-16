#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template.h"
#include "../multiplicative_functions_linear.h"
using namespace linear_sieve;

void solve() {
    const int N = 10000;
    linear_sieve_smallest_prime_factor(N + 1);
    assert(smallest_p[1] == 0);
    for (int n = 2; n <= N; ++n) {
        bool is_prime = true;
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                is_prime = false;
                assert(smallest_p[n] == i);
                break;
            }
        }
        if (is_prime) assert(smallest_p[n] == 0);
    }
    cout << "Hello World\n";
}
