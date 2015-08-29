#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  for (int n, m; scanf("%d%d", &n, &m) == 2; ) {
    vector<int> a(n + 1, 0);
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      a[u] ++; a[v] --;
    }
    int ret(0);
    for (int i = 1; i <= n; ++ i) {
      a[i] += a[i - 1];
      if (a[i]) ret ++;
    }
    ret = ret * 2 + n + 1;
    printf("%d\n", ret);
  }
  return 0;
}

