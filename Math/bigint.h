// NOTE:
// This code contains various bug fixes compared to the original version from
// indy256 (github.com/indy256/codelibrary/blob/master/cpp/numbertheory/bigint-full.cpp),
// including:
// - Fix overflow bug in mul_karatsuba.
// - Fix overflow bug in fft.
// - Fix bug in initialization from long long.
// - Removed operator*=(long long), which caused several subtle bugs.
//
// TODO:
//
// Optimize += and -= (http://codeforces.com/blog/entry/22566?#comment-394735)
//   This code implemented += via +. It is not optimal, doing the other way is
//   much better. Consider the example
//     bigint large; // some large number
//     for (int i = 0; i < 100000; ++i) {
//       large += i;
//     }
//   Here large will be copied on each iteration, because += calls +.
//   And if you implemented += inplace, this code would run in linear time.
//   If you do it, + is implemented like
//
//     friend bigint operator+(bigint lhs, const bigint& rhs) {
//       return lhs += rhs;
//     }
//
// Tested:
// - https://www.e-olymp.com/en/problems/266: Comparison
// - https://www.e-olymp.com/en/problems/267: Subtraction
// - https://www.e-olymp.com/en/problems/271: Multiplication
// - https://www.e-olymp.com/en/problems/272: Multiplication
// - https://www.e-olymp.com/en/problems/313: Addition
// - https://www.e-olymp.com/en/problems/314: Addition/Subtraction
// - https://www.e-olymp.com/en/problems/317: Multiplication (simple / karatsuba / fft)
// - https://www.e-olymp.com/en/problems/1327: Multiplication
// - https://www.e-olymp.com/en/problems/1328
// - VOJ BIGNUM: Addition, Subtraction, Multiplication.
// - SGU 111: sqrt

const int base = 1e9;
const int base_digits = 9;

struct BigInt {
    vector<int> a;
    int sign;

    BigInt() :
        sign(1) {
    }

    BigInt(long long v) {
        *this = v;
    }

    BigInt(const string &s) {
        read(s);
    }

    void operator=(const BigInt &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        a.clear();
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    BigInt operator+(const BigInt &v) const {
        if (sign == v.sign) {
            BigInt res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    BigInt operator-(const BigInt &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                BigInt res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {
        int norm = base / (b1.a.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    friend BigInt sqrt(const BigInt &a1) {
        BigInt a = a1;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);

        int n = a.a.size();

        int firstDigit = (int) sqrt((double) a.a[n - 1] * base + a.a[n - 2]);
        int norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);

        BigInt r = (long long) a.a[n - 1] * base + a.a[n - 2];
        firstDigit = (int) sqrt((double) a.a[n - 1] * base + a.a[n - 2]);
        int q = firstDigit;
        BigInt res;

        for(int j = n / 2 - 1; j >= 0; j--) {
            for(; ; --q) {
                BigInt r1 = (r - (res * 2 * BigInt(base) + q) * q) * BigInt(base) * BigInt(base) + (j > 0 ? (long long) a.a[2 * j - 1] * base + a.a[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q;

            if (j > 0) {
                int d1 = res.a.size() + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;
                int d2 = res.a.size() + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;
                int d3 = res.a.size() < r.a.size() ? r.a[res.a.size()] : 0;
                q = ((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2);
            }
        }

        res.trim();
        return res / norm;
    }

    BigInt operator/(const BigInt &v) const {
        return divmod(*this, v).first;
    }

    BigInt operator%(const BigInt &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(long long v) {
        assert(v < base);
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    BigInt operator/(long long v) const {
        BigInt res = *this;
        res /= v;
        return res;
    }

    int operator%(long long v) const {
        assert(v < base);
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const BigInt &v) {
        *this = *this + v;
    }
    void operator-=(const BigInt &v) {
        *this = *this - v;
    }
    void operator*=(const BigInt &v) {
        *this = *this * v;
    }
    void operator/=(const BigInt &v) {
        *this = *this / v;
    }

    bool operator<(const BigInt &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const BigInt &v) const {
        return v < *this;
    }
    bool operator<=(const BigInt &v) const {
        return !(v < *this);
    }
    bool operator>=(const BigInt &v) const {
        return !(*this < v);
    }
    bool operator==(const BigInt &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    BigInt operator-() const {
        BigInt res = *this;
        res.sign = -sign;
        return res;
    }

    BigInt abs() const {
        BigInt res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend BigInt gcd(const BigInt &a, const BigInt &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend BigInt lcm(const BigInt &a, const BigInt &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, BigInt &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const BigInt &v) {
        if (v.sign == -1 && !v.isZero())
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    // Convert base 10^old --> 10^new.
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    void fft(vector<complex<double> > & a, bool invert) const {
        int n = (int) a.size();

        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * 3.14159265358979323846 / len * (invert ? -1 : 1);
            complex<double> wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                complex<double> w(1);
                for (int j = 0; j < len / 2; ++j) {
                    complex<double> u = a[i + j];
                    complex<double> v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (int i = 0; i < n; ++i)
                a[i] /= n;
    }

    void multiply_fft(const vector<int> &a, const vector<int> &b, vector<int> &res) const {
        vector<complex<double> > fa(a.begin(), a.end());
        vector<complex<double> > fb(b.begin(), b.end());
        int n = 1;
        while (n < (int) max(a.size(), b.size()))
            n <<= 1;
        n <<= 1;
        fa.resize(n);
        fb.resize(n);

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);

        res.resize(n);
        long long carry = 0;
        for (int i = 0; i < n; ++i) {
            long long t = (long long) (fa[i].real() + 0.5) + carry;
            carry = t / 1000;
            res[i] = t % 1000;
        }
    }

    BigInt operator*(const BigInt &v) const {
        BigInt res;
        res.sign = sign * v.sign;
        multiply_fft(convert_base(a, base_digits, 3), convert_base(v.a, base_digits, 3), res.a);
        res.a = convert_base(res.a, 3, base_digits);
        res.trim();
        return res;
    }

    BigInt mul_simple(const BigInt &v) const {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.resize(a.size() + v.a.size());
        for (int i = 0; i < (int) a.size(); ++i)
            if (a[i])
                for (int j = 0, carry = 0; j < (int) v.a.size() || carry; ++j) {
                    long long cur = res.a[i + j] + (long long) a[i] * (j < (int) v.a.size() ? v.a[j] : 0) + carry;
                    carry = (int) (cur / base);
                    res.a[i + j] = (int) (cur % base);
                }
        res.trim();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    BigInt mul_karatsuba(const BigInt &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        long long carry = 0;
        for (int i = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = cur / 1000000;
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
