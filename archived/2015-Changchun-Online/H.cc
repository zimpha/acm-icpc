#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
int ls[MAXN], rs[MAXN];
int a[MAXN], mx[MAXN];
int n, p;

int build(int l, int r) {
  int m = l;
  for (; m <= r && a[m] <= a[l]; ++ m);
  if (l + 1 <= m - 1) {
    ls[a[l]] = build(l + 1, m - 1);
  }
  if (m <= r) {
    rs[a[l]] = build(m, r);
  }
  return a[l];
}

void solve(int u, int x) {
  if (u == x) {puts(""); return;}
  if (x < u) {
    putchar('E');
    solve(ls[u], x);
  }
  else {
    putchar('W');
    solve(rs[u], x);
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
      scanf("%d", a + i);
      ls[i] = rs[i] = -1;
    }
    int rt = build(1, n);
    int q; scanf("%d", &q);
    while (q --) {
      int x; scanf("%d", &x);
      solve(rt, x);
    }
  }
  return 0;
}

