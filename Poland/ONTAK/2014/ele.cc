#include <bits/stdc++.h>
#define val first
#define idx second
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int MAXN = 5e5 + 10;
vector<int> G[MAXN];
int sz[MAXN], N;
LL cost[MAXN], ret;
LL dn[MAXN], cr[MAXN], cd[MAXN];

void dfs(int u, int f = 0) {
    sz[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        int v = G[u][i]; if (v == f) continue;
        dfs(v, u); sz[u] += sz[v];
    }
    cost[u] = (LL)sz[u] * (N - sz[u]);
}

inline LL takemax(PLI a[], int n, PLI b[], int m) {
    LL ret = 0;
    for (int i = 0; i < n; ++ i) for (int j = 0; j < m; ++ j) {
        if (a[i].idx != b[j].idx) ret = max(ret, a[i].val + b[j].val);
    }
    return ret;
}

inline void update(PLI a[], int n, PLI v) {
    for (int i = 0; i < n; ++ i) if (v > a[i]) {
        for (int j = n - 1; j > i; -- j) a[j] = a[j - 1];
        a[i] = v; break;
    }
}

inline void update(LL x) {
    ret = max(ret, x);
}

void solve(int u, int f = 0) {
    PLI dm[3], cm[3], bm[2];
    dm[0] = dm[1] = dm[2] = bm[0] = PLI(0, 0);
    cm[0] = cm[1] = cm[2] = bm[1] = PLI(0, 0);
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        int v = G[u][i]; if (v == f) continue;
        solve(v, u);
        
        dn[u] = max(dn[u], dn[v] + cost[v]);
        update(dm, 3, PLI(dn[v] + cost[v], v));

        cr[u] = max(cr[u], cr[v]);
        update(cm, 3, PLI(cr[v], v));

        cd[u] = max(cd[u], cd[v] + cost[v]);
        update(bm, 2, PLI(cd[v] + cost[v], v));
    }
    cr[u] = max(cr[u], dm[0].val + dm[1].val);
    cd[u] = max(cd[u], takemax(cm, 2, dm, 2));
    update(cm[0].val + cm[1].val);
    update(takemax(bm, 2, dm, 2));
    
    if (cm[0].idx != dm[0].idx && cm[0].idx != dm[1].idx) update(cm[0].val + dm[0].val + dm[1].val);
    if (cm[0].idx != dm[0].idx && cm[0].idx != dm[2].idx) update(cm[0].val + dm[0].val + dm[2].val);
    if (cm[0].idx != dm[1].idx && cm[0].idx != dm[2].idx) update(cm[0].val + dm[1].val + dm[2].val);
    if (cm[1].idx != dm[0].idx && cm[1].idx != dm[1].idx) update(cm[1].val + dm[0].val + dm[1].val);
    if (cm[1].idx != dm[0].idx && cm[1].idx != dm[2].idx) update(cm[1].val + dm[0].val + dm[2].val);
    if (cm[1].idx != dm[1].idx && cm[1].idx != dm[2].idx) update(cm[1].val + dm[1].val + dm[2].val);
    if (cm[2].idx != dm[0].idx && cm[2].idx != dm[1].idx) update(cm[2].val + dm[0].val + dm[1].val);
    if (cm[2].idx != dm[0].idx && cm[2].idx != dm[2].idx) update(cm[2].val + dm[0].val + dm[2].val);
    if (cm[2].idx != dm[1].idx && cm[2].idx != dm[2].idx) update(cm[2].val + dm[1].val + dm[2].val);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N; ++ i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1); solve(1);
    for (int i = 1; i <= N; ++ i) ret -= cost[i];
    printf("%lld\n", -ret);
    return 0;
}
