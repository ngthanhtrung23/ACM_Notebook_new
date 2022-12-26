#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template.h"
#include "../NumberTheory/cnt_divisors.h"
#include "../multiplicative_function.h"

const int N = 1000000;
MultiplicativeFunction<N + 1> mf;
auto divisors = mf.divisors();

#include "../multiplicative_functions_linear.h"

void solve() {
    linear_sieve::linear_sieve_divisors(N + 1);
    for (int i = 1; i <= N; ++i) {
        assert(divisors[i] == cnt_divisors(i));
        assert(divisors[i] == linear_sieve::cnt_divisors[i]);
    }
    cout << "Hello World\n";
}
