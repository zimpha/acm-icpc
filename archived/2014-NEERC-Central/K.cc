#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL dp[40][2][3][3];
int f[4];
int e[][2] = {{0,2},{0,3},{1,2},{1,3},{2,3}};

int get(int x) {
  if (x != f[x]) f[x] = get(f[x]);
  return f[x];
}

int main() {
  int n; scanf("%d", &n);
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;
  dp[0][1][1][1] = 1;
  for (int i = 0; i < n; ++ i) {
    for (int a = 0; a <= 2; ++ a) {
      for (int b = 0; b <= 2; ++ b) {
        for (int s = 0; s < 2; ++ s) if (dp[i][s][a][b]) {
          for (int msk = 0; msk < 32; ++ msk) {
            int d[4] = {a, b, 0, 0};
            f[0] = 0; f[1] = 1; f[2] = 2; f[3] = 3;
            if (s) f[1] = 0;
            bool flag(1);
            for (int j = 0; j < 5; ++ j) if (msk >> j & 1) {
              int x = e[j][0], y = e[j][1];
              d[x] ++; d[y] ++;
              if (d[x] > 2 || d[y] > 2) flag = 0;
              if (get(x) == get(y)) flag = 0;
              x = get(x); y = get(y);
              if (x < y) f[y] = x;
              else f[x] = y;
            }
            if (i == 0 && d[0] > 1) continue;
            if (!flag || (get(2) == 2 && get(3) == 3)) continue;
            if (get(2) == 2) {
              if (get(0) == 0 && get(1) == 0 && get(3) == 0) {
                dp[i + 1][0][d[2]][d[3]] += dp[i][s][a][b];
              }
            }
            else if (get(3) == 3) {
              if (get(0) == 0 && get(1) == 0 && get(2) == 0) {
                dp[i + 1][0][d[2]][d[3]] += dp[i][s][a][b];
              }
            }
            else {
              if (get(2) == get(3)) {
                if (get(1) == 0) {
                  dp[i + 1][1][d[2]][d[3]] += dp[i][s][a][b];
                }
              }
              else {
                assert(s == 0);
                dp[i + 1][0][d[2]][d[3]] += dp[i][s][a][b];
              }
            }
          }
        }
      }
    }
  }
  LL ret(0);
  for (int a = 0; a <= 2; ++ a) {
    for (int b = 0; b <= 2; ++ b) {
      ret += dp[n][1][a][b];
    }
  }
  printf("%lld\n", ret);
  return 0;
}