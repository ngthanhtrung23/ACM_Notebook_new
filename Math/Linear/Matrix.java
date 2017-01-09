import java.math.*;
import java.util.*;
import java.io.*;

class Matrix
{
    public int m, n;
    public BigInteger[][] a;

    Matrix(int m, int n) {
        this.m = m;
        this.n = n;
        a = new BigInteger[m][n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = BigInteger.ZERO;
    }

    public void print() {
        System.out.println("size = " + m + " " + n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }

    public BigInteger det() {
        boolean rev = false;
        BigInteger mult = BigInteger.ONE;
        for(int j = 0; j < n; j++) {
            int save = -1;
            for(int i = j; i < n; i++)
                if (a[i][j].compareTo(BigInteger.ZERO) != 0)
                if (save < 0 || a[save][j].abs().compareTo(a[i][j].abs()) > 0)
                    save = i;

            if (save < 0 || a[save][j].compareTo(BigInteger.ZERO) == 0) return BigInteger.ZERO;

            if (save != j) {
                rev = !rev;
                for(int k = 0; k < n; k++) {
                    BigInteger tmp = a[j][k];
                    a[j][k] = a[save][k];
                    a[save][k] = tmp;
                }
            }

            BigInteger m1, m2;
            for(int i = j+1; i < n; i++) if (a[i][j].compareTo(BigInteger.ZERO) != 0) {
                m1 = a[j][j];
                m2 = a[i][j];
                mult = mult.multiply(m1);
                for(int k = 0; k < n; k++) {
                    a[i][k] = a[i][k].multiply(m1).subtract(a[j][k].multiply(m2));
                }
            }
        }
        BigInteger res = BigInteger.ONE;
        for(int i = 0; i < n; i++)
            res = res.multiply(a[i][i]);
        if (rev) res = res.negate();
        return res.divide(mult);
    }
}
