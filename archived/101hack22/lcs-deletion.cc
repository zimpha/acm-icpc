#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500000 + 10;
int u[MAXN], a[MAXN], b[MAXN], n;

void add(int x, int v) {
  for (; x <= n; x += ~x & x + 1) u[x] = max(u[x], v);
}
int get(int x) {
  int r(0);
  for (; x >= 0; x -= ~x & x + 1) r = max(r, u[x]);
  return r;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a + i);
    -- a[i]; b[a[i]] = i;
  }
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    -- x; a[i] = b[x];
  }
  for (int i = n - 1; i >= 0; -- i) {
    int x = get(a[i] - 1);
    add(a[i], x + 1);
  }
  printf("%d\n", get(n));
  return 0;
}

