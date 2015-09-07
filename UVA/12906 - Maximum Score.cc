#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10, MOD = 1e9 + 7;
PII A[MAXN];
int n;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      scanf("%d%d", &A[i].first, &A[i].second);
    }
    sort(A, A + n);
    LL ret(0), cnt(1), sum(0);
    for (int i = 0; i < n; ++ i) {
      sum += A[i].second;
      ret += sum * A[i].second;
      if (i + 1 < n) {
        cnt = cnt * (A[i].second + 1) % MOD;
      }
    }
    printf("Case %d: %llu %llu\n", cas, ret, cnt);
  }
  return 0;
}
