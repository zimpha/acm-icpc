#include <bits/stdc++.h>
using namespace std;

int s[4][4] ={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
bool f[1000];

void dfs(int k, int now, int x, int y) {
    if (k < 3) {
        for (int i = x; i < 4; ++ i)
            for (int j = y; j < 3; ++ j)
                if (s[i][j] != -1) dfs(k + 1, now * 10 + s[i][j], i, j);
    }
    f[now] = true;
}

bool ch(int d) {
    return (d < 0 || d >= 1000) ? false : f[d];
}

int main() {
    dfs(0, 0, 0, 0);
    int T; scanf("%d", &T);
    while (T --) {
        int t; scanf("%d", &t);
        int d = 0;
        while(!(ch(t + d) || ch(t - d))) ++ d;
        printf("%d\n", ch(t + d) ? t + d : t - d);
    }
    return 0;
}
