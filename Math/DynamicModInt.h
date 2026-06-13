// Useful when mod changes between test cases (we can't use ModInt 
// since mod is templated)
//
// DynamicModInt {{{
struct DynamicModInt {
    static i64 MOD;
    i64 x;

    DynamicModInt(i64 v = 0) {
        if (MOD == 0) x = v;
        else {
            v %= MOD;
            if (v < 0) v += MOD;
            x = v;
        }
    }

    DynamicModInt& operator += (const DynamicModInt& other) {
        x += other.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }

    DynamicModInt& operator *= (const DynamicModInt& other) {
        x = (i128)x * other.x % MOD;
        return *this;
    }

    friend DynamicModInt operator + (DynamicModInt a, const DynamicModInt& b) { return a += b; }
    friend DynamicModInt operator * (DynamicModInt a, const DynamicModInt& b) { return a *= b; }

    bool operator != (const DynamicModInt& other) const {
        return x != other.x;
    }
};
// }}}
