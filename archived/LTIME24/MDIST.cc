#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10, inf = 2e9 + 10;

struct SegTree {
  int mx[MAXN << 2], mi[MAXN << 2];
  void upd(int rt) {
    mx[rt] = max(mx[lson], mx[rson]);
    mi[rt] = min(mi[lson], mi[rson]);
  }
  void modify(int rt, int l, int r, int p, int v) {
    if (l + 1 == r) {mx[rt] = mi[rt] = v; return;}
    if (p < mid) modify(lson, l, mid, p, v);
    else modify(rson, mid, r, p, v);
    upd(rt);
  }
  void upd(PII &x, PII y) {
    x.first = max(x.first, y.first);
    x.second = min(x.second, y.second);
  }
  PII ask(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) return PII(mx[rt], mi[rt]);
    PII ret(-inf, inf); 
    if (L < mid) upd(ret, ask(lson, l, mid, L, R));
    if (R > mid) upd(ret, ask(rson, mid, r, L, R));
    return ret;
  }
} st[4];

int main() {
  int n, q; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int x, y; scanf("%d%d", &x, &y);
    st[0].modify(1, 0, n, i, +x + y);
    st[1].modify(1, 0, n, i, +x - y);
    st[2].modify(1, 0, n, i, -x + y);
    st[3].modify(1, 0, n, i, -x - y);
  }
  scanf("%d", &q);
  while (q --) {
    char op[10]; scanf("%s", op);
    if (op[0] == 'U') {
      int i, x, y; scanf("%d%d%d", &i, &x, &y);
      st[0].modify(1, 0, n, i, +x + y);
      st[1].modify(1, 0, n, i, +x - y);
      st[2].modify(1, 0, n, i, -x + y);
      st[3].modify(1, 0, n, i, -x - y);
    }
    else {
      int l, r; scanf("%d%d", &l, &r); ++ r;
      PII tmp = st[0].ask(1, 0, n, l, r);
      LL ret = (LL)tmp.first - tmp.second;
      tmp = st[1].ask(1, 0, n, l, r);
      ret = max(ret, (LL)tmp.first - tmp.second);
      tmp = st[2].ask(1, 0, n, l, r);
      ret = max(ret, (LL)tmp.first - tmp.second);
      tmp = st[3].ask(1, 0, n, l, r);
      ret = max(ret, (LL)tmp.first - tmp.second);
      printf("%lld\n", ret);
    }
  }
  return 0;
}
