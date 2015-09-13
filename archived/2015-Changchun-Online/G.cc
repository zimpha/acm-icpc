#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[10000];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
    int q; scanf("%d", &q);
    while (q --) {
      int l, r; scanf("%d%d", &l, &r);
      int mx = a[l];
      for (int i = l; i <= r; ++ i) mx = max(mx, a[i]);
      printf("%d\n", mx);
    }
  }
  return 0;
}

