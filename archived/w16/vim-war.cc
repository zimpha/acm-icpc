#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 1 << 20, MOD = 1e9 + 7;
int f[MAXN], p[MAXN], n, m;

int main() {
  p[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    p[i] = p[i - 1] * 2 % MOD;
  }
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    char s[30]; scanf("%s", s);
    int x(0);
    for (int i = 0; i < m; ++ i) {
      x = x << 1 | (s[i] == '1');
    }
    f[x] ++;
  }
  for (int i = 0; i < m; ++ i) {
    for (int s = 0; s < (1 << m); ++ s) {
      if (s >> i & 1) f[s] += f[s ^ 1 << i];
    }
  }
  for (int s = 0; s < (1 << m); ++ s) f[s] = p[f[s]];
  for (int i = 0; i < m; ++ i) {
    for (int s = 0; s < (1 << m); ++ s) {
      if (s >> i & 1) {
        f[s] -= f[s ^ 1 << i];
        if (f[s] < 0) f[s] += MOD;
      }
    }
  }
  char s[30]; scanf("%s", s);
  int S(0);
  for (int i = 0; i < m; ++ i) {
    S = S << 1 | (s[i] == '1');
  }
  if (S == 0) f[S] = (f[S] + MOD - 1) % MOD;
  printf("%d\n", f[S]);
  return 0;
}