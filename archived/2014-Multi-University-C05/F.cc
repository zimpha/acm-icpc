#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10, inf = 1e9;

struct Edge {
    int v, nxt;
    Edge() {}
    Edge(int a, int b) : v(a), nxt(b) {}
} E[MAXN << 1];

int G[MAXN], dep[MAXN], father[MAXN], child[MAXN][4];
int belong[MAXN], path[MAXN], subtree[MAXN], Q[MAXN];
int N, M;

char buf;
inline int xint() { while (buf = getchar(), buf < '0' || buf > '9'); int x = buf - '0'; for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0'); return x; }

int query(int u, int v) {
    if (u > v) swap(u, v);
    if (u != 0 && belong[u] == belong[v]) return 0;
    int i = 0;
    while (child[0][i] == belong[u] || child[0][i] == belong[v]) ++ i;
    int ret = u == 0 ? path[v] : min(path[u], path[v]);
    return min(ret, child[0][i]);
}

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; ++ i) {
            G[i] = -1;
            for (int _ = 0; _ < 4; ++ _) child[i][_] = inf;
        }
        for (int i = 0; i < N - 1; ++ i) {
            int u = xint(), v = xint(); 
            -- u, -- v;
            E[i << 1] = Edge(v, G[u]); G[u] = i << 1;
            E[i << 1 | 1] = Edge(u, G[v]); G[v] = i << 1 | 1; 
        }
        Q[0] = 0; father[0] = -1; dep[0] = 0;
        for (int h = 0, t = 1; h < t; ++ h) {
            int u = Q[h];
            for (int now = G[u]; ~now; now = E[now].nxt) {
                int v = E[now].v; if (v == father[u]) continue;
                father[v] = u; dep[v] = dep[u] + 1;
                Q[t ++] = v;
            }
        }
        for (int i = N - 1; i >= 0; -- i) {
            int u = Q[i], p = father[u];
            subtree[u] = min(u, child[u][0]);
            if (~p) {
                child[p][3] = subtree[u];
                sort(child[p], child[p] + 4);
            }
        }
        int tail = 0;
        for (int now = G[0]; ~now; now = E[now].nxt) {
            int v = E[now].v;
            path[v] = inf;
            belong[v] = subtree[v];
            Q[tail ++] = v;
        }
        path[0] = inf; belong[0] = -1;
        for (int h = 0; h < tail; ++ h) {
            int u = Q[h];
            for (int now = G[u]; ~now; now = E[now].nxt) {
                int v = E[now].v; if (v == father[u]) continue;
                path[v] = min(path[u], child[u][subtree[v] == child[u][0]]);
                belong[v] = belong[u]; Q[tail ++] = v;
            }
            path[u] = min(path[u], child[u][0]);
        }
        int lastans = 0;
        while (M --) {
            int u = xint(), v = xint();
            u ^= lastans; v ^= lastans;
            lastans = query(u - 1, v - 1) + 1;
            printf("%d\n", lastans);
        }
    }
    return 0;
}
