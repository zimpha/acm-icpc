#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    vector<int> a(m);
    for (int i = 0; i < m; ++ i) {
      scanf("%d", &a[i]);
    }
    if (m == 1) {puts("0"); continue;}
    sort(a.begin(), a.end());
    int rest(m), sum(0), ret;
    for (int i = 0; i < m; ++ i) {
      rest --; sum += a[i];
      if (sum == rest - 1) {
        ret = sum; break;
      }
      if (sum > rest - 1) {
        ret = rest;
        break;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}