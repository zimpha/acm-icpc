#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 50000 + 10;

struct Edge {
  int u, v, w; 
  bool operator < (const Edge &rhs) const {
    return w < rhs.w;
  }
} E[MAXN];
int dsu[MAXN], n, m;

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < m; ++ i) {
      scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
    }
    sort(E, E + m);
    for (int i = 1; i <= n; ++ i) dsu[i] = i;
    vector<int> can;
    int cost(0);
    for (int i = 0; i < m; ++ i) {
      int u = get(E[i].u), v = get(E[i].v);
      if (u != v) {
        can.push_back(i);
        dsu[u] = v;
        cost += E[i].w;
      }
    }
    int ret(0), sum(0);
    for (auto &e: can) {
      for (int i = 1; i <= n; ++ i) dsu[i] = i;
      int tmp(0), cnt(0);
      for (int i = 0; i < m; ++ i) if (i != e) {
        int u = get(E[i].u), v = get(E[i].v);
        if (u != v) {
          dsu[u] = v;
          cnt ++;
          tmp += E[i].w;
        }
      }
      if (cnt != n - 1 || tmp > cost) {
        ret ++; sum += E[e].w;
      }
    }
    printf("%d %d\n", ret, sum);
  }
  return 0;
}

