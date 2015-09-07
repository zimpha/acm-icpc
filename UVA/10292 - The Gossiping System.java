import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		while (T -- > 0) {
			BigInteger N = cin.nextBigInteger();
			N = N.shiftLeft(1);
			BigInteger left = BigInteger.ONE, right = N;
			while (left.compareTo(right) < 0) {
				BigInteger mid = left.add(right).subtract(BigInteger.ONE).shiftRight(1);
				BigInteger now = mid.pow(2).subtract(mid);
				if (now.compareTo(N) >= 0) right = mid;
				else left = mid.add(BigInteger.ONE);
			}
			N = N.subtract(left.pow(2).subtract(left));
			if (N.equals(BigInteger.ZERO)) System.out.println("Yes.");
			else System.out.println("No.");
		}
	}
}
