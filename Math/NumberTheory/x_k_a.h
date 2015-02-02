//Find all x such that x^k=a(mod n) n is pime
int generator (int p) { //Return primirity root of prime p
    vector<int> fact; int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i); 
            while (n % i == 0)    n /= i;
        }
    if (n > 1)
        fact.push_back (n); 
    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powMod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
} 
int main() { 
    int n, k, a; cin >> n >> k >> a;
    if (a == 0) { puts ("1\n0");  return 0; } 
    int g = generator (n); 
    int sq = (int) sqrt (n + .0) + 1;
    vector < pair<int,int> > dec (sq);
    for (int i=1; i<=sq; ++i)
    dec[i-1] = make_pair (powMod (g, int (i * sq * 1ll * k % (n - 1)), n), i);
    sort (dec.begin(), dec.end());
    int any_ans = -1;
    for (int i=0; i<sq; ++i) {
        int my = int (powMod (g, int (i * 1ll * k % (n - 1)), n) * 1ll * a % n);
        vector < pair<int,int> >::iterator it =
                  lower_bound (dec.begin(), dec.end(), make_pair (my, 0));
        if (it != dec.end() && it->first == my) { 
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) { puts ("0");  return 0; }
    int delta = (n-1) / gcd (k, n-1);  vector<int> ans;
    for (int cur=any_ans%delta; cur<n-1; cur+=delta) 
        ans.push_back (powMod (g, cur, n));
    sort (ans.begin(), ans.end());
    for (size_t i=0; i<ans.size(); ++i) printf ("%d ", ans[i]);  
}

