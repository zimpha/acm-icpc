#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;
int x[MAXN], n, k;
int vs[MAXN];
map<int, int> mp;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++ i) {
    scanf("%d", x + i);
    mp[x[i]] = i;
  }
  int d = x[n] / k, flag = 0;
  for (int i = 0; i < n; ++ i) if (!vs[i]) {
    int cnt(0), p = i; vs[p] = 1;
    for (; ; ) {
      int nx = (x[p] + d) % x[n];
      if (!mp.count(nx)) break;
      p = mp[nx] % n; ++ cnt;
      if (p == i) {
        if (cnt == k) flag = 1;
        break;
      }
      vs[p] = 1;
    }
  }
  printf("%d\n", flag);
  return 0;
}

