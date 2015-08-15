#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000000 + 10, MOD = 1e9 + 7;

int seated[MAXN], knight[MAXN], sum[MAXN];
int Q[MAXN], N, M;

int main() {
  while (scanf("%d%d", &N, &M) == 2) {
    for (int i = 1; i <= N; ++ i) {
      seated[i] = knight[i] = 0;
    }
    for (int i = 0; i < M; ++ i) {
      int a, b; scanf("%d%d", &a, &b);
      knight[a] = seated[b] = 1;
    }
    sum[0] = 0;
    for (int i = 1; i <= N * 2; ++ i) {
      int x = i > N ? i - N : i;
      sum[i] = sum[i - 1];
      if (knight[x]) -- sum[i];
      if (seated[x]) ++ sum[i];
    }
    int h = 0, t = -1, st(-1);
    for (int i = 1; i <= N * 2; ++ i) {
      while (h <= t && Q[h] <= i - N) ++ h;
      if (i >= N) {
        int mx = sum[Q[h]];
        if (mx >= sum[i - N]) {
          st = i - N + 1;
          break;
        }
      }
      while (h <= t && sum[Q[t]] >= sum[i]) -- t;
      Q[++ t] = i;
    }
    LL ret(1);
    for (int i = 0, cnt(0); i < N; ++ i) {
      int x = st + i > N ? st + i - N : st + i;
      if (!knight[x]) ++ cnt;
      if (!seated[x]) ret = ret * cnt % MOD, -- cnt;
    }
    printf("%lld\n", ret);
  }
  return 0;
}
