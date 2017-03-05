struct Fraction {
    int a, b;

    Fraction() {
        a = 0;
        b = 1;
    }

    Fraction(int _a, int _b) {
        a = _a;
        b = _b;
        norm();
    }

    Fraction(int x) {
        a = x;
        b = 1;
    }

    Fraction operator + (const Fraction& other) const {
        return Fraction(a * other.b + b * other.a, b * other.b);
    }
    Fraction operator - (const Fraction& other) const {
        return Fraction(a * other.b - b * other.a, b * other.b);
    }
    Fraction operator * (const Fraction& other) const {
        return Fraction(a * other.a, b * other.b);
    }
    Fraction operator / (const Fraction& other) const {
        assert(other.a != 0);
        return Fraction(a * other.b, b * other.a);
    }

    int cmp(Fraction other) const {
        return ::cmp(a * other.b, b * other.a);
    }

#define Comp(x) bool operator x (Fraction q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp

    void norm() {
        if (b < 0) {
            a = -a;
            b = -b;
        }

        if (a == 0) b = 1;
        else {
            int g = __gcd(llabs(a), llabs(b));
            a /= g;
            b /= g;
        }
    }
};
istream& operator >> (istream& cin, Fraction& p) {
    cin >> p.a;
    p.b = 1;
    return cin;
}
ostream& operator << (ostream& cout, Fraction& p) {
    cout << p.a << '/' << p.b;
    return cout;
}
