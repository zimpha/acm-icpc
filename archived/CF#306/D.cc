#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
vector<int> G[MAXN];
bool solve(int n, int d) {
  if ((n * d - 1) & 1) return false;
  vector<PII> deg;
  for (int i = 0; i < n; ++ i) G[i].clear();
  for (int i = 1; i < n; ++ i) deg.push_back(PII(d, i));
  deg.push_back(PII(d - 1, 0));
  for (int i = 0; i < n; ++ i) {
    sort(deg.begin() + i, deg.end(), greater<PII>());
    if (i + deg[i].first >= n) return false;
    for (int j = 1; j <= deg[i].first; ++ j) {
      if (deg[i + j].first == 0) return false;
      deg[i + j].first --;
      G[deg[i].second].push_back(deg[i + j].second);
    }
  }
  return true;
}
int main() {
  int k; scanf("%d", &k);
  if (k % 2 == 0) puts("NO");
  else {
    int n;
    for (n = k; ; ++ n) {
      if (solve(n, k)) break;
    }
    puts("YES");
    printf("%d %d\n", n * 2, n * k);
    for (int u = 0; u < n; ++ u) {
      for (auto &v: G[u]) {
        printf("%d %d\n", u + 1, v + 1);
        printf("%d %d\n", u + n + 1, v + n + 1);
      }
    }
    printf("%d %d\n", 1, n + 1);
  }
  return 0;
}
