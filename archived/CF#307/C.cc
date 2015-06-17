#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int a[MAXN], b[MAXN], n, m;

int main() {
  scanf("%d%d", &n, &m); LL s(0);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i), s += a[i];
  LL left = 2, right = s + n;
  while (left < right) {
    LL mid = (left + right - 1) >> 1;
    memcpy(b, a, sizeof(a[0]) * n);
    int p = n - 1;
    for (int i = 0; i < m; ++ i) {
      while (p >= 0 && b[p] == 0) -- p;
      LL t = mid - p - 1;
      if (t <= 0) break;
      while (p >= 0 && b[p] <= t) t -= b[p --];
      if (p >= 0) b[p] -= t;
    }
    if (p < 0) right = mid;
    else left = mid + 1;
  }
  cout << left << endl;
  return 0;
}

