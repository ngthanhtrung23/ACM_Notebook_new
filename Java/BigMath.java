import java.math.*;

class BMath {
    static int cnt1, cnt2;
    public static MathContext mc = null;
    public static BigDecimal eps = null;
    public static BigDecimal two = null;
    public static BigDecimal sqrt3 = null;
    public static BigDecimal pi = null;
    public static final int PRECISION = 128;

    static {
        mc = new MathContext(PRECISION);
        eps = BigDecimal.ONE.scaleByPowerOfTen(-PRECISION);
        two = BigDecimal.valueOf(2);
        sqrt3 = sqrt(BigDecimal.valueOf(3));
        pi = asin(BigDecimal.valueOf(0.5)).multiply(BigDecimal.valueOf(6));
    }

    // val > 0
    public static BigInteger sqrt(BigInteger val) {
        int len = val.bitLength();
        BigInteger left = BigInteger.ONE.shiftLeft((len - 1) / 2);
        BigInteger right = BigInteger.ONE.shiftLeft(len / 2 + 1);
        while (left.compareTo(right) < 0) {
            BigInteger mid = left.add(right).shiftRight(1);
            if (mid.multiply(mid).compareTo(val) <= 0) {
                left = mid.add(BigInteger.ONE);
            } else {
                right = mid;
            }
        }
        return right.subtract(BigInteger.ONE);
    }

    public static BigDecimal sqrt(BigDecimal val) {
        BigInteger unscaledVal = val.scaleByPowerOfTen(2 * mc.getPrecision()).toBigInteger();
        return new BigDecimal(sqrt(unscaledVal)).scaleByPowerOfTen(-mc.getPrecision());
    }

    // arcsin x =∑(n=1～∞) [(2n)!]x^(2n+1)/[4^n*(n!)^2*(2n+1)]
    // arctan x =∑(n=1～∞) [(-1)^n]x^(2n+1)/(2n+1)
    public static BigDecimal asin(BigDecimal val) {
        BigDecimal tmp = val;
        BigDecimal ret = tmp;
        val = val.multiply(val, mc);
        for (int n = 1; tmp.compareTo(eps) > 0; ++n) {
            tmp = tmp.multiply(val, mc).multiply(
                    BigDecimal.valueOf(2 * n - 1).divide(BigDecimal.valueOf(2 * n), mc), mc);
            ret = ret.add(tmp.divide(BigDecimal.valueOf(2 * n + 1), mc), mc);
        }
        return ret;
    }
}
