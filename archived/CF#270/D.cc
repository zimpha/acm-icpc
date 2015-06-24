#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 10, inf = 1e9;

void halt(char s[]) {
    cout << s << endl;
    exit(0);
}
typedef long long LL;

int pre[MAXN], vis[MAXN], n;
LL mx[MAXN], d[MAXN][MAXN];

LL prim() {
    LL ret = 0;
    int i, j, k;
    for (i = 0; i < n; ++ i) mx[i] = inf, vis[i] = false, pre[i] = -1;
    for (mx[j = 0] = 0; j < n; ++ j) {
        for (k = -1, i = 0; i < n; ++ i) {
            if (!vis[i] && (k == -1 || mx[i] < mx[k])) k = i;
        }
        for (vis[k] = 1, ret += mx[k], i = 0; i < n; ++ i) {
            if (!vis[i] && d[k][i] < mx[i]) mx[i] = d[pre[i] = k][i];
        }
    }
    return ret;
}

vector<int> G[MAXN];

void dfs(int u, LL val) {
    vis[u] = true; mx[u] = val;
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        int v = G[u][i]; if (vis[v]) continue;
        dfs(v, val + d[u][v]);
    }
}

bool check() {
    prim();
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 0; i < n; ++ i) {
        if (pre[i] != -1) G[i].push_back(pre[i]), G[pre[i]].push_back(i);
    }
    for (int i = 0; i < n; ++ i) {
        memset(vis, 0, sizeof(vis[0]) * n);
        dfs(i, 0);
        for (int j = i + 1; j < n; ++ j) {
            if (d[i][j] != mx[j]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; ++ i) {
        if (d[i][i] != 0) halt("NO");
        for (int j = i + 1; j < n; ++ j) {
            if (d[i][j] != d[j][i] || d[i][j] == 0) halt("NO");
        }
    }
    if (check()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
