#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500000 + 10;
struct Edge {
  int v, nx;
} E[MAXN << 1];
int g[MAXN], vs[MAXN], n, m;
vector<PII> sg[MAXN];

struct FastIO {
  static const int S = 1310720;
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
} io;

PII gao(const vector<PII> &s, LL &ret) {
  static PII ev[MAXN << 1]; int m(0);
  LL left(0), right(0);
  int lc(0), rc(0);
  for (auto &x: s) {
    ev[m ++] = PII(x.first, 0);
    ev[m ++] = PII(x.second + 1, -1);
    right += x.first; rc ++;
  }
  sort(ev, ev + m);
  int l(-1), r(-1);
  for (int i = 0; i < m; ++ i) {
    PII &e = ev[i];
    if (e.second == -1) left += e.first - 1, lc ++;
    else right -= e.first, rc --;
    if (lc == rc) {
      l = e.first + e.second;
      ret += (LL)lc * l - left;
      ret += right - (LL)rc * l;
    }
    else if (l != -1) {
      r = e.first + e.second;
      break;
    }
  }
  assert(l != -1);
  return PII(l, r);
}

int main() {
  n = io.xint(); m = io.xint();
  memset(g, -1, sizeof(g[0]) * n);
  for (int i = 0; i + 1 < n; ++ i) {
    int u = io.xint(), v = io.xint();
    vs[-- u] ++; vs[-- v] ++;
    E[i*2]={v,g[u]}; g[u]=i*2;
    E[i*2+1]={u,g[v]}; g[v]=i*2+1;
  }
  vector<int> q1(m), q2;
  for (int i = 0; i < m; ++ i) {
    int x = io.xint();
    q1[i] = i; assert(vs[i] == 1);
    sg[i].push_back(PII(x, x));
  }
  LL ret(0);
  int cnt(0);
  while (1) {
    for (auto &u: q1) {
      for (int it = g[u]; ~it; it = E[it].nx) {
        int v = E[it].v;
        sg[v].push_back(*sg[u].begin());
        if (-- vs[v] == 1) q2.push_back(v);
      }
    }
    if (q2.empty()) break;
    q1.swap(q2); q2.clear();
    for (auto &v: q1) {
      cnt += sg[v].size();
      PII x = gao(sg[v], ret);
      sg[v].clear();
      sg[v].push_back(x);
    }
  }
  if (q1.size() == 2) {
    PII x = *sg[q1[0]].begin();
    PII y = *sg[q1[1]].begin();
    gao({x,y}, ret);
    cnt ++;
  }
  printf("%lld\n", ret);
  return 0;
}