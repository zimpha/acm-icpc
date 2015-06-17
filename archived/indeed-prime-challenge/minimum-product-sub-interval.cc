#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10, inf = 1e9;

struct Node {
  int cl, cr, cm;
  int s, l, r;
  PII mx;
} T[MAXN << 2];

Node upd(const Node &x, const Node &y) {
  Node z; z.l = x.l; z.r = y.r;
  z.mx = min(x.mx, y.mx); z.cm = max(x.cm, y.cm);
  z.s = (z.cm == x.cm) ? x.s : y.s;
  z.cl = x.cl; z.cr = y.cr;
  if (x.cl == x.r - x.l) z.cl = x.cl + y.cl;
  if (y.cr == y.r - y.l) z.cr = y.cr + x.cr;

  if (z.cl && z.cl >= z.cm) z.cm = z.cl, z.s = z.l;

  if (z.cr > z.cm) z.cm = z.cr, z.s = z.r - z.cr;
  else if (z.cr == z.cm && z.r - z.cr < z.s) z.s = z.r - z.cr;

  if (x.cr + y.cl > z.cm) z.cm = x.cr + y.cl, z.s = x.r - x.cr;
  else if (x.cr + y.cl == z.cm && x.r - x.cr < z.s) z.s = x.r - x.cr;
  return z;
}

void build(int rt, int l, int r) {
  T[rt].l = l; T[rt].r = r; T[rt].s = -1;
  T[rt].cl = T[rt].cr = T[rt].cm = 0;
  if (l + 1 == r) {
    int x; scanf("%d", &x);
    T[rt].mx = PII(x, l);
    if (x == 1) {
      T[rt].cl = T[rt].cr = T[rt].cm = 1; T[rt].s = l;
    }
    return;
  }
  build(lson, l, mid); build(rson, mid, r);
  T[rt] = upd(T[lson], T[rson]);
}

void modify(int rt, int l, int r, int p, int v) {
  if (l + 1 == r) {
    T[rt].mx = PII(v, l);
    if (v == 1) {
      T[rt].cl = T[rt].cr = T[rt].cm = 1; T[rt].s = l;
    }
    else {
      T[rt].cl = T[rt].cr = T[rt].cm = 0; T[rt].s = -1;
    }
    return;
  }
  if (p < mid) modify(lson, l, mid, p, v);
  else modify(rson, mid, r, p, v);
  T[rt] = upd(T[lson], T[rson]);
}

Node ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[rt];
  if (R <= mid) return ask(lson, l, mid, L, R);
  else if (L >= mid) return ask(rson, mid, r, L, R);
  else return upd(ask(lson, l, mid, L, mid), ask(rson, mid, r, mid, R));
}

int main() {
  int n, q; scanf("%d%d", &n, &q);
  build(1, 0, n);
  for (int _ = 0; _ < q; ++ _) {
    int op, x, y; scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      Node z = ask(1, 0, n, x - 1, y);
      if (z.mx.first == 0) printf("0 %d %d\n", x, y);
      else if (z.mx.first == 1) {
        printf("1 %d %d\n", z.s + 1, z.s + z.cm);
      }
      else printf("%d %d %d\n", z.mx.first, z.mx.second + 1, z.mx.second + 1);
    }
    else modify(1, 0, n, x - 1, y);
  }
  return 0;
}
