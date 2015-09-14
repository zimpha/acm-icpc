#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
int s[MAXN], a[MAXN];
int g[MAXN], f[MAXN];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++ i) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= k; ++ i) f[i] = s[i];
  for (int i = k + 1; i <= n; ++ i) {
    f[i] = f[i - 1];
    f[i] = max(f[i], s[i] - s[i - k]);
  }
  for (int i = n; i > n - k; -- i) {
    g[i] = s[n] - s[i - 1];
  }
  for (int i = n - k; i >= 1; -- i) {
    g[i] = g[i + 1];
    g[i] = max(g[i], s[i + k - 1] - s[i - 1]);
  }
  int ret = 0;
  for (int i = 0; i <= n; ++ i) {
    ret = max(ret, f[i] + g[i + 1]);
  }
  printf("%d\n", ret);
  return 0;
}
