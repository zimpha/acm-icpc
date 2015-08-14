#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  for (int n, t; scanf("%d%d", &n, &t) == 2; ) {
    int a[100]; for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    int ret(0), s(0);
    for (int i = 0; i < n; ++ i) {
      s += a[i];
      if (s > t) continue;
      ret = i + 1;
    }
    if (s <= t) ret = n;
    printf("%d\n", ret);
  }
  return 0;
}

