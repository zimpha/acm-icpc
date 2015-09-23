#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;

bool a[MAXN << 1], b[MAXN << 1];
int so[MAXN << 1], se[MAXN << 1];
int n, k;

int calc1(int x) {return n - abs(n + 1 - x);}
int calc2(int x) {return n - abs(x);}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      a[x + y] = b[x - y + MAXN] = 1;
    }
    LL ret(0);
    for (int i = 2; i <= n + n; ++ i) {
      if (a[i]) ret += calc1(i);
    }
    for (int i = -n + 1; i < n; ++ i) {
      if (b[i + MAXN]) ret += calc2(i);
    }
    for (int i = 2; i <= n + n; ++ i) {
      if (i & 1) so[i] = so[i - 2] + a[i];
      else se[i] = se[i - 2] + a[i];
    }
    for (int i = -n + 1; i < n; ++ i) if (b[i + MAXN]) {
      int x = 2 + abs(i), y = n + n - abs(i);
      if (x % 2 == 0) ret -= se[y] - se[x - 2];
      else ret -= so[y] - so[x - 2];
    }
    printf("%lld\n", (LL)n * n - ret);
  return 0;
}
