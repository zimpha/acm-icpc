#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10, MOD = 10009;

template<int M> struct Mint {
  int x;
  Mint(): x(0) { }
  Mint(int y) {x=y%M; if (x<0) x+=M;}
  Mint(long long y) {x=y%M; if (x<0) x+=M;}
  int get() const {return x;}
  bool operator==(const Mint &r) const {return x==r.x;}
  Mint &operator+=(const Mint &r) {if((x+=r.x)>=M) x-=M; return *this;}
  Mint &operator-=(const Mint &r) {if((x+=M-r.x)>=M) x-=M; return *this;}
  Mint &operator*=(const Mint &r) {x=(long long)x*r.x% M; return *this;}
  Mint operator+(const Mint &r) const {return Mint(*this)+=r; }
  Mint operator-(const Mint &r) const {return Mint(*this)-=r; }
  Mint operator*(const Mint &r) const {return Mint(*this)*=r; }
};
typedef Mint<MOD> mint;

int sz[MAXN], dep[MAXN], fa[MAXN];
int st[MAXN], ed[MAXN], top[MAXN];
int pt[MAXN], n, m, cnt;
vector<int> G[MAXN];

struct SegTree {
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
  struct Node {
    mint s1, s2, ss, add;
    int l, r;
    void set(mint v) {
      s1 += v * (r - l);
      s2 += ss * v;
      add += v;
    }
  } T[MAXN << 2];
  void upd(int rt) {
    T[rt].s1 = T[lson].s1 + T[rson].s1;
    T[rt].s2 = T[lson].s2 + T[rson].s2;
    T[rt].ss = T[lson].ss + T[rson].ss;
  }
  void psd(int rt) {
    T[lson].set(T[rt].add); T[rson].set(T[rt].add);
    T[rt].add = 0;
  }
  void build(int rt, int l, int r) {
    T[rt].l = l; T[rt].r = r; T[rt].add = 0;
    if (l + 1 == r) {
      T[rt].s1 = T[rt].s2 = 0;
      T[rt].ss = sz[pt[l]];
      return;
    }
    build(lson, l, mid); build(rson, mid, r);
    upd(rt);
  }
  void add(int rt, int l, int r, int L, int R, int v) {
    if (L <= l && R >= r) {T[rt].set(v); return;}
    psd(rt);
    if (L < mid) add(lson, l, mid, L, R, v);
    if (R > mid) add(rson, mid, r, L, R, v);
    upd(rt);
  }
  mint ask1(int rt, int l, int r, int L, int R) {
    if (L >= R) return 0;
    if (L <= l && R >= r) return T[rt].s1;
    psd(rt); mint ret(0);
    if (L < mid) ret += ask1(lson, l, mid, L, R);
    if (R > mid) ret += ask1(rson, mid, r, L, R);
    return ret;
  }
  mint ask2(int rt, int l, int r, int L, int R) {
    if (L >= R) return 0;
    if (L <= l && R >= r) return T[rt].s2;
    psd(rt); mint ret(0);
    if (L < mid) ret += ask2(lson, l, mid, L, R);
    if (R > mid) ret += ask2(rson, mid, r, L, R);
    return ret;
  }
  void add(int l, int r, int v) {add(1, 0, n, l, r, v);}
  mint ask1(int l, int r) {return ask1(1, 0, n, l, r);}
  mint ask2(int l, int r) {return ask2(1, 0, n, l, r);}
} AC;

void dfs1(int u, int f = 0, int d = 0) {
  dep[u] = d; fa[u] = f; sz[u] = 1;
  for (auto &v: G[u]) if (v != f) {
    dfs1(v, u, d + 1); sz[u] += sz[v];
  }
}

void dfs2(int u, int chain) {
  int son(-1); pt[cnt] = u; st[u] = cnt ++; top[u] = chain;
  for (auto &v: G[u]) if (dep[v] > dep[u]) {
    if (son == -1 || sz[v] > sz[son]) son = v;
  }
  if (son == -1) {
    ed[u] = cnt;
    return;
  }
  dfs2(son, chain);
  for (auto &v: G[u]) if (dep[v] > dep[u]) {
    if (v != son) dfs2(v, v);
  }
  ed[u] = cnt;
}
void add(int u, int v, int w) {
  int fu = top[u], fv = top[v];
  while (fu != fv) {
    if (dep[fu] < dep[fv]) swap(u, v), swap(fu, fv);
    AC.add(st[fu], st[u] + 1, w);
    u = fa[fu]; fu = top[u];
  }
  if (dep[u] > dep[v]) swap(u, v);
  AC.add(st[u], st[v] + 1, w);
}
mint ask1(int u, int v) {
  int fu = top[u], fv = top[v];
  mint ret(0);
  while (fu != fv) {
    if (dep[fu] < dep[fv]) swap(u, v), swap(fu, fv);
    ret += AC.ask1(st[fu], st[u] + 1);
    u = fa[fu]; fu = top[u];
  }
  if (dep[u] > dep[v]) swap(u, v);
  return ret + AC.ask1(st[u], st[v] + 1);
}

int main() {
  scanf("%d", &n); cnt = 0;
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v); G[v].push_back(u);
  }
  dfs1(1); dfs2(1, 1);
  AC.build(1, 0, n);
  scanf("%d", &m);
  for (int _ = 0; _ < m; ++ _) {
    int op; scanf("%d", &op);
    if (op == 1) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
    }
    else {
      int u; scanf("%d", &u);
      mint ret = ask1(1, u) * sz[u];
      if (st[u] + 1 != ed[u]) {
        ret += AC.ask2(st[u] + 1, ed[u]);
      }
      printf("%d\n", ret.get());
    }
  }
}