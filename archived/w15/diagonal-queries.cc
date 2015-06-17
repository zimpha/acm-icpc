#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10, P = 1e9 + 7;

struct Node {
  LL l, r, a, d, val;
  void mark_d(LL x, LL y) {   //x + y * i
    a = (a + x) % P;
    d = (d + y) % P;
    LL n = r - l + 1;
    val = (val + x * n % P + n * (n - 1) / 2 % P * y % P) % P;
  }
} pt[MAXN << 2];

void update(int rt) {
  pt[rt].val = (pt[lson].val + pt[rson].val) % P;
}

void pushdown(int rt) {
  pt[lson].mark_d(pt[rt].a, pt[rt].d);
  LL l = pt[rt].l, r = pt[rt].r, mid = (l + r) >> 1;
  LL am = (pt[rt].a + pt[rt].d * (mid - l + 1) % P) % P;
  pt[rson].mark_d(am, pt[rt].d);
  pt[rt].a = pt[rt].d = 0;
}

void build(int rt, int l, int r) {
  pt[rt].l = l, pt[rt].r = r;
  pt[rt].a = pt[rt].d = 0;
  if (l == r) {pt[rt].val = 0; return;}
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
  update(rt);
}

void add(int rt, int l, int r, int L, int R, int a, int d) {
  if (L <= l && R >= r) {
    LL am = (a + (LL)d * (l - L) % P) % P;
    pt[rt].mark_d(am, d);
    return;
  }
  pushdown(rt);
  int mid = (l + r) >> 1;
  if (L <= mid) add(lson, l, mid, L, R, a, d);
  if (R > mid) add(rson, mid + 1, r, L, R, a, d);
  update(rt);
}

LL sum(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) {return pt[rt].val;}
  pushdown(rt);
  LL ret = 0;
  int mid = (l + r) >> 1;
  if (L <= mid) ret += sum(lson, l, mid, L, R);
  if (R > mid) ret += sum(rson, mid + 1, r, L, R);
  return ret % P;
}

int main() {
  int n, m, q; scanf("%d%d%d", &n, &m, &q);
  int s = n + m - 1;
  build(1, 1, s);
  while (q --) {
    char op[10]; scanf("%s", op);
    if (op[1] == 'c') {
      int c, d; scanf("%d%d", &c, &d);
      int L = c, R = c + n - 1;
      add(1, 1, s, L, R, (LL)d * n % P, P - d);
    }
    else if (op[1] == 'r') {
      int r, d; scanf("%d%d", &r, &d); r = n + 1 - r;
      int L = r, R = r + m - 1;
      add(1, 1, s, L, R, d, d);
    }
    else if (op[1] == 's') {
      int x1, y1, x2, y2, d; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &d);
      x1 = n + 1 - x1; x2 = n + 1 - x2; swap(x1, x2);
      int gap = min(x2 - x1, y2 - y1);
      int L = x1 + y1 - 1, R = x2 + y2 - 1;
      if (gap) {
        add(1, 1, s, L, L + gap - 1, d, d);
        add(1, 1, s, R - gap + 1, R, (LL)d * gap % P, P - d);
      }
      add(1, 1, s, L + gap, R - gap, (LL)d * (gap + 1) % P, 0);
    }
    else if (op[1] == 'd') {
      int l, r; scanf("%d%d", &l, &r);
      printf("%lld\n", sum(1, 1, s, l, r));
    }
  }
  return 0;
}