import java.util.Scanner;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Xi Lin (zimpha@gmail.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskI solver = new TaskI();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskI {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        BigInteger f0 = in.nextBigInteger();
        BigInteger f1 = in.nextBigInteger();
        int n = in.nextInt() - 1;
        if (n == -1) {
            out.println(f0);
            return;
        }
        BigInteger a[][] = new BigInteger[2][2];
        a[0][0] = BigInteger.ONE;
        a[0][1] = BigInteger.ONE;
        a[1][0] = BigInteger.ONE;
        a[1][1] = BigInteger.ZERO;
        for (; n > 0; n >>= 1) {
            if (n % 2 == 1) {
                BigInteger t1 = f1.multiply(a[0][0]).add(f0.multiply(a[0][1]));
                BigInteger t0 = f1.multiply(a[1][0]).add(f0.multiply(a[1][1]));
                f1 = t1; f0 = t0;
            }
            BigInteger a00 = a[0][0].multiply(a[0][0]).add(a[0][1].multiply(a[1][0]));
            BigInteger a01 = a[0][0].multiply(a[0][1]).add(a[0][1].multiply(a[1][1]));
            BigInteger a10 = a[1][0].multiply(a[0][0]).add(a[1][1].multiply(a[1][0]));
            BigInteger a11 = a[1][0].multiply(a[0][1]).add(a[1][1].multiply(a[1][1]));
            a[0][0] = a00; a[0][1] = a01;
            a[1][0] = a10; a[1][1] = a11;
        }
        out.println(f1);
    }
}
