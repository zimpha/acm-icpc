#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;

PII a[MAXN];
int vs[MAXN], n;

int main() {
  scanf("%d", &n);
  int tot(n), has(0);
  for (int i = 0; i < n; ++ i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    if (a[i].first > a[i].second) vs[i] = 1, ++ has;
    else vs[i] = 0;
  }
  vector<PII> ret;
  for (int i = 0; i + 1 < n; ++ i) {
    if (has * 2 > tot) break;
    if (!vs[i] && !vs[i + 1]) {
      ret.push_back(PII(i, i + 1));
      ++ i; -- tot; continue;
    }
    if (!vs[i] || !vs[i + 1]) {
      int x = a[i].first + a[i + 1].first;
      int y = a[i].second + a[i + 1].second;
      if (x > y) {
        ret.push_back(PII(i, i + 1));
        ++ i; -- tot; continue;
      }
    }
  }
  if (has * 2 <= tot) puts("-1");
  else {
    printf("%d\n", (int)ret.size());
    for (auto &x: ret) printf("%d %d\n", x.first + 1, x.second + 1);
  }
  return 0;
}

