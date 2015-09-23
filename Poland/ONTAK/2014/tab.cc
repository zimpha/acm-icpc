#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10, MAXM = 1000000, inf = 1e9;
int A[MAXN][MAXN], vis[MAXN], n, k;

namespace NetFlow {
    struct Edge {
        int v, c, f, nxt;
        Edge() {}
        Edge(int v, int c, int f, int n) :
            v(v), c(c), f(f), nxt(n) {}
    } E[MAXM];
    int G[MAXN], cur[MAXN], pre[MAXN], dis[MAXN], gap[MAXN];
    int N, S, T, sz;
    void init(int _n, int _s, int _t) {
        N = _n, S = _s, T = _t; sz = 0;
        memset(G, -1, sizeof(G));
    }
    void addedge(int u, int v, int c) {
        E[sz] = Edge(v, c, 0, G[u]); G[u] = sz ++;
        E[sz] = Edge(u, 0, 0, G[v]); G[v] = sz ++;
    }
    int flow() {
        int maxflow = 0, aug = inf, u, v;
        for (int i = 0; i <= N; ++ i) cur[i] = G[i], gap[i] = dis[i] = 0;
        for (gap[S] = N, u = pre[S] = S; dis[S] < N;) {
            bool flag = false;
            for (int &it = cur[u]; ~it; it = E[it].nxt) {
                Edge &ne = E[it];
                if (ne.c > ne.f && dis[u] == dis[v = ne.v] + 1) {
                    if (ne.c - ne.f < aug) aug = ne.c - ne.f;
                    pre[v] = u; u = v; flag = true;
                    if (u == T) {
                        for (maxflow += aug; u != S;) {
                            E[cur[u = pre[u]]].f += aug;
                            E[cur[u] ^ 1].f -= aug;
                        }
                        aug = inf;
                    }
                    break;
                }
            }
            if (flag) continue;
            int ms = N;
            for (int it = G[u]; ~it; it = E[it].nxt) {
                if (E[it].c > E[it].f && dis[E[it].v] < ms) {
                    ms = dis[E[it].v]; cur[u] = it;
                }
            }
            if ((--gap[dis[u]]) == 0) break;
            ++ gap[dis[u] = ms + 1]; u = pre[u];
        }
        return maxflow;
    }
    void gao(int u) {
        for (int it = G[u]; ~it; it = E[it].nxt) {
            int v = E[it].v; if (v == S) continue;
            A[u][v - n] = E[it].f;
        }
    }
    void solve() {
        for (int it = G[S]; ~it; it = E[it].nxt) gao(E[it].v);
    }
}

int main() {
    scanf("%d%d", &n, &k); k -= n;
    if (k < 0) {
        puts("NIE");
        return 0;
    }
    int S = n << 1, T = n << 1 | 1;
    NetFlow::init(S + 10, S, T);
    for (int i = 0; i < n; ++ i) {
        NetFlow::addedge(S, i, k);
        NetFlow::addedge(i + n, T, k);
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            NetFlow::addedge(i, j + n, inf);
        }
    }
    int ret = NetFlow::flow();
    if (ret != n * k) puts("NIE");
    else {
        puts("TAK");
        memset(vis, 0, sizeof(vis));
        NetFlow::solve();
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                printf("%d%c", A[i][j] + 1, " \n"[j == n - 1]);
            }
        }
    }
    return 0;
}
