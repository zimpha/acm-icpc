#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10;

int T[MAXN << 2], a[MAXN], b[MAXN], r[MAXN], n;

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

void build(int rt, int l, int r) {
  T[rt] = r - l;
  if (l + 1 == r) return;
  build(lson, l, mid);
  build(rson, mid, r);
}

void modify(int rt, int l, int r, int p) {
  T[rt] --;
  if (l + 1 == r) return;
  if (p < mid) modify(lson, l, mid, p);
  else modify(rson, mid, r, p);
}

int ask(int rt, int l, int r, int k) {
  if (l + 1 == r) return l;
  if (k <= T[lson]) return ask(lson, l, mid, k);
  else return ask(rson, mid, r, k - T[lson]);
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  for (int i = 0; i < n; ++ i) scanf("%d", r + i);
  build(1, 0, n);
  for (int i = n - 1; i >= 0; -- i) {
    int k = i + 1 - r[i];
    k = ask(1, 0, n, k);
    b[i] = a[k];
    modify(1, 0, n, k);
  }
  for (int i = 0; i < n; ++ i) {
    printf("%d%c", b[i], " \n"[i == n - 1]);
  }
  return 0;
}