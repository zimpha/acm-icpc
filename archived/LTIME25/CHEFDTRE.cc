#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 300000, SZ = MAXN << 4;

int ls[SZ], rs[SZ], cnt[SZ];
int rt[MAXN], sz, n, q;

int build(int l, int r, int v) {
  int p = ++ sz; cnt[sz] = 1;
  if (l == r) return p;
  int m = (l + r) >> 1;
  if (v <= m) ls[p] = build(l, m, v);
  else rs[p] = build(m + 1, r, v);
  return p;
}

int merge(int a, int b) {
  if (a == 0) return b;
  else if (b == 0) return a;
  int p = ++ sz;
  ls[p] = merge(ls[a], ls[b]);
  rs[p] = merge(rs[a], rs[b]);
  cnt[p] = cnt[ls[p]] + cnt[rs[p]];
  return p;
}

int ask(int o, int l, int r, int k) {
  if (l == r) return l;
  int lc = cnt[ls[o]], m = (l+r)>>1;
  if (k <= lc) return ask(ls[o], l, m, k);
  else return ask(rs[o], m + 1, r, k - lc);
}

int main() {
  sz = 1; scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++ i) {
    rt[i] = build(1, n, i);
  }
  int m = n;
  for (int i = 0; i < q; ++ i) {
    char op[100];
    int a, b; scanf("%s%d%d", op, &a, &b);
    if (op[0] == 'U') {
      rt[++ m] = merge(rt[a], rt[b]);
    }
    else {
      printf("%d\n", ask(rt[a], 1, n, b));
    }
  }
  return 0;
}

