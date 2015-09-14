#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;
int a[MAXN], nx[MAXN];
int n, k, lim;

int u[MAXN];
void add(int x, int v) {
  for (; x <= n; x += ~x & x + 1) u[x] += v;
}
int sum(int x) {
  int r(0);
  for (; x >= 0; x -= ~x & x + 1) r += u[x];
  return r;
}
int sum(int l, int r) {
  return sum(r) - sum(l - 1);
}
int get(int x) {
  if (a[x] > lim) return x;
  else return nx[x] = get(nx[x]);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++ i) {
    nx[i] = i - 1;
    scanf("%d", a + i);
    add(i, a[i]);
  }
  lim = *min_element(a, a + n);
  LL ret = 0;
  for (int i = k - 1; i < n; ++ i) {
    int now = sum(i - k + 1, i);
    if (now < 0) continue;
    ret += ++ now;
    for (int p = i; now; p = get(p)) {
      int delta = min(now, a[p] - lim);
      add(p, -delta); a[p] -= delta;
      now -= delta; 
    }
  }
  printf("%lld\n", ret);
  for (int i = 0; i < n; ++ i) printf("%d ", a[i]);
  puts("");
  return 0;
}