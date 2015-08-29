#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[20], b[20], c[20];
int n, m;

int solve(int a[], int b[], int n) {
  int p[20], vis[20];
  for (int i = 0; i < n; ++ i) p[i] = -1, vis[i] = 0;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) if (!vis[j] && a[i] == b[j]) {
      p[i] = j; vis[j] = 1; break;
    }
    if (p[i] == -1) return 1e9;
  }
  int ret(0);
  for (int i = 0; i < n; ++ i) {
    for (int j = i + 1; j < n; ++ j) {
      ret += p[i] > p[j];
    }
  }
  return ret;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    for (int i = 0; i < m; ++ i) scanf("%d", b + i);
    for (int i = 0, t(0); i < m; ++ i) {
      for (int j = 0; j < b[i]; ++ j) {
        c[t ++] = i & 1;
      }
    }
    int ret = solve(a, c, n);
    for (int i = 0; i < n; ++ i) c[i] ^= 1;
    ret = min(ret, solve(a, c, n));
    printf("%d\n", ret);
  }
  return 0;
}

