#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
struct Edge {
  int v, w, nx;
} E[MAXN << 1];

int G[MAXN], top[MAXN], pos[MAXN], fa[MAXN];
int sz[MAXN], dep[MAXN], sum[MAXN];
int n, m, q;

struct UpperConvex {
  vector<int>
};

struct LowerConvex {

};

void addedge(int u, int v, int w) {
  E[m].v = v; E[m].w = w; E[m].nx = G[u]; G[u] = m ++;
  E[m].v = u; E[m].w = w; E[m].nx = G[v]; G[v] = m ++;
}

void dfs1(int u, int f, int d) {
  dep[u] = d; fa[u] = f; sz[u] = 1;
  for (int it = G[u]; ~it; it = E[it].nx) {
    int v = E[it].v; if (v == f) continue;
    dfs1(v, u, d + 1); sz[u] += sz[v];
  }
}

void dfs2(int u, int chain) {
  int son(-1); pos[u] = m ++; top[u] = chain;
  for (int it = G[u]; ~it; it = E[it].nx) {
    int v = E[it].v; if (dep[v] < dep[u]) continue;
    if (son == -1 || size[v] > size[son]) son = v;
  }
  if (son == -1) return; dfs2(son, chain);
  for (int it = G[u]; ~it; it = E[it].nx) {
    int v = E[it].v; if (v == son || dep[v] < dep[u]) continue;
    dfs2(v, v);
  }
}

int main() {

  return 0;
}