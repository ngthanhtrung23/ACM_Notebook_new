struct Hash {
    ll x, y;
    Hash(ll x = 0, ll y = 0) : x(x), y(y) {}

    Hash operator + (const Hash& a) const { return Hash((x+a.x) % MOD, y+a.y); }
    Hash operator - (const Hash& a) const { return Hash((x-a.x+MOD) % MOD, y-a.y); }
    Hash operator * (const Hash& a) const { return Hash((x*a.x) % MOD, y*a.y); }
    Hash operator * (ll k) { return Hash((x*k) % MOD, y*k); }

    friend ostream& operator << (ostream& cout, const Hash& h) {
        cout << h.x << ' ' << h.y;
        return cout;
    }
};
bool operator == (const Hash& a, const Hash& b) {
    return a.x == b.x && a.y == b.y;
}
bool operator < (const Hash& a, const Hash& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
