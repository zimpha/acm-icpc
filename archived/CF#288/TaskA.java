package task;

import task.InputReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class TaskA {
    int A[][], n, m, k;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        A = new int[n][m];
        out.println(gao(in));
    }
    int gao(InputReader in) {
        for (int i = 0; i < n; ++ i) Arrays.fill(A[i], 0);
        for (int i = 1; i <= k; ++ i) {
            int x = in.nextInt() - 1, y = in.nextInt() - 1;
            A[x][y] = 1;
            if (check(x, y)) return i;
        }
        return 0;
    }
    boolean check(int x, int y) {
        if (x >= 1 && y >= 1 && A[x][y - 1] == 1 && A[x - 1][y] == 1 && A[x - 1][y - 1] == 1) return true;
        if (x >= 1 && y + 1 < m && A[x][y + 1] == 1 && A[x - 1][y] == 1 && A[x - 1][y + 1] == 1) return true;
        if (x + 1 < n && y >= 1 && A[x][y - 1] == 1 && A[x + 1][y] == 1 && A[x + 1][y - 1] == 1) return true;
        if (x + 1 < n && y + 1 < m && A[x][y + 1] == 1 && A[x + 1][y] == 1 && A[x + 1][y + 1] == 1) return true;
        return false;
    }
}
