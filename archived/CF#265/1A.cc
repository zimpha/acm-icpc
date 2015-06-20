#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;

char ret[MAXN];
int n, p;

bool dfs(int d) {
    if (d > n) return true;
    for (char c = 'a'; c < 'a' + p; ++ c) {
        if (c != ret[d - 1] && c != ret[d - 2]) {
            ret[d] = c;
            if (dfs(d + 1)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d%s", &n, &p, ret + 1);
    bool flag = false;
    for (int i = n; i && !flag; -- i) {
        if (i == 1) {
            for (ret[1] ++; ret[1] < 'a' + p; ++ ret[1]) {
                if (dfs(2)) {flag = true; break;}
            }
        }
        else {
            for (ret[i] ++; ret[i] < 'a' + p; ++ ret[i]) {
                if (ret[i] != ret[i - 1] && ret[i] != ret[i - 2]) {
                    if (dfs(i + 1)) {flag = true; break;}
                }
            }
        }
    }
    if (!flag) puts("NO");
    else printf("%s\n", ret + 1);
    return 0;
}
