package task;

import task.InputReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class TaskC {
    int w[], cnt[], ok[];
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), t = in.nextInt(), r = in.nextInt();
        w = new int[n]; cnt = new int[630]; ok = new int[630];
        Arrays.fill(cnt, 0); Arrays.fill(ok, 0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
            boolean flag = true;
            while (cnt[w[i]] < r) {
                int st = w[i] - 1 + 300;
                flag = false; ++ ret;
                for (int j = st; j >= 0; -- j) {
                    if (ok[j] == 0 && j - 300 + t >= w[i]) {
                        flag = true;
                        ok[j] = 1;
                        cover(j + 1 - 300, j + t - 300);
                        break;
                    }
                }
                if (flag == false) break;
            }
            if (flag == false) {
                ret = -1;
                break;
            }
        }
        out.println(ret);
    }
    void cover(int l, int r) {
        if (l < 0) l = 0;
        for (int i = l; i <= r; ++ i) cnt[i] ++;
    }
}
