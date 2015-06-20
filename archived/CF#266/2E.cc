#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<PII> query[MAXN];
vector<int> G[MAXN];
int t[MAXN], x[MAXN], y[MAXN];
int st[MAXN], ed[MAXN], dsu[MAXN];
int ret[MAXN], deg[MAXN];
int n, m, sz;

int get(int x) {
    if (x != dsu[x]) dsu[x] = get(dsu[x]);
    return dsu[x];
}

void dfs(int u) {
    st[u] = sz ++;
    for (int v : G[u]) dfs(v);
    ed[u] = sz ++;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", t + i, x + i);
        if (t[i] != 2) scanf("%d", y + i);
        if (t[i] == 1) G[y[i]].push_back(x[i]), deg[x[i]] ++;
        if (t[i] == 3) query[y[i]].push_back(PII(x[i], i));
        ret[i] = -1;
    }
    for (int i = 1; i <= n; ++ i) {
        if (!deg[i]) G[0].push_back(i);
    }
    dfs(0);
    for (int i = 1; i <= n; ++ i) dsu[i] = i;
    for (int i = 0, pack = 0; i < m; ++ i) {
        if (t[i] == 1) dsu[get(x[i])] = get(y[i]);
        else if (t[i] == 2) {
            ++ pack;
            for (auto &it : query[pack]) {
                int v = x[i], u = it.first, id = it.second;
                if (get(u) == get(v) && st[u] <= st[v] && ed[u] >= ed[v]) ret[id] = 1;
                else ret[id] = 0;
            }
        }
    }
    for (int i = 0; i < m; ++ i) {
        if (ret[i] == -1) continue;
        if (ret[i] == 0) puts("NO");
        else puts("YES");
    }
    return 0;
}
