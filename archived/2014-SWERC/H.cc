#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL inf = 1ll << 60;
const int MAXN = 1000 + 10, MAXM = 10000 + 10;

int u[MAXM], v[MAXM], w[MAXM];
int N, M, X, Y;
LL dis[2][MAXN][MAXN];
bool mark[MAXN];

void bellman() {
  for (int i = 0; i < N; ++ i) {
    for (int j = 0; j <= N; ++ j) {
      dis[0][i][j] = dis[1][i][j] = inf;
    }
  }
  dis[1][X][0] = 0;
  for (int e = 1; e <= N; ++ e) {
    for (int i = 0; i < M; ++ i) {
      if (mark[u[i]] && mark[v[i]]) {
        dis[1][u[i]][e] = min(dis[1][u[i]][e], dis[1][v[i]][e - 1] + w[i]);
        dis[1][v[i]][e] = min(dis[1][v[i]][e], dis[1][u[i]][e - 1] + w[i]);
      }
      dis[0][u[i]][e] = min(dis[0][u[i]][e], dis[0][v[i]][e - 1] + w[i]);
      dis[0][v[i]][e] = min(dis[0][v[i]][e], dis[0][u[i]][e - 1] + w[i]);
      if (!mark[u[i]]) {
        dis[0][u[i]][e] = min(dis[0][u[i]][e], dis[1][v[i]][e - 1] + w[i]);
      }
      if (!mark[v[i]]) {
        dis[0][v[i]][e] = min(dis[0][v[i]][e], dis[1][u[i]][e - 1] + w[i]);
      }
    }
  }
}

LL solve() {
  LL *A = dis[1][Y], *B = dis[0][Y];
  int x, y;
  for (x = 1; x < N && A[x] == inf; ++ x);
  for (y = 1; y < N && B[y] == inf; ++ y);
  if (x == N) return -1;
  if (x < y || (x == y && A[x] < B[y])) return inf;
  LL ret(-1);
  for (; x < N; ++ x) if (B[x] > A[x]) {
    LL add = inf;
    for (int j = 1; j < x; ++ j) {
      if (B[j] <= A[x]) {add = -1; break;}
      LL s = B[j] - A[x], t = x - j;
      LL tmp = s / t - (s % t == 0);
      add = min(add, tmp);
    }
    if (add >= 0) {
      for (int j = x + 1; j < N; ++ j) if (B[j] < A[x]) {
        LL s = A[x] - B[j], t = j - x;
        LL tmp = s / t + (s % t == 0);
        if (add < tmp) {add = -1; break;}
      }
    }
    ret = max(ret, add);
  }
  return ret;
}

int main() {
  while (scanf("%d%d%d%d", &N, &M, &X, &Y) == 4) {
    X --; Y --;
    for (int i = 0; i < N; ++ i) mark[i] = 0;
    for (int i = 0; i < M; ++ i) {
      scanf("%d%d%d", u + i, v + i, w + i);
      -- u[i]; -- v[i];
    }
    int s; scanf("%d", &s);
    for (int i = 0; i < s; ++ i) {
      int x; scanf("%d", &x);
      mark[x - 1] = 1;
    }
    bellman();
    LL ret = solve();
    if (ret == -1) puts("Impossible");
    else if (ret == inf) puts("Infinity");
    else printf("%lld\n", ret);
  }
  return 0;
}

