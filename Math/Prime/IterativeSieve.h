typedef unsigned int uint;

// NOTE: gP(n) is incorrect for even values of n
#define N 90000000
uint mark[N / 64 + 1];
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))

// prime indexed from 0
uint prime[5222222], nprime;

void sieve() {
    memset( mark, -1, sizeof( mark ) );
    uint i;
    uint sqrtN = ( uint )sqrt( ( double )N ) + 1;

    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) ) {
        uint i2 = i + i;
        for( uint j = i * i; j < N; j += i2 ) rP( j );
    }
    nprime = 0;
    prime[nprime++] = 2;
    for( i = 3; i < N; i += 2)
        if (gP(i)) prime[nprime++] = i;
}
