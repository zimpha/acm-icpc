#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dp[11][11][11][11][11][11];
int B[11], S[11], G[11];
int mul[31], b, s, g;

int solve(int lb, int rb, int ls, int rs, int lg, int rg) {
  if (lb + rb == b && ls + rs == s && lg + rg == g) return 0;
  int &ret = dp[lb][rb][ls][rs][lg][rg];
  if (ret != -1) return ret;
  int n = lb + rb + ls + rs + lg + rg;
  if (lb + rb < b) {
    ret = max(ret, solve(lb + 1, rb, ls, rs, lg, rg) + B[lb] * mul[n]);
    ret = max(ret, solve(lb, rb + 1, ls, rs, lg, rg) + B[b - rb - 1] * mul[n]);
  }
  if (ls + rs < s) {
    ret = max(ret, solve(lb, rb, ls + 1, rs, lg, rg) + S[ls] * mul[n]);
    ret = max(ret, solve(lb, rb, ls, rs + 1, lg, rg) + S[s - rs - 1] * mul[n]);
  }
  if (lg + rg < g) {
    ret = max(ret, solve(lb, rb, ls, rs, lg + 1, rg) + G[lg] * mul[n]);
    ret = max(ret, solve(lb, rb, ls, rs, lg, rg + 1) + G[g - rg - 1] * mul[n]);
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &b, &s, &g);
  for (int i = 0; i < b; ++ i) scanf("%d", B + i);
  for (int i = 0; i < s; ++ i) scanf("%d", S + i);
  for (int i = 0; i < g; ++ i) scanf("%d", G + i);
  for (int i = 0; i < b + s + g; ++ i) scanf("%d", mul + i);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(0, 0, 0, 0, 0, 0));
  return 0;
}

