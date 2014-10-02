// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
    Int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}