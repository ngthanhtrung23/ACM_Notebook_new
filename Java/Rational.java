import java.math.*;

class Rational implements Comparable<Rational> {
    public BigInteger a, b;

    public Rational(BigInteger a, BigInteger b) {
        this.a = a;
        this.b = b;
        norm();
    }

    public int compareTo(Rational other) {
        return a.multiply(other.b).compareTo(b.multiply(other.a));
    }

    public Rational(BigInteger bigInteger) {
        this(bigInteger, BigInteger.ONE);
    }

    public Rational(int integer) {
        this(BigInteger.valueOf(integer), BigInteger.ONE);
    }

    public String toString() {
        return a.toString() + "/" + b.toString();
    }

    private void reduce() {
        BigInteger gcd = a.gcd(b);
        if (!gcd.equals(BigInteger.ONE)) {
            a = a.divide(gcd);
            b = b.divide(gcd);
        }
    }

    private void norm() {
        if (b.compareTo(BigInteger.ZERO) == -1) {
            a = a.negate();
            b = b.negate();
        }

        if (a.equals(BigInteger.ZERO)) {
            b = BigInteger.ONE;
        } else {
            reduce();
        }
    }

    public Rational add(Rational other) {
        return new Rational(
                a.multiply(other.b).add(other.a.multiply(b)),
                b.multiply(other.b));
    }

    public Rational negate() {
        return new Rational(a.negate(), b);
    }

    public Rational subtract(Rational other) {
        return add(other.negate());
    }

    public Rational multiply(Rational other) {
        return new Rational(a.multiply(other.a), b.multiply(other.b));
    }

    public Rational reciprocal() {
        if (a.equals(BigInteger.ZERO)) {
            throw new java.lang.ArithmeticException();
        }
        return new Rational(b, a);
    }

    public Rational divide(Rational other) {
        return multiply(other.reciprocal());
    }

    public boolean isInteger() {
        return b.equals(BigInteger.ONE);
    }

    public BigInteger asInteger() {
        if (!isInteger()) {
            throw new java.lang.ArithmeticException();
        }
        return a;
    }

    public boolean isZero() {
        return a.equals(BigInteger.ZERO);
    }

    public static final Rational ZERO = new Rational(BigInteger.ZERO);
    public static final Rational ONE = new Rational(BigInteger.ONE);
}

