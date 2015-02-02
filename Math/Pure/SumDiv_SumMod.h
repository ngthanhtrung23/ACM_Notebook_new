// sumdiv(n) = [n/1] + [n/2] + [n/3] + ... + [n/n]
long long sumdiv(long long n) {
    long long s=0;
    for (long long i=1; i<=n; ) {
        long long q=n/i, r=n/q;
        s+=(long long)(r-i+1)*q;
        i=r+1;
    }
    return s;
}
// summod(n,k) = n%1 + n%2 + ... + n%k   (k<=n)
long long summod(int n, int k) {
    long long s=0;
    for (int i=1; i<=k;) {
        int q=n/i, r=min(k,n/q), t=r-i+1;
        s+=(n%i)*t-(t*(t-1)*q)/2;
        i=r+1;
    }
    return s;
}

