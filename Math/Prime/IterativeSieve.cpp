// NOTE: gP(n) is incorrect for even values of n
#define N 90000000
unsigned int mark[N / 64];
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))

void sieve() {
    memset( mark, -1, sizeof( mark ) );
    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;

    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) ) {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
   prime[++nprime] = 2;
   for( i = 3; i < N; i += 2)
      if (gP(i)) prime[++nprime] = i;
}