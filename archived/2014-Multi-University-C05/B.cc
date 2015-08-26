#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

struct Edge {
    int v, nxt;
    Edge() {}
    Edge(int a, int b) : v(a), nxt(b) {}
} E[MAXN << 1];

int G[MAXN], dep[MAXN], st[MAXN], ed[MAXN];
int father[MAXN][20], pos[MAXN], C[MAXN];
int N, M, sz;

namespace LCA {
    static const int POW = 17;
    void build() {
        for (int i = 1; (1 << i) <= N; ++ i) {
            for (int j = 1; j <= N; ++ j) {
                if (father[j][i - 1] == 0) continue;
                father[j][i] = father[father[j][i - 1]][i - 1];
            }
        }
    }
    int up(int u, int d) {
        for (int i = 0; d; ++ i, d >>= 1) {
            if (d & 1) u = father[u][i];
        }
        return u;
    }
    int query(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = up(u, dep[u] - dep[v]);
        for (int i = POW; i >= 0; -- i) {
            if (father[u][i] == father[v][i]) continue;
            u = father[u][i]; v = father[v][i];
        }
        if (u != v) u = father[u][0];
        return u;
    }
}

void dfs(int u) {
    st[u] = ++ sz; pos[u] = sz;
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v; if (dep[v] != -1) continue;
        father[v][0] = u; dep[v] = dep[u] + 1;
        dfs(v);
    }
    ed[u] = sz;
}

struct Node {
    int u, v, f;
    bool operator < (const Node &rhs) const {
        return dep[f] > dep[rhs.f];
    }
} Query[MAXN];

void add(int i, int v) {
    for (; i <= N; i += i & -i) C[i] += v;
}

int sum(int i) {
    int ret = 0;
    for (; i; i -= i & -i) ret += C[i];
    return ret;
}

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; ++ i) {
            G[i] = -1; dep[i] = -1;
            memset(father[i], 0, sizeof(father[i]));
        }
        sz = 0;
        for (int i = 1; i < N; ++ i) {
            int u, v; scanf("%d%d", &u, &v);
            E[sz] = Edge(v, G[u]); G[u] = sz ++;
            E[sz] = Edge(u, G[v]); G[v] = sz ++;
        }
        sz = 0; dep[1] = 0; dfs(1);
        LCA::build();
        for (int i = 1; i <= N; ++ i) C[i] = 0;
        for (int i = 0; i < M; ++ i) {
            scanf("%d%d", &Query[i].u, &Query[i].v);
            Query[i].f = LCA::query(Query[i].u, Query[i].v);
        }
        sort(Query, Query + M);
        int ret = 0;
        for (int i = 0; i < M; ++ i) {
            int u = Query[i].u, v = Query[i].v, f = Query[i].f;
            int vu = sum(pos[u]), vv = sum(pos[v]);
            if (vu || vv) continue;
            add(st[f], 1); add(ed[f] + 1, -1);
            ++ ret;
        }
        printf("%d\n", ret);
    }
}
