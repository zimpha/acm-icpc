#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;
int ca[MAXN], cb[MAXN], n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x); ca[x] ++;
  }
  for (int i = 0; i < m; ++ i) {
    int x; scanf("%d", &x); cb[x] ++;
  }
  LL ret = 0;
  for (int i = 1; i < MAXN; ++ i) if (cb[i]) {
    for (int j = i; j < MAXN; j += i) {
      ret += (LL)cb[i] * ca[j] * j / i;
    }
  }
  printf("%lld\n", ret);
  return 0;
}