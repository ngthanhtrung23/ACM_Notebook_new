// Copied from team TwT514 (Shik + takaramono + coquelicot)
// Tested:
// - https://open.kattis.com/problems/polymul2
// - http://codeforces.com/gym/100341 - C
// Notes:
// - n must be power of 2. Remember to memset a, b, c to 0
ll buf[10000000],*ptr=buf;
void mul( int n, ll *a, ll *b, ll *c ) {
    if ( n<=32 ) {
        REP(i,2*n) c[i]=0;
        REP(i,n) REP(j,n) c[i+j]+=a[i]*b[j];
        REP(i,2*n) c[i]%=MOD;
        return;
    }
    int m=n/2;
    ll *s1=ptr; ptr+=n;
    ll *s2=ptr; ptr+=n;
    ll *s3=ptr; ptr+=n;
    ll *aa=ptr; ptr+=m;
    ll *bb=ptr; ptr+=m;
    REP(i,m) {
        aa[i]=a[i]+a[i+m];
        bb[i]=b[i]+b[i+m];
        if ( aa[i]>=MOD ) aa[i]-=MOD;
        if ( bb[i]>=MOD ) bb[i]-=MOD;
    }
    mul(m,a,b,s1);
    mul(m,a+m,b+m,s2);
    mul(m,aa,bb,s3);
    memcpy(c,s1,n*sizeof(ll));
    memcpy(c+n,s2,n*sizeof(ll));
    REP(i,n) c[i+m]+=s3[i]-s1[i]-s2[i];
    REP(i,2*n) c[i]%=MOD;
    ptr-=4*n;
}
// mul(2^x, a, b, c); REP(i,2*n) c[i] = (c[i] % MOD + MOD) % MOD
