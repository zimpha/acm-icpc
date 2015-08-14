#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000;
int dsu[MAXN], mk[MAXN];
int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  int n, m, k;
  while (scanf("%d%d%d", &m, &n, &k) == 3) {
    for (int i = 0; i < n + m; ++ i) dsu[i] = i;
    for (int i = 0; i < n; ++ i) mk[i] = 0;
    for (int i = 0; i < m; ++ i) {
      for (int j = 0; j < n; ++ j) {
        int x; scanf("%d", &x);
        if (x == 0) {
          mk[j] = 1;
          int a = get(j);
          int b = get(i + n);
          if (a != b) dsu[b] = a;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i) {
      if (mk[i]) cnt += get(i) == i;
      else cnt = k + 1;
    }
    if (cnt > k) puts("no");
    else puts("yes");
  }
  return 0;
}

