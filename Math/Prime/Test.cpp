#include <bits/stdc++.h>
using namespace std;

#include "RabinMiller.h"
#include "IterativeSieve.h"
#include "SegmentedSieve.h"

int main() {    
    sieve();
    for (int i = 0; i < nprime; i++)
        if (!isPrime(prime[i])) {
            cout << prime[i] << endl;
            cout << "FAIL";
            return 0;
        }

    vector<bool> table = segmentSieve(2000000, 10000000);
    for (int i = 0; i < nprime; i++)
        if (prime[i] >= 2000000 && !table[prime[i] - 2000000]) {
            cout << prime[i] << endl;
            cout << "FAIL";
            return 0;   
        }

    return 0;
}
