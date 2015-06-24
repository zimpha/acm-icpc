package task;

import task.InputReader;
import java.io.PrintWriter;
import java.util.Stack;

public class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] l = new int[n], r = new int[n], p = new int[n];
        Stack<Integer> S = new Stack<Integer>();
        String ret = new String();
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            p[i] = ret.length();
            ret = ret + "(";
            S.push(i);
            while (!S.empty() && p[S.peek()] + l[S.peek()] <= ret.length()) {
                if (p[S.peek()] + r[S.peek()] < ret.length()) {
                    out.println("IMPOSSIBLE");
                    return;
                }
                S.pop(); ret = ret + ")";
            }
        }
        if (!S.empty()) out.println("IMPOSSIBLE");
        else out.println(ret);
    }
}
