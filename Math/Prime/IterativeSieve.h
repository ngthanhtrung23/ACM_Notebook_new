typedef unsigned int uint;

// NOTE: gP(n) is incorrect for even values of n
#define N 90000000
uint mark[N / 64 + 1];
// DO NOT USE gP(n) directly.
#define gP(n) (mark[(n)>>6]&(1<<(((n)>>1)&31)))
#define rP(n) (mark[(n)>>6]&=~(1<<(((n)>>1)&31)))

// prime indexed from 0
uint prime[5222222], nprime;

void sieve() {
    memset(mark, -1, sizeof mark);
    uint i;
    uint sqrtN = (uint)sqrt((double) N) + 1;

    for (i = 3; i < sqrtN; i += 2) if (gP(i)) {
        uint i2 = i + i;
        for (uint j = i * i; j < N; j += i2) rP(j);
    }
    for (i = 4; i < N; i += 2) {
        rP(i);
    }
    nprime = 0;
    prime[nprime++] = 2;
    for (i = 3; i < N; i += 2)
        if (gP(i)) prime[nprime++] = i;
}

bool isPrime(uint n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    if (gP(n)) return true;
    return false;
}
