#include <bits/stdc++.h>

const int MAXN = 300005;

int st[MAXN * 100], en[MAXN * 100];
int child[MAXN], stack[MAXN], cur[MAXN];
int n;

void dfs(int u) {
    int top = 0, cnt = 0;
    stack[++ top] = u;
    st[u] = cnt ++;
    while (top) {
	    int u = stack[top];
	    bool flag = false;
	    for (int &i = cur[u]; i < child[u + 1]; ++ i) {
	        st[i] = cnt ++;
	        if (i < n) {
		        stack[++ top] = i ++;
		        flag = true;
		        break;
	        }
	        else en[i] = cnt ++;
	    }
	    if (!flag) top --, en[u] = cnt ++;
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
	    scanf("%d", &n); child[0] = 1;
	    for (int i = 0; i < n; ++ i) {
	        int c; scanf("%d", &c);
	        child[i + 1] = child[i] + c;
        }
        for (int i = 0; i <= n; ++ i) cur[i] = child[i];
        dfs(0);
        int m; scanf("%d", &m);
        printf("Case %d:\n", cas);
        while (m --) {
            int u, v; scanf("%d%d", &u, &v);
            if (st[u] < st[v] && en[u] > en[v]) printf("Yes\n");
            else printf("No\n");
        }
        if (cas < T) printf("\n");
    }
    return 0;
}
