import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static BigInteger x, y;
    final static BigInteger ZERO = BigInteger.ZERO;
    final static BigInteger ONE = BigInteger.ONE;
    
    static BigInteger exgcd(BigInteger a, BigInteger b) {
        if (b.equals(BigInteger.ZERO)) {
            x = BigInteger.ONE;
            y = BigInteger.ZERO;
            return a;
        }
        BigInteger g = exgcd(b, a.mod(b)), t = x;
        x = y;
        y = t.subtract(a.divide(b).multiply(y));
        return g;
    }
    
    static BigInteger gcd(BigInteger a, BigInteger b) {
        if (b.equals(ZERO)) return a;
        else return gcd(b, a.mod(b));
    }
    
    public static void main(String[] args) throws IOException{
        Scanner cin = new Scanner(new File("e.in"));
        //Scanner cin = new Scanner(System.in);
        BigInteger a = cin.nextBigInteger();
        BigInteger b = cin.nextBigInteger();
        BigInteger c = cin.nextBigInteger();        
        if (b.equals(ZERO)) {
            BigInteger t = a; a = b; b = t;
        }
        if (c.equals(a) || c.equals(b)) {
            System.out.println("YES");
            return;
        }
        if (a.equals(ZERO)) {
            if (b.equals(ZERO)) System.out.println("NO");
            else {
                if (c.mod(b).equals(ZERO)) System.out.println("YES");
                else System.out.println("NO");
            }
        }
        else {
            BigInteger g = exgcd(a, b);
            if (c.mod(g).equals(ZERO)) {
                b = b.divide(g); a = a.divide(g); c = c.divide(g);                
                x = x.mod(b).multiply(c.mod(b)).mod(b);
                x = x.add(b).mod(b);
                y = c.subtract(a.multiply(x)).divide(b);
                if (x.equals(ZERO)) {x = x.add(b);y = y.subtract(a);}
                boolean flag = false;
                while (y.compareTo(ONE) >= 0) {
                    if (gcd(x, y).equals(ONE)) {
                        flag = true;
                        break;
                    }
                    x = x.add(b);
                    y = y.subtract(a);
                }
                //System.out.println(x + " " + y);
                if (flag) System.out.println("YES");
                else System.out.println("NO");
            }
            else System.out.println("NO");
        }
    }
}

