// http://codeforces.com/blog/entry/23442
// Polynomial P of degree N --> need N+1 points. Let n = N+1
// init y[i], i = 1..n
// init coefficient:
FOR(i,1,n) f[i] = (x - i + MOD) % MOD;
l[0] = 1; FOR(i,1,n) l[i] = l[i-1] * f[i] % MOD;
r[n+1] = 1; FORD(i,n,1) r[i] = r[i+1] * f[i] % MOD;
// P(x) = sum(y[i] * product((x - j) / (i - j), j=1..n, j != i), i=1..n)
int res = 0;
FOR(i,1,n) {
	// j < i
	int cur = l[i-1] * inv_gt[i - 1] % MOD;
	// j > i
	cur = cur * r[i+1] % MOD * inv_gt[n - i] % MOD;
	if ((n - i) % 2) cur = cur * (MOD - 1) % MOD;
	// add y[i] * product
	res = (res + cur * y[i]) % MOD;
}
