#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 10;

bool G[MAXN][MAXN], vis[MAXN];
int idx[MAXN], deg[MAXN], N;
double t[MAXN], p[MAXN];

bool cmp(int a, int b) {
    return t[a] * (1.0 - p[b]) < t[b] * (1.0 - p[a]);
}

int main() {
    scanf("%d", &N);
    memset(G, 0, sizeof(G));
    for (int i = 1, k; i <= N; ++ i) {
        scanf("%lf%lf%d", &t[i], &p[i], &k);
        for (int x; k --; ) {
            scanf("%d", &x);
            G[x][i] = 1;
        }
    }
    for (int k = 1; k <= N; ++ k) {
        for (int i = 1; i <= N; ++ i) {
            for (int j = 1; j <= N; ++ j) {
                G[i][j] |= G[i][k] & G[k][j];
            }
        }
    }
    for (int i = 1; i <= N; ++ i) {
        vis[i] = true;
        for (int j = 1; j < i; ++ j) {
            if (G[i][j] && G[j][i]) vis[i] = false;
        }
    }
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= N; ++ j) {
            if (i == j || !vis[i] || !vis[j]) continue;
            if (G[i][j]) ++ deg[j];
        }
    }
    queue<int> Q;
    for (int i = 1; i <= N; ++ i) {
        if (vis[i] && deg[i] == 0) Q.push(i);
    }
    int tot = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int now = tot;
        for (int i = 1; i <= N; ++ i) {
            if (i == u || (G[u][i] && G[i][u])) {
                idx[tot ++] = i;
            }
        }
        sort(idx + now, idx + tot, cmp);
        for (int i = 1; i <= N; ++ i) {
            if (vis[i] && G[u][i]) {
                -- deg[i];
                if (deg[i] == 0) Q.push(i);
            }
        }
    }
    for (int i = 0; i < N; ++ i) {
        int u = idx[i];
        for (int j = 0; j < i; ++ j) {
            int v = idx[j];
            if (G[v][u]) t[u] *= p[v];
        }
    }
    double ret = 0;
    for (int i = 1; i <= N; ++ i) ret += t[i];
    printf("%.10f\n", ret);
    return 0;
}
