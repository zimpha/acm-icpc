#include <bits/stdc++.h>
#include "message.h"
#include "sabotaz.h"

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;
const int MAXM = 3000000 + 10;

struct Edge {
  int v, nx;
} E[MAXN << 1];

int e[MAXM];
bool mark[MAXM], vis[MAXN];
int G[MAXN], f[MAXN], dep[MAXN], fa[MAXN];
int belong[MAXN], tmp[MAXN];
int N, M, sz;
int NodeID, Node;

void addedge(int u, int v) {
  E[sz].v = v; E[sz].nx = G[u]; G[u] = sz ++;
  E[sz].v = u; E[sz].nx = G[v]; G[v] = sz ++;
}

int get(int x, int f[]) {
  if (x != f[x]) f[x] = get(f[x], f);
  return f[x];
}

void dfs(int u) {
  vis[u] = 1;
  for (int it = G[u], v; ~it; it = E[it].nx) {
    if (vis[v = E[it].v]) continue;
    fa[v] = u; dep[v] = dep[u] + 1;
    dfs(v);
  }
}

int lca(int x, int y) {
  while (x != y) {
    if (dep[x] > dep[y]) x = get(fa[x], f);
    if (dep[x] < dep[y]) y = get(fa[y], f);
    else x = get(fa[x], f), y = get(fa[y], f);
  }
  return x;
}

void solve() {
  for (int i = 0; i < N; ++ i) {
    G[i] = -1; f[i] = i;
  }
  sz = 0;
  for (int i = 0; i < M; ++ i) {
    int u = get(BridgeEndA(e[i]), belong);
    int v = get(BridgeEndB(e[i]), belong);
    if (get(u, f) != get(v, f)) {
      addedge(u, v);
      f[get(u, f)] = get(v, f);
      mark[i] = 1;
    }
    else mark[i] = 0;
  }
  for (int i = 0; i < N; ++ i) {
    f[i] = i; dep[i] = vis[i] = 0;
  }
  for (int i= 0; i < N; ++ i) {
    if (!vis[i]) dfs(i);
  }
  for (int i = 0; i < M; ++ i) if (!mark[i]) {
    int x = get(BridgeEndA(e[i]), belong);
    int y = get(BridgeEndB(e[i]), belong);
    x = get(x, f); y = get(y, f); if (x == y) continue;
    int t = lca(x, y);
    for (int u = x; u != t; u = get(fa[u], f)) f[u] = t;
    for (int u = y; u != t; u = get(fa[u], f)) f[u] = t;
  }
  sz = 0;
  for (int i = 0; i < M; ++ i) if (mark[i]) {
    int x = get(BridgeEndA(e[i]), belong);
    int y = get(BridgeEndB(e[i]), belong);
    x = get(x, f); y = get(y, f);
    if (x != y) e[sz ++] = e[i];
  }
  M = sz;
  for (int i = 0; i < N; ++ i) {
    int u = get(i, belong);
    u = get(u, f);
    belong[i] = u;
  }
}

void merge(int flag=0) {
  for (int i = 0; i < N; ++ i) f[i] = i;
  for (int i = 0; i < N; ++ i) {
    int u = get(i, belong);
    int v = get(i, tmp);
    u = get(u, f); v = get(v, f);
    if (u != v) {
      cerr << u << " " << v << endl;
      if (rand() % 2) f[v] = u;
      else f[u] = v;
    }
  }
  //if (flag) cerr << "gege" << endl;
  for (int i = 0; i < N; ++ i) {
    int u = get(i, belong);
    u = get(u, f); belong[i] = u;
    cerr << u << endl;
  }
}

const int LIM = 60000;
void give(int sid) {
  int cnt(0);
  for (int i = 0; i < N; ++ i) {
    PutInt(sid, belong[i]);
    //if (++ cnt == LIM) {Send(sid); cnt = 0;}
  }
  Send(sid);
  PutInt(sid, M);
  //if (++ cnt == LIM) {Send(sid); cnt = 0;}
  for (int i = 0; i < M; ++ i) {
    PutInt(sid, e[i]);
    //if (++ cnt == LIM) {Send(sid); cnt = 0;}
  }
  //if (cnt) Send(sid);
  Send(sid);
}

void take(int sid) {
  int cnt(0);
  Receive(sid);
  for (int i = 0; i < N; ++ i) {
    tmp[i] = GetInt(sid);
    //if (++ cnt == LIM) {Receive(sid); cnt = 0;}
  }
  if (NodeID == 0 && sid == Node / 2) cerr << "ok 0" << endl;
  merge(1);
  Receive(sid);
  int num = GetInt(sid);
  //if (++ cnt == LIM) {Receive(sid); cnt = 0;}
  while (num --) {
    e[M ++] = GetInt(sid);
    if (NodeID == 0 && sid == Node / 2) {
      cerr << M << " " << e[M - 1] << endl;
    }
    //if (++ cnt == LIM) {Receive(sid); cnt = 0;}
  }
  if (NodeID == 0 && sid == Node / 2) cerr << "ok 0" << endl;
}

int main() {
  Node = NumberOfNodes(), NodeID = MyNodeId();
  int L = Node / 2, R = Node - L;
  int a = L / 2, b = L - a;
  int c = R / 2, d = R - c;
  N = NumberOfIsles(); M = 0;
  int TM = NumberOfBridges();
  {// first
    for (int i = 0; i < N; ++ i) belong[i] = i;
    for (int i = NodeID; i < TM; i += Node) e[M ++] = i;
    solve();
    int sid(L + c);
    if (NodeID < a) sid = 0;
    else if (NodeID < L) sid = a;
    else if (NodeID < L + c) sid = L;
    if (sid != NodeID) give(sid);
  }

  if (NodeID == 0 || NodeID == a || NodeID == L || NodeID == L + c)
  {// second
    int st, ed;
    if (NodeID == 0) st = 0, ed = a;
    else if (NodeID == a) st = a, ed = L;
    else if (NodeID == L) st = L, ed = L + c;
    else st = L + c, ed = Node;
    for (int i = st + 1; i < ed; ++ i) take(i);
    solve();
    int sid = L * (NodeID >= L);
    if (sid != NodeID) give(sid);
  }

  if (NodeID == 0 || NodeID == L)
  {// third
    int st, ed;
    if (NodeID == 0) st = 0, ed = a;
    else st = L, ed = L + c;
    take(ed);
    solve();
    if (NodeID != 0) give(0);
  }

  if (NodeID == 0)
  {//final
    int st(0), ed(L);
    take(ed);
    solve();
    printf("%d\n", M);
  }
  return 0;
}