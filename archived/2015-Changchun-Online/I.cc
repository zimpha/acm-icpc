#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 60000 + 10;

// vol, wei
PII A[MAXN], B[MAXN];
int f[MAXN], g[MAXN];
int n, m, p, ca, cb;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d", &n, &m, &p);
    ca = cb = 0;
    for (int i = 0; i < n; ++ i) {
      int x, y, z; scanf("%d%d%d", &x, &y, &z);
      for (int s(1); s <= z; s <<= 1) {
        A[ca ++] = PII(s * x, s * y);
        z -= s;
      }
      if (z) A[ca ++] = PII(z * x, z * y);
    }
    for (int i = 0; i < m; ++ i) {
      int x, y, z; scanf("%d%d%d", &x, &y, &z);
      for (int s(1); s <= z; s <<= 1) {
        B[cb ++] = PII(s * y, s * x);
        z -= s;
      }
      if (z) B[cb ++] = PII(z * y, z * x);
    }

    for (int i = 0; i <= p + 10000; ++ i) f[i] = 1e9;
    f[0] = 0;
    for (int i = 0; i < ca; ++ i) {
      int v = A[i].first, w = A[i].second;
      for (int j = p + 10000; j >= v; -- j) {
        f[j] = min(f[j], f[j - v] + w);
      }
    }
    int vol = f[p];
    for (int i = 0; i < 10000; ++ i) vol = min(vol, f[p + i + 1]);
    p = 50000;
    for (int i = 0; i <= p; ++ i) f[i] = 0;
    for (int i = 0; i < cb; ++ i) {
      int v = B[i].first, w = B[i].second;
      for (int j = p; j >= v; -- j) {
        f[j] = max(f[j], f[j - v] + w);
      }
    }
    int ret(-1);
    for (int i = 0; i <= p; ++ i) {
      if (f[i] >= vol) {ret = i; break;}
    }
    if (ret == -1) puts("TAT");
    else printf("%d\n", ret);
  }
  return 0;
}