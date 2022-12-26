#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template.h"
#include "../Prime/SieveFast.h"
#include "../Prime/RabinMiller32.h"

bitset<INT_MAX> all_primes;
void newPrime(int p) {
    all_primes[p] = 1;
}

void solve() {
    srand(7777);
    sieve(INT_MAX, newPrime);
    cerr << "DONE SIEVE" << endl;
    for (int i = 0; i < INT_MAX; ++i) {
        if (rand() % 30) continue;
        if (all_primes[i] == 1) assert(is_prime(i));
        else assert(!is_prime(i));
    }

    cout << "Hello World\n";
}
