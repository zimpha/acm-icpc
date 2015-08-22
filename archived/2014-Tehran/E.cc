#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 5000 + 10;
const LL inf = 1ll << 60;

struct Node {
  int a, b, type, mark;
  void read() {
    scanf("%d%d%d", &a, &b, &type);
    mark = 0;
  }
  bool operator < (const Node &rhs) const {
    return b < rhs.b || (b == rhs.b && a > rhs.a);
  }
} A[MAXN];

int n, R, C1, C2, C3, m;
LL Cost1[MAXN][MAXN], Cost2[MAXN][MAXN];
LL dp[MAXN];
int nxt1[MAXN], nxt2[MAXN];

int main() {
  while (scanf("%d%d%d%d%d", &n, &R, &C1, &C2, &C3) == 5) {
    if (n == 0 && R == 0 && C1 == 0 && C2 == 0 && C3 == 0) break;
    vector<int> pt;
    for (int i = 1; i <= n; ++ i) {
      A[i].read();
      A[i].a -= R; A[i].b += R;
      for (int j = 0; j <= n; ++ j) {
        Cost1[i][j] = Cost2[i][j] = 0;
      }
    }
    sort(A + 1, A + 1 + n);
    A[0].a = A[0].b = -2 * R;
    for (int i = 0; i <= n; ++ i) {
      nxt1[i] = nxt2[i] = 0;
      for (int j = i + 1; j <= n; ++ j) {
        if (A[j].type == 1 && !nxt1[i] && A[j].a > A[i].b) nxt1[i] = j;
        if (A[j].type == 2 && !nxt2[i] && A[j].a > A[i].b) nxt2[i] = j;
      }
    }
    for (int i = 1; i <= n; ++ i) if (A[i].type == 1) {
      LL now(0), r = -R * 2;
      for (int j = i; j <= n; ++ j) {
        if (A[j].type == 1 && A[j].a > r) {
          now += C1, r = A[j].b;
        }
        Cost1[i][j] = now;
      }
    }
    for (int i = 1; i <= n; ++ i) if (A[i].type == 2) {
      LL now(0), r = -R * 2;
      for (int j = i; j <= n; ++ j) {
        if (A[j].type == 2 && A[j].a > r) {
          now += C2, r = A[j].b;
        }
        Cost2[i][j] = now;
      }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++ i) {
      dp[i] = inf;
      for (int j = 0; j < i; ++ j) {
        dp[i] = min(dp[i], dp[j] + Cost1[nxt1[j]][i - 1] + Cost2[nxt2[j]][i - 1]);
      }
      dp[i] += C3;
    }
    LL ret(inf);
    for (int i = 0; i <= n; ++ i) {
      ret = min(ret, dp[i] + Cost1[nxt1[i]][n] + Cost2[nxt2[i]][n]);
    }
    printf("%lld\n", ret);
  }
  return 0;
}