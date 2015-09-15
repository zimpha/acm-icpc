#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000 + 10;
vector<int> G[MAXN];
int dis[MAXN], father[MAXN];
int a[MAXN], b[MAXN], d[MAXN];
int n, m;

void dfs(int u, int f = -1, int d = 0) {
    dis[u] = d; father[u] = f;
    for (auto &v : G[u]) {
        if (v != f) dfs(v, u, d + 1);
    }
}

int solve() {
    int ret = 0;
    for (int _=  0; _ < 2; ++ _) {
        dfs(ret);
        int mx = 0, idx = -1;
        for (int i = 0; i < m; ++ i) {
            int td = (dis[a[i]] + dis[b[i]] - d[i] + 1) / 2;
            if (td > mx) mx = td, idx = i;
        }
        if (mx == 0) return ret; ret = a[idx];
        for (int i = 0; i < dis[a[idx]] - mx; ++ i) ret = father[ret];
    }
    return -1;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++ i) G[i].clear();
        for (int i = 1; i < n; ++ i) {
            int u, v; scanf("%d%d", &u, &v); -- u, -- v;
            G[u].push_back(v); G[v].push_back(u);
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d%d", a + i, b + i, d + i);
            -- a[i]; -- b[i];
        }
        int ret = solve();
        if (ret < 0) puts("NIE");
        else printf("TAK %d\n", ret + 1);
    }
    return 0;
}