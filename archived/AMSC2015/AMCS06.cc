#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

int dp[MAXN], N, L, D;
PII A[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d", &N, &L, &D);
    for (int i = 1; i <= N; ++ i) {
      scanf("%d%d", &A[i].first, &A[i].second);
    }
    sort(A + 1, A + 1 + N);
    A[++ N] = PII(L, 0);
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    Q.push(PII(0, 0)); dp[0] = 0;
    for (int i = 1; i <= N; ++ i) dp[i] = -1;
    for (int i = 1; i <= N; ++ i) {
      while (!Q.empty() && Q.top().second + D < A[i].first) Q.pop();
      if (Q.empty()) break;
      dp[i] = A[i].second + Q.top().first;
      Q.push(PII(dp[i], A[i].first));
    }
    if (dp[N] != -1) printf("YES %d\n", dp[N]);
    else puts("NO");
  }
  return 0;
}

