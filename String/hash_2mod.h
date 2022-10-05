#include "../Math/modint.h"

// NOT TESTED
const int MOD = 1e9 + 7;
using modular = ModInt<MOD>;

struct Hash {
    long long x;
    modular y;

    Hash operator + (const Hash& a) const { return Hash{x + a.x, y + a.y}; }
    Hash operator - (const Hash& a) const { return Hash{x - a.x, y - a.y}; }
    Hash operator * (const Hash& a) const { return Hash{x * a.x, y * a.y}; }
    Hash operator * (int k) const { return Hash{x*k, y*k}; }
    Hash operator / (int k) const { return Hash{x/k, y/k}; }

    Hash& operator += (const Hash& a) { return *this = *this + a; }
    Hash& operator -= (const Hash& a) { return *this = *this - a; }
    Hash& operator *= (const Hash& a) { return *this = *this * a; }
    Hash& operator /= (const Hash& a) { return *this = *this / a; }
};
bool operator == (const Hash& a, const Hash& b) {
    return a.x == b.x && a.y == b.y;
}
std::ostream& operator << (std::ostream& out, const Hash& h) {
    out << '(' << h.x << ", " << h.y << ')';
    return out;
}
