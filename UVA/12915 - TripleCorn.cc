#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10, inf = 1e9;

int f[2][MAXN], a[MAXN], s[MAXN];
int p[2][MAXN], N, M;

int W(int x, int y) {
  int t = (x + y) >> 1;
  return s[y] - s[t] - (y - t) * a[t] + (t - x) * a[t] - (s[t - 1] - s[x - 1]);
}

void solve() {
  for (int i = 1; i <= N; ++ i) {
    f[0][i] = W(1, i); p[0][i] = 0;
  }
  int t = 0;
  for (int c(2); c <= M; ++ c) {
    p[t ^ 1][N + 1] = N;
    for (int i = N; i; -- i) {
      int tmp = inf, k;
      for (int j = p[t][i]; j <= p[t ^ 1][i + 1]; ++ j) {
        if (f[t][j] + W(j + 1, i) < tmp) tmp = f[t][k = j] + W(j + 1, i);
      }
      f[t ^ 1][i] = tmp; p[t ^ 1][i] = k;
    }
    t ^= 1;
  }
  printf("%d\n", f[t][N]);
}

int main() { 
  while(scanf("%d%d", &N, &M) == 2) {
    for (int i = 1; i <= N; ++ i) scanf("%d", a + i);
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; ++ i) s[i] = s[i - 1] + a[i];
    solve();
  }
  return 0;
}
