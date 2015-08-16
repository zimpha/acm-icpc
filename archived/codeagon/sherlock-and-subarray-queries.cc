#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;

struct Node {
  int mx, cnt;
} T[MAXN << 2];

int A[MAXN], N, M;

void upd(Node &x, const Node &y) {
  if (y.mx > x.mx) x = y;
  else if (y.mx == x.mx) x.cnt += y.cnt;
}

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

void build(int rt, int l, int r) {
  if (l + 1 == r) {
    scanf("%d", &T[rt].mx);
    T[rt].cnt = 1;
    return;
  }
  build(lson, l, mid);
  build(rson, mid, r);
  T[rt] = T[lson];
  upd(T[rt], T[rson]);
}

Node ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[rt];
  Node ret; ret.mx = 0;
  if (L < mid) upd(ret, ask(lson, l, mid, L, R));
  if (R > mid) upd(ret, ask(rson, mid, r, L, R));
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  build(1, 0, N);
  for (int i = 0; i < M; ++ i) {
    int l, r; scanf("%d%d", &l, &r);
    -- l;
    Node ret = ask(1, 0, N, l, r);
    printf("%d\n", ret.cnt);
  }
  return 0;
}