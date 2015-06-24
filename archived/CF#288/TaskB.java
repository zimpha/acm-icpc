package task;

import task.InputReader;
import java.io.PrintWriter;

public class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        char s[] = in.next().toCharArray();
        String ans = new String("-1");
        int n = s.length, last = -1;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % 2 == 0) {
                if (s[n - 1] > s[i]) {
                    char t = s[i]; s[i] = s[n - 1]; s[n - 1] = t;
                    ans = new String(s);
                    break;
                }
                last = i;
            }
        }
        if (ans.equals("-1") && last != -1) {
            char t = s[last]; s[last] = s[n - 1]; s[n - 1] = t;
            ans = new String(s);
        }
        out.println(ans);
    }
}
