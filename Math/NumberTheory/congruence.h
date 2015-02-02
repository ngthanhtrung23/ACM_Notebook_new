// Giải phương trình: a1x1 + a2x2 + … + anxn ≡ b (modul m)
// Trong đó a1, a2, …, an, b, m là các số nguyên dương.

int g[MAXN], x[MAXN];

bool congruenceEquation(vector<int> a, int b, int m, vector<int> &ret) {
    int n = sz(a);
    a.pb(m);
    g[0] = a[0];
    For(i, 1, n) g[i] = gcd(g[i - 1], a[i]);
    ret.clear();
    if (b % g[n]) return false;
    int val = b / g[n];
    Ford(i, n, 1) {
        pair<ll, ll> p = extgcd(g[i - 1], a[i]);
        x[i] = p.se * val % m;
        val = p.fi * val % m;
    }
    x[0] = val;
    For(i, 0, n) x[i] = (x[i] + m) % m;
    Rep(i, n) ret.pb(x[i]);
    return true;
}
