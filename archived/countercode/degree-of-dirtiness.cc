#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN = 50000 + 10;

struct Node {
  int mx, lm, rm;
} T[MAXN << 2];

void build(int rt, int l, int r) {
  T[rt].mx = 0; T[rt].lm = l; T[rt].rm = r;
  if (l == r) return;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void add(int rt, int l, int r, int p) {
  if (l == r) {
    T[rt].mx ++;
    return;
  }
  if (p <= mid) add(lson, l, mid, p);
  else add(rson, mid + 1, r, p);
  T[rt].mx = min(T[lson].mx, T[rson].mx);
  if (T[rt].mx == T[lson].mx) T[rt].lm = T[lson].lm;
  else T[rt].lm = T[rson].lm;
  if (T[rt].mx == T[rson].mx) T[rt].rm = T[rson].rm;
  else T[rt].rm = T[lson].rm;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    build(1, 1, n);
    int ret, dirty;
    for (int i = 0; i < m; ++ i) {
      if (i % 2 == 0) {
        ret = ::T[1].lm;
        dirty = ::T[1].mx;
        add(1, 1, n, ret);
      }
      else {
        ret = ::T[1].rm;
        dirty = ::T[1].mx;
        add(1, 1, n, ret);
      }
    }
    printf("%d %d\n", ret, dirty);
  }
  return 0;
}