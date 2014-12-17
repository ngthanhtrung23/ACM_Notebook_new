// Proof : http://www.fq.math.ca/Scanned/10-4/advanced10-4.pdf
bool isSquare(long long n) { /* */}
bool isFibonacci(int n) {
    return n >= 0 && isSquare(5*n*n+4) || isSquare(5*n*n-4);
}
