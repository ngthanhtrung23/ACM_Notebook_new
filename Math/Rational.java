import java.math.*;

class Rational {
    private BigInteger num, denom;

    public BigInteger getNumerator() {
        return num;
    }

    public BigInteger getDenominator() {
        return denom;
    }

    public Rational(BigInteger num, BigInteger denom) {
        this.num = num;
        this.denom = denom;
        norm();
    }

    public Rational(BigInteger bigInteger) {
        this(bigInteger, BigInteger.ONE);
    }

    public Rational(int integer) {
        this(BigInteger.valueOf(integer), BigInteger.ONE);
    }

    public String toString() {
        return num.toString() + "/" + denom.toString();
    }

    private void reduce() {
        BigInteger gcd = num.gcd(denom);
        if (!gcd.equals(BigInteger.ONE)) {
            num = num.divide(gcd);
            denom = denom.divide(gcd);
        }
    }

    private void norm() {
        if (denom.compareTo(BigInteger.ZERO) == -1) {
            num = num.negate();
            denom = denom.negate();
        }

        if (num.equals(BigInteger.ZERO)) {
            denom = BigInteger.ONE;
        } else {
            reduce();
        }
    }

    public Rational add(Rational other) {
        return new Rational(num.multiply(other.denom).add(other.num.multiply(denom)), denom.multiply(other.denom));
    }

    public Rational negate() {
        return new Rational(num.negate(), denom);
    }

    public Rational subtract(Rational other) {
        return add(other.negate());
    }

    public Rational multiply(Rational other) {
        return new Rational(num.multiply(other.num), denom.multiply(other.denom));
    }

    public Rational reciprocal() {
        if (num.equals(BigInteger.ZERO)) {
            throw new java.lang.ArithmeticException();
        }
        return new Rational(denom, num);
    }

    public Rational divide(Rational other) {
        return multiply(other.reciprocal());
    }

    public boolean isInteger() {
        return denom.equals(BigInteger.ONE);
    }

    public BigInteger asInteger() {
        if (!isInteger()) {
            throw new java.lang.ArithmeticException();
        }
        return num;
    }

    public boolean isZero() {
        return num.equals(BigInteger.ZERO);
    }

    public static final Rational ZERO = new Rational(BigInteger.ZERO);
    public static final Rational ONE = new Rational(BigInteger.ONE);
}

