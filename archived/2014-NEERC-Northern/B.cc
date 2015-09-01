#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 50000 + 10;

PII D[MAXN], P[MAXN];
LL SD[MAXN], SP[MAXN];
int b, k, cd, cp;

int main() {
  freopen("buffcraft.in", "r", stdin);
  freopen("buffcraft.out", "w", stdout);
  scanf("%d%d%d%d", &b, &k, &cd, &cp);
  for (int i = 1; i <= cd; ++ i) {
    scanf("%d", &D[i].first);
    D[i].second = i;
  }
  for (int i = 1; i <= cp; ++ i) {
    scanf("%d", &P[i].first);
    P[i].second = i;
  }
  sort(D + 1, D + cd + 1, greater<PII>());
  sort(P + 1, P + cp + 1, greater<PII>());
  LL ret = b * 100;
  int n = 0, m = 0;
  for (int i = 1; i <= cd; ++ i) {
    SD[i] = SD[i - 1] + D[i].first;
  }
  for (int i = 1;  i <= cp; ++ i) {
    SP[i] = SP[i - 1] + P[i].first;
  }
  for (int i = 0; i <= cd && i <= k; ++ i) {
    int j = k - i;
    if (j > cp) j = cp;
    LL now = (LL)(b + SD[i]) * (SP[j] + 100);
    if (now > ret) {
      ret = now;
      n = i, m = j;
    }
  }
  printf("%d %d\n", n, m);
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", D[i].second, " \n"[i == n]);
  }
  if (n == 0) puts("");
  for (int i = 1; i <= m; ++ i) {
    printf("%d%c", P[i].second, " \n"[i == m]);
  }
  if (m == 0) puts("");
  return 0;
}