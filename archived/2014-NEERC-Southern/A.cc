#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10, P = 250;

namespace DSU {
  int fa[MAXN], ds[MAXN], rk[MAXN];
  int S[MAXN], top;
  void init(int n) {
    for (int i = 1; i <= n; ++ i) {
      fa[i] = i, rk[i] = ds[i] = 0;
    }
    top = 0;
  }
  int dis(int x) {
    int r(0);
    for (; x != fa[x]; x = fa[x]) r ^= ds[x];
    return r;
  }
  int get(int x) {
    while (x != fa[x]) x = fa[x];
    return fa[x];
  }
  void merge(int x, int y, int d) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (rk[x] > rk[y]) swap(x, y);
    if (rk[x] == rk[y]) ++ rk[y], S[++ top] = -y;
    fa[x] = y; ds[x] = d; S[++ top] = x;
  }
  void restore(int ed) {
    for (; top > ed; -- top) {
      if (S[top] < 0) -- rk[-S[top]];
      else fa[S[top]] = S[top], ds[S[top]] = 0;
    }
  }
}

struct Query {
  int l, r, id;
  Query() {}
  Query(int _l, int _r, int _i): l(_l), r(_r), id(_i) {}
  bool operator < (const Query &rhs) const {
    return r < rhs.r;
  }
};

vector<Query> ql[MAXN];
int x[MAXN], y[MAXN], ret[MAXN];
int n, m, q;

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++ i) scanf("%d%d", x + i, y + i);
  for (int i = 0; i < q; ++ i) {
    int l, r; scanf("%d%d", &l, &r); -- l;
    ql[l / P].push_back(Query(l, r, i));
  }
  for (int i = 0; i < m; ++ i) if (ql[i].size()) {
    vector<Query> &Q = ql[i];
    sort(Q.begin(), Q.end());
    DSU::init(n);
    int st(i * P + P), flag(1);
    for (size_t j = 0; j < Q.size(); ++ j) {
      if (Q[j].r <= i * P + P) {
        int ok(1), cp(DSU::top);
        for (int k = Q[j].l; k < Q[j].r && ok; ++ k) {
          int a = DSU::get(x[k]), b = DSU::get(y[k]);
          int d = DSU::dis(x[k]) ^ DSU::dis(y[k]) ^ 1;
          if (a != b) DSU::merge(a, b, d);
          else if (d & 1) ok = 0;
        }
        ret[Q[j].id] = ok;
        DSU::restore(cp);
      }
      else {
        for (; st < Q[j].r && flag; ++ st) {
          int a = DSU::get(x[st]), b = DSU::get(y[st]);
          int d = DSU::dis(x[st]) ^ DSU::dis(y[st]) ^ 1;
          if (a != b) DSU::merge(a, b, d);
          else if (d & 1) flag = 0;
        }
        int ok(flag), cp(DSU::top);
        for (int k = Q[j].l; k < i * P + P && ok; ++ k) {
          int a = DSU::get(x[k]), b = DSU::get(y[k]);
          int d = DSU::dis(x[k]) ^ DSU::dis(y[k]) ^ 1;
          if (a != b) DSU::merge(a, b, d);
          else if (d & 1) ok = 0;
        }
        ret[Q[j].id] = ok;
        DSU::restore(cp);
      }
    }
  }
  for (int i = 0; i < q; ++ i) {
    if (ret[i]) puts("Possible");
    else puts("Impossible");
  }
  return 0;
}

