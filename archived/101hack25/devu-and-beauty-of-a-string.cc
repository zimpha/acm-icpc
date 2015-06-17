#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

char s[MAXN];
int n;

struct Node {
  int l, cl, sl;
  int r, cr, sr;
  int rev;
  LL s;
  void set_rev() {
    rev ^= 1;
    sl ^= 1; sr ^= 1;
  }
} T[MAXN << 2];

LL C(LL n) {return n * (n + 1) / 2;}

Node upd(const Node &x, const Node &y) {
  Node z; z.l = x.l, z.r = y.r; 
  z.cl = x.cl; z.cr = y.cr; 
  z.sl = x.sl; z.sr = y.sr;
  z.s = x.s + y.s; z.rev = 0;
  if (x.cl == x.r - x.l && x.sr != y.sl) z.cl += y.cl;
  if (y.cr == y.r - y.l && x.sr != y.sl) z.cr += x.cr;
  if (x.sr != y.sl) z.s += C(x.cr + y.cl) - C(x.cr) - C(y.cl);
  return z;
}

void psd(int rt) {
  if (T[rt].rev) {
    T[lson].set_rev();
    T[rson].set_rev();
    T[rt].rev = 0;
  }
}

void build(int rt, int l, int r) {
  T[rt].l = l; T[rt].r = r;
  if (l + 1 == r) {
    T[rt].sl = T[rt].sr = s[l] == '1';
    T[rt].cl = T[rt].cr = T[rt].s = 1;
    return;
  }
  build(lson, l, mid); build(rson, mid, r);
  T[rt] = upd(T[lson], T[rson]);
}

void modify(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) {T[rt].set_rev(); return;}
  psd(rt);
  if (L < mid) modify(lson, l, mid, L, R);
  if (R > mid) modify(rson, mid, r, L, R);
  T[rt] = upd(T[lson], T[rson]);
}

Node ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[rt];
  psd(rt);
  if (R <= mid) return ask(lson, l, mid, L, R);
  if (L >= mid) return ask(rson, mid, r, L, R);
  return upd(ask(lson, l, mid, L, mid), ask(rson, mid, r, mid, R));
}

int main() {
  scanf("%s", s); n = strlen(s);
  build(1, 0, n);
  int q; scanf("%d", &q);
  while (q --) {
    int op, l, r; scanf("%d%d%d", &op, &l, &r);
    if (op == 0) printf("%lld\n", ask(1, 0, n, l - 1, r).s);
    else modify(1, 0, n, l - 1, r);
  }
  return 0;
}

