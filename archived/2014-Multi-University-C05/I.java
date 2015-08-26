import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	final public static BigInteger ZERO = BigInteger.ZERO;
	final public static BigInteger ONE = BigInteger.ONE;
	final public static BigInteger TWO = BigInteger.valueOf(2);
	public static TreeMap<BigInteger, BigInteger> mp = new TreeMap<BigInteger, BigInteger>();
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextBigInteger()) {
			BigInteger n = cin.nextBigInteger();
			mp.clear();
			System.out.println(f(n));
		}
	}
	public static BigInteger f(BigInteger n) {
		if (n.compareTo(TWO) < 0) return ZERO;
		if (mp.containsKey(n)) return mp.get(n);
		BigInteger k = n.shiftRight(1);
		BigInteger ret = ZERO;
		if (n.and(ONE).equals(ONE)) {
			ret = f(k).shiftLeft(2).add(k.multiply(BigInteger.valueOf(6)));
		}
		else {
			ret = f(k.subtract(ONE)).shiftLeft(1);
			ret = ret.add(f(k).shiftLeft(1)).add(n.shiftLeft(1));
			ret = ret.subtract(BigInteger.valueOf(4));
		}
		mp.put(n, ret);
		return ret;
	}
}
