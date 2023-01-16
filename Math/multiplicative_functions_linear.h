// This is only for calculating multiplicative functions
// If we need a fast sieve, see SieveFast.h
// From https://codeforces.com/blog/entry/54090
namespace linear_sieve {
const int MN = 2e7;
vector<int> primes;

int smallest_p[MN];  // smallest_p[n] = smallest prime factor of n
void linear_sieve_smallest_prime_factor(int n) {
    primes.clear();
    memset(smallest_p, 0, sizeof smallest_p);

    for (int i = 2; i < n; ++i) {
        if (!smallest_p[i]) primes.push_back(i);
        for (int j = 0; j < int(primes.size()) && i * primes[j] < n; ++j) {
            smallest_p[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

// Euler Phi {{{
bool is_composite[MN];
int phi[MN];

void linear_sieve_phi(int n) {
    memset(is_composite, false, sizeof is_composite);
    primes.clear();
 
    phi[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1; // i is prime
        }
        for (int j = 0; j < (int) primes.size() && i * primes[j] < n; ++j) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j]; //primes[j] divides i
                break;
            } else {
                phi[i * primes[j]] = phi[i] * phi[primes[j]]; //primes[j] does not divide i
            }
        }
    }
}
// }}}

// Number of divisors {{{
int cnt_divisors[MN + 11];  // call linear_sieve_divisors(n+1) to init
int cnt[MN + 11];           // power of smallest prime factor of i
void linear_sieve_divisors(int n) {  // init range [1, n-1]
    memset(is_composite, false, sizeof is_composite);
    primes.clear();

    cnt_divisors[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            cnt[i] = 1;
            cnt_divisors[i] = 2;
        }
        for (int j = 0; j < (int) primes.size() && i * primes[j] < n; ++j) {
            int ip = i * primes[j];
            is_composite[ip] = true;
            if (i % primes[j] == 0) {
                cnt[ip] = cnt[i] + 1;
                cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i] + 2);
            } else {
                cnt[ip] = 1;
                cnt_divisors[ip] = 2 * cnt_divisors[i];
            }
        }
    }
}
// }}}

}
