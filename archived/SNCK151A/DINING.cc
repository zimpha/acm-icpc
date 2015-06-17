#include <bits/stdc++.h>
using namespace std;
typedef double flt;
const flt eps = 1e-11;

int sgn(flt x) {
  if (x < -eps) return -1;
  else return x > eps;
}

namespace ZKW {
    const int MAXN = 20000 + 10, MAXM = 100000 + 10, inf = 1e9;
    struct Edge {
        int u, v, f;
        flt c;
        int nxt;
        Edge() {}
        Edge(int u, int v, int f, flt c, int n) : u(u), v(v), f(f), c(c), nxt(n) {}
    } E[MAXM];
    int G[MAXN];
    flt dis[MAXN];
    int pre[MAXN], vis[MAXN];
    int S, T, cnt, tot;
    flt MinCost;
    int MaxFlow; //S源点, T汇点
    void init(int n, int s, int t) {
        memset(G, -1, sizeof(G));
        cnt = 0; tot = n; S = s; T = t;
    }
    void addedge(int u, int v, int f, flt c) {//u -> v
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
                if (E[now].f > 0 && dis[v = E[now].v] > dis[u] + E[now].c + eps) {
                    dis[v] = dis[u] + E[now].c; pre[v] = now;
                    if (!vis[v]) Q.push(v), vis[v] = true;
                }
            }
        }
        return dis[T] < inf; // 改成dis[T] <= 0 求可行流
    }
    void solve() {
        MinCost = 0, MaxFlow = 0;
        while (extand()) {
            int nec = inf;
            for (int now = pre[T]; now != -1; now = pre[E[now].u]) nec = min(nec, E[now].f);
            MinCost += nec * dis[T]; MaxFlow += nec;
            for (int now = pre[T]; now != -1; now = pre[E[now].u]) {
                E[now].f -= nec; E[now ^ 1].f += nec;
            }
        }
    }
  void get(int mp[], int n) {
    for (int u = 1; u <= n; ++ u) {
      for (int it = G[u]; ~it; it = E[it].nxt) {
        if (E[it].f == 0 && E[it].v > n) {
          mp[u] = E[it].v - n;
        }
      }
    }
  }
}


const int MAXN = 1000 + 10;
const flt MAXC = 1e5;
flt A[MAXN][MAXN];
int mp[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N, D, K; scanf("%d%d%d", &N, &D, &K);
    int S = 0, T = N + D + 1;
    ZKW::init(N + D + 10, 0, T);
    for (int i = 1; i <= N; ++ i) {
      for (int j = 1; j <= D; ++ j) {
        flt x; scanf("%lf", &x);
        A[i][j] = x;
        x = -log(x);
        ZKW::addedge(i, j + N, 1, x);
      }
    }
    for (int i = 1; i <= N; ++ i) {
      ZKW::addedge(S, i, 1, 0);
    }
    for (int i = 1; i <= D; ++ i) {
      if (K > 1) ZKW::addedge(i + N, T, K - 1, 0);
      ZKW::addedge(i + N, T, 1, -MAXC);
    }
    ZKW::solve();
    flt ret = exp(-ZKW::MinCost - MAXC * D);
    ZKW::get(mp, N);
    printf("%.10f\n", ret);
    for (int i = 1; i <= N; ++ i) printf("%d%c", mp[i], " \n"[i == N]);
  }
  return 0;
}