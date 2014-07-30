import java.math.*;
import java.io.*;
import java.util.*;

public class Main {
    final static BigInteger ZERO = BigInteger.ZERO;
    final static BigInteger ONE = BigInteger.ONE;
    final static BigInteger TWO = BigInteger.valueOf(2);
    final static BigInteger FOUR = BigInteger.valueOf(4);
    final static BigInteger SIX = BigInteger.valueOf(6);
    
    static class Pell {
        BigInteger x, y;
        boolean solve(int D) {
            int s = (int)Math.sqrt((double)D);
            if (s * s == D) return false;
            BigInteger N = BigInteger.valueOf(D);
            BigInteger sqrtD = BigInteger.valueOf(s);
            BigInteger c = sqrtD, q = N.subtract(c.pow(2));
            BigInteger a = c.add(sqrtD).divide(q);
            int step = 0;
            BigInteger X[] = {BigInteger.ONE, sqrtD};
            BigInteger Y[] = {BigInteger.ZERO, BigInteger.ONE};
            while (true) {
                X[step] = a.multiply(X[step ^ 1]).add(X[step]);
                Y[step] = a.multiply(Y[step ^ 1]).add(Y[step]);
                c = a.multiply(q).subtract(c);
                q = N.subtract(c.pow(2)).divide(q);
                a = c.add(sqrtD).divide(q);
                step ^= 1;
                if (c.equals(sqrtD) && q.equals(BigInteger.ONE) && step == 1) {
                    x = X[0]; y = Y[0];
                    return true;
                }
            }
        }
    }
    public static void main(String args[]) throws Exception{
        Scanner cin = new Scanner(System.in);
        int p, A;
        while ((p = cin.nextInt()) != 0) {
            A = cin.nextInt();
            Pell equa = new Pell();
            boolean flag = false;
            if (p == 3) {
                if (equa.solve(8 * A) && equa.x.subtract(ONE).mod(TWO).equals(ZERO)) {
                    equa.x = equa.x.subtract(ONE).divide(TWO);
                    flag = true;
                }
            }
            else if (p == 5) {
                if (equa.solve(24 * A) && equa.x.add(ONE).mod(SIX).equals(ZERO)) {
                    equa.x = equa.x.add(ONE).divide(SIX);
                    flag = true;
                }
            }
            else if (p == 6) {
                if (equa.solve(8 * A) && equa.x.add(ONE).mod(FOUR).equals(ZERO)) {
                    equa.x = equa.x.add(ONE).divide(FOUR);
                    flag = true;
                }
            }
            if (!flag) System.out.println("Impossible!");
            else System.out.println(equa.x + " " + equa.y);
        }
    }
}
