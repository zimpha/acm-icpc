import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	final static BigInteger ZERO = BigInteger.ZERO;
	final static BigInteger ONE = BigInteger.ONE;
	static int A[] = new int[200];
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		while (T -- > 0) {
			BigInteger L = cin.nextBigInteger();
			BigInteger R = cin.nextBigInteger();
			BigInteger ret = solve(R);
			ret = ret.subtract(solve(L.subtract(ONE)));
			if (ret.equals(ZERO)) System.out.println("Error!");
			else {
				BigInteger mo = ret.mod(BigInteger.valueOf(9));
				if (mo.compareTo(ZERO) <= 0) mo = mo.add(BigInteger.valueOf(9));
				ret = ret.mod(mo);
				ret = ret.add(mo);
				ret = ret.mod(mo);
				System.out.println(ret);
			}
		}
	}
	
	public static BigInteger solve(BigInteger N) {
		BigInteger ret = ZERO;
		if (N.compareTo(ZERO) <= 0) return ret;
		BigInteger ten = BigInteger.valueOf(10);
		BigInteger nine = BigInteger.valueOf(9);
		BigInteger FF = BigInteger.valueOf(45);
		String S = N.toString();
		int len = S.length();
		for (int i = 0; i < len; ++ i) A[i] = S.charAt(i) - '0';
		for (int i = 1; i < len; ++ i) {
			for (int j = 0; j < i; ++ j) {
				if (j % 2 == 0) {
					if (j == 0) ret = ret.add(FF.multiply(ten.pow(i - 1)));
					else ret = ret.add(nine.multiply(FF.multiply(ten.pow(i - 2))));
				}
				else {
					ret = ret.subtract(nine.multiply(FF.multiply(ten.pow(i - 2))));
				}
			}
		}
		for (int i = 0; i < len; ++ i) {
			for (int j = i, mul = 0; j < len; ++ j) {
				if (i == 0) mul = A[i]- 1;
				else mul = A[i];
				if (j % 2 == 0) {
					if (j == i) ret = ret.add(ten.pow(len - i - 1).multiply(BigInteger.valueOf(A[i]* (A[i]-1)/2)));
					else ret = ret.add(ten.pow(len - i - 2).multiply(BigInteger.valueOf(mul).multiply(FF)));
				}
				else {
					if (j == i) ret = ret.subtract(ten.pow(len - i - 1).multiply(BigInteger.valueOf(A[i]* (A[i]-1)/2)));
					else ret = ret.subtract(ten.pow(len - i - 2).multiply(BigInteger.valueOf(mul).multiply(FF)));
				}
			}
			if (i % 2 == 0) ret = ret.add(calc(i, len).multiply(BigInteger.valueOf(A[i])));
			else ret = ret.subtract(calc(i, len).multiply(BigInteger.valueOf(A[i])));
		}
		return ret;
	}
	
	public static BigInteger calc(int idx, int len) {
		BigInteger ret = ONE;
		BigInteger ten = BigInteger.valueOf(10);
		for (int i = idx + 1; i < len; ++ i) {
			ret = ret.add(ten.pow(len - i - 1).multiply(BigInteger.valueOf(A[i])));
		}
		return ret;
	}
}
