#include <bits/stdc++.h>
using namespace std;

int n, limits;

namespace MCMF {
    const int MAXN = 50 + 10, MAXM = 100000 + 10, inf = 1e9;
    struct Edge {
        int u, v, f, c;
        int nxt;
        Edge() {}
        Edge(int u, int v, int f, int c, int n) : u(u), v(v), f(f), c(c), nxt(n) {}
    } E[MAXM];
    int G[MAXN], dis[MAXN], pre[MAXN], vis[MAXN];
    int S, T, cnt, tot, MinCost, MaxFlow; //S源点, T汇点
    void init(int n, int s, int t) {
        memset(G, -1, sizeof(G));
        cnt = 0; tot = n; S = s; T = t;
    }
    void addedge(int u, int v, int f, int c) {//u -> v
        E[cnt] = Edge(u, v, f, c, G[u]); G[u] = cnt ++;
        E[cnt] = Edge(v, u, 0, -c, G[v]); G[v] = cnt ++;
    }
    bool extand() {
        queue<int> Q;
        for (int i = 0; i <= tot; ++ i) dis[i] = inf, vis[i] = 0, pre[i] = -1;
        Q.push(S); vis[S] = 1; dis[S] = 0;
        while (!Q.empty()) {
            int u = Q.front(), v; Q.pop(); vis[u] = false;
            for (int now = G[u]; now != -1; now = E[now].nxt) {
                if (E[now].f > 0 && dis[v = E[now].v] > dis[u] + E[now].c) {
                    dis[v] = dis[u] + E[now].c; pre[v] = now;
                    if (!vis[v]) Q.push(v), vis[v] = true;
                }
            }
        }
        return dis[T] <= limits; // 改成dis[T] <= 0 求可行流
    }
    void solve() {
        MinCost = 0, MaxFlow = 0;
        while (extand()) {
            int nec = inf;
            for (int now = pre[T]; now != -1; now = pre[E[now].u]) nec = min(nec, E[now].f);
            if (dis[T]) nec = 1, limits -= dis[T];
            MinCost += nec * dis[T]; MaxFlow += nec;
            for (int now = pre[T]; now != -1; now = pre[E[now].u]) {
                E[now].f -= nec; E[now ^ 1].f += nec;
            }
        }
    }
}

int main() {
    cin >> n >> limits;
    MCMF::init(n, 0, n - 1);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int x; cin >> x;;
            if (x) {
                MCMF::addedge(i, j, x, 0);
                MCMF::addedge(i, j, MCMF::inf, 1);
            }
        }
    }
    MCMF::solve();
    cout << MCMF::MaxFlow << endl;
    return 0;
}
