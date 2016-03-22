// Primitive root of modulo n is integer g iff for all a < n & gcd(a, n) == 1, there exist k: g^k = a mod n
// k is called discrete log of a (in case P is prime, can find in O(sqrt(P)) by noting that (P-1) is divisible by k)
//
// Exist if:
// - n is 1, 2, 4
// - n = p^k for odd prime p
// - n = 2*p^k for odd prime p
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}
 
int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);
 
    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
